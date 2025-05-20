//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLUMNS 100
#define MAX_LINE_LENGTH 256
#define DELIMITER ","

typedef struct {
    char name[MAX_COLUMNS];
    int age;
    float height;
} Person;

void read_csv(FILE *file, Person *people, int *num_people) {
    char line[MAX_LINE_LENGTH];
    char *token[MAX_COLUMNS];
    int num_tokens, i, j;

    *num_people = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        num_tokens = 0;
        char *token_pointer = strtok(line, DELIMITER);

        if (token_pointer == NULL) {
            printf("Invalid CSV format: %s\n", line);
            continue;
        }

        for (i = 0; i < MAX_COLUMNS && token_pointer != NULL; i++) {
            strcpy(people[*num_people].name, token_pointer);

            if (i == 1) {
                people[*num_people].age = atoi(strtok(NULL, DELIMITER));
            }

            if (i == 2) {
                people[*num_people].height = strtof(strtok(NULL, DELIMITER), NULL);
            }

            if (token[i + 1] != NULL) {
                printf("Invalid number of columns in CSV line: %s\n", line);
                free(people);
                return;
            }

            token_pointer = strtok(NULL, DELIMITER);
        }

        (*num_people)++;
    }
}

int main() {
    FILE *file;
    Person *people;
    int num_people;

    file = fopen("people.csv", "r");

    if (file == NULL) {
        printf("Error opening file: people.csv\n");
        return 1;
    }

    people = malloc(num_people * sizeof(Person));

    if (people == NULL) {
        printf("Error allocating memory for people.\n");
        fclose(file);
        return 1;
    }

    read_csv(file, people, &num_people);

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s, Age: %d, Height: %.2f\n", people[i].name, people[i].age, people[i].height);
    }

    free(people);
    fclose(file);

    return 0;
}