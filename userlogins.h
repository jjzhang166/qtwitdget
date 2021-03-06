/* Copyright (c) 2011, Antonie Jovanoski
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

#ifndef USERLOGINS_H
#define USERLOGINS_H

#include <QString>

/**
 *  Stores login data for one user
 */
struct UserLoginData
{
    UserLoginData() : id(0) { }
    QString oauthToken;
    QString oauthTokenSecret;
    qint64 id;
    QString screenName;

    bool operator ==(const UserLoginData& other) const { return id == other.id; }
};

/**
 *  Class for maintaning user logins
 */
class UserLogins
{
public:
    UserLogins();
    QList<UserLoginData> getUserLogins() const;
    void writeUserLogin(const UserLoginData& userlogin);
    UserLoginData lastLoggedUser() const;
    void clearUserLogin(qint64 userid);
};

#endif // USERLOGINS_H
