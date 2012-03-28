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

#include <QtDebug>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "qtweetgeoplaceid.h"
#include "qtweetplace.h"
#include "qtweetconvert.h"
#include "json/qjsondocument.h"
#include "json/qjsonobject.h"

/**
 *  Constructor
 */
QTweetGeoPlaceID::QTweetGeoPlaceID(QObject *parent) :
    QTweetNetBase(parent)
{
}

/**
 *  Constructor
 *  @param oauthTwitter OAuthTwitter object
 *  @param parent parent QObject
 */
QTweetGeoPlaceID::QTweetGeoPlaceID(OAuthTwitter *oauthTwitter, QObject *parent) :
    QTweetNetBase(oauthTwitter, parent)
{
}

/**
 *  Starts fetching information about place
 *  @param placeid a place in the world. These ID's can be retrieved from QTweetGeoReverseGeoCode
 */
void QTweetGeoPlaceID::get(const QString &placeid)
{
    QUrl url(QString("http://api.twitter.com/1/geo/id/%1.json").arg(placeid));

    QNetworkRequest req(url);

    if (isAuthenticationEnabled()) {
        QByteArray oauthHeader = oauthTwitter()->generateAuthorizationHeader(url, OAuth::GET);
        req.setRawHeader(AUTH_HEADER, oauthHeader);
    }

    QNetworkReply *reply = oauthTwitter()->networkAccessManager()->get(req);
    connect(reply, SIGNAL(finished()), this, SLOT(reply()));
}

void QTweetGeoPlaceID::parseJsonFinished(const QJsonDocument &jsonDoc)
{
    if (jsonDoc.isObject()) {
        QTweetPlace place = QTweetConvert::jsonObjectToPlaceRecursive(jsonDoc.object());

        emit parsedPlace(place);
    }
}
