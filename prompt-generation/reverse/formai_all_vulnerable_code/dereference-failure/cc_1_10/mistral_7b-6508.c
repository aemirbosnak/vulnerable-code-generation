//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float weight;
} bird;

void read_csv(FILE *file, bird *birds, int *num_birds) {
    char line[1024];
    char *token;
    int col = 0;

    *num_birds = 0;

    while (fgets(line, sizeof(line), file)) {
        bird *new_bird = malloc(sizeof(bird));

        token = strtok(line, ",");
        strcpy(new_bird->name, token);

        token = strtok(NULL, ",");
        new_bird->age = atoi(token);

        token = strtok(NULL, ",");
        new_bird->weight = atof(token);

        (*num_birds)++;
        birds = realloc(birds, (*num_birds) * sizeof(bird));
        birds[*num_birds - 1] = *new_bird;
    }
}

int main() {
    FILE *input_file;
    bird *birds = NULL;
    int num_birds = 0;

    input_file = fopen("input.csv", "r");

    if (input_file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    read_csv(input_file, &birds, &num_birds);
    fclose(input_file);

    printf("CSV Parrot says:\n");

    for (int i = 0; i < num_birds; i++) {
        printf("Name: %s, Age: %d, Weight: %.2f\n", birds[i].name, birds[i].age, birds[i].weight);
    }

    for (int i = 0; i < num_birds; i++) {
        free(birds + i);
    }
    free(birds);

    return 0;
}