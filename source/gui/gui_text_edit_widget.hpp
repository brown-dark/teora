/* Copyright (C) Yevhenii Mamontov 2022 */

#pragma once

#include <QPlainTextEdit>

namespace teora::core
{
    class DiskFileReader;
}

namespace teora {
namespace gui {

class TextEditWidget final
    :   public QPlainTextEdit
{
    Q_OBJECT

public:

    TextEditWidget(QWidget * _parent);

private:

    void doSignalSlotConnections();

signals:

    void signalCursorPositionChanged(int _lineNumber, int _columnNumber);
    void signalWordsCountChanged(int _wordsCount);

private slots:

    void slotOnCursorPositionChanged();
    void slotOnTextChanged();

};

} // namespace gui
} // namespace teora::gui