//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    double height;
} Person;

int main() {
    FILE *file = fopen("people.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    char line[100];
    char *token;
    int count = 0;
    Person people[100];

    while (fgets(line, sizeof(line), file) != NULL) {
        if (count == 0) {
            // Skip first line
            count++;
            continue;
        }

        Person person;
        token = strtok(line, ",");
        strcpy(person.name, token);
        token = strtok(NULL, ",");
        person.age = atoi(token);
        token = strtok(NULL, ",");
        person.height = atof(token);

        people[count-1] = person;
        count++;
    }

    fclose(file);

    printf("%-20s %-10s %-10s\n", "Name", "Age", "Height");
    for (int i = 0; i < count-1; i++) {
        printf("%-20s %-10d %-10.2f\n", people[i].name, people[i].age, people[i].height);
    }

    return 0;
}