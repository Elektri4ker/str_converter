#include <QStringList>
#include <QVector>
#include <algorithm>

/*
 * Возвращает строку, в которое конвертировано число (или диапазон чисел,
 * если числа идут подряд), на которое указывает it.
 * Возвращает it, указывающий на следующее целое число, или на end
 */
QString num2str_nextstep(QVector<int>::iterator &it, QVector<int>::iterator it_end) {
    int prev_num = *it;
    QString str = QString::number(prev_num);
    bool diapason_flag = false;
    //Если мы не попали на диапазон, то it увеличится только на 1.
    while (++it != it_end && *it == prev_num+1) {
        prev_num = *it;
        diapason_flag = true;
    }
    if (diapason_flag)
        str = str + "-" + QString::number(prev_num);

    return str;
}

namespace str_converter {


    void num2str(QVector<int> num, QString &str) {
        str.clear();
        if (num.isEmpty())
            return;
        //Сортировка входного массива: 3-им параметром передается
        //функция, оставлено для совместимости
        std::sort(num.begin(), num.end());
        num.resize(std::distance(num.begin(), std::unique(num.begin(), num.end())));

        QVector<int>::iterator it = num.begin();
        while (it != num.end())
            str+= num2str_nextstep(it, num.end()) + ",";

        str.remove(str.size()-1, 1); //удаляем последнюю запятую
    }

    bool str2num(QString str, QVector<int> &num) {
        num.clear();
        //Удаляем пробельные символы
        str.remove(QRegExp("\\s"));

        QStringList all_entries = str.split(',', QString::SkipEmptyParts);
        foreach (QString entry, all_entries) {
            QStringList numbers = entry.split('-');

            if (numbers.size()>2 || numbers.size()<1)
                return false;
            bool ok;
            int i_num1 = numbers.first().toInt(&ok);
            int i_num2 = numbers.last().toInt(&ok); //Если знака '-' не было, i_num1=i_num2
            if (!ok)
                return false;
            for (int i=i_num1; i<=i_num2; i++)
                num.append(i);
        }

        std::sort(num.begin(), num.end());

        num.resize(std::distance(num.begin(), std::unique(num.begin(), num.end())));
        return true;
    }
}
