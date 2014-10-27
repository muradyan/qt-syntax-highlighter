#pragma once

#include <QSyntaxHighlighter>

#include <QHash>
#include <QTextCharFormat>

class QTextDocument;

/**
 * @brief Extension of the QSyntaxHighlighter to add highlighting rules
 */
class Highlighter : public QSyntaxHighlighter
{
Q_OBJECT

public:
    Highlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text);

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QTextCharFormat commentFormat;
    QTextCharFormat keywordFormat;
    QTextCharFormat breakingFormat;
    QTextCharFormat numberFormat;
};
