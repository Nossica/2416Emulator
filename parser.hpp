#ifndef PARSER_HPP
#define PARSER_HPP

#include <QList>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

enum PARSE_STATE {
    PARSE_STATE_BEGIN,
    FILE_END,
    VALID_FIELD,
    INVALID_FIELD,
    PARSE_STATE_END
};

class Parser
{
    QString fileName_;
    QFile* file_;
    QTextStream *in_;

    PARSE_STATE validateLine(QString& line, int& instruction, int& parameter);
    PARSE_STATE validateBinary(QString& line, int& instruction, int& parameter);
    PARSE_STATE validateHex(QString& line, int& instruction, int& parameter);
public:
    Parser(const QString& fileName)
        : fileName_(fileName)
    {
        file_ = new QFile(fileName_);

        if(!file_->open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", file_->errorString());
        };

        in_ = new QTextStream(file_);
    }

    ~Parser() {
        file_->close();
        delete file_;
        delete in_;
    }

    PARSE_STATE parse(int& instruction, int& parameter);
};

#endif // PARSER_HPP
