/************************************************************************
**
**  Copyright (C) 2015-2020 Kevin B. Hendricks, Stratford, Ontario Canada
**  Copyright (C) 2009-2011 Strahinja Markovic  <strahinja.markovic@gmail.com>
**
**  This file is part of Sigil.
**
**  Sigil is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  Sigil is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Sigil.  If not, see <http://www.gnu.org/licenses/>.
**
*************************************************************************/

#pragma once
#ifndef IMPORTTXT_H
#define IMPORTTXT_H

#include <QtCore/QSharedPointer>
#include <QtCore/QUrl>

#include "Importers/Importer.h"

class ImportTXT : public Importer
{

public:

    // Constructor;
    // The parameter is the file to be imported
    ImportTXT(const QString &fullfilepath);

    // Reads and parses the file
    // and returns the created Book
    virtual QSharedPointer<Book> GetBook(bool extract_metadata=true);

private:

    QString LoadSource() const;

    HTMLResource *CreateHTMLResource(const QString &source);

    void InitializeHTMLResource(const QString &source, HTMLResource *resource);

    // Accepts a list of text lines and returns
    // a string with paragraphs wrapped into <p> tags
    QString CreateParagraphs(const QStringList &lines) const;

    QString m_EpubVersion;
};

#endif // IMPORTTXT_H
