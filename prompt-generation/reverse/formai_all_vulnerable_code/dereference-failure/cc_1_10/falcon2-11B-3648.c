//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to embed a watermark into a file
void embedWatermark(char *filename, char *watermark) {
    // Open the input file for reading
    FILE *input = fopen(filename, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return;
    }

    // Open the output file for writing
    FILE *output = fopen(filename, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        return;
    }

    // Read the input file into a buffer
    char buffer[256];
    fread(buffer, 1, sizeof(buffer), input);

    // Find the position of the watermark in the buffer
    int watermarkPos = strstr(buffer, watermark) - buffer;

    // Embed the watermark into the output file
    fwrite(watermark, 1, strlen(watermark), output);
    fwrite(buffer, watermarkPos, sizeof(buffer) - watermarkPos, output);

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Function to extract the watermark from a file
char *extractWatermark(char *filename) {
    // Open the input file for reading
    FILE *input = fopen(filename, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return NULL;
    }

    // Read the input file into a buffer
    char buffer[256];
    fread(buffer, 1, sizeof(buffer), input);

    // Find the position of the watermark in the buffer
    int watermarkPos = strstr(buffer, "watermark") - buffer;

    // Extract the watermark from the buffer
    char *watermark = malloc(sizeof(char) * (watermarkPos + strlen("watermark")));
    strncpy(watermark, buffer, watermarkPos);
    watermark[watermarkPos] = '\0';

    // Close the input file
    fclose(input);

    // Return the extracted watermark
    return watermark;
}

int main() {
    // Test the embedWatermark function
    embedWatermark("input.txt", "watermark");

    // Test the extractWatermark function
    char *watermark = extractWatermark("output.txt");
    if (watermark == NULL) {
        printf("Error extracting watermark.\n");
    } else {
        printf("Extracted watermark: %s\n", watermark);
        free(watermark);
    }

    return 0;
}