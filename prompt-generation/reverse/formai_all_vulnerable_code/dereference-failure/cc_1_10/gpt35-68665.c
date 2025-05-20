//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_BAGS 1000

struct bag {
    char id[6];
    int weight;
    int destination;
    int priority;
};

struct conveyor_belt {
    int capacity;
    int current_bags;
    struct bag* bags[MAX_BAGS];
};

struct sorting_machine {
    int num_bins;
    int** bin_contents;
};

struct bag* create_bag(char* id, int weight, int destination, int priority) {
    struct bag* b = (struct bag*)malloc(sizeof(struct bag));
    strcpy(b->id, id);
    b->weight = weight;
    b->destination = destination;
    b->priority = priority;
    return b;
}

void destroy_bag(struct bag* b) {
    free(b);
}

void print_bag(struct bag* b) {
    printf("Bag ID: %s\tWeight: %d kg\tDestination: %d\tPriority: %d\n", b->id, b->weight, b->destination, b->priority);
}

void load_bags(struct conveyor_belt* cb, int* num_bags_loaded, struct bag** bags) {
    while (cb->current_bags < cb->capacity && *num_bags_loaded > 0) {
        cb->bags[cb->current_bags++] = bags[--(*num_bags_loaded)];
    }
}

void sort_bags(struct sorting_machine* sm, struct conveyor_belt* cb) {
    for (int i = 0; i < cb->current_bags; i++) {
        struct bag* b = cb->bags[i];
        sm->bin_contents[b->destination][b->priority]++;
    }
    cb->current_bags = 0;
}

void unload_bags(struct sorting_machine* sm) {
    for (int dest = 0; dest < sm->num_bins; dest++) {
        for (int pri = 0; pri < 3; pri++) {
            int num_bags_unloaded = sm->bin_contents[dest][pri];
            while (num_bags_unloaded > 0) {
                printf("Unloading bag at destination %d with priority %d\n", dest, pri);
                num_bags_unloaded--;
            }
            sm->bin_contents[dest][pri] = 0;
        }
    }
}

int main() {
    // Initialize random number generator
    srand(time(NULL));
    
    // Create conveyor belt and sorting machine
    struct conveyor_belt cb = { .capacity = 10, .current_bags = 0 };
    struct sorting_machine sm = { .num_bins = 5, .bin_contents = (int**)malloc(sm.num_bins * sizeof(int*)) };
    for (int i = 0; i < sm.num_bins; i++) {
        sm.bin_contents[i] = (int*)calloc(3, sizeof(int));
    }
    
    // Generate bags and load onto conveyor belt
    int num_bags_loaded = 20;
    struct bag** bags = (struct bag**)malloc(num_bags_loaded * sizeof(struct bag*));
    for (int i = 0; i < num_bags_loaded; i++) {
        char id[6];
        sprintf(id, "%05d", i); // Generate unique bag ID
        int weight = rand() % 20 + 10; // Generate random weight between 10 and 30 kg
        int dest = rand() % sm.num_bins; // Generate random destination
        int priority = rand() % 3; // Generate random priority level (0-2)
        bags[i] = create_bag(id, weight, dest, priority);
        print_bag(bags[i]);
    }
    load_bags(&cb, &num_bags_loaded, bags);
    
    // Sort bags and unload from sorting machine
    sort_bags(&sm, &cb);
    unload_bags(&sm);
    
    // Free memory
    for (int i = 0; i < num_bags_loaded; i++) {
        destroy_bag(bags[i]);
    }
    free(bags);
    for (int i = 0; i < sm.num_bins; i++) {
        free(sm.bin_contents[i]);
    }
    free(sm.bin_contents);
    
    return 0;
}