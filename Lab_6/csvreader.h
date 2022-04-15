#ifndef CSVREADER_H
#define CSVREADER_H
#include <QString>
#include <fstream>
#include <vector>
#include <lesson.h>
#include <abstractreader.h>

class CSVReader : public AbstractReader
{
    std::ifstream fin;

    //запрещаем
    CSVReader(const CSVReader&) = delete;
    CSVReader& operator=(const CSVReader&) = delete;

public:
    CSVReader(const QString& filename);
    ~CSVReader();

    //конструктор перемещения
    CSVReader(CSVReader&& other); //принимает в кач. параметра ссылку на тип класса

    //оператор присваивания перемещением
    CSVReader& operator = (CSVReader&& other); //принимает в кач. параметра ссылку на тип класса и возвращает ссылку на тип класса


    virtual bool is_open() const {return fin.is_open();} //определяем конкретную реализацию для виртуальной функции
    virtual std::vector<Lesson> readAll();
    virtual AbstractReader& operator>> (Lesson &l);

    virtual operator bool (){
        return !(this->fin.eof());
    }
};

#endif // CSVREADER_H
