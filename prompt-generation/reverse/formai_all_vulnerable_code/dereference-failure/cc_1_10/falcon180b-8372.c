//Falcon-180B DATASET v1.0 Category: Data mining ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_DATA 1000
#define MAX_ATTRIBUTES 10
#define MAX_VALUES 100

struct Data {
    int numAttributes;
    char **attributeNames;
    int *attributeTypes;
    int **attributeValues;
};

struct Data *createData(int numAttributes, char **attributeNames, int *attributeTypes, int **attributeValues) {
    struct Data *data = malloc(sizeof(struct Data));
    data->numAttributes = numAttributes;
    data->attributeNames = attributeNames;
    data->attributeTypes = attributeTypes;
    data->attributeValues = attributeValues;
    return data;
}

void destroyData(struct Data *data) {
    for (int i = 0; i < data->numAttributes; i++) {
        free(data->attributeNames[i]);
    }
    free(data->attributeNames);
    free(data->attributeTypes);
    for (int i = 0; i < data->numAttributes; i++) {
        free(data->attributeValues[i]);
    }
    free(data->attributeValues);
    free(data);
}

void printData(struct Data *data) {
    for (int i = 0; i < data->numAttributes; i++) {
        printf("%s ", data->attributeNames[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    struct Data *data = createData(3, (char *[]){"age", "gender", "income"}, (int []){0, 1, 0}, (int **){NULL, NULL, malloc(sizeof(int) * MAX_VALUES)});

    for (int i = 0; i < MAX_DATA; i++) {
        data->attributeValues[2][i] = rand() % 100000;
    }

    for (int i = 0; i < 10; i++) {
        printData(data);
    }

    destroyData(data);

    return 0;
}