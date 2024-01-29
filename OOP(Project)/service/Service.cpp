//
// Created by Ebrahim Emad on 1/28/2024.
//
#include "../Repo/Repository.cpp"
////////// Student //////////
// Interface
class StudentService{
public:
    virtual int  addStudent(Student student)=0;

};
class StudentServiceImpl{
private:
    StudentImpl StudentRepo;

public:
    int addStudent(Student student){
      return StudentRepo.addStudent(student);
}


};
////////// Course //////////
// Interface
class CourseService{
public:
    virtual int  addCourse(Course course)=0;
};
// Impl
class CourseServiceImpl{
private:
    CourseImpl CourseRepo;
public:
    int  addCourse(Course course){
      return CourseRepo.addCourse(course);
    }
};
////////// Teacher //////////
// Interface
class TeacherService{
public:
    virtual int  addTeacher(Teacher teacher)=0;
};
// Impl
class TeacherServiceImpl{
private:
    TeacherImpl TeacherRepo;
public:
    int  addTeacher(Teacher teacher){
        return TeacherRepo.addTeacher(teacher);
    }

};