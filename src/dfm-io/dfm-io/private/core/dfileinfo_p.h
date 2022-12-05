/*
 * Copyright (C) 2020 ~ 2021 Uniontech Software Technology Co., Ltd.
 *
 * Author:     zhangsheng<zhangsheng@uniontech.com>
 *
 * Maintainer: max-lv<lvwujun@uniontech.com>
 *             lanxuesong<lanxuesong@uniontech.com>
 *             xushitong<xushitong@uniontech.com>
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
#ifndef DFILEINFO_P_H
#define DFILEINFO_P_H

#include "core/dfileinfo.h"
#include "dfmio_global.h"
#include "utils/dmediainfo.h"

#include <QUrl>
#include <QVariant>
#include <QSharedData>

#include <unordered_map>
#include <string>

BEGIN_IO_NAMESPACE

class DFileInfoPrivate : public QSharedData
{
public:
    inline DFileInfoPrivate(DFileInfo *q)
        : QSharedData(),
          q(q)
    {
    }

    inline DFileInfoPrivate(const DFileInfoPrivate &copy)
        : QSharedData(copy)
    {
    }

    inline ~DFileInfoPrivate()
    {
    }

    void attributeExtend(DFileInfo::MediaType type, QList<DFileInfo::AttributeExtendID> ids, DFileInfo::AttributeExtendFuncCallback callback = nullptr);
    DFM_VIRTUAL [[nodiscard]] DFileFuture *attributeExtend(DFileInfo::MediaType type, QList<DFileInfo::AttributeExtendID> ids, int ioPriority, QObject *parent = nullptr);
    bool cancelAttributeExtend();
    void attributeExtendCallback();

public:
    DFileInfo *q = nullptr;

    QUrl uri = QUrl();
    char *attributes = strdup("*");
    DFileInfo::FileQueryInfoFlags flag = DFileInfo::FileQueryInfoFlags::kTypeNone;

    QSharedPointer<DFMIO::DMediaInfo> mediaInfo = nullptr;
    QList<DFileInfo::AttributeExtendID> extendIDs;
    DFileFuture *future = nullptr;
    DFileInfo::MediaType mediaType = DFileInfo::MediaType::kGeneral;
    DFileInfo::AttributeExtendFuncCallback attributeExtendFuncCallback = nullptr;

    DFileInfo::InitQuerierFunc initQuerierFunc = nullptr;
    DFileInfo::InitQuerierAsyncFunc initQuerierAsyncFunc = nullptr;
    DFileInfo::AttributeFunc attributeFunc = nullptr;
    DFileInfo::AttributeAsyncFunc attributeAsyncFunc = nullptr;
    DFileInfo::SetAttributeFunc setAttributeFunc = nullptr;
    DFileInfo::HasAttributeFunc hasAttributeFunc = nullptr;
    DFileInfo::ExistsFunc existsFunc = nullptr;
    DFileInfo::RefreshFunc refreshFunc = nullptr;
    DFileInfo::SetCustomAttributeFunc setCustomAttributeFunc = nullptr;
    DFileInfo::CustomAttributeFunc customAttributeFunc = nullptr;
    DFile::PermissionFunc permissionFunc = nullptr;
    DFileInfo::LastErrorFunc lastErrorFunc = nullptr;

    // future
    DFileInfo::InitQuerierAsyncFunc2 initQuerierAsyncFunc2 = nullptr;
    DFileInfo::AttributeAsyncFunc2 attributeAsyncFunc2 = nullptr;
    DFileInfo::AttributeAsyncFunc3 attributeAsyncFunc3 = nullptr;
    DFileInfo::ExistsAsyncFunc existsAsyncFunc = nullptr;
    DFileInfo::RefreshAsyncFunc refreshAsyncFunc = nullptr;
    DFileInfo::PermissionsAsyncFunc permissionsAsyncFunc = nullptr;
};

END_IO_NAMESPACE

#endif   // DFILEINFO_P_H
