//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct Survivor {
    char name[50];
    int water_level;
    int food_level;
};

void read_survivor_file(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    struct Survivor survivor;

    while (fread(&survivor, sizeof(struct Survivor), 1, file) > 0) {
        printf("Name: %s\n", survivor.name);
        printf("Water level: %d\n", survivor.water_level);
        printf("Food level: %d\n", survivor.food_level);
        printf("\n");
    }

    fclose(file);
}

void write_survivor_file(char *filename, struct Survivor survivor) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: Unable to open file %s for writing\n", filename);
        return;
    }

    fprintf(file, "Name: %s\n", survivor.name);
    fprintf(file, "Water level: %d\n", survivor.water_level);
    fprintf(file, "Food level: %d\n", survivor.food_level);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <read|write> <filename> [name water_level food_level]\n", argv[0]);
        return 1;
    }

    char *operation = argv[1];
    char *filename = argv[2];

    if (strcmp(operation, "read") == 0) {
        read_survivor_file(filename);
    } else if (strcmp(operation, "write") == 0 && argc >= 5) {
        struct Survivor survivor;

        strcpy(survivor.name, argv[3]);
        survivor.water_level = atoi(argv[4]);
        survivor.food_level = atoi(argv[5]);

        write_survivor_file(filename, survivor);
    } else {
        printf("Error: Invalid operation %s\n", operation);
        return 1;
    }

    return 0;
}