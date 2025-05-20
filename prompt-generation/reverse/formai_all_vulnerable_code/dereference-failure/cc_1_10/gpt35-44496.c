//FormAI DATASET v1.0 Category: Data recovery tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    float salary;
} Employee;

int main() {
    FILE *fp;
    int empId, choice;
    char file[20] = "employees.dat";
    Employee emp, e;

    printf("Enter employee ID to recover: ");
    scanf("%d", &empId);

    fp = fopen(file, "rb");

    if (fp == NULL) {
        printf("File does not exist!");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long int fileSize = ftell(fp);

    if (fileSize == 0) {
        printf("File is empty!");
        return 0;
    }

    printf("\nChoose recovery algorithm:\n");
    printf("1. Recover from backup\n");
    printf("2. Recover using file system structures\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fseek(fp, (-1)*sizeof(Employee), SEEK_END);

            if (fileSize > sizeof(Employee)) {
                fread(&emp, sizeof(Employee), 1, fp);
                printf("\nRecovered employee:\n");
                printf("ID: %d, Name: %s, Salary: %.2f\n", emp.id, emp.name, emp.salary);
            } else {
                printf("No backup found!");
            }

            break;
        case 2:
            rewind(fp);
            int found = 0;

            while (fread(&e, sizeof(Employee), 1, fp)) {
                if (e.id == empId) {
                    printf("\nRecovered employee:\n");
                    printf("ID: %d, Name: %s, Salary: %.2f\n", e.id, e.name, e.salary);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("\nEmployee with ID %d not found!\n", empId);
            }

            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }

    fclose(fp);

    return 0;
}