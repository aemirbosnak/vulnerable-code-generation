//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to extract metadata information from a given file */
void extract_metadata(char *filename){

    printf("======================\n");
    printf("Extracting Metadata:\n");
    printf("======================\n");

    /* Opening the file in binary read mode */
    FILE *file = fopen(filename, "rb");

    /* Declaring variables to store metadata information */
    char camera_make[50] = "Unknown";
    char camera_model[50] = "Unknown";
    char date[20] = "Unknown";
    char time[20] = "Unknown";
    char lens_make[50] = "Unknown";
    char lens_focal_length[20] = "Unknown";

    /* Check if file exists */
    if (file == NULL){
        printf("Error! File not found.\n");
        return;
    }

    /* Read Exif Metadata from file */
    fseek(file, 0, SEEK_END);
    long int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    /* Allocate memory to store the whole file */
    char *file_data = (char *) malloc(size);

    /* Read the whole file into memory */
    fread(file_data, sizeof(char), size, file);

    /* Close the file */
    fclose(file);

    /* Search for metadata information */
    char *ptr = strstr(file_data, "Make");
    if(ptr){
        sscanf(ptr+5, "%[^\n]", camera_make);
    }

    ptr = strstr(file_data, "Model");
    if(ptr){
        sscanf(ptr+6, "%[^\n]", camera_model);
    }

    ptr = strstr(file_data, "DateTime");
    if(ptr){
        sscanf(ptr+10, "%s %s", date, time);
    }

    ptr = strstr(file_data, "LensMake");
    if(ptr){
        sscanf(ptr+8, "%[^\n]", lens_make);
    }

    ptr = strstr(file_data, "FocalLength");
    if(ptr){
        sscanf(ptr+12, "%[^\n]", lens_focal_length);
    }

    /* Print the extracted metadata information */
    printf("Camera Make: %s\n", camera_make);
    printf("Camera Model: %s\n", camera_model);
    printf("Date: %s\n", date);
    printf("Time: %s\n", time);
    printf("Lens Make: %s\n", lens_make);
    printf("Lens Focal Length: %s\n", lens_focal_length);

    /* Free the allocated memory */
    free(file_data);
}

int main(){
    char filename[100];

    /* Get file name from user input */
    printf("Enter file name: ");
    scanf("%s", filename);

    /* Call the function to extract metadata information from the given file */
    extract_metadata(filename);

    return 0;
}