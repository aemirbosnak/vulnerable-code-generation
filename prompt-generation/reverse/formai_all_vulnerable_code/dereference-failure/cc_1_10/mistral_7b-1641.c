//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 100
#define MAX_LINE_LENGTH 1024

typedef struct {
    char name[50];
    int age;
    float height;
    char favorite_color[20];
} Person;

int main() {
    FILE *csv_file = fopen("people.csv", "r");
    Person people[MAX_COLUMNS];
    char line[MAX_LINE_LENGTH];
    int num_people = 0;

    if (csv_file == NULL) {
        printf("Could not open file 'people.csv'\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), csv_file)) {
        char *token = strtok(line, ",");
        if (token == NULL) {
            printf("Invalid CSV format: %s\n", line);
            continue;
        }

        strcpy(people[num_people].name, token);
        token = strtok(NULL, ",");
        people[num_people].age = atoi(token);
        token = strtok(NULL, ",");
        strcpy(people[num_people].favorite_color, token);
        token = strtok(NULL, ",");
        people[num_people].height = atof(token);
        num_people++;

        if (num_people >= MAX_COLUMNS) {
            printf("Too many people in CSV file!\n");
            break;
        }
    }

    fclose(csv_file);

    printf("\nPeople read from CSV file:\n");
    for (int i = 0; i < num_people; i++) {
        printf("Name: %s, Age: %d, Favorite Color: %s, Height: %.2f\n",
               people[i].name, people[i].age, people[i].favorite_color, people[i].height);
    }

    return EXIT_SUCCESS;
}