//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void embedWatermark(char* image_name, char* watermark_text){
    FILE *image_file, *output_file;
    char ch, *watermark, target[100], image_data[10000], output_name[100];
    int pos, watermark_len, i, j;

    // Open the image file
    image_file = fopen(image_name, "rb");

    // If image not found, return
    if(image_file == NULL){
        printf("Image not found.\n");
        return;
    }

    // Get the length of the watermark text
    watermark_len = strlen(watermark_text);

    // Allocate memory to store the watermark text
    watermark = (char*) malloc(watermark_len + 1);

    // Copy the watermark text into the allocated memory
    strcpy(watermark, watermark_text);

    // Read the image file data
    fread(image_data, sizeof(char), 10000, image_file);

    // Close the image file
    fclose(image_file);

    // Find a position in the image to embed the watermark
    pos = rand() % ((strlen(image_data) - watermark_len) / 2);

    // Copy the image data into the output file till the position to embed the watermark
    strncpy(output_name, image_name, strlen(image_name) - 4);
    strcat(output_name, "_watermarked.bmp");
    output_file = fopen(output_name, "wb");
    for(i=0; i<pos; i++){
        fputc(image_data[i], output_file);
    }

    // Embed the watermark in the image
    for(i=0, j=pos; i<watermark_len; i++, j++){
        ch = watermark[i];
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            ch = ch ^ 32; // Convert to uppercase if letter
        }
        sprintf(target, "%c", ch);
        fputc(target[0], output_file);
    }

    // Copy the remaining image data into the output file
    for(i=pos+watermark_len; i<strlen(image_data); i++){
        fputc(image_data[i], output_file);
    }

    // Close the output file and free the memory allocated for the watermark
    fclose(output_file);
    free(watermark);

    printf("Watermark successfully embedded in the image!\n");
}

void decodeWatermark(char* image_name){
    FILE *image_file;
    char ch, image_data[10000], watermark[100];
    int watermark_len, pos, i;

    // Open the image file
    image_file = fopen(image_name, "rb");

    // If image not found, return
    if(image_file == NULL){
        printf("Image not found.\n");
        return;
    }

    // Read the image file data
    fread(image_data, sizeof(char), 10000, image_file);

    // Close the image file
    fclose(image_file);

    // Find the position where the watermark is embedded in the image
    pos = strstr(image_data, "ETC") - image_data;

    // Get the length of the watermark text
    watermark_len = strlen(image_data) - pos - 3;

    // Extract the watermark from the image data
    for(i=pos+3; i<strlen(image_data); i++){
        ch = image_data[i];
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            ch = ch ^ 32; // Convert to uppercase if letter
        }
        sprintf(watermark + strlen(watermark), "%c", ch);
    }

    printf("Decoded watermark: %s\n", watermark);
}

int main(){
    char image[100], watermark[100];

    printf("Enter the name of the image file to embed watermark:\n");
    scanf("%s", image);

    printf("Enter the text to embed in the image as watermark:\n");
    scanf("%s", watermark);

    // Embed the watermark in the image
    embedWatermark(image, watermark);

    // Decode the watermark from the image and print it
    decodeWatermark(strcat(image, "_watermarked.bmp"));

    return 0;
}