//FormAI DATASET v1.0 Category: Data recovery tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void readData(char* fileName, long size, char* buffer) {
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Could not open file %s\n", fileName);
        exit(1);
    }

    fread(buffer, size, 1, file);
    fclose(file);
}

void writeData(char* fileName, long size, char* buffer) {
    FILE* file = fopen(fileName, "wb");
    if (file == NULL) {
        printf("Could not open file %s\n", fileName);
        exit(1);
    }

    fwrite(buffer, size, 1, file);
    fclose(file);
}

void recoverData(char* corruptFileName, char* recoveredFileName) {
    long corruptSize;
    FILE* corruptFile = fopen(corruptFileName, "rb");
    if (corruptFile == NULL) {
        printf("Could not open file %s\n", corruptFileName);
        exit(1);
    }

    fseek(corruptFile, 0, SEEK_END);
    corruptSize = ftell(corruptFile);
    fseek(corruptFile, 0, SEEK_SET);

    char* corruptBuffer = (char*) malloc(corruptSize);
    if (corruptBuffer == NULL) {
        printf("Out of memory\n");
        exit(1);
    }

    fread(corruptBuffer, corruptSize, 1, corruptFile);
    fclose(corruptFile);

    char* recoveredBuffer = (char*) calloc(corruptSize, sizeof(char));

    for (int i = 0; i < corruptSize; i++) {
        if (i % 2 == 0) {
            recoveredBuffer[i] = corruptBuffer[i];
        }
    }

    writeData(recoveredFileName, corruptSize, recoveredBuffer);

    printf("Data recovery successful!\n");

    free(corruptBuffer);
    free(recoveredBuffer);
}

int main() {
    char* corruptFileName = "corrupt_data.bin";
    char* recoveredFileName = "recovered_data.bin";

    printf("Initializing data recovery tool...\n");

    recoverData(corruptFileName, recoveredFileName);

    return 0;
}