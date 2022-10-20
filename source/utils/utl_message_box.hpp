/* Copyright (C) Yevhenii Mamontov 2022 */

#pragma once

#include <QMessageBox>

namespace teora::gui::utils
{

static void showErrorMessageBox(QWidget* _parent, QString _message)
{
    QMessageBox * msgBox = new QMessageBox(_parent);
    msgBox->setWindowTitle("Error");
    msgBox->setText(_message);
    msgBox->setIcon(QMessageBox::Icon::Critical);

    msgBox->setStandardButtons(QMessageBox::StandardButton::Ok);

    msgBox->show();
}

static void showInfoMessageBox(QWidget* _parent, QString _message)
{
    QMessageBox * msgBox = new QMessageBox(_parent);
    msgBox->setWindowTitle("Info");
    msgBox->setText(_message);
    msgBox->setIcon(QMessageBox::Icon::Information);

    msgBox->setStandardButtons(QMessageBox::StandardButton::Ok);

    msgBox->show();
}

} // namespace teora::gui::utils