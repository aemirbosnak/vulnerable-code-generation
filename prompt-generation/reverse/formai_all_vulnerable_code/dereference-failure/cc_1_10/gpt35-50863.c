//FormAI DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Create a custom structure to demonstrate memory management
struct Student {
    int id;
    char* name;
    int age;
};

int main() {
    // Allocate memory for 5 students using dynamic memory allocation
    struct Student* students = (struct Student*) malloc(5 * sizeof(struct Student));
    if(students == NULL) {
        printf("Error allocating memory!\n");
        return -1;
    }
    
    // Initialize the students with some data
    students[0].id = 1;
    students[0].name = (char*) malloc(10 * sizeof(char));
    if(students[0].name == NULL) {
        printf("Error allocating memory!\n");
        return -1;
    }
    strcpy(students[0].name, "Alice\0");
    students[0].age = 20;
    
    students[1].id = 2;
    students[1].name = (char*) malloc(10 * sizeof(char));
    if(students[1].name == NULL) {
        printf("Error allocating memory!\n");
        return -1;
    }
    strcpy(students[1].name, "Bob\0");
    students[1].age = 21;
    
    students[2].id = 3;
    students[2].name = (char*) malloc(10 * sizeof(char));
    if(students[2].name == NULL) {
        printf("Error allocating memory!\n");
        return -1;
    }
    strcpy(students[2].name, "Charlie\0");
    students[2].age = 22;
    
    students[3].id = 4;
    students[3].name = (char*) malloc(10 * sizeof(char));
    if(students[3].name == NULL) {
        printf("Error allocating memory!\n");
        return -1;
    }
    strcpy(students[3].name, "David\0");
    students[3].age = 23;
    
    students[4].id = 5;
    students[4].name = (char*) malloc(10 * sizeof(char));
    if(students[4].name == NULL) {
        printf("Error allocating memory!\n");
        return -1;
    }
    strcpy(students[4].name, "Emily\0");
    students[4].age = 24;
    
    // Print the data of the students
    for(int i=0; i<5; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("\n");
    }
    
    // Release the memory allocated for the students
    for(int i=0; i<5; i++) {
        free(students[i].name);
    }
    free(students);
    
    return 0;
}