//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    float weight;
    float height;
} Person;

void read_data(FILE *file, Person **persons, int *num_persons) {
    int i = 0;
    while (fscanf(file, "%s %f %f", (*persons)[i].name, &((*persons)[i].weight), &((*persons)[i].height)) == 3) {
        i++;
        *num_persons = i;
        *persons = realloc(*persons, sizeof(Person) * (*num_persons));
    }
}

float calculate_love_score(Person person1, Person person2) {
    float distance = sqrt(pow(person1.height - person2.height, 2) + pow(person1.weight - person2.weight, 2));
    return 1.0 / (1.0 + distance);
}

int main() {
    FILE *file = fopen("romantic_data.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    Person *persons = NULL;
    int num_persons = 0;
    read_data(file, &persons, &num_persons);
    fclose(file);

    for (int i = 0; i < num_persons; i++) {
        for (int j = i + 1; j < num_persons; j++) {
            float love_score = calculate_love_score(persons[i], persons[j]);
            printf("%s and %s have a love score of %.2f.\n", persons[i].name, persons[j].name, love_score);
        }
    }

    free(persons);
    return 0;
}