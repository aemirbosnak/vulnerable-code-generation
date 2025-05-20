//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1000
#define MIN_SUPPORT 1
#define MAX_SUPPORT 100

typedef struct {
    char *name;
    int support;
} Item;

typedef struct {
    int *frequencies;
    int *supports;
    int size;
} Dataset;

void load_dataset(Dataset *d, char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LENGTH];
    int i = 0;

    while (fgets(line, MAX_LENGTH, file)) {
        if (i == 0) {
            // Skip header line
            continue;
        }

        char *token = strtok(line, "\t");
        int frequency = atoi(token);
        int support = atoi(token + 1);

        if (frequency > 0 && support > MIN_SUPPORT && support < MAX_SUPPORT) {
            d->frequencies[i] = frequency;
            d->supports[i] = support;
            i++;
        }
    }

    fclose(file);
    d->size = i;
}

void print_dataset(Dataset *d) {
    for (int i = 0; i < d->size; i++) {
        printf("%s\t%d\n", d->frequencies[i], d->supports[i]);
    }
}

void build_model(Dataset *d) {
    int i, j;
    int *frequencies = d->frequencies;
    int *supports = d->supports;

    for (i = 0; i < d->size; i++) {
        for (j = i + 1; j < d->size; j++) {
            if (frequencies[i] > frequencies[j]) {
                int temp = frequencies[i];
                frequencies[i] = frequencies[j];
                frequencies[j] = temp;

                temp = supports[i];
                supports[i] = supports[j];
                supports[j] = temp;
            }
        }
    }
}

int main() {
    Dataset *d = (Dataset *)malloc(sizeof(Dataset));
    char *filename = "example_data.csv";

    load_dataset(d, filename);
    build_model(d);
    print_dataset(d);

    free(d);
    return 0;
}