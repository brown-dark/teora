/* Copyright (C) Yevhenii Mamontov 2022 */

#pragma once

#include <QMainWindow>

namespace teora::gui
{
    class MainWindowStatusBar;
    class TextEditWidget;
}
class QAction;
class QTextEdit;

namespace teora::gui
{

class MainWindow final
    :   public QMainWindow
{
    Q_OBJECT

private:

    TextEditWidget * m_textEdit;
    MainWindowStatusBar * m_statusBar;

    QAction * m_newFileAction;
    QAction * m_openFileAction;
    QAction * m_saveFileAction;
    QAction * m_exitApplicationAction;

    QAction * m_switchThemeAction;
    QAction * m_renderNonPrintableSymbolsAction;

    QAction * m_searchAction;
    QAction * m_checkSpellingAction;

    QAction * m_settingsAction;
    QAction * m_aboutAction;

public:

    MainWindow();

private:

    void prepareMainWindow();
    void addMenuBar();
    void addStatusBar();
    void initializeActions();
    void doSignalSlotConnections();

private slots:

    void slotOnNewFileActionTriggered();
    void slotOnOpenFileActionTriggered();
    void slotOnSaveFileActionTriggered();
    void slotOnExitApplicationActionTriggered();

    void slotOnSwitchThemeActionTriggered();
    void slotOnRenderNonPrintableSymbolsActionTriggered();

    void slotOnSearchActionTriggered();
    void slotOnCheckSpellingActionTriggered();

    void slotOnSettingsActionTriggered();
    void slotOnAboutActionTriggered();
};

} // namespace teora::gui
