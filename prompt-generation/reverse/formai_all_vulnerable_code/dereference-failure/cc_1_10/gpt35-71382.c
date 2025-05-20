//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_BAGGAGE 1000
#define MAX_FLIGHTS 10

typedef struct Baggage {
    int flight_num;
    double weight;
} Baggage;

typedef struct Bin {
    int bin_num;
    double weight;
    Baggage *baggage[MAX_BAGGAGE];
    int num_baggage;
} Bin;

int main() {
    srand(time(NULL));
    Bin bins[MAX_FLIGHTS];
    int num_flights = rand() % MAX_FLIGHTS + 1;
    int total_num_baggage = 0;

    for (int i = 0; i < num_flights; i++) {
        bins[i].bin_num = i+1;
        bins[i].weight = 0;
        bins[i].num_baggage = rand() % MAX_BAGGAGE + 1;
        for (int j = 0; j < bins[i].num_baggage; j++) {
            bins[i].baggage[j] = (Baggage*)malloc(sizeof(Baggage));
            bins[i].baggage[j]->flight_num = i+1;
            bins[i].baggage[j]->weight = (double)(rand() % 1000) / 10;
            bins[i].weight += bins[i].baggage[j]->weight;
            total_num_baggage++;
        }
    }

    printf("Total number of flights: %d\n", num_flights);
    printf("Total number of baggage: %d\n", total_num_baggage);

    for (int i = 0; i < num_flights; i++) {
        printf("Bin#%d weight: %.2f\n", bins[i].bin_num, bins[i].weight);
        printf("Bin#%d baggage:\n", bins[i].bin_num);
        for (int j = 0; j < bins[i].num_baggage; j++) {
            printf("Flight#%d Baggage#%d weight: %.2f\n", bins[i].baggage[j]->flight_num, j+1, bins[i].baggage[j]->weight);
        }
        printf("\n");
    }

    for (int i = 0; i < num_flights; i++) {
        for (int j = 0; j < bins[i].num_baggage; j++) {
            free(bins[i].baggage[j]);
        }
    }

    return 0;
}