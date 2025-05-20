//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_IMAGE_SIZE 1000

void embed(char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], char watermark[], int watermark_size) {
    int image_size = strlen(image[0]) - 1;
    int i, j, k;
    for(i=0; i<watermark_size; i++){
        k = watermark[i];
        for(j=0; j<8; j++){
            if(k%2==0){
                if(image[i%image_size][i/image_size]%2!=0)
                    image[i%image_size][i/image_size]--;
            } 
            else{
                if(image[i%image_size][i/image_size]%2==0)
                    image[i%image_size][i/image_size]++;
            }
            k /= 2;
        }
    }
}

void extract(char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], char watermark[], int watermark_size) {
    int image_size = strlen(image[0]) - 1;
    int i, j, k=0;
    for(i=0; i<watermark_size; i++){
        k = 0;
        for(j=0; j<8; j++){
            k *= 2;
            if(image[i%image_size][i/image_size]%2!=0)
                k++;
        }
        watermark[i] = k;
    }
}

int main(){
    char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    FILE *fp = fopen("sample_image.pgm", "r");
    if(fp == NULL){
        printf("Error opening file\n");
        exit(0);
    }
    int i, j, image_size;
    char c = fgetc(fp);
    if(c != 'P' && fgetc(fp) != '5'){
        printf("Invalid PGM file\n");
        exit(0);
    }
    while(c != '\n')
        c = fgetc(fp);
    c = fgetc(fp);
    while(c == '#'){
        while(c != '\n')
            c = fgetc(fp);
        c = fgetc(fp);
    }
    fseek(fp, -1, SEEK_CUR);
    fscanf(fp, "%d", &image_size);
    fgets(image[0], MAX_IMAGE_SIZE, fp);
    fgets(image[0], MAX_IMAGE_SIZE, fp);
    for(i=1; i<image_size; i++){
        fgets(image[i], MAX_IMAGE_SIZE, fp);
    }
    fclose(fp);
    char watermark[] = "UNIQUE WATERMARK";
    int watermark_size = strlen(watermark);
    embed(image, watermark, watermark_size);
    fp = fopen("watermarked_image.pgm", "w");
    fprintf(fp, "P5\n");
    fprintf(fp, "%d\n", image_size);
    fprintf(fp, "%s", image[0]);
    fprintf(fp, "%s", image[1]);
    for(i=2; i<image_size; i++){
        fprintf(fp, "%s", image[i]);
    }
    fclose(fp);
    printf("Watermark embedded successfully\n");
    char extracted_watermark[50];
    extract(image, extracted_watermark, watermark_size);
    printf("Extracted watermark: %s\n", extracted_watermark);
    return 0;
}