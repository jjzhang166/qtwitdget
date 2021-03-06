import QtQuick 1.0

Item {
    property alias model: dmListView.model

    signal replyClicked(string screenname)

    ListView {
        id: dmListView
        anchors.fill: parent
        clip: true
        delegate: TweetDelegate {
            tweetScreenName: screenNameRole
            tweetText: statusTextRole
            tweetAvatar: avatarUrlRole
            tweetid:  statusIdRole
            isOwnTweet: ownTweetRole
            isNewTweet: newTweetRole
            tweetSinceTime: sinceTimeRole

            onReplyButtonClicked: replyClicked(tweetScreenName)
        }
    }

    Rectangle {
        id: scrollbar
        anchors.right: dwListView.right
        y: dmListView.visibleArea.yPosition * dmListView.height
        width: 2
        height: dmListView.visibleArea.heightRatio * dmListView.height
        color: "black"
    }
}
