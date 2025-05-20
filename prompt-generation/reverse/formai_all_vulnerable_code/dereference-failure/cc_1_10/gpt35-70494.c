//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char job[50];
} person;

int main() {

    FILE* fp;

    fp = fopen("employees.csv", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("========================================\n");
    printf("= WELCOME TO THE FUTURE EMPLOYEE SYSTEM =\n");
    printf("========================================\n\n");

    char line[100];
    char* token;
    int count = 0;
    person* employees = (person*) malloc(sizeof(person));

    while(fgets(line, 100, fp) != NULL) {
        token = strtok(line, ",");
        strcpy(employees[count].name, token);
        token = strtok(NULL, ",");
        employees[count].age = atoi(token);
        token = strtok(NULL, ",");
        strcpy(employees[count].job, token);

        count++;
        employees = (person*) realloc(employees, sizeof(person)*(count+1));
    }

    int menu_choice;
    char search_name[50];

    do {
        printf("\nPlease choose from the following options:\n");
        printf("1. Display all employees\n");
        printf("2. Search for an employee by name\n");
        printf("3. Exit\n\n");

        scanf("%d", &menu_choice);

        switch(menu_choice) {
            case 1: 
                printf("\n========================================\n");
                printf("| %-20s| %-5s| %-20s|\n", "Name", "Age", "Job");
                printf("========================================\n");
                for (int i=0; i<count; i++) {
                    printf("| %-20s| %-5d| %-20s|\n", employees[i].name, employees[i].age, employees[i].job);
                }
                printf("========================================\n\n");
            break;

            case 2:
                printf("Enter the name you want to search for: ");
                scanf("%s", search_name);
                printf("\n========================================\n");
                printf("| %-20s| %-5s| %-20s|\n", "Name", "Age", "Job");
                printf("========================================\n");
                for (int i=0; i<count; i++) {
                    if (strcmp(employees[i].name, search_name) == 0) {
                        printf("| %-20s| %-5d| %-20s|\n", employees[i].name, employees[i].age, employees[i].job);
                    }
                }
                printf("========================================\n\n");
            break;

            case 3:
                printf("Exiting...");
            break;

            default:
                printf("Invalid choice. Please try again.\n");
            break;
        }

    } while (menu_choice != 3);

    free(employees);

    return 0;
}