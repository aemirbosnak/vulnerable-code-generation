//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Watermark{
    int width, height;
    char message[MAX_SIZE];
};

void embedWatermark(char *inputFile, char *outputFile, struct Watermark watermark){
    FILE *fInput, *fOutput;
    int i, j, k, c;
    char data[54];
    unsigned char imgData[watermark.width][watermark.height][3];
    unsigned char msgData[MAX_SIZE];
    
    // Open input file
    fInput = fopen(inputFile, "rb");
    if(fInput == NULL){
        printf("ERROR: Could not open input file.");
        return;
    }
    
    // Open output file
    fOutput = fopen(outputFile, "wb");
    if(fOutput == NULL){
        printf("ERROR: Could not create output file.");
        return;
    }
    
    // Read image header data
    for(i = 0; i < 54; i++){
        data[i] = getc(fInput);
    }
    
    // Write image header to output file
    fwrite(data, sizeof(char), 54, fOutput);
    
    // Read image data and store in array
    for(i = 0; i < watermark.width; i++){
        for(j = 0; j < watermark.height; j++){
            for(k = 0; k < 3; k++){
                imgData[i][j][k] = getc(fInput);
            }
        }
    }
    
    // Convert message to binary data
    for(i = 0; i < strlen(watermark.message); i++){
        for(j = 0; j < 8; j++){
            msgData[i*8+j] = (char)(((watermark.message[i] >> j) & 0x01) + '0');
        }
    }
    msgData[strlen(watermark.message)*8] = '\0';
    
    // Embed binary message data in image data array
    k = 0;
    for(i = 0; i < watermark.width; i++){
        for(j = 0; j < watermark.height; j++){
            for(c = 0; c < 3; c++){
                if(k < strlen(msgData)){
                    imgData[i][j][c] = (imgData[i][j][c] & 0xFE) | (msgData[k++] - '0');
                }
            }
        }
    }
    
    // Write embedded image data to output file
    for(i = 0; i < watermark.width; i++){
        for(j = 0; j < watermark.height; j++){
            for(k = 0; k < 3; k++){
                putc(imgData[i][j][k], fOutput);
            }
        }
    }
    
    // Close files
    fclose(fInput);
    fclose(fOutput);
}

struct Watermark extractWatermark(char *inputFile){
    FILE *fInput;
    int i, j, k, c, bitCount;
    char data[54];
    unsigned char imgData[MAX_SIZE][MAX_SIZE][3];
    char msgData[MAX_SIZE];
    struct Watermark watermark;
    
    // Open input file
    fInput = fopen(inputFile, "rb");
    if(fInput == NULL){
        printf("ERROR: Could not open input file.");
        return watermark;
    }
    
    // Read image header data
    for(i = 0; i < 54; i++){
        data[i] = getc(fInput);
    }
    
    // Read image data and store in array
    for(i = 0; i < MAX_SIZE; i++){
        for(j = 0; j < MAX_SIZE; j++){
            for(k = 0; k < 3; k++){
                imgData[i][j][k] = getc(fInput);
            }
        }
    }
    
    // Extract binary message data from image data array
    bitCount = 0;
    for(i = 0; i < MAX_SIZE; i++){
        for(j = 0; j < MAX_SIZE; j++){
            for(c = 0; c < 3; c++){
                if(bitCount < 8*MAX_SIZE){
                    msgData[bitCount/8] = (msgData[bitCount/8] << 1) | (imgData[i][j][c] & 0x01);
                    bitCount++;
                }
            }
        }
    }
    msgData[bitCount/8] = '\0';
    
    // Convert binary message data to text
    for(i = 0; i < strlen(msgData)/8; i++){
        watermark.message[i] = 0;
        for(j = 0; j < 8; j++){
            watermark.message[i] = (watermark.message[i] << 1) | (msgData[i*8+j] - '0');
        }
    }
    watermark.message[strlen(msgData)/8] = '\0';
    watermark.width = MAX_SIZE;
    watermark.height = MAX_SIZE;
    
    // Close file
    fclose(fInput);
    
    return watermark;
}

int main(){
    struct Watermark watermark;
    char inputFile[] = "input.bmp";
    char outputFile[] = "output.bmp";
    char message[] = "Hello World!";
    
    watermark.width = MAX_SIZE;
    watermark.height = MAX_SIZE;
    strcpy(watermark.message, message);
    
    embedWatermark(inputFile, outputFile, watermark);
    
    watermark = extractWatermark(outputFile);
    printf("Extracted message: %s\n", watermark.message);
    
    return 0;
}