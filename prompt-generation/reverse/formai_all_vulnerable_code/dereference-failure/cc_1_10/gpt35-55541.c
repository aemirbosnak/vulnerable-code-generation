//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char name[50];
    int age;
    float height;
} Person;

int main() {
    FILE *file = fopen("people.csv", "r");

    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    Person person;
    int lineno = 1;

    while (fgets(buffer, BUFFER_SIZE, file)) {
        // skip first line (header)
        if (lineno == 1) {
            lineno++;
            continue;
        }

        char *name = strtok(buffer, ",");
        char *ageStr = strtok(NULL, ",");
        char *heightStr = strtok(NULL, ",");
        char *newline = strchr(heightStr, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }

        int age = atoi(ageStr);
        float height = atof(heightStr);

        strncpy(person.name, name, 49);
        person.name[49] = '\0';
        person.age = age;
        person.height = height;

        printf("Name: %s, Age: %d, Height: %.2f\n", person.name, person.age, person.height);

        lineno++;
    }

    fclose(file);

    return 0;
}