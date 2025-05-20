//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int id;
    float gpa;
};

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    struct student *students = (struct student *) malloc(num_students * sizeof(struct student));

    FILE *file_pointer;
    char file_name[50];
    printf("Enter the name of the XML file to parse: ");
    scanf("%s", file_name);
    file_pointer = fopen(file_name, "r");

    if (file_pointer == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[100];
    char *tag_name, *tag_value;

    while (fgets(line, sizeof(line), file_pointer)) {
        tag_name = strtok(line, "<>");
        tag_value = strtok(NULL, "<>");
        if (strcmp(tag_name, "name") == 0) {
            strcpy(students->name, tag_value);
        }
        else if (strcmp(tag_name, "id") == 0) {
            students->id = atoi(tag_value);
        }
        else if (strcmp(tag_name, "gpa") == 0) {
            students->gpa = atof(tag_value);
            students++;
        }
    }

    fclose(file_pointer);

    printf("\nStudent information:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s\n", (students - num_students + i)->name);
        printf("ID: %d\n", (students - num_students + i)->id);
        printf("GPA: %.2f\n\n", (students - num_students + i)->gpa);
    }

    free(students);

    return 0;
}