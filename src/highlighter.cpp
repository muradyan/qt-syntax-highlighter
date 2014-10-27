#include <QtGui>

#include "highlighter.h"

static const QVector<QString> keywords = {
    "for", "seq", "raw", "if", "when", "unless",
    "mload", "sload", "mstore", "sstore",
    "def", "gav", "config", "allgas", "sendgavcoin", "regname", "regcoins",
    "send", "msg", "create", "sha3", "sha3pair", "sha3trip", "return", "returnlll", "asm"
};

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    foreach (const QString& k, keywords) {
        rule.pattern = QRegExp("\\b" + k + "\\b");
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    breakingFormat.setFontWeight(QFont::Bold);
    breakingFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegExp("\\bsuicide\\b");
    rule.format = breakingFormat;
    highlightingRules.append(rule);
    rule.pattern = QRegExp("\\bstop\\b");
    rule.format = breakingFormat;
    highlightingRules.append(rule);

    commentFormat.setForeground(Qt::red);
    rule.pattern = QRegExp(";[^\n]*");
    rule.format = commentFormat;
    highlightingRules.append(rule);

    /// @todo add support for sientific notationed numbers
    numberFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("\\b[0-9]+\\b");
    rule.format = numberFormat;
    highlightingRules.append(rule);
    rule.pattern = QRegExp("\\b0x[0-9a-fA-F]+\\b");
    rule.format = numberFormat;
    highlightingRules.append(rule);
}

void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
}
