/*
 * Copyright (C) 2013  Vishesh Handa <me@vhanda.in>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) version 3, or any
 * later version accepted by the membership of KDE e.V. (or its
 * successor approved by the membership of KDE e.V.), which shall
 * act as a proxy defined in Section 6 of version 3 of the license.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "extractionresult.h"

#include <QMimeDatabase>

using namespace KFileMetaData;

class ExtractionResult::Private {
public:
    QString url;
    QString mimetype;
    ExtractionResult::Flags flags;
};

ExtractionResult::ExtractionResult(const QString& url, const QString& mimetype, const Flags& flags)
    : d(new Private)
{
    d->url = url;
    d->mimetype = mimetype;
    if (mimetype.isEmpty()) {
        d->mimetype = QMimeDatabase().mimeTypeForFile(url).name();
    }
    d->flags = flags;
}

ExtractionResult::ExtractionResult(const ExtractionResult& rhs)
    : d(new Private(*rhs.d))
{
}

ExtractionResult::~ExtractionResult()
{
    delete d;
}

QString ExtractionResult::inputUrl() const
{
    return d->url;
}

QString ExtractionResult::inputMimetype() const
{
    return d->mimetype;
}

ExtractionResult::Flags ExtractionResult::inputFlags() const
{
    return d->flags;
}

