//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to extract metadata information
void extract_metadata(char *filename) {
    FILE *fp;
    fp = fopen(filename, "rb");
    char buffer[10];
    if(fp == NULL) {
        printf("File not found!");
        exit(1);
    } else {
        fseek(fp, 0, SEEK_SET);
        fread(buffer, 8, 1, fp);
        if(strcmp(buffer,"IMG-FILE") != 0) {
            printf("Invalid file format");
            exit(1);
        } else {
            fseek(fp, 8, SEEK_SET);
            fread(buffer, 8, 1, fp);
            int img_width = buffer[0] * 10 + buffer[1];
            int img_height = buffer[2] * 10 + buffer[3];
            printf("Image resolution: %dx%d\n", img_width, img_height);
            fseek(fp, 16, SEEK_SET);
            fread(buffer, 4, 1, fp);
            int img_size = buffer[0] * 1000 + buffer[1] * 100 + buffer[2] * 10 + buffer[3];
            printf("Image size: %d KB\n", img_size);
            printf("Metadata:\n");
            char c;
            int flag = 0;
            int count = 0;
            fseek(fp, 20, SEEK_SET);
            while(fread(&c, 1, 1, fp)) {
                if(c == '\n') {
                    flag = 0;
                    count = 0;
                }
                if(flag == 1 && count < 80) {
                    printf("%c", c);
                    count++;
                }
                if(c == 'M') {
                    fseek(fp, -1, SEEK_CUR);
                    fread(buffer, 4, 1, fp);
                    int metadata_size = buffer[0] * 1000 + buffer[1] * 100 + buffer[2] * 10 + buffer[3];
                    fseek(fp, 4, SEEK_CUR);
                    char metadata[metadata_size];
                    fread(metadata, metadata_size, 1, fp);
                    printf("\n%s\n", metadata);
                    flag = 1;
                }
            }
        }
        fclose(fp);
    }
}

int main() {
    char filename[] = "sample.img";
    extract_metadata(filename);
    return 0;
}