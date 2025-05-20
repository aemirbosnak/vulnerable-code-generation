//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    char *value;
} KeyValuePair;

int compare_key_pairs(const void *a, const void *b) {
    KeyValuePair *pa = (KeyValuePair *)a;
    KeyValuePair *pb = (KeyValuePair *)b;
    return pa->key - pb->key;
}

char *get_random_string(int length) {
    char *random_string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        random_string[i] = 'a' + rand() % 26;
    }
    random_string[length] = '\0';
    return random_string;
}

int main() {
    srand(time(NULL));

    // Generate a random array of key-value pairs
    int num_pairs = 10;
    KeyValuePair key_value_pairs[num_pairs];
    for (int i = 0; i < num_pairs; i++) {
        key_value_pairs[i].key = rand() % 100;
        key_value_pairs[i].value = get_random_string(5);
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < num_pairs; i++) {
        printf("%d: %s\n", key_value_pairs[i].key, key_value_pairs[i].value);
    }

    // Sort the array using qsort
    qsort(key_value_pairs, num_pairs, sizeof(KeyValuePair), compare_key_pairs);

    // Print the sorted array
    printf("\nSorted array:\n");
    for (int i = 0; i < num_pairs; i++) {
        printf("%d: %s\n", key_value_pairs[i].key, key_value_pairs[i].value);
    }

    // Free the memory allocated for the random strings
    for (int i = 0; i < num_pairs; i++) {
        free(key_value_pairs[i].value);
    }

    return 0;
}