//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LEN 1024
#define MAX_DIGITS 10

// Structure to hold the data
typedef struct {
    char *name;
    int age;
    float height;
    double weight;
} person_t;

// Function to generate random data
void generate_data(person_t *data, int num_people) {
    srand(time(NULL));
    for (int i = 0; i < num_people; i++) {
        data[i].name = (char *)malloc(MAX_LEN * sizeof(char));
        snprintf(data[i].name, MAX_LEN, "Person %d", i + 1);
        data[i].age = rand() % 100 + 1;
        data[i].height = rand() % 200 + 100;
        data[i].weight = rand() % 100 + 100;
    }
}

// Function to mine the data
void mine_data(person_t *data, int num_people) {
    for (int i = 0; i < num_people; i++) {
        printf("%d. %s (%d years old, %d cm tall, %d kg heavy)\n", i + 1, data[i].name, data[i].age, data[i].height, data[i].weight);
    }
}

int main() {
    person_t *data;
    int num_people;

    // Generate random data
    generate_data(&data, num_people = 10);

    // Mine the data
    mine_data(data, num_people);

    // Free the memory
    for (int i = 0; i < num_people; i++) {
        free(data[i].name);
    }
    free(data);

    return 0;
}