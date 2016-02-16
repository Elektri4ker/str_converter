#include "str_converter.h"
#include <QTextStream>


using namespace std;
using namespace str_converter;

//исходные данные
QVector<QVector<int> > numbers = {
    {1, 2, 3, 5, 8, 9, 11},
    {},
    {2, 9, 56, 58, 3, 57, 1, 5},
    {2,2,5,6,8,7},
    {3,3,3,3}
};

QStringList strings = {
    "1-2, 4,8, 10-\t16",
    "3-1, 9,4",
    "3, 1- 5, 9, 9, 8, 5-7",
    "5, 8, 3-5-34, 78",
    "",
    "78, ,,, 87"
};

QTextStream& operator<<(QTextStream &os, const QVector<int> v) {
    os << "[";
    for (int i=0; i<v.size()-1; i++)
        os << v[i] << ",";
    if (!v.isEmpty())
        os << v.last();
    os << "]";
    return os;
}



int main(int argc, char *argv[])
{
    QTextStream cout(stdout);
    foreach (QVector<int> a_number, numbers) {
        QString str;
        num2str(a_number, str);
        cout << a_number << " => " << "\"" <<str<< "\"" << endl;
    }
    cout <<endl;
    foreach (QString str, strings) {
        QVector<int> a_number;
        cout << "\"" <<str<< "\" => ";
        if (!str2num(str, a_number))
            cout << "Illegal characters present!" << endl;
        else
            cout << a_number << endl;
    }

    return 0;
}
