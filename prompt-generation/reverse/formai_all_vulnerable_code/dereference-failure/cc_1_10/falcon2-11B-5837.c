//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *age;
    char *gender;
    char *occupation;
} Person;

int main() {
    FILE *csv_file = fopen("data.csv", "r");
    if (csv_file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    Person current_person;
    char line[256];
    while (fgets(line, sizeof(line), csv_file)!= NULL) {
        char *name_ptr, *age_ptr, *gender_ptr, *occupation_ptr;
        name_ptr = strtok(line, ",");
        age_ptr = strtok(NULL, ",");
        gender_ptr = strtok(NULL, ",");
        occupation_ptr = strtok(NULL, ",");

        if (name_ptr!= NULL) {
            current_person.name = malloc(strlen(name_ptr) + 1);
            strcpy(current_person.name, name_ptr);
        } else {
            fprintf(stderr, "Error parsing name\n");
            continue;
        }

        if (age_ptr!= NULL) {
            current_person.age = malloc(strlen(age_ptr) + 1);
            strcpy(current_person.age, age_ptr);
        } else {
            fprintf(stderr, "Error parsing age\n");
            continue;
        }

        if (gender_ptr!= NULL) {
            current_person.gender = malloc(strlen(gender_ptr) + 1);
            strcpy(current_person.gender, gender_ptr);
        } else {
            fprintf(stderr, "Error parsing gender\n");
            continue;
        }

        if (occupation_ptr!= NULL) {
            current_person.occupation = malloc(strlen(occupation_ptr) + 1);
            strcpy(current_person.occupation, occupation_ptr);
        } else {
            fprintf(stderr, "Error parsing occupation\n");
            continue;
        }

        printf("%s, %s, %s, %s\n", current_person.name, current_person.age, current_person.gender, current_person.occupation);
    }

    fclose(csv_file);

    return 0;
}