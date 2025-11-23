#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

void addStudent();
void deleteStudent(int id);
void listStudents();
void searchStudent(const char* name);
void sortStudents();
void saveToFile();
void loadFromFile();

#endif
