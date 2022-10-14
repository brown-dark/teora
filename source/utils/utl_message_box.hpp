/* Copyright (C) Yevhenii Mamontov 2022 */

#pragma once

#include <QMessageBox>

namespace teora::gui::utils
{

static void showErrorMessageBox(QString const & _message)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("ERROR");
    msgBox.setText(_message);
    msgBox.setIcon(QMessageBox::Icon::Critical);

    msgBox.setStandardButtons(QMessageBox::StandardButton::Ok);

    msgBox.show();
}

} // namespace teora::gui::utils