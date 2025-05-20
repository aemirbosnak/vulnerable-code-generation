//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

void embedWatermark(char* input, char* output, char* watermark) {
    FILE* in = fopen(input, "rb");
    FILE* out = fopen(output, "wb");
    FILE* mark = fopen(watermark, "rb");

    // Error checking
    if(!in || !out || !mark) {
        printf("Error: Unable to open files\n");
        exit(1);
    }

    int watermarkSize = 0;
    char c;
    while((c = fgetc(mark)) != EOF) { // Counting the size of the watermark
        watermarkSize++;        
    }
    rewind(mark);

    int i = 0, j;
    char buffer[MAX];
    while(fgets(buffer, MAX, in)) { // Read the input file line by line
        j = 0;
        while(buffer[j] != '\0') {
            if(buffer[j] == '\n') { // Newline character
                buffer[j + 1] = '\0';
                fwrite(buffer, sizeof(char), strlen(buffer), out); // Write the line to the output file
                for(int k = 0; k < watermarkSize; k++) {
                    if(i < MAX && k < MAX - i) { // Embedding the watermark in the newline
                        fputc(fgetc(mark), out);
                        i++;
                    }
                }
            }
            j++;
        }
    }

    fclose(in);
    fclose(out);
    fclose(mark);
}

void extractWatermark(char* output, char* watermark) {
    FILE* out = fopen(output, "rb");
    FILE* mark = fopen(watermark, "wb");

    // Error checking
    if(!out || !mark) {
        printf("Error: Unable to open files\n");
        exit(1);
    }

    int i = 0, c;
    char buffer[MAX];
    while((c = fgetc(out)) != EOF) { // Read the output file byte by byte
        if(i >= MAX) {
            break;
        }
        buffer[i] = (char) c; // Store the embedded watermark in a buffer
        i++;
    }

    fwrite(buffer, sizeof(char), i, mark); // Write the watermark to the output file

    fclose(out);
    fclose(mark);
}

int main() {
    embedWatermark("input.txt", "output.txt", "watermark.txt");
    extractWatermark("output.txt", "extracted.txt");
    printf("Watermarking demonstration complete\n");
    return 0;
}