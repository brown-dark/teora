/* Copyright (C) Yevhenii Mamontov 2022 */

#pragma once

#include <QMainWindow>

class QAction;
class QTextEdit;

namespace teora::gui
{
    class MainWindowStatusBar;
    class TextEditWidget;
}

namespace teora {
namespace gui {

class MainWindow final
    :   public QMainWindow
{
    Q_OBJECT

private:

    TextEditWidget * m_textEdit;
    MainWindowStatusBar * m_statusBar;

    QAction * m_openFileAction;

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

};

} // namespace gui
} // namespace teora
