//FormAI DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

int main() {
    char coverFile[100], outFile[100], secretMsg[1000];
    int key = 1234;

    printf("Enter the name of the cover image file: ");
    scanf("%s", coverFile);

    printf("Enter the name of the output file: ");
    scanf("%s", outFile);

    printf("Enter the secret message: ");
    scanf(" %[^\n]s", secretMsg);

    int coverFileSize;
    unsigned char *coverData, *outData;
    FILE *fpCover, *fpOut;

    fpCover = fopen(coverFile, "rb");
    if (fpCover == NULL) {
        printf("Error: Could not open file %s\n", coverFile);
        exit(1);
    }

    fpOut = fopen(outFile, "wb");
    if (fpOut == NULL) {
        printf("Error: Could not open file %s\n", outFile);
        exit(1);
    }

    fseek(fpCover, 0L, SEEK_END);
    coverFileSize = ftell(fpCover);
    rewind(fpCover);

    coverData = (unsigned char*) malloc(coverFileSize * sizeof(unsigned char));
    if (coverData == NULL) {
        printf("Error: Memory allocation error\n");
        fclose(fpCover);
        fclose(fpOut);
        exit(1);
    }

    outData = (unsigned char*) malloc(coverFileSize * sizeof(unsigned char));
    if (outData == NULL) {
        printf("Error: Memory allocation error\n");
        free(coverData);
        fclose(fpCover);
        fclose(fpOut);
        exit(1);
    }

    fread(coverData, sizeof(unsigned char), coverFileSize, fpCover);

    int secretMsgLength = strlen(secretMsg);
    int bitPairs[secretMsgLength * 4];
    int idx = 0;
    for (int i = 0; i < secretMsgLength; i++) {
        for (int j = 0; j < 4; j++) {
            bitPairs[idx++] = secretMsg[i] & 0x03;
            secretMsg[i] = secretMsg[i] >> 2;
        }
    }

    srand(key);
    int randomIndex[secretMsgLength * 4];
    for (int i = 0; i < secretMsgLength * 4; i++) {
        randomIndex[i] = rand() % (coverFileSize * 8);
    }

    memcpy(outData, coverData, coverFileSize);

    for (int i = 0; i < secretMsgLength * 4; i++) {
        int byteIndex = randomIndex[i] / 8;
        int bitIndex = randomIndex[i] % 8;

        if (bitPairs[i] == 0) {
            outData[byteIndex] &= ~(1 << bitIndex);
        } else {
            outData[byteIndex] |= (1 << bitIndex);
        }
    }

    fwrite(outData, sizeof(unsigned char), coverFileSize, fpOut);

    fclose(fpCover);
    fclose(fpOut);

    free(coverData);
    free(outData);

    printf("Message successfully hidden in file %s\n", outFile);

    return 0;
}