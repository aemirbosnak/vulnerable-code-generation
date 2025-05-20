//FormAI DATASET v1.0 Category: Database querying ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student { // Define a structure for a student
    char name[50];
    int rollnum;
    float gpa;
};

void displayRecords(struct student s[], int n) { // Display all records
    printf("Name\tRoll Number\tGPA\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%.2f\n", s[i].name, s[i].rollnum, s[i].gpa);
    }
}

void searchRecord(struct student s[], int n, char searchName[]) { // Search for a specific record by name
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(s[i].name, searchName) == 0) {
            printf("Record Found!\n");
            printf("Name\tRoll Number\tGPA\n");
            printf("%s\t%d\t\t%.2f\n", s[i].name, s[i].rollnum, s[i].gpa);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Sorry, Record not found!\n");
    }
}

int main() {
    int n;
    printf("How many students' records do you want to create? ");
    scanf("%d", &n);

    struct student s[n]; // Create an array of student struct objects

    // Get input from user and store it in the array
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i+1);
        printf("Enter Name: ");
        scanf("%s", s[i].name);
        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollnum);
        printf("Enter GPA: ");
        scanf("%f", &s[i].gpa);
    }

    // Display all records
    displayRecords(s, n);

    // Search for the record of a specific student
    char searchName[50];
    printf("\nEnter name to search for: ");
    scanf("%s", searchName);
    searchRecord(s, n, searchName);

    return 0;
}