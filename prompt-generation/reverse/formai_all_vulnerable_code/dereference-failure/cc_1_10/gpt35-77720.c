//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100000 // maximum file size

// function to embed the watermark into the given file
void embedWatermark(FILE* in, FILE* out, const char* watermark) {
    char buffer[MAX_FILE_SIZE], c; // buffer to hold the data of in file
    int i = 0, watermarkIndex = 0;

    // read the data from input file in buffer
    while((c = fgetc(in)) != EOF) {
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';

    // add the watermark to the end of the buffer
    strcat(buffer, watermark);

    // write the modified buffer to output file
    fprintf(out, "%s", buffer);
}

// function to extract the watermark from the given file
void extractWatermark(FILE* in, char* watermark, int watermarkSize) {
    char buffer[MAX_FILE_SIZE], c; // buffer to hold the data of in file
    int i = 0;

    // read the data from input file in buffer
    while((c = fgetc(in)) != EOF) {
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';

    // copy the watermark from the end of the file
    strcpy(watermark, buffer + i - watermarkSize);
}

int main(int argc, char** argv) {
    FILE* inFile, *outFile;
    char watermark[] = "My Digital Watermark", extractedWatermark[50];
    char filename[50];
    int choice;

    printf("Enter the input filename: ");
    scanf("%s", filename);

    inFile = fopen(filename, "r");

    if(inFile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    printf("1. Embed Watermark\n2. Extract Watermark\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            sprintf(filename, "watermarked_%s", argv[1]);
            outFile = fopen(filename, "w");

            if(outFile == NULL) {
                printf("Error opening file\n");
                exit(1);
            }

            embedWatermark(inFile, outFile, watermark);
            printf("Watermark embedded successfully\n");
            break;

        case 2:
            extractWatermark(inFile, extractedWatermark, strlen(watermark));
            printf("Extracted Watermark: %s\n", extractedWatermark);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}