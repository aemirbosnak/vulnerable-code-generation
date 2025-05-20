//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ALIEN_COUNT 1000000

typedef struct {
    double probability;
    char name[50];
} Factor;

typedef struct {
    Factor *factors;
    int num_factors;
} ProbabilityModel;

void read_factors_from_file(FILE *fp, ProbabilityModel *model) {
    char name[50];
    double prob;
    int i = 0;

    while (fscanf(fp, "%s %lf", name, &prob) == 2) {
        Factor *new_factor = malloc(sizeof(Factor));
        strcpy(new_factor->name, name);
        new_factor->probability = prob;
        model->factors[i] = *new_factor;
        model->num_factors++;
        i++;
    }
}

ProbabilityModel load_probability_model_from_file(const char *filename) {
    ProbabilityModel model;
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    model.num_factors = 0;
    model.factors = calloc(1, sizeof(Factor) * ALIEN_COUNT);

    read_factors_from_file(fp, &model);
    fclose(fp);

    return model;
}

double calculate_probability(ProbabilityModel model) {
    double total_probability = 1.0;

    for (int i = 0; i < model.num_factors; i++) {
        total_probability *= pow(model.factors[i].probability, ALIEN_COUNT);
    }

    return total_probability;
}

int main(int argc, char *argv[]) {
    ProbabilityModel model;

    if (argc != 2) {
        printf("Usage: %s <probability_model_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    model = load_probability_model_from_file(argv[1]);

    clock_t start = clock();
    double probability = calculate_probability(model);
    clock_t end = clock();

    printf("Probability of alien invasion: %.16f\n", probability);
    printf("Time taken to calculate probability: %.16fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(model.factors);

    return EXIT_SUCCESS;
}