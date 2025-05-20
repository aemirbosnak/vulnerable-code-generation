//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DATABASE_SIZE 1000
#define MAX_STRING_LENGTH 20

// Structure to hold the data
typedef struct {
    char name[MAX_STRING_LENGTH];
    int age;
} person_t;

// Function to read the data from a file
person_t *read_data(const char *filename) {
    person_t *data = calloc(1, sizeof(person_t));
    int i = 0;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    while (i < DATABASE_SIZE) {
        fscanf(file, "%s %d", data[i].name, &data[i].age);
        i++;
    }

    fclose(file);
    return data;
}

// Function to print the data
void print_data(person_t *data) {
    int i = 0;

    printf("Name\tAge\n");

    while (i < DATABASE_SIZE) {
        printf("%s\t%d\n", data[i].name, data[i].age);
        i++;
    }
}

int main() {
    // Read the data from a file
    person_t *data = read_data("people.dat");

    if (data == NULL) {
        printf("Error reading data\n");
        return 1;
    }

    // Print the data
    print_data(data);

    // Free the memory
    free(data);

    return 0;
}