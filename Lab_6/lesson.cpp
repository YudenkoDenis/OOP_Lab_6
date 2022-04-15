#include "lesson.h"
#include<iostream>
#include<QString>

QString Lesson::to_string(){
    return("Name: " + nameLes + "Auditorium: " + QString::number(auditorium));
}

Lesson::Lesson(){

}
