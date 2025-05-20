//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FACTORS 20
#define MAX_ALIENS 100

typedef struct {
    int num_factors;
    int *factors;
} FactorSet;

typedef struct {
    int num_factors;
    int *factors;
    double probability;
} AlienSpecies;

void generate_factors(int num_factors, int *factors) {
    for (int i = 0; i < num_factors; i++) {
        factors[i] = rand() % 100 + 1;
    }
}

int count_factors(int num_factors, int *factors) {
    int count = 0;
    for (int i = 0; i < num_factors; i++) {
        count += (num_factors - 1) / factors[i];
    }
    return count;
}

void generate_aliens(AlienSpecies *aliens, int num_aliens) {
    srand(time(NULL));
    for (int i = 0; i < num_aliens; i++) {
        aliens[i].num_factors = rand() % MAX_FACTORS + 1;
        aliens[i].factors = malloc(aliens[i].num_factors * sizeof(int));
        generate_factors(aliens[i].num_factors, aliens[i].factors);
        aliens[i].probability = 1 / (double)count_factors(aliens[i].num_factors, aliens[i].factors);
    }
}

void print_aliens(AlienSpecies *aliens, int num_aliens) {
    for (int i = 0; i < num_aliens; i++) {
        printf("Alien %d:\n", i + 1);
        printf("Number of factors: %d\n", aliens[i].num_factors);
        printf("Factors:\n");
        for (int j = 0; j < aliens[i].num_factors; j++) {
            printf("%d ", aliens[i].factors[j]);
        }
        printf("\nProbability of invasion: %.2f%%\n\n", aliens[i].probability * 100);
    }
}

int main() {
    int num_aliens = 10;
    AlienSpecies aliens[MAX_ALIENS];
    generate_aliens(aliens, num_aliens);
    print_aliens(aliens, num_aliens);
    return 0;
}