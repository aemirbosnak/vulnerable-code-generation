//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 40
#define BUCKET_SIZE 3
#define NUM_BUCKETS WIDTH * HEIGHT / BUCKET_SIZE
#define MAX_RAIN 0.9
#define MIN_RAIN 0.1
#define RAIN_INCREMENT 0.1

typedef struct {
    int x, y;
} Point;

typedef struct {
    int num_sites;
    Point *sites;
    double *rain_rates;
} PercolationSimulator;

void init_simulator(PercolationSimulator *simulator) {
    simulator->num_sites = 0;
    simulator->sites = NULL;
    simulator->rain_rates = NULL;
}

void add_site(PercolationSimulator *simulator, int x, int y) {
    Point point = {x, y};
    simulator->sites = realloc(simulator->sites, sizeof(Point) * ++simulator->num_sites);
    simulator->sites[simulator->num_sites - 1] = point;
}

void set_rain_rates(PercolationSimulator *simulator, double min_rain, double max_rain, double increment) {
    simulator->rain_rates = malloc(sizeof(double) * NUM_BUCKETS);
    srand(time(NULL));
    for (int i = 0; i < NUM_BUCKETS; i++) {
        simulator->rain_rates[i] = min_rain + (max_rain - min_rain) * (double)i / (NUM_BUCKETS - 1);
    }
}

int get_bucket(int x, int y) {
    return (x / BUCKET_SIZE) * HEIGHT + (y / BUCKET_SIZE);
}

void simulate_rain(PercolationSimulator *simulator) {
    for (int i = 0; i < NUM_BUCKETS; i++) {
        int bucket_x = i % WIDTH;
        int bucket_y = i / WIDTH;
        double rain_rate = simulator->rain_rates[i];
        for (int j = 0; j < simulator->num_sites; j++) {
            Point site = simulator->sites[j];
            int site_x = site.x;
            int site_y = site.y;
            if (site_x / BUCKET_SIZE == bucket_x && site_y / BUCKET_SIZE == bucket_y) {
                printf("Rain at site (%d, %d)\n", site_x, site_y);
            }
        }
    }
}

int main() {
    PercolationSimulator simulator;
    init_simulator(&simulator);
    add_site(&simulator, 0, 0);
    add_site(&simulator, 1, 1);
    set_rain_rates(&simulator, MIN_RAIN, MAX_RAIN, RAIN_INCREMENT);
    simulate_rain(&simulator);
    return 0;
}