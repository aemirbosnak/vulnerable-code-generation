//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
    double probability;
    char name[50];
} AlienSpecies;

void read_aliens(const char *filename, AlienSpecies *aliens, int num_aliens) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_aliens; i++) {
        fscanf(file, "%lf %s", &(aliens[i].probability), aliens[i].name);
    }

    fclose(file);
}

double calculate_invasion_probability(AlienSpecies *aliens, int num_aliens, int num_spaceships) {
    double total_probability = 0.0;

    for (int i = 0; i < num_aliens; i++) {
        total_probability += aliens[i].probability * pow(aliens[i].probability, num_spaceships);
    }

    return total_probability;
}

void print_result(const char *result_filename, double probability) {
    FILE *file = fopen(result_filename, "w");
    if (!file) {
        printf("Error: Could not open file %s for writing\n", result_filename);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Invasion Probability: %.12f\n", probability);
    fclose(file);

    printf("Invasion Probability: %.12f\n", probability);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (argc < 4) {
        printf("Usage: %s <aliens.txt> <num_aliens> <num_spaceships> <result.txt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *aliens_filename = argv[1];
    int num_aliens = atoi(argv[2]);
    int num_spaceships = atoi(argv[3]);
    const char *result_filename = argv[4];

    AlienSpecies *aliens = (AlienSpecies *) malloc(num_aliens * sizeof(AlienSpecies));

    read_aliens(aliens_filename, aliens, num_aliens);

    double probability = calculate_invasion_probability(aliens, num_aliens, num_spaceships);

    print_result(result_filename, probability);

    free(aliens);

    return EXIT_SUCCESS;
}