#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>

int main( int argc, char *argv[] )
{
    QApplication qtApp(argc, argv);

    QMessageBox msgbox(nullptr);
    msgbox.setText("Hello, Teora!");
    msgbox.show();

    return qtApp.exec();
}