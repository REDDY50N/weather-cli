// Qt
#include <QCoreApplication>
#include <QDebug>
#include <QCommandLineParser>
#include <memory>

// API
#include "weatherapi.h"




int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("OpenWheaterMap-CLI");
    QCoreApplication::setApplicationVersion("1.0.0");

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

    // UserManager manager;
    // manager.start();
    // bool writeAllTriggered = false;
    // manager.connect(&manager, &UserManager::newCurrentUser, [&manager, &writeAllTriggered]());




    QCommandLineParser parser;
    parser.setApplicationDescription("Description: OpenWeatherMap console application (CLI)");
    parser.addVersionOption();
    parser.addHelpOption();


    parser.addOptions({
        // A boolean option with a single name (-p)
        {"p",
            QCoreApplication::translate("main", "Show progress during copy")},
        // A boolean option with multiple names (-f, --force)
        {{"f", "force"},
            QCoreApplication::translate("main", "Overwrite existing files.")},
        // An option with a value
        {{"t", "target-directory"},
            QCoreApplication::translate("main", "Copy all source files into <directory>."),
            QCoreApplication::translate("main", "directory")},
    });

    parser.addOptions({
        {"debug",
            "Enable the debug mode."},

        {{"f", "file"},
            "Write the logs into <file>.",
            "logfile"},

        {{"l", "level"},
            "Restrict the logs to level <level>. Default is 'fatal'.",
            "level",
            "fatal"},
    });


    // Process the actual command line arguments given by the user
    parser.process(app);



    qDebug() << "===============================================================";
    qDebug() << "debug mode:" << parser.isSet("debug");
    qDebug() << "file:" << parser.value("file");
    qDebug() << "level:" << parser.value("level");




    return app.exec();
}
