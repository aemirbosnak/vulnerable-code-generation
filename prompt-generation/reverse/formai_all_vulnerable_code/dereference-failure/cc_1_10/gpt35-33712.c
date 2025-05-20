//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATERMARK_SIZE 100
#define MAX_FILENAME_SIZE 50

void embedWatermark(char* filename, char* watermark) {
    FILE* fp;
    char filedata[1000], data;
    int idx = 0, watermarkSize = strlen(watermark);
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    while((data = fgetc(fp)) != EOF) {
        filedata[idx++] = data;
    }
    fclose(fp);
    idx = 0;
    while(watermarkSize > 0) {
        int i = idx % strlen(filedata);
        int j = watermarkSize % 129;
        filedata[i] = filedata[i] | (watermark[idx++] ^ j);
        watermarkSize--;
    }
    fp = fopen(filename, "w");
    fprintf(fp, "%s",filedata);
    fclose(fp);
    printf("Watermark embedded successfully.\n");
}

char* extractWatermark(char* filename) {
    FILE* fp;
    char filedata[1000], data;
    char* watermark = (char*)malloc(MAX_WATERMARK_SIZE * sizeof(char));
    int idx = 0;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }
    while((data = fgetc(fp)) != EOF) {
        filedata[idx++] = data;
    }
    fclose(fp);
    for(int i = 0; i < strlen(filedata); i++) {
        int j = idx % 129;
        if(j == 0) {
            break;
        }
        watermark[i] = filedata[i] ^ j;
    }
    printf("Watermark extracted successfully: %s\n", watermark);
    return watermark;
}

int main() {
    char filename[MAX_FILENAME_SIZE], watermark[MAX_WATERMARK_SIZE], option;
    printf("Enter the filename to embed or extract the watermark: ");
    fgets(filename, MAX_FILENAME_SIZE, stdin);
    filename[strcspn(filename, "\n")] = '\0'; //Removing newline character from filename
    printf("Do you want to embed or extract watermark? (e/E for embed and x/X for extract): ");
    option = getchar();
    getchar(); //To discard newline character
    if(option == 'e' || option == 'E') {
        printf("Enter the watermark to embed: ");
        fgets(watermark, MAX_WATERMARK_SIZE, stdin);
        watermark[strcspn(watermark, "\n")] = '\0'; //Removing newline character from watermark
        embedWatermark(filename, watermark);
    } else if(option == 'x' || option == 'X') {
        extractWatermark(filename);
    } else {
        printf("Invalid option.\n");
    }
    return 0;
}