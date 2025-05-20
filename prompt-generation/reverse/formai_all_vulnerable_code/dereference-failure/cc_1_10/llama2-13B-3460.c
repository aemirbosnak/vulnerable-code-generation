//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_RECORDS 10000
#define MAX_FEATURES 5

// Structure to hold a single record
typedef struct {
    int age;
    int income;
    char gender[5];
    int education;
    int occupation[5];
} record_t;

// Function to generate random records
record_t* generate_records(int num_records) {
    record_t* records = calloc(num_records, sizeof(record_t));

    for (int i = 0; i < num_records; i++) {
        records[i].age = rand() % 100 + 1;
        records[i].income = rand() % 10000 + 1;
        strcpy(records[i].gender, "Male");
        records[i].education = rand() % 5 + 1;
        strcpy(records[i].occupation, "Software Engineer");
    }

    return records;
}

// Function to calculate the similarity between two records
double calculate_similarity(record_t* record1, record_t* record2) {
    int similarity = 0;

    if (record1->age == record2->age) {
        similarity++;
    }

    if (record1->income == record2->income) {
        similarity++;
    }

    if (strcmp(record1->gender, record2->gender) == 0) {
        similarity++;
    }

    if (record1->education == record2->education) {
        similarity++;
    }

    if (strcmp(record1->occupation, record2->occupation) == 0) {
        similarity++;
    }

    return (double)similarity / MAX_FEATURES;
}

int main() {
    srand(time(NULL));

    // Generate 10000 random records
    record_t* records = generate_records(10000);

    // Calculate the similarity between all pairs of records
    double* similarities = calloc(10000 * 10000, sizeof(double));

    for (int i = 0; i < 10000; i++) {
        for (int j = i + 1; j < 10000; j++) {
            similarities[i * 10000 + j] = calculate_similarity(records + i, records + j);
            similarities[j * 10000 + i] = similarities[i * 10000 + j];
        }
    }

    // Visualize the similarity matrix
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            printf("%.2f ", similarities[i * 10000 + j]);
        }
        printf("\n");
    }

    free(records);
    free(similarities);

    return 0;
}