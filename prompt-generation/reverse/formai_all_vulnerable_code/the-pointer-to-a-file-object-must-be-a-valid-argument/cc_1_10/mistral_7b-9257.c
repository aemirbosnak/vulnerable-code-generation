//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[256];
    float weight;
    int age;
} Exoplanet;

void read_csv(const char *filename, Exoplanet **planets, size_t *num_planets) {
    FILE *file = fopen(filename, "r");
    size_t capacity = 10;
    size_t current = 0;

    *planets = malloc(capacity * sizeof(Exoplanet));

    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        if (current >= capacity) {
            capacity *= 2;
            *planets = realloc(*planets, capacity * sizeof(Exoplanet));
        }

        sscanf(line, "%[^,],%f,%d", (*planets)[current].name, &((*planets)[current].weight), &((*planets)[current].age));
        current++;
    }

    *num_planets = current;
    fclose(file);
}

void print_planets(const Exoplanet *planets, size_t num_planets) {
    for (size_t i = 0; i < num_planets; i++) {
        printf("%s - Weight: %.2f, Age: %d\n", planets[i].name, planets[i].weight, planets[i].age);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <csv_filename>\n", argv[0]);
        return 1;
    }

    Exoplanet *planets = NULL;
    size_t num_planets = 0;

    read_csv(argv[1], &planets, &num_planets);

    printf("Data from file '%s':\n", argv[1]);
    print_planets(planets, num_planets);

    free(planets);

    return 0;
}