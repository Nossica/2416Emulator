#include "parser.hpp"

PARSE_STATE Parser::parse(int& instruction, int& parameter) {
    if (in_->atEnd())
        return FILE_END;

    QString inputLine = in_->readLine();
    return validateLine(inputLine, instruction, parameter);
}

PARSE_STATE Parser::validateLine(QString& line, int& instruction, int& parameter) {
    // remove white space
    line = line.simplified();
    line.replace( " ", "" );
    //remove text after a comment
    line = line.left(line.indexOf('#'));

    switch(line.length()) {
    default:
        // malformed statement
        return INVALID_FIELD;
    case 0:
        // empty line or a pure comment
        return INVALID_FIELD;
    case 41:
        // Binary entry
        return validateBinary(line, instruction, parameter);
    case 11:
        // Hex entry
        return validateHex(line, instruction, parameter);
    }
}

PARSE_STATE Parser::validateBinary(QString& line, int& instruction, int& parameter) {
    // check whether there is a separator
    if (line.indexOf('_') == -1)
        return INVALID_FIELD;

    QStringList myStringList = line.split("_");
    QString address = myStringList.at(0);
    QString data = myStringList.at(1);

    if((address.length() != 16) || (data.length() != 24))
        return INVALID_FIELD;

    bool ok;

    instruction = address.toInt(&ok, 2);

    if(ok) {
        parameter = data.toInt(&ok, 2);
        return VALID_FIELD;
    }

    return INVALID_FIELD;
}

PARSE_STATE Parser::validateHex(QString& line, int& instruction, int& parameter) {
    // check whether there is a separator
    if (line.indexOf('_') == -1)
        return INVALID_FIELD;

    QStringList myStringList = line.split("_");
    QString address = myStringList.at(0);
    QString data = myStringList.at(1);

    if((address.length() != 4) || (data.length() != 6))
        return INVALID_FIELD;

    // check whether the hex numbers are correctly formed
    bool ok;
    instruction = address.toUInt(&ok, 16);
    if (ok) {
        parameter = data.toUInt(&ok, 16);
        return VALID_FIELD;
    }

    return INVALID_FIELD;
}
