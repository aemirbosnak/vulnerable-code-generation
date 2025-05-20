//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_FILE_SIZE 100000

struct watermark {
    int size;
    char *data;
};

struct file {
    int size;
    char *data;
    struct watermark *mark;
};

void embed(struct file *f, char *message, int length);
void extract(struct file *f);

int main() {
    
    struct file f;
    f.size = 0;
    f.data = malloc(MAX_FILE_SIZE * sizeof(char));
    f.mark = NULL;

    FILE *fp = fopen("cyberpunk_file.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read file into buffer
    char c = fgetc(fp);
    while (c != EOF) {
        f.data[f.size++] = c;
        c = fgetc(fp);
    }

    fclose(fp);

    char message[] = "ECHO ECHO ECHO. THIS FILE HAS BEEN MARKED BY THE CYBERPUNKS.";
    embed(&f, message, strlen(message));

    fp = fopen("cyberpunk_stamped_file.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not create file.\n");
        return 1;
    }

    // Write marked file to disk
    for (int i = 0; i < f.size; i++) {
        fputc(f.data[i], fp);
    }

    fclose(fp);

    // Extract watermark from marked file
    f.mark = malloc(sizeof(struct watermark));
    extract(&f);

    printf("Watermark found in marked file: %s\n", f.mark->data);

    free(f.data);
    free(f.mark->data);
    free(f.mark);
    return 0;
}

void embed(struct file *f, char *message, int length) {
    // Calculate number of bytes to store watermark size
    int size_bytes = ceil(log10(length) / log10(2) / 8);

    // Create watermark
    f->mark = malloc(sizeof(struct watermark));
    f->mark->size = length;
    f->mark->data = malloc((length + 1) * sizeof(char));
    strcpy(f->mark->data, message);

    // Embed watermark size into file
    for (int i = 0; i < size_bytes; i++) {
        unsigned char byte = (f->mark->size >> (8 * i)) & 0xFF;
        f->data[i] = (f->data[i] & 0xFE) | ((byte >> 7) & 0x01);
        f->data[i+1] = (f->data[i+1] & 0xFE) | ((byte >> 6) & 0x01);
        f->data[i+2] = (f->data[i+2] & 0xFE) | ((byte >> 5) & 0x01);
        f->data[i+3] = (f->data[i+3] & 0xFE) | ((byte >> 4) & 0x01);
        f->data[i+4] = (f->data[i+4] & 0xFE) | ((byte >> 3) & 0x01);
        f->data[i+5] = (f->data[i+5] & 0xFE) | ((byte >> 2) & 0x01);
        f->data[i+6] = (f->data[i+6] & 0xFE) | ((byte >> 1) & 0x01);
        f->data[i+7] = (f->data[i+7] & 0xFE) | ((byte >> 0) & 0x01);
    }

    // Embed watermark data into file
    int offset = size_bytes * 8;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < 8; j++) {
            unsigned char byte = (f->mark->data[i] >> j) & 0x01;
            f->data[offset++] = (f->data[offset] & 0xFE) | byte;
        }
    }
}

void extract(struct file *f) {
    // Extract watermark size from file
    int size_bytes = 4;
    int watermark_size = 0;

    for (int i = 0; i < size_bytes; i++) {
        watermark_size |= ((f->data[i] & 0x01) << (8 * i + 7));
        watermark_size |= ((f->data[i+1] & 0x01) << (8 * i + 6));
        watermark_size |= ((f->data[i+2] & 0x01) << (8 * i + 5));
        watermark_size |= ((f->data[i+3] & 0x01) << (8 * i + 4));
        watermark_size |= ((f->data[i+4] & 0x01) << (8 * i + 3));
        watermark_size |= ((f->data[i+5] & 0x01) << (8 * i + 2));
        watermark_size |= ((f->data[i+6] & 0x01) << (8 * i + 1));
        watermark_size |= ((f->data[i+7] & 0x01) << (8 * i + 0));
    }

    // Extract watermark data from file
    int watermark_offset = size_bytes * 8;
    char *watermark_data = malloc((watermark_size + 1) * sizeof(char));

    for (int i = 0; i < watermark_size; i++) {
        int byte = 0;

        for (int j = 0; j < 8; j++) {
            byte |= ((f->data[watermark_offset++] & 0x01) << j);
        }

        watermark_data[i] = (char)byte;
    }

    watermark_data[watermark_size] = '\0';

    f->mark->size = watermark_size;
    f->mark->data = watermark_data;
}