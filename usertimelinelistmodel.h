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

#ifndef USERTIMELINELISTMODEL_H
#define USERTIMELINELISTMODEL_H

#include <QAbstractListModel>
#include "qtweetlib/qtweetstatus.h"

class OAuthTwitter;

/**
 *  List model for user timeline
 */
class UserTimelineListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    /** model roles */
    enum TweetRoles {
        StatusTextRole = Qt::UserRole + 1,
        SinceTimeRole,
        StatusIdRole
    };

    explicit UserTimelineListModel(QObject *parent = 0);
    UserTimelineListModel(OAuthTwitter *oauthTwitter, QObject *parent = 0);
    void setOAuthTwitter(OAuthTwitter *oauthTwitter);
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    Q_INVOKABLE void fetch(qint64 userid);
    Q_INVOKABLE void fetch(const QString& screenname);

private slots:
    void finishedFetching(const QList<QTweetStatus>& statuses);
    void errorFetching();

private:
    OAuthTwitter* m_oauthTwitter;
    QList<QTweetStatus> m_statuses;
};

#endif // USERTIMELINELISTMODEL_H
