/* Copyright (C) Yevhenii Mamontov 2022 */

#include "gui_main_window_status_bar.hpp"

#include <QLabel>

namespace teora::gui
{

namespace
{
    constexpr const char CursorPositionLabelTextTemplate[] = "Line: %1, Column: %2";
    constexpr const char WordsCountLabelTextTemplate[] = "Words: %1";
}

MainWindowStatusBar::MainWindowStatusBar(QWidget * _parent)
    :   QToolBar(_parent)
    ,   m_cursorPositionLabel(new QLabel(this))
    ,   m_wordsCountLabel(new QLabel(this))
{
    prepareToolBar();
}

void
MainWindowStatusBar::prepareToolBar()
{
    setMovable(false);
    setLayoutDirection(Qt::RightToLeft);

    addWidget(m_wordsCountLabel);
    addSeparator();
    addWidget(m_cursorPositionLabel);
}

void
MainWindowStatusBar::slotOnCursorPositionChanged(
        int _lineNumber /*= 0*/
    ,   int _columnNumber /*= 0*/
)
{
    if(_lineNumber == 0 || _columnNumber == 0)
    {
        return;
    }

    m_cursorPositionLabel->setText(
        QString(CursorPositionLabelTextTemplate)
            .arg(_lineNumber)
            .arg(_columnNumber)
    );
}

void
MainWindowStatusBar::slotOnWordsCountChanged(int _wordsCount /*= 0*/)
{
    if(_wordsCount == 0)
    {
        return;
    }

    m_wordsCountLabel->setText(QString(WordsCountLabelTextTemplate).arg(_wordsCount));
}

} // namespace teora::gui