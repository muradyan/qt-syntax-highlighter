#pragma once 

#include <QObject>

class Highlighter;
class QQuickItem;
class QTextDocument;

class QHighlighter : public QObject
{
    Q_OBJECT
public:
    QHighlighter();

    Q_PROPERTY(QQuickItem *target READ target WRITE setTarget NOTIFY targetChanged)

public:
    QQuickItem *target() { return m_target; }
    void setTarget(QQuickItem *target);

Q_SIGNALS:
    void targetChanged();

private:
    QQuickItem *m_target;
    Highlighter *m_highlighter;
};
