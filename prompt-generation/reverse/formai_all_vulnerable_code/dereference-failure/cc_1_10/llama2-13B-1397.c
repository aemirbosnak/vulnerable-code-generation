//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold the data to be searched
typedef struct {
    int key;
    char value;
} data_t;

// Function to generate random data
void generate_data(int num_elements) {
    srand(time(NULL));
    data_t *data = malloc(num_elements * sizeof(data_t));
    for (int i = 0; i < num_elements; i++) {
        data[i].key = rand() % 100;
        data[i].value = 'A' + (rand() % 26);
    }
}

// Function to search the data
int search(data_t *data, int num_elements, int key) {
    int low = 0;
    int high = num_elements - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (data[mid].key == key) {
            return mid;
        }

        // Check if the key is less than the mid element
        if (key < data[mid].key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int num_elements = 10;
    data_t *data = malloc(num_elements * sizeof(data_t));
    generate_data(num_elements);

    int key = 42;
    int result = search(data, num_elements, key);

    if (result != -1) {
        printf("Found %d at index %d\n", data[result].value, result);
    } else {
        printf("Not found\n");
    }

    free(data);
    return 0;
}