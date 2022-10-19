/* Copyright (C) Yevhenii Mamontov 2022 */

#pragma once

#include <QAction>

namespace teora::gui::utils
{

template<typename T, typename TSlot>
static void initializeAction(
        QAction * _action
    ,   T * _object
    ,   TSlot _slot
    ,   QString _text
    ,   QString _explanation
    ,   QString _shortcut
    ,   QString _pathToIcon
)
{
    assert(_action != nullptr);
    assert(_object != nullptr);

    _action->setText(_text);

    if(!_explanation.isEmpty())
    {
        _action->setToolTip(_explanation);
        _action->setWhatsThis(_explanation);
    }
    if(!_shortcut.isEmpty())
    {
        _action->setShortcut(_shortcut);
    }
    if(!_pathToIcon.isEmpty())
    {
        _action->setIcon(QIcon(_pathToIcon));
    }

    _object->addAction(_action);
    _object->connect(_action, &QAction::triggered, _object, _slot);
}

} // namespace teora::gui::utils