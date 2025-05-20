//FormAI DATASET v1.0 Category: Image Steganography ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

#define FILENAME "original.bmp"
#define NEWFILENAME "stegano.bmp"

void hideDataInBMP(char *cover, char *output, char *data, int data_size);

int main() {
    char buffer[1024];
    FILE *input_file = fopen("input.txt", "rb");
    FILE *output_file = fopen("output.txt", "wb");
    
    if (input_file == NULL) {
        printf("Cannot open input file.\n");
        exit(1);
    }
    
    if (output_file == NULL) {
        printf("Cannot open output file.\n");
        exit(1);
    }
    
    while (fgets(buffer, sizeof(buffer), input_file)) {
        fputs(buffer, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
    
    hideDataInBMP(FILENAME, NEWFILENAME, "output.txt", 10);
    
    return 0;
}

void hideDataInBMP(char *cover, char *output, char *data, int data_size) {
    FILE *fp_cover = fopen(cover, "rb");
    FILE *fp_output = fopen(output, "wb");
    FILE *fp_data = fopen(data, "rb");
    
    if (fp_cover == NULL || fp_output == NULL || fp_data == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    
    // Read BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp_cover);
    fwrite(header, sizeof(unsigned char), 54, fp_output);
    
    // Read BMP pixel data
    unsigned char pixel_data[3];
    while (fread(pixel_data, sizeof(unsigned char), 3, fp_cover) == 3) {
        if (data_size > 0) {
            unsigned char byte;
            fread(&byte, sizeof(unsigned char), 1, fp_data);
            
            pixel_data[0] = (pixel_data[0] & 0xFC) | (byte >> 6);
            pixel_data[1] = (pixel_data[1] & 0xFC) | ((byte >> 4) & 0x03);
            pixel_data[2] = (pixel_data[2] & 0xFC) | ((byte >> 2) & 0x03);
            
            data_size--;
        }
        
        fwrite(pixel_data, sizeof(unsigned char), 3, fp_output);
    }
    
    fclose(fp_cover);
    fclose(fp_output);
    fclose(fp_data);
}