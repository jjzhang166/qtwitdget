/* Copyright (c) 2009, Antonie Jovanoski
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

#include <QResizeEvent>
#include <QPropertyAnimation>
#include "qtwitview.h"

/*!
    Constructor
 */
QTwitView::QTwitView(QWidget *parent) 
    : QGraphicsView(parent),
      m_scrbarAnimation(new QPropertyAnimation(this, "valueVertScrollBar", this))
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

	QScrollBar *scrollBar = verticalScrollBar();
	connect(scrollBar, SIGNAL(valueChanged(int)), this, SLOT(scrollBarPos(int)));

    //do translation with translating one root item
    //setTransformationAnchor(QGraphicsView::NoAnchor);

    m_scrbarAnimation->setDuration(500);
    m_scrbarAnimation->setEasingCurve(QEasingCurve::InOutExpo);
}

void QTwitView::scrollBarPos(int pos)
{
	if(pos == verticalScrollBar()->maximum() && verticalScrollBar()->isEnabled())
		emit scrollBarMaxPos(true);
	else
		emit scrollBarMaxPos(false);
}

/*!
    \reimp
 */
void QTwitView::resizeEvent(QResizeEvent *e)
{
	QSize s = e->size();

    emit resizeWidth(s.width());
    
	QWidget::resizeEvent(e);
}

/*!
    Sets vertical scrollbar position
    \param value Vertical scrollbar position
 */
void QTwitView::setValueVertScrollbar(int value)
{
    verticalScrollBar()->setValue(value);
}

/*!
    Gets vertical scrollbar position
 */
int QTwitView::valueVertScrollbar() const
{
    return verticalScrollBar()->value();
}

/* since horizontal scrollbar is disabled, and statuses are resizable to get whole x sizing
 * we need just y position to focus to y position of status
 *
 * y should be y position of status to be centered (top left corner)
 * uses scrollbar for moving
 */

/*!
    Starts animated move of view (by moving vertical scrollbar) to center on given y position
    \param y Where to move
    \remarks x position is fixed (0)
 */
void QTwitView::moveToPointAnim(qreal y)
{
    //WHY 17? scrollbar width/height?
    qreal maxYMovement = sceneRect().height() - viewport()->height() + 17;

    if (maxYMovement > 0) {
        int vBarNextPosition = 0;
        int vBarMin = verticalScrollBar()->minimum();
        int vBarMax = verticalScrollBar()->maximum();

        if (y > maxYMovement) {
            vBarNextPosition = vBarMax;
        } else {
            vBarNextPosition = vBarMin + (vBarMax - vBarMin) * y / maxYMovement;
        }

        m_scrbarAnimation->setEndValue(vBarNextPosition);
        m_scrbarAnimation->start();
    }
}
