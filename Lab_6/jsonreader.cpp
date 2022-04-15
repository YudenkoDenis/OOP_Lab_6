#include "jsonreader.h"
#include <json.hpp>
#include <QString>
#include <iostream>

JSONReader::JSONReader(const QString& filename)
{
    fin.open(filename.toLatin1().data());
}

std::vector<Lesson> JSONReader::readAll(){

    std::vector<Lesson> result;
    nlohmann::json json;

    fin >> json;

    for (auto& au: json){
        Lesson l;
        au.at("number").get_to(l.number);
        au.at("auditorium").get_to(l.auditorium);

        std::string str;
        au.at("nameLes").get_to(str);
        l.nameLes = QString::fromStdString(str);

        std::string str1;
        au.at("type").get_to(str1);
        l.type = QString::fromStdString(str1);

        result.push_back(l);
    }

    return result;
}

AbstractReader& JSONReader::operator>>(Lesson &l){
    l.nameLes = "11111111111";
    l.auditorium = -1;
    l.type = "lab";
    l.number = -1;
    return *this;
}
