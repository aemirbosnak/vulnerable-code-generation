//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

typedef struct {
    char name[100];
    float weight;
    int age;
} Entity;

void DreamParseLine(char *line) {
    Entity entity;
    char *token;

    memset(&entity, 0, sizeof(Entity));

    token = strtok(line, ",");
    strcpy(entity.name, token);

    token = strtok(NULL, ",");
    entity.weight = atof(token);

    token = strtok(NULL, ",");
    entity.age = atoi(token);

    printf("In the land of %s, there lived a %s, weighed %f ounces, and was %d years old.\n",
           entity.name, entity.name, entity.weight * 14.5, entity.age);
}

int main(int argc, char *argv[]) {
    char *line;
    FILE *file;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    printf("Welcome, dreamer, to the enchanted world of CSV files!\n");
    printf("Prepare yourself for a surreal journey through fields and commas!\n");
    printf("Let us begin with the file: %s\n", argv[1]);

    while (getline(&line, 1024, file) > 0) {
        DreamParseLine(line);
    }

    fclose(file);
    free(line);

    printf("Our journey has come to an end. Thank you for joining me on this whimsical adventure!\n");
}