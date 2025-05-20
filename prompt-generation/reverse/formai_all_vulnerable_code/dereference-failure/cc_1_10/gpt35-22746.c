//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: retro
// Retro Style C Digital Watermarking Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000

void embed_watermark(char* source_file, char* target_file, char* watermark);
void extract_watermark(char* watermarked_file);

int main(int argc, char* argv[]) {
    char source_file[MAX_SIZE], target_file[MAX_SIZE], watermark[MAX_SIZE];

    printf("Welcome to the Retro Style C Digital Watermarking Example Program!\n\n");

    printf("Enter the name of the source file: ");
    scanf("%s", source_file);

    printf("Enter the name of the target file: ");
    scanf("%s", target_file);

    printf("Enter the watermark: ");
    scanf("%s", watermark);

    embed_watermark(source_file, target_file, watermark);

    printf("\nWatermark has been embedded in the file successfully!\n\n");

    printf("Do you want to extract the watermark? (y/n): ");
    char response;
    scanf(" %c", &response);

    if(response == 'y' || response == 'Y') {
        extract_watermark(target_file);
    }

    return 0;
}

void embed_watermark(char* source_file, char* target_file, char* watermark) {
    FILE* source_fp, *target_fp;
    source_fp = fopen(source_file, "rb");
    target_fp = fopen(target_file, "wb");

    if(source_fp == NULL || target_fp == NULL) {
        printf("Error opening files. Aborting.\n");
        exit(1);
    }

    char buffer[MAX_SIZE], modified_buffer[MAX_SIZE];
    int read_size, watermark_size = strlen(watermark);
    srand(time(NULL));

    while((read_size = fread(buffer, sizeof(char), MAX_SIZE, source_fp)) > 0) {
        int random_index = rand() % read_size;
        int modified_size = read_size + watermark_size;
        memcpy(modified_buffer, buffer, random_index);
        memcpy(modified_buffer + random_index, watermark, watermark_size);
        memcpy(modified_buffer + random_index + watermark_size, buffer + random_index, read_size - random_index);
        fwrite(modified_buffer, sizeof(char), modified_size, target_fp);
    }

    fclose(source_fp);
    fclose(target_fp);
}

void extract_watermark(char* watermarked_file) {
    FILE* fp;
    fp = fopen(watermarked_file, "rb");

    if(fp == NULL) {
        printf("Error opening file. Aborting.\n");
        exit(1);
    }

    char buffer[MAX_SIZE], watermark[MAX_SIZE];
    int read_size, watermark_index = -1;

    while((read_size = fread(buffer, sizeof(char), MAX_SIZE, fp)) > 0) {
        int i;
        for(i = 0; i < read_size; i++) {
            if(buffer[i] == 'W') {
                watermark_index = i;
                break;
            }
        }
        if(watermark_index != -1) {
            break;
        }
    }

    if(watermark_index == -1) {
        printf("Watermark not found in the file.\n");
        exit(1);
    }

    int watermark_size = strlen(buffer + watermark_index);
    memcpy(watermark, buffer + watermark_index, watermark_size);
    printf("Extracted watermark: %s\n", watermark);

    fclose(fp);
}