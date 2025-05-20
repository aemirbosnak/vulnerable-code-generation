//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define WATERMARK "this_is_a_secret_watermark"

// Function to embed watermark
void embed_watermark(FILE *fp, FILE *fw) {
    char byte, pattern;
    int i = 0, j;
    while((byte = fgetc(fp)) != EOF) {
        pattern = WATERMARK[i];
        for (j=0; j<8; j++) {
            if (i < strlen(WATERMARK)) {
                if (pattern & (1 << j))
                    byte |= (1 << j);
                else
                    byte &= ~(1 << j);
            }
            fputc(byte, fw);
            if (byte == EOF) break;
        }
        i++;
    }
}

// Function to extract watermark
void extract_watermark(FILE *fp) {
    char byte, pattern;
    int i = 0, j;
    while((byte = fgetc(fp)) != EOF) {
        pattern = 0x00;
        for (j=0; j<8; j++) {
            if (i < strlen(WATERMARK)) {
                if (byte & (1 << j))
                    pattern |= (1 << j);
                else
                    pattern &= ~(1 << j);
            }
            if (byte == EOF) break;
        }
        if (pattern != WATERMARK[i]) {
            printf("Watermark not found in the file!\n");
            exit(1);
        }
        i++;
    }
    printf("Watermark found in the file!\n");
}

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage: ./watermark embed|extract input_file output_file\n");
        exit(1);
    }

    FILE *fp, *fw;
    char *operation = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];

    // Open input file
    if ((fp = fopen(input_file, "rb")) == NULL) {
        printf("Could not open file %s\n", input_file);
        exit(1);
    }

    // Open output file
    if ((fw = fopen(output_file, "wb")) == NULL) {
        printf("Could not open file %s\n", output_file);
        exit(1);
    }

    if (strcmp(operation, "embed") == 0) {
        // Embed watermark
        embed_watermark(fp, fw);
        printf("Watermark embedded successfully!\n");
    } else if (strcmp(operation, "extract") == 0) {
        // Extract watermark
        extract_watermark(fp);
    } else {
        printf("Invalid operation!\n");
        exit(1);
    }

    // Close files
    fclose(fp);
    fclose(fw);

    return 0;
}