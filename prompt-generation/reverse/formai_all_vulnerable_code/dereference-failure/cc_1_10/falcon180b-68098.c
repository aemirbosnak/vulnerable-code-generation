//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int id;
} Student;

int main() {
    Student students[MAX_SIZE];
    int num_students = 0;
    char input[50];

    printf("Enter student names and IDs in the format: name_id\n");
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        if (num_students >= MAX_SIZE) {
            printf("Maximum number of students reached.\n");
            break;
        }
        char *token = strtok(input, "_");
        char *name = token;
        int id = atoi(token + strlen(name) + 1);
        students[num_students] = (Student) {name, id};
        num_students++;
    }

    printf("Enter a student name or ID to search for:\n");
    char search_query[50];
    fgets(search_query, sizeof(search_query), stdin);
    char *query = strtok(search_query, " ");

    int found_index = -1;
    for (int i = 0; i < num_students; i++) {
        if (strcmp(query, students[i].name) == 0 || students[i].id == atoi(query)) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Student not found.\n");
    } else {
        printf("Student found at index %d.\n", found_index);
    }

    return 0;
}