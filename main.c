#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
    int choice;
    loadFromFile();

    while (1) {
        printf("\n===== Student Database Menu =====\n");
        printf("1. Add student\n");
        printf("2. Delete student\n");
        printf("3. List students\n");
        printf("4. Search by name\n");
        printf("5. Sort by grade\n");
        printf("6. Save to file\n");
        printf("7. Exit\n");
        printf("Choose: ");

        scanf("%d", &choice);

        if (choice == 1) addStudent();
        else if (choice == 2) {
            int id;
            printf("Enter ID: ");
            scanf("%d", &id);
            deleteStudent(id);
        }
        else if (choice == 3) listStudents();
        else if (choice == 4) {
            char name[50];
            printf("Enter name to search: ");
            scanf(" %[^\n]", name);
            searchStudent(name);
        }
        else if (choice == 5) sortStudents();
        else if (choice == 6) saveToFile();
        else if (choice == 7) {
            saveToFile();
            printf("Goodbye!\n");
            break;
        }
        else printf("Invalid option!\n");
    }

    return 0;
}
