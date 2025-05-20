//FormAI DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

void saveToFile(double data[], int size, char* filename) {
    FILE* file = fopen(filename, "w");

    if (file != NULL) {
        for (int i = 0; i < size; i++) {
            fprintf(file, "%.2lf\n", data[i]);
        }

        fclose(file);
        printf("Data saved to file successfully.\n");
    } else {
        printf("Failed to open file for writing.\n");
    }
}

void readFromFile(double* data, int* size, char* filename) {
    FILE* file = fopen(filename, "r");

    if (file != NULL) {
        (*size) = 0;

        while (!feof(file)) {
            double value;
            fscanf(file, "%lf\n", &value);

            if (!feof(file)) {
                data[(*size)] = value;
                (*size)++;
            }
        }

        fclose(file);
        printf("Data read from file successfully.\n");
    } else {
        printf("Failed to open file for reading.\n");
    }
}

int main() {
    int dataSize = 5;
    double data[] = { 1.23, 4.56, 7.89, 0.12, 3.45 };
    char* filename = "data.txt";

    // Save data to file
    saveToFile(data, dataSize, filename);

    // Read data from file
    int readSize = 0;
    double* readData = (double*)malloc(dataSize * sizeof(double));
    readFromFile(readData, &readSize, filename);

    // Check if data was read correctly
    if (readSize == dataSize) {
        printf("Data was read correctly from file.\n");

        for (int i = 0; i < readSize; i++) {
            printf("%.2lf ", readData[i]);
        }

        printf("\n");
    } else {
        printf("Data was not read correctly from file.\n");
    }

    free(readData);
    return 0;
}