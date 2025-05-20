//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 1000
#define MAX_CAPACITY 2500
#define MAX_CYCLES 10

typedef struct Baggage {
    int id;
    int weight;
} Baggage;

typedef struct Bin {
    int capacity;
    int current_weight;
    int count;
    Baggage* baggage_list[MAX_BAGS];
} Bin;

void add_baggage(Bin* bin, Baggage* baggage) {
    if (bin->current_weight + baggage->weight > bin->capacity) {
        printf("Bin is full, cannot add baggage!\n");
        return;
    }
    bin->current_weight += baggage->weight;
    bin->baggage_list[bin->count++] = baggage;
    printf("Baggage with id %d added to bin!\n", baggage->id);
}

void simulate_cycles(Bin** bin_list, int num_bins, Baggage** baggage_list, int num_bags, int num_cycles) {
    for (int i = 0; i < num_cycles; i++) {
        printf("Cycle %d started...\n", i+1);
        for (int j = 0; j < num_bins; j++) {
            for (int k = 0; k < num_bags; k++) {
                int random_bin = rand() % num_bins;
                if (bin_list[random_bin]->count < MAX_BAGS) {
                    add_baggage(bin_list[random_bin], baggage_list[k]);
                }
            }
        }
        for (int j = 0; j < num_bins; j++) {
            printf("Bin %d: %d/%d - ", j+1, bin_list[j]->current_weight, bin_list[j]->capacity);
            for (int k = 0; k < bin_list[j]->count; k++) {
                printf("%d ", bin_list[j]->baggage_list[k]->id);
                free(bin_list[j]->baggage_list[k]);
                bin_list[j]->baggage_list[k] = NULL;
            }
            bin_list[j]->count = 0;
            bin_list[j]->current_weight = 0;
            printf("\n");
        }
        printf("Cycle %d finished...\n", i+1);
    }
}

int main() {
    srand(time(0));
    int num_bins = 5;
    Bin** bin_list = calloc(num_bins, sizeof(Bin*));
    for (int i = 0; i < num_bins; i++) {
        bin_list[i] = malloc(sizeof(Bin));
        bin_list[i]->capacity = MAX_CAPACITY;
        bin_list[i]->count = 0;
        bin_list[i]->current_weight = 0;
    }
    int num_bags = 50;
    Baggage** baggage_list = calloc(num_bags, sizeof(Baggage*));
    for (int i = 0; i < num_bags; i++) {
        baggage_list[i] = malloc(sizeof(Baggage));
        baggage_list[i]->id = i+1;
        baggage_list[i]->weight = rand() % 50 + 10;
    }
    int num_cycles = MAX_CYCLES;
    simulate_cycles(bin_list, num_bins, baggage_list, num_bags, num_cycles);
    return 0;
}