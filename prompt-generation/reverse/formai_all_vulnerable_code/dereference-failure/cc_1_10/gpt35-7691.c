//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

// Function to calculate the hash value of a string
int hash(char *string) {
    int hash_value = 0;
    for (int i = 0; i < strlen(string); i++) {
        hash_value += (int) string[i];
    }
    return hash_value;
}

// Function to embed the watermark in the image file
void embed_watermark(char *image_file, char *watermark) {

    // Open image file for reading
    FILE *fp_image = fopen(image_file, "rb");
    if (fp_image == NULL) {
        printf("Error: could not open %s\n", image_file);
        exit(1);
    }

    // Open temporary file for writing
    FILE *fp_temp = tmpfile();
    if (fp_temp == NULL) {
        printf("Error: could not create temporary file\n");
        exit(1);
    }

    // Read image data and write it to temporary file
    char buffer[MAX_SIZE];
    while (fgets(buffer, MAX_SIZE, fp_image) != NULL) {
        fputs(buffer, fp_temp);
    }

    // Calculate hash value of watermark
    int watermark_hash = hash(watermark);

    // Write watermark hash value to end of temporary file
    fprintf(fp_temp, "%d", watermark_hash);

    // Close both files
    fclose(fp_image);
    fclose(fp_temp);

    // Rename temporary file to original image file
    rename(tmpnam(NULL), image_file);
}

// Function to extract watermark from the image file
void extract_watermark(char *image_file) {

    // Open image file for reading
    FILE *fp_image = fopen(image_file, "rb");
    if (fp_image == NULL) {
        printf("Error: could not open %s\n", image_file);
        exit(1);
    }

    // Read image data and find watermark hash value at end of file
    char buffer[MAX_SIZE];
    int watermark_hash = 0;
    while (fgets(buffer, MAX_SIZE, fp_image) != NULL) {
        watermark_hash = atoi(buffer);
    }

    // Close file
    fclose(fp_image);

    // Print watermark hash value
    printf("Watermark hash value: %d\n", watermark_hash);
}

int main() {

    // Embed watermark in image file
    embed_watermark("example.jpg", "This is a watermark");

    // Extract watermark from image file
    extract_watermark("example.jpg");

    return 0;
}