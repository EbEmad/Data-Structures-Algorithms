//
// Created by Ebrahim Emad on 1/28/2024.
//
#include "../Model/Models.cpp"
#include <iostream>
using namespace std;

/////////////////// Student\\\\\\\\\\\\\\\\\\\\
// interface
class Student_Repo{
public :
    virtual int  addStudent(Student student)=0; // we should assign 0 to virtual function


};

//impl
class StudentImpl:public Student_Repo{
private:
    Student students[25];
    int index=0;
public:
        //overiding
        int  addStudent(Student student){
            if(index>=25){
                cout<<"Full Student\n";
            }
            else {
                students[index] = student;
                index++;
            }
        }
};
/////////////////// Course \\\\\\\\\\\\\\\\\\\\\\\\
// interface
class Course_Repo{
    virtual int  addCourse(Course course)=0;
};

//impl
class CourseImpl:public Course_Repo{
private:
    Course courses[25];
    int index=0;
public:
    //overiding
    int  addCourse(Course course){
        if(index>=25){
            cout<<"Full Course\n";
        }
        else {
            courses[index] = course;
            index++;
        }
    }
};


/////////////////// Teacher\\\\\\\\\\\\\\\\\\\\
// interface
class Teacher_Repo{
    virtual int  addTeacher(Teacher teacher)=0;
};

//impl
class TeacherImpl:public Teacher_Repo{
private:
    Teacher teachers[25];
    int index=0;
public:
    //overiding
    int  addTeacher(Teacher teacher){
        if(index>=25){
            cout<<"Full Teacher\n";
        }
        else {
            teachers[index] = teacher;
            index++;
        }
    }
};
