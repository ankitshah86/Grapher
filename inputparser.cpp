#include "inputparser.h"
#include <iostream>

InputParser::InputParser()
{

    equationLine = new QLineEdit();
    okBtn = new QPushButton("Calculate");
    answerLabel = new QLabel("Answer : ");

    QVBoxLayout *v = new QVBoxLayout();
    v->addWidget(equationLine);
    v->addWidget(answerLabel);
    v->addWidget(okBtn);
    this->setLayout(v);

    connect(okBtn,SIGNAL(clicked(bool)),this,SLOT(calculateClicked()));


}

void InputParser::calculateClicked()
{
    QString s = equationLine->text();

    double d = evaluateString(s);

    answerLabel->setText(QString::number(d));

  // qDebug()<<d<<"\n\n";

}

double InputParser::evaluateString(QString s)
{
    QString tmp;

    QVector <double> numbers;
    QVector <char> ops; // operations

    int i = 0;

    string sstd = s.toStdString();

    while(i < s.size())
    {
        tmp.clear();

        while(isNumberOrDecimalPoint(sstd[i]))
        {
            tmp.append(sstd[i]);
            i++;
        }

        numbers.append(tmp.toDouble());

        if(isValidOperator(sstd[i]))
        {
            ops.append(sstd[i]);
            i++;
        }
        else
        {
            i++;
        }

     }


    //Follow BODMAS here -- To be done later
    // PADMAS can be optional for the user

    double d = numbers[0];

    for(i = 0; i < ops.size() ; i++)
    {
        d = evaluateSingleOperation(parseOpChar(ops.at(i)),d,numbers[i+1]);
    }

    return d;
}

bool InputParser::isNumberOrDecimalPoint(char c)
{
    if( c == '1'||
        c == '2'||
        c == '3'||
        c == '4'||
        c == '5'||
        c == '6'||
        c == '7'||
        c == '8'||
        c == '9'||
        c == '0'||
        c == '.')
        return true;

    return false;
}

bool InputParser::isValidOperator(char c)
{
    if(c == '+'||
       c == '-'||
       c == '*'||
       c == '/')
        return true;
    return false;
}

// 0 meas no parenthesis, 1 means starting parenthesis & 2 means ending parenthesis
int InputParser::isParenthesis(char c)
{
    if(c == '(')
        return 1;
    else if(c == ')')
        return 2;
    else
        return 0;

}

double InputParser::evaluateSingleOperation(op ops, double num1, double num2)
{
    if(ops == op::ADDDITION )
    {
        return num1 + num2;
    }
    else if(ops == op::MULTIPLICATION)
    {
        return num1 * num2;
    }
    else if(ops == op::SUBSTRACTION)
    {
        return num1 - num2;
    }
    else if(ops == op::DIVISION)
    {
        if(num2 < 0.0000000001 && num2 > -0.000000000001)
            return 0;
        else
            return num1/num2;
    }
    return 0;
}

op InputParser::parseOpChar(char c)
{
    if(c == '+')
        return op::ADDDITION;
    else if(c == '-')
        return op::SUBSTRACTION;
    else if(c == '*')
        return op::MULTIPLICATION;
    else if(c == '/')
        return op::DIVISION;


}
