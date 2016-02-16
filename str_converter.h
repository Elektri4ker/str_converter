#ifndef STR_CONVERTER_H
#define STR_CONVERTER_H

#include <QStringList>
#include <QVector>


namespace str_converter {
    /*
     * Преобразует вектор num в строку str
     */
    void num2str(QVector<int> num, QString &str);

    /*
     * Преобразует строку str в вектор num, возвращает false в случае некорректной строки.
     */
    bool str2num(QString str, QVector<int> &num);
}

#endif // STR_CONVERTER_H
