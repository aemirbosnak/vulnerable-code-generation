//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATASET_SIZE 10000
#define FEATURE_COUNT 5

typedef struct {
    int age;
    int income;
    char gender[5];
} customer_t;

void load_dataset(customer_t** dataset) {
    int i, j;
    for (i = 0; i < DATASET_SIZE; i++) {
        customer_t* customer = malloc(sizeof(customer_t));
        for (j = 0; j < FEATURE_COUNT; j++) {
            switch (j) {
                case 0:
                    customer->age = rand() % 50 + 18;
                    break;
                case 1:
                    customer->income = rand() % 10000 + 2000;
                    break;
                case 2:
                    customer->gender[0] = 'M';
                    break;
                case 3:
                    customer->gender[1] = 'a';
                    break;
                case 4:
                    customer->gender[2] = 'n';
                    break;
                default:
                    customer->gender[3] = 'e';
                    break;
            }
        }
        dataset[i] = customer;
    }
}

void mine_data(customer_t** dataset, int* count) {
    int i, j;
    for (i = 0; i < DATASET_SIZE; i++) {
        for (j = 0; j < FEATURE_COUNT; j++) {
            switch (j) {
                case 0:
                    printf("Age: %d\n", dataset[i]->age);
                    break;
                case 1:
                    printf("Income: %d\n", dataset[i]->income);
                    break;
                case 2:
                    printf("Gender: %c%c%c\n", dataset[i]->gender[0], dataset[i]->gender[1], dataset[i]->gender[2]);
                    break;
            }
        }
        printf("\n");
    }
    *count = DATASET_SIZE;
}

int main() {
    customer_t** dataset;
    int count;

    load_dataset(&dataset);
    mine_data(dataset, &count);

    return 0;
}