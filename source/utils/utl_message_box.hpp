/* Copyright (C) Yevhenii Mamontov 2022 */

#pragma once

#include <QMessageBox>

namespace teora {
namespace gui {
namespace utils {

static void showErrorMessageBox(QString const & _message)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("ERROR");
    msgBox.setText(_message);
    msgBox.setIcon(QMessageBox::Icon::Critical);

    msgBox.setStandardButtons(QMessageBox::StandardButton::Ok);

    msgBox.show();
}


} // namespace utils
} // namespace gui
} // namespace teora
