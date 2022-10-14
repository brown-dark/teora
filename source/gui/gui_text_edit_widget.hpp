/* Copyright (C) Yevhenii Mamontov 2022 */

#pragma once

#include <QPlainTextEdit>

namespace teora::core
{
    class DiskFileReader;
}
class QFile;

namespace teora::gui
{

class TextEditWidget final
    :   public QPlainTextEdit
{
    Q_OBJECT

public:

    TextEditWidget(QWidget * _parent);

    bool loadData();
    bool saveData();

private:

    void doSignalSlotConnections();

signals:

    void signalCursorPositionChanged(int _lineNumber, int _columnNumber);
    void signalWordsCountChanged(int _wordsCount);

private slots:

    void slotOnCursorPositionChanged();
    void slotOnTextChanged();

private:

    QFile * m_file;

};

} // namespace teora::gui