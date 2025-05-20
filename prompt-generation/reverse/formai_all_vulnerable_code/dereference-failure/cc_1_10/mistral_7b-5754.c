//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 256
#define MAX_LENGTH 1024

typedef struct {
    char name[MAX_FIELDS][MAX_LENGTH];
    int age;
    char gender;
} Person;

void read_csv(FILE *file, Person people[], int *num_people) {
    char line[MAX_LENGTH];
    int row = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, ",");
        int col = 0;

        if (row >= *num_people) {
            Person *new_people = realloc(people, sizeof(Person) * (*num_people + 16));
            if (new_people == NULL) {
                fprintf(stderr, "Out of memory!\n");
                exit(EXIT_FAILURE);
            }
            people = new_people;
            *num_people += 16;
        }

        while (token != NULL) {
            strcpy(people[row].name[col], token);
            col++;

            if (col > MAX_FIELDS - 1 || (col == MAX_FIELDS - 1 && strlen(token) > MAX_LENGTH)) {
                fprintf(stderr, "Field too long!\n");
                exit(EXIT_FAILURE);
            }

            if (col == 2) {
                people[row].age = atoi(token);
            }

            token = strtok(NULL, ",");
            col++;
        }

        row++;
    }

    *num_people = row;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Person people[3];
    int num_people = 3;

    read_csv(file, people, &num_people);

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s, Age: %d, Gender: %c\n", people[i].name[0], people[i].age, people[i].name[1][0]);
    }

    fclose(file);

    return EXIT_SUCCESS;
}