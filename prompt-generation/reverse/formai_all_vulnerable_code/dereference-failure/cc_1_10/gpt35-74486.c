//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK "© MyWatermark"

int main(int argc, char **argv) {
    FILE *fpIn, *fpOut;
    char *buf;
    const int bufSize = 1024;
    long fileSize = 0;
    int watermarkSize = strlen(WATERMARK);
    int i;

    if (argc < 3) {
        printf("Usage: %s [input file] [output file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open input file
    fpIn = fopen(argv[1], "rb");
    if (!fpIn) {
        printf("Error opening input file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Get size of input file
    fseek(fpIn, 0, SEEK_END);
    fileSize = ftell(fpIn);
    rewind(fpIn);

    // Allocate buffer for input file
    buf = (char *) malloc(bufSize * sizeof(char));

    // Open output file
    fpOut = fopen(argv[2], "wb");
    if (!fpOut) {
        printf("Error opening output file: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // Embed watermark in buffer
    for (i = 0; i < watermarkSize; i++) {
        buf[i] = WATERMARK[i];
    }

    // Copy input file to output file
    while (!feof(fpIn)) {
        int bytesRead = fread(buf + watermarkSize, sizeof(char), bufSize - watermarkSize, fpIn);

        fwrite(buf, sizeof(char), bytesRead + watermarkSize, fpOut);
    }

    printf("Watermark embedded successfully!\n");

    // Cleanup
    fclose(fpIn);
    fclose(fpOut);
    free(buf);

    return 0;
}