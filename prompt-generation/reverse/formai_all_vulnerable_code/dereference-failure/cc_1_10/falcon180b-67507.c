//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_DATA_SIZE 1000000
#define MAX_STRING_SIZE 100

typedef struct {
    char *string;
    int length;
} StringData;

typedef struct {
    double *data;
    int size;
} DataSet;

void generateRandomData(DataSet *dataSet) {
    srand(time(NULL));
    dataSet->size = MAX_DATA_SIZE;
    dataSet->data = (double *)malloc(dataSet->size * sizeof(double));
    for (int i = 0; i < dataSet->size; i++) {
        dataSet->data[i] = rand() % 1000;
    }
}

void generateRandomString(StringData *stringData) {
    srand(time(NULL));
    stringData->length = rand() % MAX_STRING_SIZE + 1;
    stringData->string = (char *)malloc(stringData->length * sizeof(char));
    for (int i = 0; i < stringData->length; i++) {
        stringData->string[i] = rand() % 26 + 'a';
    }
    stringData->string[stringData->length - 1] = '\0';
}

int main() {
    StringData stringData;
    DataSet dataSet;

    generateRandomData(&dataSet);
    generateRandomString(&stringData);

    printf("String Data: %s\n", stringData.string);
    printf("Data Set:\n");
    for (int i = 0; i < dataSet.size; i++) {
        printf("%lf ", dataSet.data[i]);
    }
    printf("\n");

    free(stringData.string);
    free(dataSet.data);

    return 0;
}