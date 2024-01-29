//
// Created by Ebrahim Emad on 1/28/2024.
//
#include <iostream>
using namespace std;
class PublicData{
private:
    int id;
    string name;
public :
    // Setter
    void setId(int id){
        this->id = id;
    }
    void setName(std::string name){
        this->name = name;
    }

    //Getter
    int getId(){
        return id;
    }
    std::string getName(){
        return name;
    }
};
class  Person: public PublicData{
private:
    int age;
    double salary;
    std::string name, phone_number;
public:
    // Setter

    void setAge(int age){
        this->age = age;
    }
    void setPhone_Number(std::string phone_number){
        this->phone_number = phone_number;
    }


    // Getter

    int getAge(){
        return age;
    }
    std::string getPhone_Number(){
        return phone_number;
    }

};
class Teacher: public Person{
private:
    double salary;
    int student_ids[5];
public:
    // Setter
    void setSalary(double salary){
        this->salary = salary;
    }
    void set_student_ids(int student_ids[] ){
        for(int i=0;i<5;i++)this->student_ids[i]=student_ids[i];
    }

    //Getter
    double getSalary(){
        return salary;
    }
    int * get_student_ids(){
        return student_ids;
    }
};
class Course:public PublicData{
private:

    double hour;
    int student_ids[5];
public :
    // Setter

    void setHour(double hour){
        this->hour = hour;
    }
    void set_student_ids(int student_ids[] ){
        for(int i=0;i<5;i++)this->student_ids[i]=student_ids[i];
    }
    //Getter

    double getHour(){
        return hour;
    }
    int * get_student_ids(){
        return student_ids;
    }
};
class Student: public Person{
private:
    double gpa;
    Teacher arr[5];
    Course courses[5];
public:
    // Setter
    void setGpa(double gpa){
        this->gpa = gpa;
    }
    void setTeachers(Teacher arr[5]){
        for(int i=0;i<5;i++)this->arr[i]=arr[i];
    }
    void setTeachers(Course courses[5]){
        for(int i=0;i<sizeof(courses) / sizeof(int);i++)this->courses[i]=courses[i];
    }
    // Getter
    double getGpa(){
        return gpa;
    }
    Teacher * getTeachers(){
        return arr;
    }
    // return a pointer that refer to the whole array
    Course * getCourses(){
        return courses;
    }
};