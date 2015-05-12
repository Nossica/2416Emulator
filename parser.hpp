#ifndef PARSER_HPP
#define PARSER_HPP

#include <QList>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

class Parser
{
    QString fileName_;
    QFile* file_;
    QTextStream *in_;

    bool validateLine(QString& line, int& instruction, int& parameter);
    bool validateBinary(QString& line, int& instruction, int& parameter);
    bool validateHex(QString& line, int& instruction, int& parameter);
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

    //
    void parse(QList<QString>& input);
    bool parse(int& instruction, int& parameter);

};

#endif // PARSER_HPP
