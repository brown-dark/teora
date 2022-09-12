/* Copyright (C) Yevhenii Mamontov 2022 */

#include "gui_text_edit_widget.hpp"

#include <QRegularExpression>

namespace teora {
namespace gui {

TextEditWidget::TextEditWidget(QWidget * _parent)
    :   QPlainTextEdit(_parent)
{
    doSignalSlotConnections();
}

void
TextEditWidget::doSignalSlotConnections()
{
    connect(
            this
        ,   &QPlainTextEdit::cursorPositionChanged
        ,   this
        ,   &TextEditWidget::slotOnCursorPositionChanged
    );

    connect(
            this
        ,   &QPlainTextEdit::textChanged
        ,   this
        ,   &TextEditWidget::slotOnTextChanged
    );
}

void
TextEditWidget::slotOnCursorPositionChanged()
{
    const int lineNumber = textCursor().blockNumber() + 1;
    const int columnNumber = textCursor().positionInBlock() + 1;

    emit signalCursorPositionChanged(lineNumber, columnNumber);
}

void
TextEditWidget::slotOnTextChanged()
{
    int wordsCount = 0;

    QRegularExpression regex("\\w+");
    auto matchIterator = regex.globalMatch(toPlainText());

    while(matchIterator.hasNext())
    {
        wordsCount++;
        matchIterator.next();
    }

    emit signalWordsCountChanged(wordsCount);
}

} // namespace gui
} // namespace teora