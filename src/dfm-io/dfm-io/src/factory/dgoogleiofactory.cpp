/*
 * Copyright (C) 2020 ~ 2021 Uniontech Software Technology Co., Ltd.
 *
 * Author:     dengkeyun<dengkeyun@uniontech.com>
 *
 * Maintainer: max-lv<lvwujun@uniontech.com>
 *             xushitong<xushitong@uniontech.com>
 *             zhangsheng<zhangsheng@uniontech.com>
 *             lanxuesong<lanxuesong@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "factory/dgoogleiofactory.h"
#include "factory/dgoogleiofactory_p.h"
#include "local/dlocalhelper.h"

#include "local/dlocalenumerator.h"
#include "local/dlocalwatcher.h"
#include "local/dlocaloperator.h"
#include "local/dlocalfile.h"

#include <QDebug>

USING_IO_NAMESPACE

DGoogleIOFactoryPrivate::DGoogleIOFactoryPrivate(DGoogleIOFactory *q) : DIOFactoryPrivate(q)
{
}

DGoogleIOFactoryPrivate::~DGoogleIOFactoryPrivate()
{
}

QSharedPointer<DFileInfo> DGoogleIOFactoryPrivate::doCreateFileInfo() const
{
    const QString &url = uri.url();

    return DLocalHelper::getFileInfo(url);
}

QSharedPointer<DFile> DGoogleIOFactoryPrivate::doCreateFile() const
{
    return QSharedPointer<DLocalFile>(new DLocalFile(uri));
}

QSharedPointer<DEnumerator> DGoogleIOFactoryPrivate::doCreateEnumerator() const
{
    return QSharedPointer<DLocalEnumerator>(new DLocalEnumerator(uri));
}

QSharedPointer<DWatcher> DGoogleIOFactoryPrivate::doCreateWatcher() const
{
    return QSharedPointer<DLocalWatcher>(new DLocalWatcher(uri));
}

QSharedPointer<DOperator> DGoogleIOFactoryPrivate::doCreateOperator() const
{
    return QSharedPointer<DLocalOperator>(new DLocalOperator(uri));
}

DGoogleIOFactory::DGoogleIOFactory(const QUrl &uri)
    : DIOFactory()
{
    d_ptr.reset(new DGoogleIOFactoryPrivate(this));
    d_ptr->uri = uri;
}

DGoogleIOFactory::~DGoogleIOFactory()
{
}