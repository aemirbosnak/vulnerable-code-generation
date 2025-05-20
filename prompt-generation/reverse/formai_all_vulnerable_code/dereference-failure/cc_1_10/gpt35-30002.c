//FormAI DATASET v1.0 Category: Image Steganography ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIZE 54
#define PNG_HEADER_SIZE 8
#define BITS_PER_PIXEL 3

void bmpSteg(char* coverPath, char* secretPath, char* output){
    FILE* coverBmp = fopen(coverPath, "rb");
    FILE* secret = fopen(secretPath, "rb");
    FILE* stegoBmp = fopen(output, "wb");
    if(coverBmp == NULL || secret == NULL || stegoBmp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    fseek(secret, 0, SEEK_END);
    long secretSize = ftell(secret);
    rewind(secret);

    unsigned char header[BMP_HEADER_SIZE];
    if(fread(header, 1, BMP_HEADER_SIZE, coverBmp) != BMP_HEADER_SIZE){
        printf("Error reading header!\n");
        exit(1);
    }
    fwrite(header, 1, BMP_HEADER_SIZE, stegoBmp);

    unsigned char buffer;
    int bitCount = 0;
    int byteCount = 0;
    while(fread(&buffer, 1, 1, coverBmp) == 1){
        if(byteCount < secretSize + BMP_HEADER_SIZE){
            if(bitCount == 8){
                bitCount = 0;
                byteCount++;
            }
            if(byteCount > BMP_HEADER_SIZE){
                unsigned char secretByte;
                if(fread(&secretByte, 1, 1, secret) != 1){
                    secretByte = 0;
                }
                unsigned char coverBit = (buffer & 0xFE) | ((secretByte >> (7 - bitCount)) & 0x01);
                fwrite(&coverBit, 1 , 1, stegoBmp);
            } else {
                fwrite(&buffer, 1, 1, stegoBmp);
            }
            bitCount++;
        } else {
            fwrite(&buffer, 1, 1, stegoBmp);
        }
    }

    fclose(coverBmp);
    fclose(secret);
    fclose(stegoBmp);
}

void pngSteg(char* coverPath, char* secretPath, char* output){
    FILE* coverPng = fopen(coverPath, "rb");
    FILE* secret = fopen(secretPath, "rb");
    FILE* stegoPng = fopen(output, "wb");
    if(coverPng == NULL || secret == NULL || stegoPng == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    fseek(secret, 0, SEEK_END);
    long secretSize = ftell(secret);
    rewind(secret);

    unsigned char header[PNG_HEADER_SIZE];
    if(fread(header, 1, PNG_HEADER_SIZE, coverPng) != PNG_HEADER_SIZE){
        printf("Error reading header!\n");
        exit(1);
    }
    fwrite(header, 1, PNG_HEADER_SIZE, stegoPng);

    unsigned char buffer;
    int bitCount = 0;
    int byteCount = 0;
    while(fread(&buffer, 1, 1, coverPng) == 1){
        if(byteCount < secretSize + PNG_HEADER_SIZE){
            if(bitCount == 8){
                bitCount = 0;
                byteCount++;
            }
            if(byteCount > PNG_HEADER_SIZE){
                unsigned char secretByte;
                if(fread(&secretByte, 1, 1, secret) != 1){
                    secretByte = 0;
                }
                unsigned char coverBit = (buffer & 0xFE) | ((secretByte >> (7 - bitCount)) & 0x01);
                fwrite(&coverBit, 1 , 1, stegoPng);
            } else {
                fwrite(&buffer, 1, 1, stegoPng);
            }
            bitCount++;
        } else {
            fwrite(&buffer, 1, 1, stegoPng);
        }
    }

    fclose(coverPng);
    fclose(secret);
    fclose(stegoPng);
}

int main(){
    char* coverPath = "cover.png";
    char* secretPath = "secret.txt";
    char* stegoPath = "stego.png";

    pngSteg(coverPath, secretPath, stegoPath);

    return 0;
}