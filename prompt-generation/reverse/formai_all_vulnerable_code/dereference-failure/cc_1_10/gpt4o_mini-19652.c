//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA_SIZE 256
#define MAX_FACTORS 100

typedef struct {
    int *factors;
    int count;
} Factorization;

void freeFactorization(Factorization *f) {
    free(f->factors);
}

Factorization primeFactorization(int n) {
    Factorization f;
    f.count = 0;
    f.factors = malloc(MAX_FACTORS * sizeof(int));

    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            f.factors[f.count++] = i;
            n /= i;
        }
    }
    return f;
}

void printFactorization(Factorization f) {
    if (f.count == 0) {
        printf("No factors.\n");
        return;
    }
    printf("Factors: ");
    for (int i = 0; i < f.count; i++) {
        printf("%d ", f.factors[i]);
    }
    printf("\n");
}

int recoverData(const char *encodedData) {
    int sum = 0;
    for (int i = 0; i < strlen(encodedData); i++) {
        sum += (int)encodedData[i]; // Simple encoding scheme: sum ASCII values
    }
    return sum;
}

void encodeData(const char *inputData, char *encodedData) {
    int n = strlen(inputData);
    for (int i = 0; i < n; i++) {
        encodedData[i] = inputData[i] + 1; // Simple encryption by shifting chars
    }
    encodedData[n] = '\0';
}

void saveDataToFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fputs(data, file);
        fclose(file);
    } else {
        perror("Failed to open file for writing");
    }
}

void loadDataFromFile(const char *filename, char *data, size_t size) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        fread(data, sizeof(char), size, file);
        fclose(file);
    } else {
        perror("Failed to open file for reading");
    }
}

int main() {
    char inputData[MAX_DATA_SIZE];
    char encodedData[MAX_DATA_SIZE];
    int recoveredData;
    
    printf("Enter data to encode (max %d characters): ", MAX_DATA_SIZE - 1);
    fgets(inputData, MAX_DATA_SIZE, stdin);
    
    inputData[strcspn(inputData, "\n")] = 0; // Remove newline character
    
    encodeData(inputData, encodedData);
    
    printf("Encoded Data: %s\n", encodedData);
    
    saveDataToFile("encoded_data.txt", encodedData);
    printf("Encoded data saved to 'encoded_data.txt'.\n");
    
    char readData[MAX_DATA_SIZE];
    loadDataFromFile("encoded_data.txt", readData, sizeof(readData));
    
    printf("Loaded Encoded Data from file: %s\n", readData);
    
    recoveredData = recoverData(readData);
    
    printf("Recovered Data (sum of ASCII values): %d\n", recoveredData);
    
    Factorization f = primeFactorization(recoveredData);
    printFactorization(f);
    freeFactorization(&f);
    
    return 0;
}