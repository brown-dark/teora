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

    _object->addAction(_action);
    _object->connect(_action, &QAction::triggered, _object, _slot);
}

} // namespace teora::gui::utils