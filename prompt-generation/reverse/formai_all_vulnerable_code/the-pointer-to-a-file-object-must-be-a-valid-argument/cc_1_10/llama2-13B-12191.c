//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_NUMBER_OF_RECORDS 10000
#define MAX_NUMBER_OF_FEATURES 100

// Structure to store a single record
typedef struct {
    int age;
    int income;
    char gender[10];
    char education[10];
    int num_children;
} record_t;

// Function to calculate the distance between two records
typedef int (*distance_fn_t)(record_t *, record_t *);

int distance_cosine(record_t *r1, record_t *r2) {
    int age_diff = abs(r1->age - r2->age);
    int income_diff = abs(r1->income - r2->income);
    int gender_diff = strcmp(r1->gender, r2->gender);
    int education_diff = strcmp(r1->education, r2->education);
    int num_children_diff = abs(r1->num_children - r2->num_children);

    return (age_diff * age_diff + income_diff * income_diff +
            gender_diff * gender_diff + education_diff * education_diff +
            num_children_diff * num_children_diff) /
           (10 * 10 + 10 * 10 + 10 * 10 + 10 * 10 + 10 * 10);
}

int main() {
    // Load the data from a file
    FILE *file = fopen("data.txt", "r");
    char line[1024];
    record_t *records = calloc(MAX_NUMBER_OF_RECORDS, sizeof(record_t));
    int i = 0;
    while (fgets(line, 1024, file) != NULL) {
        sscanf(line, "%d %d %s %s %d", &records[i].age, &records[i].income,
               records[i].gender, records[i].education, &records[i].num_children);
        i++;
    }
    fclose(file);

    // Calculate the similarity between each pair of records
    distance_fn_t distance_fn = distance_cosine;
    int similar_records[MAX_NUMBER_OF_RECORDS];
    for (int i = 0; i < MAX_NUMBER_OF_RECORDS; i++) {
        similar_records[i] = 0;
    }
    for (int i = 0; i < MAX_NUMBER_OF_RECORDS; i++) {
        for (int j = i + 1; j < MAX_NUMBER_OF_RECORDS; j++) {
            similar_records[i] += distance_fn(records + i, records + j);
        }
    }

    // Print the top 5 similar records
    int top_5[5];
    for (int i = 0; i < 5; i++) {
        top_5[i] = -1;
    }
    for (int i = 0; i < MAX_NUMBER_OF_RECORDS; i++) {
        if (similar_records[i] > top_5[4]) {
            top_5[4] = similar_records[i];
            top_5[3] = i;
        }
        if (similar_records[i] > top_5[3]) {
            top_5[3] = i;
        }
        if (similar_records[i] > top_5[2]) {
            top_5[2] = i;
        }
        if (similar_records[i] > top_5[1]) {
            top_5[1] = i;
        }
        if (similar_records[i] > top_5[0]) {
            top_5[0] = i;
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d: %d %d %s %s %d\n", top_5[i], records[top_5[i]].age,
               records[top_5[i]].income, records[top_5[i]].gender,
               records[top_5[i]].education, records[top_5[i]].num_children);
    }

    return 0;
}