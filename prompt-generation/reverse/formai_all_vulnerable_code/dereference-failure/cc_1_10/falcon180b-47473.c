//Falcon-180B DATASET v1.0 Category: File handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char *name;
    int age;
    float height;
} Person;

int main() {
    FILE *file;
    char filename[50];
    char line[MAX_LINE_LENGTH];
    Person people[100];
    int num_people = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_people >= 100) {
            printf("Maximum number of people reached\n");
            break;
        }

        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        float height = atof(strtok(NULL, ","));

        people[num_people] = (Person) {.name = name,.age = age,.height = height};
        num_people++;
    }

    fclose(file);

    printf("Number of people: %d\n", num_people);

    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old and %.2f meters tall\n", people[i].name, people[i].age, people[i].height);
    }

    return 0;
}