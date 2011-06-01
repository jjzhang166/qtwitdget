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

import QtQuick 1.0

Rectangle  {
    id: container

    property string tweetid
    property string tweetScreenName
    property string tweetText
    property string tweetAvatar
    property string tweetSinceTime
    property bool isOwnTweet: false
    property bool isNewTweet: false

    signal avatarClicked
    signal tweetClicked

    //signal replyClicked
    //signal retweetClicked
    //signal favoriteClicked
    //signal conversationClicked
    //signal mentionLinkClicked(string screenname)
    //signal hashtagLinkClicked(string hashtag)

//    function handleLink(link) {
//        if (link.slice(0, 3) == 'tag') {
//            hashtagLinkClicked(link.slice(6))
//        } else if (link.slice(0, 4) == 'http') {
//            Qt.openUrlExternally(link);
//        } else if (link.slice(0, 7) == 'mention') {
//            mentionLinkClicked(link.slice(10));
//        }
//    }

    width: ListView.view.width;
    //width: 360;
    height: (statusText.paintedHeight < 87) ? 97 : (statusText.paintedHeight + 3)
    color: {
        if (isNewTweet)
            return (index % 2) ? '#ffd954' : '#ffb300'
        else
            return (index % 2) ? '#ffffff' : '#d9d9d9'
    }

    Behavior on color { ColorAnimation { duration: 300 } }

    Rectangle {
        id: avatarBackground
        width: 52
        height: 52
        color:  '#2bace2'
        anchors.top: parent.top
        anchors.topMargin: 4
        anchors.left: parent.left
        anchors.leftMargin: 4

        Image {
            id: avatarImage
            width: 48
            height: 48
            sourceSize.width: 48
            sourceSize.height: 48
            anchors.centerIn: parent
            fillMode: Image.Stretch
            source: tweetAvatar
        }

//        MouseArea {
//            id: avatarMouseArea
//            anchors.fill: parent

//            //onClicked: mentionLinkClicked(tweetScreenName)
//            onClicked: avatarClicked()
//        }
    }

//    MouseArea {
//        id: moreArea
//        anchors.bottomMargin: 0
//        anchors.leftMargin: -20
//        anchors.top: parent.top
//        anchors.bottom: buttonLoader.top
//        anchors.left: rightArrow.left
//        anchors.right: parent.right

//        onClicked: {
//            if (container.state == 'showButtons')
//                container.state = ''
//            else
//                container.state = 'showButtons'
//        }
//    }

    Text {
        id: statusText
        color: "#333333"
        text: '<b>' + tweetScreenName + ':<\/b><br \/> ' + tweetText
        anchors.topMargin: 0
        anchors.top: parent.top;
        anchors.right: parent.right
        anchors.left: avatarBackground.right; anchors.leftMargin: 4
        textFormat: Text.RichText
        wrapMode: "WordWrap"
        font.family: "Segoe UI"
        font.pointSize: 6
    }

    Text {
        id: sinceText
        text: tweetSinceTime
        anchors.top: avatarBackground.bottom
        anchors.leftMargin: 10
        anchors.topMargin: 4
        anchors.left: parent.left
        font.family: "Segoe UI"
        font.pointSize: 5
    }

    MouseArea {
        id: tweetMouseArea
        anchors.left: avatarMouseArea.right
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        anchors.leftMargin: 0

        onClicked: tweetClicked()
    }

    MouseArea {
        id: avatarMouseArea
        width: 100
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: avatarBackground.right

        onClicked: avatarClicked()
    }

//    Loader {
//        id: buttonLoader
//        anchors.left: parent.left
//        anchors.right: parent.right
//        anchors.bottom: parent.bottom
//    }

//    Connections { target: buttonLoader.item; onReplyButtonClicked: replyClicked() }
//    Connections { target: buttonLoader.item; onRetweetButtonClicked: retweetClicked() }
//    Connections { target: buttonLoader.item; onFavoriteButtonClicked: favoriteClicked() }
//    Connections { target: buttonLoader.item; onConversationButtonClicked: conversationClicked() }

//    Component {
//        id: buttonRow

//        Item {
//            id: buttonContainer

//            signal replyButtonClicked()
//            signal retweetButtonClicked()
//            signal favoriteButtonClicked()
//            signal conversationButtonClicked()

//            ButtonImage {
//                id: replyButton
//                width: 76; height: 40
//                sourceSizeWidth: 76; sourceSizeHeight: 40
//                anchors.bottom: parent.bottom
//                anchors.bottomMargin: 4
//                anchors.right: retweetButton.left
//                anchors.rightMargin: 5
//                pressedButtonImageUrl: "images/reply_button_pressed.png"
//                buttonImageUrl: "images/reply_button.png"

//                onClicked: replyButtonClicked()
//            }

//            ButtonImage {
//                id: retweetButton
//                width: 76; height: 40
//                sourceSizeWidth: 76; sourceSizeHeight: 40
//                anchors.bottom: parent.bottom
//                anchors.bottomMargin: 4
//                anchors.right: parent.horizontalCenter
//                anchors.rightMargin: 2
//                pressedButtonImageUrl: "images/retweet_button_pressed.png"
//                buttonImageUrl: "images/retweet_button.png"

//                onClicked: retweetButtonClicked()
//            }

//            ButtonImage {
//                id: favouriteButton
//                width: 76; height: 40
//                sourceSizeWidth: 76; sourceSizeHeight: 40
//                anchors.bottom: parent.bottom
//                anchors.bottomMargin: 4
//                anchors.left: retweetButton.right
//                anchors.leftMargin: 5
//                pressedButtonImageUrl: "images/favourite_button_pressed.png"
//                buttonImageUrl: "images/favourite_button.png"

//                onClicked: favoriteButtonClicked()
//            }

//            ButtonImage {
//                id: conversationButton
//                width: 76; height: 40
//                sourceSizeWidth: 76; sourceSizeHeight: 40
//                anchors.bottom: parent.bottom
//                anchors.bottomMargin: 4
//                anchors.left: favouriteButton.right
//                anchors.leftMargin: 5
//                pressedButtonImageUrl: "images/conversation_button_pressed.png"
//                buttonImageUrl: "images/conversation_button.png"

//                onClicked: conversationButtonClicked()
//            }
//        }
//    }

//    states: State {
//        name: 'showButtons'
//        PropertyChanges { target: buttonLoader; sourceComponent: buttonRow }
//        PropertyChanges { target: container; height: container.height + 40; explicit: true }
//        PropertyChanges { target: rightArrow; rotation: 90 }
//    }

//    transitions: Transition {
//            NumberAnimation { target: container; property: "height"; duration: 200 }
//            NumberAnimation { target: rightArrow; property: "rotation"; duration: 200 }
//    }

    ListView.onAdd: SequentialAnimation {
        ParallelAnimation {
            PropertyAction { target: container; property: "height"; value:  0 }
            PropertyAction { target: container; property: "x"; value: container.width }
            PropertyAction { target: container; property: "opacity"; value: 0 }
        }
        NumberAnimation { target: container; property: "height"; easing.type: Easing.OutExpo; from: 0; to: (statusText.paintedHeight < 87) ? 95 : (statusText.paintedHeight + 4); duration: 300 }
        PropertyAction { target: container; property: "opacity"; value: 1 }
        PauseAnimation { duration: index * 20 }
        NumberAnimation { target: container; property: "x"; easing.type: Easing.InOutBack; to: 0; duration: 500 }
    }

    ListView.onRemove: SequentialAnimation {
        PropertyAction { target: container; property: "ListView.delayRemove"; value: true }
        NumberAnimation { target: container; property: "opacity"; to: 0; duration: 300 }
        NumberAnimation { target: container; property: "height"; to: 0; duration: 300 }
        PropertyAction { target: container; property: "ListView.delayRemove"; value: false }
    }
}
