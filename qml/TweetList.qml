import Qt 4.7

Item {
    id: tweetListViewItem
    height: tweetListView.count * 100
    width: /* 500 */  viewWidth

	ListView {
        id: tweetListView
        model: tweetListModel
        width: parent.width
        height: parent.height
		delegate: Tweet {
            tweetScreenName: screenNameRole
            tweetText: statusTextRole
		}
	}
}
