/* Copyright (C) Yevhenii Mamontov 2022 */

#include "gui_main_window.hpp"

#include "utils/utl_suplementary_widget_functions.hpp"

#include <QApplication>
#include <QAction>
#include <QDir>
#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QScreen>
#include <QTextEdit>

namespace teora {
namespace gui {

namespace {
    const QRect kScreenGeometry = QApplication::screens().first()->geometry();
} // namespace

// TODO: load strings from resources.

GuiMainWindow::GuiMainWindow()
    :   m_textEdit(new QTextEdit(this))
    ,   m_openFileAction(new QAction(this))
{
    prepareMainWindow();
    addMenuBar();
    initializeActions();
}

void
GuiMainWindow::prepareMainWindow()
{
    setCentralWidget(m_textEdit);

    resize(kScreenGeometry.width() / 2, kScreenGeometry.height() / 2);
}

void
GuiMainWindow::addMenuBar()
{
    QMenu * fileMenu = new QMenu("File", this);
    fileMenu->addAction(m_openFileAction);

    menuBar()->addMenu(fileMenu);
}

void
GuiMainWindow::initializeActions()
{
    utils::initializeAction(
            m_openFileAction
        ,   this
        ,   &GuiMainWindow::slotOnOpenFileActionTriggered
        ,   "Open File"
        ,   "Open file on a disk"
    );
}

void
GuiMainWindow::slotOnOpenFileActionTriggered()
{
    QString pathToFile =
        QFileDialog::getOpenFileName(
                this
            ,   "Open File"
            ,   QDir::currentPath()
            ,   "*.txt"
        );

    QFile file(pathToFile);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox msgbox;
        msgbox.setText("Failed to open file");
        msgbox.setWindowTitle("Error");
        msgbox.show();
    }

    m_textEdit->insertPlainText(file.readAll());
}

} // namespace gui
} // namespace teora