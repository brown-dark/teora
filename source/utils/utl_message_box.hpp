/* Copyright (C) Yevhenii Mamontov 2022 */

#pragma once

#include <QMessageBox>

namespace teora::gui::utils
{

static void showErrorMessageBox(QWidget * _parent, QString const & _message)
{
    QMessageBox * msgBox = new QMessageBox(_parent);
    msgBox->setWindowTitle("ERROR");
    msgBox->setText(_message);
    msgBox->setIcon(QMessageBox::Icon::Critical);

    msgBox->setStandardButtons(QMessageBox::StandardButton::Ok);

    msgBox->exec();
    msgBox->deleteLater();
}

} // namespace teora::gui::utils