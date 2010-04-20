/* Copyright (c) 2010, Antonie Jovanoski
 *
 * All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Contact e-mail: Antonie Jovanoski <minimoog77_at_gmail.com>
 */

#ifndef XMLREADUSERLIST_H
#define XMLREADUSERLIST_H

#include <QXmlStreamReader>
#include "xmlreaduser.h"

class XmlReadUserList
{
public:
    XmlReadUserList();
    bool read(QIODevice *device);
    QString errorString() const;
    QList<QTwitUser> users() const;
    QString nextCursor() const;
    QString prevCursor() const;

private:
    void readUsersList();
    void readUsers();
    void readUser(QTwitUser& twitUser);

    QXmlStreamReader xml;
    QList<QTwitUser> m_users;
    QString m_nextCursor;
    QString m_prevCursor;
};

#endif // XMLREADUSERLIST_H