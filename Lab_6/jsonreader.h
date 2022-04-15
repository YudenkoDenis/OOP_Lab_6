#ifndef JSONREADER_H
#define JSONREADER_H
#include "abstractreader.h"
#include <fstream>


class JSONReader : public AbstractReader
{
    std::ifstream fin;

public:
    JSONReader(const QString& filename);

    virtual bool is_open() const {return fin.is_open();} //определяем конкретную реализацию для виртуальной функции
    virtual std::vector<Lesson> readAll();
    virtual AbstractReader& operator>> (Lesson &l);

    virtual operator bool (){
        return this->is_open();
    }
};

#endif // JSONREADER_H
