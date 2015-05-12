#include "parser.hpp"

void Parser::parse(QList<QString>& input) {
    QFile file(fileName_);
    QString inputLine;

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    int lineNumber = 0;
//    while(!in.atEnd()) {
//        inputLine = in.readLine();
//        if (validateLine(inputLine)) {
//            if (inputLine.length()) {
//                inputLine.replace('_',' ');
//                input.append(inputLine);
//            }
//        }
//    }

    file.close();
}

bool Parser::parse(int& instruction, int& parameter) {
    if (in_->atEnd())
        return false;

    QString inputLine = in_->readLine();
    if (validateLine(inputLine, instruction, parameter)) {
        if (inputLine.length()) {
            QString a = inputLine.left(inputLine.indexOf('_'));
            instruction = a.toInt(0,16);
            QString b = inputLine.right(inputLine.length() - 1 - inputLine.indexOf('_'));
            parameter = b.toInt(0,16);
        }
    }

    return true;
}

bool Parser::validateLine(QString& line, int& instruction, int& parameter) {
    // remove white space
    line = line.simplified();
    line.replace( " ", "" );
    //remove text after a comment
    line = line.left(line.indexOf('#'));

    switch(line.length()) {
    default:
        // malformed statement
        return false;
    case 0:
        // empty line or a pure comment
        return true;
    case 41:
        // Binary entry
        return validateBinary(line, instruction, parameter);
    case 11:
        // Hex entry
        return validateHex(line, instruction, parameter);
    }
}

bool Parser::validateBinary(QString& line, int& instruction, int& parameter) {
    // check whether there is a separator
    if (line.indexOf('_') == -1)
        return false;

    //QString address = line.left(line.indexOf('_'));
    //QString data = line.right(line.indexOf('_'));

    QString address = line.section('_',0,0);
    QString data = line.section('_',1,1);

    if((address.length() != 16) || (data.length() != 24))
        return false;

    address = address.remove('0');
    address = address.remove('1');
    if (address.length())
        return false;

    data = data.remove('0');
    data = data.remove('1');
    if (data.length())
        return false;

    return true;
}

bool Parser::validateHex(QString& line, int& instruction, int& parameter) {
    // check whether there is a separator
    if (line.indexOf('_') == -1)
        return false;

    QString address = line.section('_',0,0);
    QString data = line.section('_',1,1);


    if((address.length() != 4) || (data.length() != 6))
        return false;

    // check whether the hex numbers are correctly formed
    bool ok;

    int i = address.toUInt(&ok, 16);
    if (!ok) {
        return false;
    }

    data.toUInt(&ok, 16);
    if (!ok) {
        return false;
    }

    return true;
}
