//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char name[MAX_WORD_LENGTH];
    int age;
} Person;

int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    Person *people = (Person*) malloc(MAX_SIZE * sizeof(Person));
    int num_people = 0;

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        if (num_people == MAX_SIZE) {
            printf("Max number of people reached.\n");
            break;
        }

        char *token = strtok(line, ",");
        strcpy(people[num_people].name, token);
        token = strtok(NULL, ",");
        people[num_people].age = atoi(token);

        num_people++;
    }

    fclose(file);

    char search_name[MAX_WORD_LENGTH];
    printf("Enter a name to search for: ");
    scanf("%s", search_name);

    int found_person = 0;
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, search_name) == 0) {
            printf("Found %s, age %d.\n", people[i].name, people[i].age);
            found_person = 1;
            break;
        }
    }

    if (!found_person) {
        printf("Person not found.\n");
    }

    free(people);
    return 0;
}