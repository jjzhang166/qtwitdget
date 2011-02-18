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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSqlDatabase>
#include <QSystemTrayIcon>
#include "qmlapplicationviewer.h"

class QNetworkAccessManager;
class NetworkAccessManagerFactory;
class OAuthTwitter;
class QTweetUserStream;
class QTweetUser;
class QTweetDMStatus;
class QTweetStatus;
class TweetQmlListModel;
class MentionsQmlListModel;
class DirectMessagesQmlListModel;
class QMenu;

class MainWindow : public QmlApplicationViewer
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void startUp();

    Q_INVOKABLE void authorize(const QString& username, const QString& password);
    Q_INVOKABLE void updateButtonClicked(const QString& id, const QString& text, const QString& screenName);

private slots:
    void authorizationFinished();
    void authorizationFailed();
    void verifyCredentialsFinished(const QTweetUser& userinfo);
    void directMessageNewFinished(const QTweetDMStatus& dm);
    void statusUpdateFinished(const QTweetStatus& status);
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void changeUserPass();

protected:
    void closeEvent(QCloseEvent *e);
    //void changeEvent(QEvent *e);

private:
    void setupTrayIcon();
    void createDatabase(const QString& databaseName);
    void updateCurrentPage();
    void createDeclarativeView();
    void readSettings();
    void writeSettings();

    QNetworkAccessManager *m_netManager;
    NetworkAccessManagerFactory *m_namFactory;
    OAuthTwitter *m_oauthTwitter;
    QTweetUserStream *m_userStream;

    TweetQmlListModel* m_tweetListModel;
    MentionsQmlListModel* m_mentionsListModel;
    DirectMessagesQmlListModel *m_directMessagesListModel;

    qint64 m_userId;

    QSqlDatabase m_database;

    QSystemTrayIcon *m_trayIcon;
    QMenu *m_trayIconMenu;
};

#endif // MAINWINDOW_H
