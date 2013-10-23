#include "qtweetstatusesdestroy.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include "qtweetstatus.h"
#include "qtweetconvert.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

QTweetStatusesDestroy::QTweetStatusesDestroy(QObject *parent) : QTweetNetBase(parent)
{
}

QTweetStatusesDestroy::QTweetStatusesDestroy(OAuthTwitter *oauthTwitter, QObject *parent) : QTweetNetBase(oauthTwitter, parent)
{
}

void QTweetStatusesDestroy::fetch(qint64 id, bool trim_user)
{
    if (!isAuthenticationEnabled()) {
        qCritical("Needs authentication to be enabled");
        return;
    }

    QString urlString = QString("https://api.twitter.com/1.1/statuses/destroy/%1.json").arg(id);
    QUrl url(urlString);
    QUrlQuery urlQuery;

    if (trim_user)
        urlQuery.addQueryItem("trim_user", "true");

    url.setQuery(urlQuery);

    QNetworkRequest req(url);

    QByteArray oauthHeader = oauthTwitter()->generateAuthorizationHeader(url, OAuth::POST);
    req.setRawHeader(AUTH_HEADER, oauthHeader);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QNetworkReply *reply = oauthTwitter()->networkAccessManager()->post(req, QByteArray());
    connect(reply, SIGNAL(finished()), this, SLOT(reply()));
}

void QTweetStatusesDestroy::parseJsonFinished(const QJsonDocument &jsonDoc)
{
    if (jsonDoc.isObject()) {
        QTweetStatus parsedStatus = QTweetConvert::jsonObjectToStatus(jsonDoc.object());

        emit status(parsedStatus);
    }
}
