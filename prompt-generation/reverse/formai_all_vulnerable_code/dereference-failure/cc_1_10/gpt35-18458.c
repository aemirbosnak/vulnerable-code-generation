//FormAI DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[50];
    int age;
    int id;
} Student;

int main() {
    FILE* fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error in opening students.txt\n");
        return 1;
    }
    
    char line[100];
    Student students[1000];
    int i = 0;
    
    // Reading data from file
    while (fgets(line, 100, fp) != NULL) {
        char* token = strtok(line, ",");
        strcpy(students[i].name, token);
        
        token = strtok(NULL, ",");
        students[i].age = atoi(token);
        
        token = strtok(NULL, ",");
        students[i].id = atoi(token);
        
        i++;
    }
    
    fclose(fp);
    
    // Querying the database
    printf("Enter student ID to search: ");
    int search_id;
    scanf("%d", &search_id);
    
    for (int j = 0; j < i; j++) {
        if (students[j].id == search_id) {
            printf("Name: %s\nAge: %d\nID: %d\n", students[j].name, students[j].age, students[j].id);
            return 0;
        }
    }
    
    printf("Student not found\n");
    return 0;
}