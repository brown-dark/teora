/* Copyright (C) Yevhenii Mamontov 2022 */

#include "gui_text_edit_widget.hpp"

#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QRegularExpression>

namespace teora::gui
{

TextEditWidget::TextEditWidget(QWidget * _parent)
    :   QPlainTextEdit(_parent)
    ,   m_file(nullptr)
{
    doSignalSlotConnections();
}

bool
TextEditWidget::loadData()
{
    QString pathToFile =
        QFileDialog::getOpenFileName(
                this
            ,   "Open File"
            ,   QDir::currentPath()
            ,   "*.txt"
        );

    if(pathToFile.isEmpty())
    {
        return false;
    }

    m_file = new QFile(pathToFile, this);

    if(!m_file->open(QIODevice::ReadOnly))
    {
        return false;
    }

    setPlainText(m_file->readAll());

    m_file->close();

    return true;
}

bool
TextEditWidget::saveData()
{
    if(m_file == nullptr)
    {
        QString pathToFile =
            QFileDialog::getSaveFileName(
                    this
                ,   "Save File"
                ,   QDir::currentPath()
            );

        m_file = new QFile(pathToFile, this);
    }

    if(!m_file->open(QIODevice::WriteOnly))
    {
        return false;
    }

    bool result = m_file->write(toPlainText().toUtf8());

    m_file->close();

    return result;
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

} // namespace teora::gui