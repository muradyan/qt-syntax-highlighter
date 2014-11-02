
import QtQuick 2.3
import Highliting 1.0
import "core"

Rectangle  {
    id: screen

    width: 800; height: 600
    color: "white"

    TextArea {
        id: textArea
        backgroundColor: "#3F3F3F"
        fontColor: "#DCDCCC"
        height: parent.height
        width: parent.width
    }

    QHighlighter {
        id: highligher
        target: textArea.textEditor
    }
}
