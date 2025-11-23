#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

#define MAX 100

Student* students = NULL;
int studentCount = 0;

void addStudent() {
    students = realloc(students, (studentCount + 1) * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter student ID: ");
    scanf("%d", &students[studentCount].id);
    printf("Enter name: ");
    scanf(" %[^\n]", students[studentCount].name);
    printf("Enter grade: ");
    scanf("%f", &students[studentCount].grade);

    studentCount++;
    printf("Student added successfully!\n");
}

void deleteStudent(int id) {
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            students = realloc(students, studentCount * sizeof(Student));
            printf("Student removed!\n");
            break;
        }
    }
    if (!found)
        printf("Student not found.\n");
}

void listStudents() {
    if (studentCount == 0) {
        printf("No students available.\n");
        return;
    }
    printf("\n--- Student List ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d | Name: %s | Grade: %.2f\n",
               students[i].id,
               students[i].name,
               students[i].grade);
    }
}

void searchStudent(const char* name) {
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strstr(students[i].name, name) != NULL) {
            printf("Found: ID=%d | %s | Grade=%.2f\n",
                   students[i].id,
                   students[i].name,
                   students[i].grade);
            found = 1;
        }
    }
    if (!found)
        printf("No students match this name.\n");
}

void sortStudents() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (students[i].grade < students[j].grade) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Students sorted by grade (desc).\n");
}

void saveToFile() {
    FILE* f = fopen("database.txt", "w");
    if (!f) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        fprintf(f, "%d,%s,%.2f\n", students[i].id, students[i].name, students[i].grade);
    }
    fclose(f);
    printf("Database saved successfully!\n");
}

void loadFromFile() {
    FILE* f = fopen("database.txt", "r");
    if (!f) return;

    students = NULL;
    studentCount = 0;

    while (!feof(f)) {
        students = realloc(students, (studentCount + 1) * sizeof(Student));
        if (fscanf(f, "%d,%49[^,],%f\n",
                   &students[studentCount].id,
                   students[studentCount].name,
                   &students[studentCount].grade) == 3) {
            studentCount++;
        }
    }
    fclose(f);
    printf("Database loaded (%d students).\n", studentCount);
}
