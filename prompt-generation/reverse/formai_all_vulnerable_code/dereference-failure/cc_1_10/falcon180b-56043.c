//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum size of data to be monitored

// Structure to store data and its size
typedef struct {
    void *data;
    size_t size;
} Data;

// Function to initialize a new data entry
void init_data(Data *data, void *ptr, size_t size) {
    data->data = ptr;
    data->size = size;
}

// Function to print the current RAM usage
void print_usage(Data *data, int num_entries) {
    printf("Current RAM usage:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d: %zu bytes at %p\n", i+1, data[i].size, data[i].data);
    }
}

// Function to add a new data entry
void add_data(Data *data, void *ptr, size_t size, int *num_entries) {
    if (*num_entries >= MAX_SIZE) {
        printf("Error: Maximum number of data entries reached.\n");
        return;
    }
    init_data(&data[*num_entries], ptr, size);
    (*num_entries)++;
}

// Function to remove a data entry by pointer
void remove_data(Data *data, void *ptr, int *num_entries) {
    for (int i = 0; i < *num_entries; i++) {
        if (data[i].data == ptr) {
            memmove(&data[i], &data[i+1], sizeof(Data) * (*num_entries - i - 1));
            (*num_entries)--;
            break;
        }
    }
}

// Function to remove a data entry by index
void remove_data_by_index(Data *data, int index, int *num_entries) {
    if (index < 0 || index >= *num_entries) {
        printf("Error: Invalid data entry index.\n");
        return;
    }
    memmove(&data[index], &data[index+1], sizeof(Data) * (*num_entries - index - 1));
    (*num_entries)--;
}

int main() {
    Data data[MAX_SIZE]; // Array to store data entries
    int num_entries = 0; // Number of data entries

    // Initialize first data entry
    void *ptr = malloc(10);
    add_data(data, ptr, 10, &num_entries);

    // Print current RAM usage
    print_usage(data, num_entries);

    // Add more data entries
    ptr = malloc(20);
    add_data(data, ptr, 20, &num_entries);
    ptr = malloc(30);
    add_data(data, ptr, 30, &num_entries);

    // Print current RAM usage
    print_usage(data, num_entries);

    // Remove data entry by pointer
    remove_data(data, ptr, &num_entries);

    // Print current RAM usage
    print_usage(data, num_entries);

    // Remove data entry by index
    remove_data_by_index(data, 1, &num_entries);

    // Print current RAM usage
    print_usage(data, num_entries);

    return 0;
}