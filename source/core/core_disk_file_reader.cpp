/* Copyright (C) Yevhenii Mamontov 2022 */

#include "core_disk_file_reader.hpp"

#include <QFile>

namespace teora::core
{

bool
DiskFileReader::readFile(QString const & _pathToFile, QString & _data) const
{
    QFile file(_pathToFile);

    if(!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    _data = file.readAll();

    return true;
}

} // namespace teora::core