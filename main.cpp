// Qt
#include <QCoreApplication>
#include <QDebug>
#include <QCommandLineParser>
#include <memory>

// API
#include "weatherapi.h"

// Test
#include <QtNetwork/QDnsLookup>


void showWeather()
{
    WeatherAPI w;
    QString city = "Neu-Isenburg";
    QString country_code = "DE";

    w.getTemperature( city, country_code );
    w.getTempMin( city, country_code );
    w.getTempMax( city, country_code );
    w.getFeelsLike( city, country_code );
    w.getHumidity( city, country_code );
    w.getWindSpeed(city, country_code);
    w.getWindDeg( city, country_code );
    w.getWeatherStatus( city, country_code );
    w.getCloudCoverage( city, country_code );

    w.getSunriseTime( city, country_code );
    w.getPressure( city, country_code );
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("OpenWheaterMap-CLI");
    QCoreApplication::setApplicationVersion("1.0.0");

    WeatherAPI w;
    //QString city = "Neu-Isenburg";
    QString country_code = "DE";



    // Template:
    // https://github.com/typecaster0xf/cppExamples-Qt-00_CommandLineParse/blob/master/commandParse.cpp

    QCommandLineParser parser;
    parser.setApplicationDescription("Description: OpenWeatherMap console application (CLI)");
    parser.addVersionOption();
    parser.addHelpOption();

    // positional arguments
    parser.addPositionalArgument("city", QCoreApplication::translate("main", "City for weather query."));
    parser.addPositionalArgument("Country Code", QCoreApplication::translate("main", "Country Code of the city (i.e. DE)."));

    // value option (city, cc)
    QCommandLineOption cityOption(QStringList() << "c" << "city",
            QCoreApplication::translate("main", "Set city to <'City, DE'>."),
            QCoreApplication::translate("main", "City"));
    parser.addOption( cityOption );

    // temp
    QCommandLineOption tempOption(
            QStringList() << "t" << "temperature",
            QCoreApplication::translate("main", "Show (now, min, max) temperature."));
    parser.addOption( tempOption );

    QCommandLineOption humidtyOption(
            QStringList() << "a" << "humidity",
            QCoreApplication::translate("main", "Show air pressure."));
    parser.addOption( humidtyOption );

    QCommandLineOption pressureOption(
            QStringList() << "p" << "pressure",
            QCoreApplication::translate("main", "Show air pressure."));
    parser.addOption( pressureOption );


    // Process the actual command line arguments given by the user
    parser.process(app);

    const QStringList args = parser.positionalArguments();
    // source is args.at(0), destination is args.at(1)

    QString city = parser.value( cityOption );

    bool showTemp = parser.isSet( tempOption );
    bool showPressure = parser.isSet( pressureOption );
    bool showHumidity = parser.isSet( pressureOption );

    if ( showTemp )
    {
        w.getTemperature( city, country_code );
        return 0;
    }
    else if ( showPressure )
    {
        w.getPressure( city, country_code );
        return 0;
    }
    else if ( showHumidity )
    {
        w.getHumidity( city, country_code );
        return 0;
    }
    else
    {
        qDebug() << "No valid Option!";
        return 0;
    }

    return app.exec();
}
