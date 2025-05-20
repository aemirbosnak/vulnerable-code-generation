//FormAI DATASET v1.0 Category: Database querying ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 50
#define MAX_RECORDS 1000

typedef struct {
    char name[MAX_STR_LEN];
    int age;
    char address[MAX_STR_LEN];
    float gpa;
} Student;

int main() {
    int numStudents = 0;
    Student studentList[MAX_RECORDS];

    FILE *fPtr;
    fPtr = fopen("student_records.txt", "r");
    if (fPtr == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    // read in data from file into studentList
    char buffer[MAX_STR_LEN];
    while (fgets(buffer, MAX_STR_LEN, fPtr) != NULL) {
        char *name = strtok(buffer, ",");
        int age = atoi(strtok(NULL, ","));
        char *address = strtok(NULL, ",");
        float gpa = atof(strtok(NULL, ","));
        strcpy(studentList[numStudents].name, name);
        studentList[numStudents].age = age;
        strcpy(studentList[numStudents].address, address);
        studentList[numStudents].gpa = gpa;
        numStudents++;
    }
    fclose(fPtr);

    // query user for desired age range
    int minAge, maxAge;
    printf("Enter minimum age: ");
    scanf("%d", &minAge);
    printf("Enter maximum age: ");
    scanf("%d", &maxAge);

    // print out students within age range
    printf("\nStudents between the ages of %d and %d:\n", minAge, maxAge);
    for (int i = 0; i < numStudents; i++) {
        if (studentList[i].age >= minAge && studentList[i].age <= maxAge) {
            printf("%s, %d, %s, %.2f\n", studentList[i].name, studentList[i].age, studentList[i].address, studentList[i].gpa);
        }
    }

    return 0;
}