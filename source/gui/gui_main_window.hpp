/* Copyright (C) Yevhenii Mamontov 2022 */

#pragma once

#include <QMainWindow>

class QAction;
class QTextEdit;

namespace teora{
namespace gui {

class GuiMainWindow final
    :   public QMainWindow
{
    Q_OBJECT

private:

    QTextEdit * m_textEdit;
    QAction * m_openFileAction;

public:

    GuiMainWindow();

private:

    void prepareMainWindow();
    void addMenuBar();
    void initializeActions();

private slots:

    void slotOnOpenFileActionTriggered();

};

} // namespace gui
} // namespace teora
