#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <QtWidgets>

using namespace std;
//more operations to be added later
// use a better name for op
enum op {ADDDITION, MULTIPLICATION, DIVISION, SUBSTRACTION};

class InputParser : public QDialog
{
    Q_OBJECT

public:
    InputParser();

    QLineEdit *equationLine;
    QLabel *answerLabel;
    QPushButton *okBtn;


public slots:
    void calculateClicked();
    double evaluateString(QString s);
    bool isNumberOrDecimalPoint(char c);
    bool isValidOperator(char c);
    int isParenthesis(char c);
    //This function will have to be overloaded for single numbers also like sin()
    double evaluateSingleOperation(op ops, double num1, double num2);
    //this function will have to be overloaded for string ops like sin()
    op parseOpChar(char c);


};

#endif // INPUTPARSER_H
