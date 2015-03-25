#ifndef PARSER_HPP
#define PARSER_HPP

#include <QList>
#include <QString>

class Parser
{
    QString fileName_;


    bool validateLine(QString& line);
    bool validateBinary(QString& line);
    bool validateHex(QString& line);
public:
    Parser(const QString& fileName)
        : fileName_(fileName)
        {};

    //
    void parse(QList<QString>& input);

};

#endif // PARSER_HPP
