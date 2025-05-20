//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: invasive
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILE_NAME "arithmetic.bin"
#define ENTRY_SIZE 8

typedef uint64_t entry_t;

void swap_entries(entry_t *a, entry_t *b) {
    entry_t temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    FILE *fp = fopen(FILE_NAME, "r+b");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    size_t file_size = ftell(fp);
    entry_t *entries = malloc(file_size / ENTRY_SIZE);

    if (!entries) {
        perror("Error allocating memory");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    size_t num_entries = file_size / ENTRY_SIZE;
    fseek(fp, 0, SEEK_SET);

    for (size_t i = 0; i < num_entries; ++i) {
        fread(&entries[i], ENTRY_SIZE, 1, fp);
    }

    // Perform arithmetic operations on entries
    for (size_t i = 0; i < num_entries / 2; ++i) {
        size_t j = num_entries - i - 1;
        swap_entries(&entries[i], &entries[j]);
        entries[i] += entries[j];
        entries[j] -= entries[i];
    }

    // Write back to the file
    fseek(fp, 0, SEEK_SET);
    for (size_t i = 0; i < num_entries; ++i) {
        fwrite(&entries[i], ENTRY_SIZE, 1, fp);
    }

    fclose(fp);
    free(entries);

    printf("Arithmetic operations performed on %s successfully.\n", FILE_NAME);

    return EXIT_SUCCESS;
}