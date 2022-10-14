/* Copyright (C) Yevhenii Mamontov 2022 */

#include "gui_main_window.hpp"

#include "gui_main_window_status_bar.hpp"
#include "gui_text_edit_widget.hpp"

#include "utils/utl_message_box.hpp"
#include "utils/utl_suplementary_widget_functions.hpp"

#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QScreen>

namespace teora::gui
{

MainWindow::MainWindow()
    :   m_textEdit(new TextEditWidget(this))
    ,   m_statusBar(new MainWindowStatusBar(this))
    ,   m_openFileAction(new QAction(this))
    ,   m_saveFileAction(new QAction(this))
{
    prepareMainWindow();
    addMenuBar();
    addStatusBar();
    initializeActions();
    doSignalSlotConnections();
}

void
MainWindow::prepareMainWindow()
{
    setCentralWidget(m_textEdit);

    const QRect screenGeometry = QApplication::screens().first()->geometry();
    resize(screenGeometry.width() / 2, screenGeometry.height() / 2);
}

void
MainWindow::addMenuBar()
{
    QMenu * fileMenu = new QMenu("File", this);
    fileMenu->addAction(m_openFileAction);
    fileMenu->addAction(m_saveFileAction);

    menuBar()->addMenu(fileMenu);
}

void
MainWindow::addStatusBar()
{
    addToolBar(Qt::ToolBarArea::BottomToolBarArea, m_statusBar);
}

void
MainWindow::initializeActions()
{
    utils::initializeAction(
            m_openFileAction
        ,   this
        ,   &MainWindow::slotOnOpenFileActionTriggered
        ,   "Open File"
        ,   "Open file on a disk"
    );

    utils::initializeAction(
            m_saveFileAction
        ,   this
        ,   &MainWindow::slotOnSaveFileActionTriggered
        ,   "Save File"
        ,   "Save file on a disk"
    );
}

void
MainWindow::doSignalSlotConnections()
{
    connect(
            m_textEdit
        ,   &TextEditWidget::signalCursorPositionChanged
        ,   m_statusBar
        ,   &MainWindowStatusBar::slotOnCursorPositionChanged
    );

    connect(
            m_textEdit
        ,   &TextEditWidget::signalWordsCountChanged
        ,   m_statusBar
        ,   &MainWindowStatusBar::slotOnWordsCountChanged
    );
}

void
MainWindow::slotOnOpenFileActionTriggered()
{
    m_textEdit->loadData();
}

void
MainWindow::slotOnSaveFileActionTriggered()
{
    m_textEdit->saveData();
}

} // namespace teora::gui