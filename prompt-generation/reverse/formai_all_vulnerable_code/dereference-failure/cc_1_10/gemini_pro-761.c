//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STEPS 100000

typedef struct pedometer {
    int steps;
    int distance;
    int calories;
} pedometer;

typedef struct fitness_tracker {
    pedometer* pedo;
    int* heart_rate;
    int* blood_pressure;
} fitness_tracker;

void reset_fitness_tracker(fitness_tracker* ft) {
    ft->pedo->steps = 0;
    ft->pedo->distance = 0;
    ft->pedo->calories = 0;
    memset(ft->heart_rate, 0, sizeof(int) * MAX_STEPS);
    memset(ft->blood_pressure, 0, sizeof(int) * MAX_STEPS);
}

void print_fitness_tracker(fitness_tracker* ft) {
    printf("Steps: %d\n", ft->pedo->steps);
    printf("Distance: %d\n", ft->pedo->distance);
    printf("Calories: %d\n", ft->pedo->calories);
    printf("Heart Rate: ");
    for (int i = 0; i < MAX_STEPS; i++) {
        printf("%d ", ft->heart_rate[i]);
    }
    printf("\n");
    printf("Blood Pressure: ");
    for (int i = 0; i < MAX_STEPS; i++) {
        printf("%d ", ft->blood_pressure[i]);
    }
    printf("\n");
}

int main() {
    fitness_tracker ft;
    ft.pedo = malloc(sizeof(pedometer));
    ft.heart_rate = malloc(sizeof(int) * MAX_STEPS);
    ft.blood_pressure = malloc(sizeof(int) * MAX_STEPS);
    reset_fitness_tracker(&ft);
    print_fitness_tracker(&ft);
    return 0;
}