
#include "qhighlighter.h"
#include "highlighter.h"

#include <QQuickTextDocument>

QHighlighter::QHighlighter()
    : m_target(0)
    , m_highlighter(0)
{
}

void QHighlighter::setTarget(QQuickItem *target)
{
    m_highlighter = 0;
    m_target = target;
    if (!m_target) {
        return;
    }

    QVariant doc = m_target->property("textDocument");
    if (doc.canConvert<QQuickTextDocument*>()) {
        QQuickTextDocument *qqdoc = doc.value<QQuickTextDocument*>();
        if (qqdoc) {
            m_highlighter = new Highlighter(qqdoc->textDocument());
        }
    }
    emit targetChanged();
}
