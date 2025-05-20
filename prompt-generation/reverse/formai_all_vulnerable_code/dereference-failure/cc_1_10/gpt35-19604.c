//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARS 100

typedef struct {
    char name[MAX_CHARS];
    int age;
    char position[MAX_CHARS];
    double salary;
} Employee;

int main() {
    // Read in resume file
    FILE *fp;
    char filename[MAX_CHARS];
    printf("Enter the filename of the resume:\n");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: file not found");
        exit(1);
    }
    
    // Parse resume file
    char line[MAX_CHARS];
    char *token;
    int line_count = 0;
    Employee employees[MAX_LINES];
    
    while (fgets(line, MAX_CHARS, fp) != NULL) {
        token = strtok(line, ",");
        strcpy(employees[line_count].name, token);
        token = strtok(NULL, ",");
        employees[line_count].age = atoi(token);
        token = strtok(NULL, ",");
        strcpy(employees[line_count].position, token);
        token = strtok(NULL, ",");
        employees[line_count].salary = atof(token);
        line_count++;
    }
    
    // Print out parsed data
    for (int i = 0; i < line_count; i++) {
        printf("Name: %s\nAge: %d\nPosition: %s\nSalary: %.2f\n\n", 
            employees[i].name, employees[i].age, employees[i].position, employees[i].salary);
    }
    
    fclose(fp);
    return 0;
}