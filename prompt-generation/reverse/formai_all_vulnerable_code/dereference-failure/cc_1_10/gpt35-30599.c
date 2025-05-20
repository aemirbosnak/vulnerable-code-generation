//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to find the hash value of the string
int get_hash(char *str, int len){
    int hash = 0;
    for(int i=0; i<len; i++){
        hash = (hash << 3) ^ str[i];
    }
    return hash;
}

// Function to insert the watermark
void insert_watermark(char *filename, char *watermark){
    // Open the input file
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("Error: File not found\n");
        exit(0);
    }

    // Get the length of the input file in bytes
    fseek(fp, 0L, SEEK_END);
    int file_len = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Allocate memory for the input file content and read the content
    char *file_content = (char *)malloc(sizeof(char)*file_len);
    fread(file_content, sizeof(char), file_len, fp);

    // Insert watermark at the beginning of the file content
    char *new_content = (char *)malloc(sizeof(char)*(strlen(watermark) + file_len));
    strcpy(new_content, watermark);
    strcat(new_content, file_content);

    // Open the output file and write the new content
    char *output_file = (char *)malloc(sizeof(char)*(strlen(filename) + 6));
    strcpy(output_file, "water_");
    strcat(output_file, filename);
    FILE *out_fp = fopen(output_file, "wb");
    fwrite(new_content, sizeof(char), strlen(watermark) + file_len, out_fp);

    // Close all the file pointers and free all the allocated memory
    fclose(fp);
    free(file_content);
    free(new_content);
    fclose(out_fp);
}

// Function to extract the watermark
void extract_watermark(char *filename){
    // Open the input file
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("Error: File not found\n");
        exit(0);
    }

    // Get the length of the input file in bytes
    fseek(fp, 0L, SEEK_END);
    int file_len = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Allocate memory for the input file content and read the content
    char *file_content = (char *)malloc(sizeof(char)*file_len);
    fread(file_content, sizeof(char), file_len, fp);

    // Extract the watermark from the beginning of the file content
    int i=0;
    char *watermark = (char *)malloc(sizeof(char)*file_len);
    while(file_content[i] != '\0'){
        watermark[i] = file_content[i];
        i++;
    }
    watermark[i] = '\0';

    // Print the extracted watermark
    printf("Watermark: %s\n", watermark);

    // Close the file pointer and free the allocated memory
    fclose(fp);
    free(file_content);
    free(watermark);
}

// Function to test the watermarking
void test_watermark(char *filename){
    // Generate a random watermark
    char *watermark = "Welcome to the future!";

    // Insert the watermark into the input file
    insert_watermark(filename, watermark);

    // Extract the watermark from the output file
    char *output_file = (char *)malloc(sizeof(char)*(strlen(filename) + 6));
    strcpy(output_file, "water_");
    strcat(output_file, filename);
    extract_watermark(output_file);
    free(output_file);
}

// Driver function
int main(){
    // Test the watermarking
    char *filename = "test.txt";
    test_watermark(filename);

    return 0;
}