#ifndef LESSON_H
#define LESSON_H
#include <QString>
#include <ostream>

class Lesson
{
public:
    int number;
    QString nameLes;
    QString type;
    int auditorium;
    Lesson();

    QString to_string();

    //Переделываем сортировку без лямбда функции
    friend bool operator< (const Lesson& d1, const Lesson& d2){
        return d1.auditorium < d2.auditorium;
    }

    //Вывод информации об объекте в поток
    friend std::ostream& operator<< (std::ostream& out, const Lesson& l){
        out << "Number: " << l.number << ", LessName: " << l.nameLes.toStdString() << ", Type: " << l.type.toStdString();
        return out;
        //return out << l.toStdString();
    }
};

//std::ostream& operator << (std::ostream &os, const Lesson &l);

#endif // LESSON_H
