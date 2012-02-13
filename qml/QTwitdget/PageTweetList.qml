import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    id: container

    property alias model: tweetListView.model

    signal tweetClicked(string tweetid, string tweettext, string screenname)
    signal avatarClicked(string screenname)

    //since time is not updated

    tools: buttonTools

    ListView {
        id: tweetListView
        anchors.fill: parent
        clip: true
        cacheBuffer: 120 * 20
        delegate: TweetDelegate {
            tweetScreenName: screenNameRole
            tweetText: statusTextRole
            tweetAvatar: avatarUrlRole
            tweetid:  statusIdRole
            isOwnTweet: ownTweetRole
            isNewTweet: newTweetRole
            tweetSinceTime: sinceTimeRole

            onTweetClicked: container.tweetClicked(tweetid, tweetText, tweetScreenName)
            onAvatarClicked: container.avatarClicked(tweetScreenName)
        }
    }

    ToolBarLayout {
        id: buttonTools

        ToolIcon { iconId: "toolbar-back"; onClicked: { pageStack.pop(); } }
        ToolIcon {
            iconId: "toolbar-send-email"
            onClicked: {
                pageStack.push(Qt.resolvedUrl("PageTweetList.qml"), { model: mentionsListModel} )
            }
        }
        ToolIcon { iconId: "toolbar-view-menu"; onClicked: console.debug('crap') }
    }

//    Rectangle {
//        id: scrollbar
//        anchors.right: tweetListView.right
//        y: tweetListView.visibleArea.yPosition * tweetListView.height
//        width: 2
//        height: tweetListView.visibleArea.heightRatio * tweetListView.height
//        color: "black"
//    }
}