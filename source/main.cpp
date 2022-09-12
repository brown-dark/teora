#include <QtWidgets/QApplication>

#include "gui/gui_main_window.hpp"

int main( int argc, char *argv[] )
{
    QApplication qtApp(argc, argv);

    teora::gui::MainWindow mw;
    mw.show();

    return qtApp.exec();
}