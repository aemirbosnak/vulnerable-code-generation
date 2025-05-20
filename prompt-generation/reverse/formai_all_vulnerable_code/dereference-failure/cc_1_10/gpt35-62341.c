//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the file type constants
#define PNG_TYPE "png"
#define JPG_TYPE "jpg"
#define BMP_TYPE "bmp"

typedef struct watermark {
    char data[50];
    int size;
} watermark_t;

// Function to embed the watermark in the image
int embed_watermark(const char* image_path, const char* watermark_path) {
    // Define the file pointers for image and watermark
    FILE* image_file;
    FILE* watermark_file;
    
    // Open the image file for reading binary data
    image_file = fopen(image_path, "rb");
    if (!image_file) {
        perror("Error opening image file");
        return 1;
    }
    
    // Open the watermark file for reading binary data
    watermark_file = fopen(watermark_path, "rb");
    if (!watermark_file) {
        perror("Error opening watermark file");
        return 1;
    }
    
    // Read the image file and determine the file type
    char image_type[10];
    fread(image_type, 1, 3, image_file);
    if (strcmp(image_type, PNG_TYPE) == 0) {
        // PNG image file, proceed with embedding the watermark
        // Skip over the rest of the PNG header information
        fseek(image_file, 21, SEEK_CUR);
        
        // Allocate memory for the watermark
        watermark_t* watermark = (watermark_t*) malloc(sizeof(watermark_t));
        
        // Read the watermark file into the structure
        watermark->size = fread(watermark->data, 1, 50, watermark_file);
        
        // Embed the watermark in the image data
        fseek(image_file, 8, SEEK_CUR);
        fwrite(watermark->data, 1, watermark->size, image_file);
        
        // Clean up and close the files
        free(watermark);
        fclose(image_file);
        fclose(watermark_file);
        
        printf("Watermark embedded in %s successfully\n", image_path);
        return 0;
    } else if (strcmp(image_type, JPG_TYPE) == 0) {
        // JPG image file, proceed with embedding the watermark
        // Skip over the rest of the JPG header information
        fseek(image_file, 17, SEEK_CUR);
        
        // Allocate memory for the watermark
        watermark_t* watermark = (watermark_t*) malloc(sizeof(watermark_t));
        
        // Read the watermark file into the structure
        watermark->size = fread(watermark->data, 1, 50, watermark_file);
        
        // Embed the watermark in the image data
        fseek(image_file, -2, SEEK_END);
        fwrite(watermark->data, 1, watermark->size, image_file);
        
        // Clean up and close the files
        free(watermark);
        fclose(image_file);
        fclose(watermark_file);
        
        printf("Watermark embedded in %s successfully\n", image_path);
        return 0;
    } else if (strcmp(image_type, BMP_TYPE) == 0) {
        // BMP image file, proceed with embedding the watermark
        // Skip over the BMP header information
        fseek(image_file, 29, SEEK_CUR);
        
        // Allocate memory for the watermark
        watermark_t* watermark = (watermark_t*) malloc(sizeof(watermark_t));
        
        // Read the watermark file into the structure
        watermark->size = fread(watermark->data, 1, 50, watermark_file);
        
        // Embed the watermark in the image data
        fseek(image_file, 26, SEEK_CUR);
        fwrite(watermark->data, 1, watermark->size, image_file);
        
        // Clean up and close the files
        free(watermark);
        fclose(image_file);
        fclose(watermark_file);
        
        printf("Watermark embedded in %s successfully\n", image_path);
        return 0;
    } else {
        // Unsupported file type, return error
        fclose(image_file);
        fclose(watermark_file);
        
        printf("Unsupported file type\n");
        return 1;
    }
}

// Function to extract the watermark from the image
int extract_watermark(const char* image_path) {
    // Define the file pointer for image
    FILE* image_file;
    
    // Open the image file for reading binary data
    image_file = fopen(image_path, "rb");
    if (!image_file) {
        perror("Error opening image file");
        return 1;
    }
    
    // Read the image file and determine the file type
    char image_type[10];
    fread(image_type, 1, 3, image_file);
    if (strcmp(image_type, PNG_TYPE) == 0) {
        // PNG image file, proceed with extracting the watermark
        // Skip over the rest of the PNG header information
        fseek(image_file, 21, SEEK_CUR);
        
        // Allocate memory for the watermark
        watermark_t* watermark = (watermark_t*) malloc(sizeof(watermark_t));
        
        // Read the watermark data from the image file
        watermark->size = fread(watermark->data, 1, 50, image_file);
        
        // Display the watermark data
        printf("Watermark extracted from %s successfully: %s\n", image_path, watermark->data);
        
        // Clean up and close the file
        free(watermark);
        fclose(image_file);
        
        return 0;
    } else if (strcmp(image_type, JPG_TYPE) == 0) {
        // JPG image file, proceed with extracting the watermark
        // Skip over the rest of the JPG header information
        fseek(image_file, 17, SEEK_CUR);
        
        // Allocate memory for the watermark
        watermark_t* watermark = (watermark_t*) malloc(sizeof(watermark_t));
        
        // Read the watermark data from the image file
        watermark->size = fread(watermark->data, 1, 50, image_file);
        
        // Display the watermark data        
        printf("Watermark extracted from %s successfully: %s\n", image_path, watermark->data);
        
        // Clean up and close the file
        free(watermark);
        fclose(image_file);
        
        return 0;
    } else if (strcmp(image_type, BMP_TYPE) == 0) {
        // BMP image file, proceed with extracting the watermark
        // Skip over the BMP header information
        fseek(image_file, 29, SEEK_CUR);
        
        // Allocate memory for the watermark
        watermark_t* watermark = (watermark_t*) malloc(sizeof(watermark_t));
        
        // Read the watermark data from the image file
        watermark->size = fread(watermark->data, 1, 50, image_file);
        
        // Display the watermark data
        printf("Watermark extracted from %s successfully: %s\n", image_path, watermark->data);
        
        // Clean up and close the file
        free(watermark);
        fclose(image_file);
        
        return 0;
    } else {
        // Unsupported file type, return error
        fclose(image_file);
        
        printf("Unsupported file type\n");
        return 1;
    }
}

int main() {
    // Example usage
    // Embed the watermark in the image
    int embed_result = embed_watermark("image.png", "watermark.txt");
    if (embed_result != 0) {
        printf("Error embedding watermark\n");
        return 1;
    }
    
    // Extract the watermark from the image
    int extract_result = extract_watermark("image.png");
    if (extract_result != 0) {
        printf("Error extracting watermark\n");
        return 1;
    }
    
    return 0;
}