
#include "qhighlighter.h"

#include <QGuiApplication>
#include <QQuickView>

#include <QtQml/QQmlContext>
#include <QtQml>

int main(int argc, char *argv[])
{
    qmlRegisterType<QHighlighter>("Highliting", 1, 0, "QHighlighter");

    QGuiApplication a(argc, argv);

    QQuickView view;
    view.resize(800, 600);
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:///resources/main.qml"));
    view.show();

    return a.exec();
}
