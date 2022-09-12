/* Copyright (C) Yevhenii Mamontov 2022 */

#pragma once

class QString;

namespace teora {
namespace core {

class DiskFileReader
{

public:

    bool readFile(QString const & _pathToFile, QString & _data) const;

};

} // namespace core
} // namespace teora