#include "gui/gui_main_window.hpp"

#include <QApplication>
#include <QDir>

int main( int argc, char *argv[] )
{
    QApplication qtApp(argc, argv);

    QDir::setCurrent(QCoreApplication::applicationDirPath());

    qtApp.setApplicationName("Teora");
    qtApp.setWindowIcon(QIcon("icons/teora.png"));

    teora::gui::MainWindow mw;
    mw.show();

    return qtApp.exec();
}