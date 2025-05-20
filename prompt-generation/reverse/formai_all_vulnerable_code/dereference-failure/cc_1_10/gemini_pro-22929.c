//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define the neon-soaked, neon-bright metropolis.
typedef struct {
    int *arr;
    int size;
    int max;
} NeonCity;

// Welcome to the neon-soaked metropolis.
NeonCity *NeonCity_init(int size, int max) {
    NeonCity *city = malloc(sizeof(NeonCity));
    city->arr = malloc(sizeof(int) * size);
    city->size = size;
    city->max = max;
    return city;
}

// Randomly generate some neon-bright data.
void NeonCity_generate(NeonCity *city) {
    for (int i = 0; i < city->size; i++) {
        city->arr[i] = rand() % city->max;
    }
}

// Partition the neon-bright metropolis into gleaming neon buckets.
void NeonCity_sort(NeonCity *city) {
    int buckets[city->max];
    for (int i = 0; i < city->max; i++) {
        buckets[i] = 0;
    }
    for (int i = 0; i < city->size; i++) {
        buckets[city->arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i < city->max; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            city->arr[index++] = i;
        }
    }
}

// Paint the neon-bright metropolis with sorted light.
void NeonCity_print(NeonCity *city) {
    for (int i = 0; i < city->size; i++) {
        printf("%d ", city->arr[i]);
    }
    printf("\n");
}

int main() {
    // Step into the core of the neon-soaked metropolis.
    NeonCity *city = NeonCity_init(1000, 100);
    NeonCity_generate(city);
    NeonCity_sort(city);
    NeonCity_print(city);
    // Escape the neon-soaked metropolis.
    free(city->arr);
    free(city);
    return 0;
}