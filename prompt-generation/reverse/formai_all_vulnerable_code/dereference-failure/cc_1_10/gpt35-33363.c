//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random string of hexadecimal digits
char* generateRandomString(int length) {
    char* str = (char*) malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        sprintf(&str[i], "%x", rand() % 16);
    }
    return str;
}

// Function to perform watermarking on a given file
void watermark(char* filename) {
    FILE* file = fopen(filename, "r+b");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    // Generate a unique watermark string
    srand(time(NULL));
    char* watermark = generateRandomString(32);

    // Write the watermark into the file
    fseek(file, 0, SEEK_SET);
    fwrite(watermark, sizeof(char), strlen(watermark), file);

    // Move the file pointer to the end of the file
    fseek(file, 0, SEEK_END);

    // Write the file size into the file
    fwrite(&filesize, sizeof(long), 1, file);

    // Close the file
    fclose(file);

    printf("Watermark \"%s\" added to file %s\n", watermark, filename);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    watermark(argv[1]);

    return 0;
}