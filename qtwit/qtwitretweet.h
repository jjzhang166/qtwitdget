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

#ifndef QTWITRETWEET_H
#define QTWITRETWEET_H

#include "qtwitbase.h"
#include "qtwitstatus.h"

class QTwitRetweet : public QTwitBase
{
    Q_OBJECT
public:
    /*! Constructor */
    QTwitRetweet(QObject *parent = 0);
    /*! Retweets status with id statusid */
    void retweet(qint64 statusid);
    /*! Gets last retweeted status
     * \remark If retweeting was with error status id is zero 
     */
    QTwitStatus getRetweetedStatus() const;
    
private slots:
    void reply();
    void error();

private:
    QTwitStatus m_retweetStatus;
};

#endif //QTWITRETWEET_H