//Falcon-180B DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

enum {
    STATE_INIT,
    STATE_NAME,
    STATE_DATA,
    STATE_DONE
};

typedef struct {
    char name[MAX_LINE_SIZE];
    int age;
    int height;
    int weight;
} person_t;

int main(int argc, char *argv[]) {
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    person_t *people = NULL;
    int num_people = 0;
    int state = STATE_INIT;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)) {
        if (state == STATE_INIT) {
            if (strcmp(line, "PEOPLE\n")!= 0) {
                printf("Invalid file format\n");
                fclose(file);
                return 1;
            }
            state = STATE_NAME;
        } else if (state == STATE_NAME) {
            person_t *person = malloc(sizeof(person_t));
            strcpy(person->name, line);
            people = realloc(people, sizeof(person_t) * ++num_people);
            people[num_people - 1] = *person;
            free(person);
            state = STATE_DATA;
        } else if (state == STATE_DATA) {
            sscanf(line, "%d %d %d\n", &people[num_people - 1].age, &people[num_people - 1].height, &people[num_people - 1].weight);
            state = STATE_INIT;
        }
    }

    fclose(file);

    printf("Number of people: %d\n", num_people);

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Height: %d\n", people[i].height);
        printf("Weight: %d\n", people[i].weight);
        printf("\n");
    }

    free(people);

    return 0;
}