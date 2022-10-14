/* Copyright (C) Yevhenii Mamontov 2022 */

#pragma once

#include <QToolBar>

class QLabel;

namespace teora::gui
{

class MainWindowStatusBar final
    :   public QToolBar
{
    Q_OBJECT

private:

    QLabel * m_cursorPositionLabel;
    QLabel * m_wordsCountLabel;

public:

    MainWindowStatusBar(QWidget * _parent);

private:

    void prepareToolBar();

public slots:

    void slotOnCursorPositionChanged(
            int _lineNumber = 0
        ,   int _columnNumber = 0
    );

    void slotOnWordsCountChanged(int _wordsCount = 0);

};

} // namespace teora::gui