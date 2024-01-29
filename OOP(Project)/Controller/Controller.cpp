//
// Created by Ebrahim Emad on 1/28/2024.
//
#include "../service/Service.cpp"
class StudentController{
private:
    StudentServiceImpl StudentService;
public:
    int addStudent(Student student){
        return StudentService.addStudent(student);
    }
};


class CourseController{
private:
    CourseServiceImpl CourseService;
public:
    int  addCourse(Course course){
        return CourseService.addCourse(course);
    }
};


class TeacherController{
private:
    TeacherServiceImpl  teacherService;
public:
    int  addTeacher(Teacher teacher){
        return teacherService.addTeacher(teacher);
    }
};