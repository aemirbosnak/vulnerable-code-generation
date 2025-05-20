//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char* name;
    int age;
    char* city;
} Person;

int main() {
    FILE* file = fopen("people.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    Person people[100];
    int num_people = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strlen(line) == 0 || line[0] == '#') {
            // Skip empty lines and comment lines
            continue;
        }

        char* name = strtok(line, ",");
        char* age = strtok(NULL, ",");
        char* city = strtok(NULL, ",");

        Person person;
        person.name = strdup(name);
        person.age = atoi(age);
        person.city = strdup(city);

        if (num_people >= 100) {
            // We have reached the maximum number of people
            break;
        }

        people[num_people++] = person;
    }

    fclose(file);

    // Print the names of all the people
    for (int i = 0; i < num_people; i++) {
        printf("%s, %d, %s\n", people[i].name, people[i].age, people[i].city);
    }

    return 0;
}