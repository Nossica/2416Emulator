#include "parser.hpp"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

void Parser::parse(QList<QString>& input) {
    QFile file(fileName_);
    QString inputLine;

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        inputLine = in.readLine();
        if (validateLine(inputLine))
            input.append(in.readLine());
    }

    file.close();
    //return input;
}

bool Parser::validateLine(QString& line) {
    // remove any text left of a comment
    line = line.left(line.indexOf('#'));
    if (line.length() == 0)
        return true;


}
