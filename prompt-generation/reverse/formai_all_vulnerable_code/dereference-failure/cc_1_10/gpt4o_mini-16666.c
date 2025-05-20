//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define INITIAL_CAPACITY 10
#define LOAD_FACTOR 0.75

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

DynamicArray* create_dynamic_array(size_t initial_capacity) {
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    arr->data = malloc(initial_capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = initial_capacity;
    return arr;
}

void free_dynamic_array(DynamicArray *arr) {
    free(arr->data);
    free(arr);
}

void resize_array(DynamicArray *arr) {
    size_t new_capacity = arr->capacity * 2;
    arr->data = realloc(arr->data, new_capacity * sizeof(int));
    arr->capacity = new_capacity;
}

void add_to_array(DynamicArray *arr, int value) {
    if (arr->size >= arr->capacity * LOAD_FACTOR) {
        resize_array(arr);
    }
    arr->data[arr->size++] = value;
}

bool is_prime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;

    for (int i = 5; i <= sqrt(number); i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}

DynamicArray* generate_primes(int upper_limit) {
    DynamicArray *primes = create_dynamic_array(INITIAL_CAPACITY);
    
    for (int i = 2; i <= upper_limit; i++) {
        if (is_prime(i)) {
            add_to_array(primes, i);
        }
    }
    
    return primes;
}

void print_primes(DynamicArray *primes) {
    printf("Prime numbers:\n");
    for (size_t i = 0; i < primes->size; i++) {
        printf("%d ", primes->data[i]);
    }
    printf("\n");
}

void save_primes_to_file(DynamicArray *primes, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (size_t i = 0; i < primes->size; i++) {
        fprintf(file, "%d\n", primes->data[i]);
    }
    fclose(file);
}

void print_usage() {
    printf("Usage: ./prime_generator <upper_limit>\n");
    printf("Generates all prime numbers up to the specified upper limit.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    int upper_limit = atoi(argv[1]);
    if (upper_limit < 2) {
        printf("Please enter an upper limit greater than or equal to 2.\n");
        return 1;
    }

    DynamicArray *primes = generate_primes(upper_limit);
    print_primes(primes);
    save_primes_to_file(primes, "primes.txt");

    free_dynamic_array(primes);
    
    return 0;
}