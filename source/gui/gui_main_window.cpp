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
    ,   m_newFileAction(new QAction(this))
    ,   m_openFileAction(new QAction(this))
    ,   m_saveFileAction(new QAction(this))
    ,   m_exitApplicationAction(new QAction(this))
    ,   m_switchThemeAction(new QAction(this))
    ,   m_renderNonPrintableSymbolsAction(new QAction(this))
    ,   m_searchAction(new QAction(this))
    ,   m_checkSpellingAction(new QAction(this))
    ,   m_settingsAction(new QAction(this))
    ,   m_aboutAction(new QAction(this))
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
    fileMenu->addAction(m_newFileAction);
    fileMenu->addAction(m_openFileAction);
    fileMenu->addAction(m_saveFileAction);
    fileMenu->addAction(m_exitApplicationAction);

    QMenu * viewMenu = new QMenu("View", this);
    viewMenu->addAction(m_switchThemeAction);
    viewMenu->addAction(m_renderNonPrintableSymbolsAction);

    QMenu * toolsMenu = new QMenu("Tools", this);
    toolsMenu->addAction(m_searchAction);
    toolsMenu->addAction(m_checkSpellingAction);

    QMenu * helpMenu = new QMenu("Help", this);
    helpMenu->addAction(m_settingsAction);
    helpMenu->addAction(m_aboutAction);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(viewMenu);
    menuBar()->addMenu(toolsMenu);
    menuBar()->addMenu(helpMenu);
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
            m_newFileAction
        ,   this
        ,   &MainWindow::slotOnNewFileActionTriggered
        ,   "New File"
        ,   "Create new file"
        ,   "Ctrl+N"
        ,   "icons/new_file.png"
    );

    utils::initializeAction(
            m_openFileAction
        ,   this
        ,   &MainWindow::slotOnOpenFileActionTriggered
        ,   "Open File"
        ,   "Open file on a disk"
        ,   "Ctrl+O"
        ,   "icons/open_file.png"
    );

    utils::initializeAction(
            m_saveFileAction
        ,   this
        ,   &MainWindow::slotOnSaveFileActionTriggered
        ,   "Save File"
        ,   "Save file on a disk"
        ,   "Ctrl+S"
        ,   "icons/save_file.png"
    );

    utils::initializeAction(
            m_exitApplicationAction
        ,   this
        ,   &MainWindow::slotOnExitApplicationActionTriggered
        ,   "Exit"
        ,   "Exit application"
        ,   QString() // shortcut
        ,   "icons/exit.png"
    );

    utils::initializeAction(
            m_switchThemeAction
        ,   this
        ,   &MainWindow::slotOnSwitchThemeActionTriggered
        ,   "Switch theme"
        ,   "Switch theme to white or dark"
        ,   QString() // shortcut
        ,   "icons/switch_theme.png"
    );

    utils::initializeAction(
            m_renderNonPrintableSymbolsAction
        ,   this
        ,   &MainWindow::slotOnRenderNonPrintableSymbolsActionTriggered
        ,   "Render Non Printable Symbols"
        ,   "Render non printable symbols"
        ,   QString() // shortcut
        ,   "icons/non_printable_symbol.png"
    );

    utils::initializeAction(
            m_settingsAction
        ,   this
        ,   &MainWindow::slotOnSettingsActionTriggered
        ,   "Settings"
        ,   "Configure settings"
        ,   QString() // shortcut
        ,   "icons/settings.png"
    );

    utils::initializeAction(
            m_checkSpellingAction
        ,   this
        ,   &MainWindow::slotOnCheckSpellingActionTriggered
        ,   "Check Spelling"
        ,   "Check spellings on text"
        ,   QString() // shortcut
        ,   "icons/check_spelling.png"
    );

    utils::initializeAction(
            m_aboutAction
        ,   this
        ,   &MainWindow::slotOnAboutActionTriggered
        ,   "About"
        ,   "Read Teora info"
        ,   QString() // shortcut
        ,   "icons/about.png"
    );

    utils::initializeAction(
            m_searchAction
        ,   this
        ,   &MainWindow::slotOnSearchActionTriggered
        ,   "Search"
        ,   "Search within text"
        ,   "Ctrl+F"
        ,   "icons/search.png"
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
MainWindow::slotOnNewFileActionTriggered()
{
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

void
MainWindow::slotOnExitApplicationActionTriggered()
{
    QApplication::exit();
}

void
MainWindow::slotOnSwitchThemeActionTriggered()
{
    utils::showInfoMessageBox(this, "Switch theme not implemented yet.");
}

void
MainWindow::slotOnRenderNonPrintableSymbolsActionTriggered()
{
    utils::showInfoMessageBox(this, "Render non printable symbols not implemented yet.");
}

void
MainWindow::slotOnSearchActionTriggered()
{
    utils::showInfoMessageBox(this, "Search not implemented yet.");
}

void
MainWindow::slotOnCheckSpellingActionTriggered()
{
    utils::showInfoMessageBox(this, "Check spelling not implemented yet.");
}

void
MainWindow::slotOnSettingsActionTriggered()
{
    utils::showInfoMessageBox(this, "Settings not implemented yet.");
}

void
MainWindow::slotOnAboutActionTriggered()
{
    utils::showInfoMessageBox(this, "Teora 2022 all rights reserved");
}

} // namespace teora::gui