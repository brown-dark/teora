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

    QAction * m_openFileAction;
    QAction * m_saveFileAction;

public:

    MainWindow();

private:

    void prepareMainWindow();
    void addMenuBar();
    void addStatusBar();
    void initializeActions();
    void doSignalSlotConnections();

private slots:

    void slotOnOpenFileActionTriggered();
    void slotOnSaveFileActionTriggered();

};

} // namespace teora::gui
