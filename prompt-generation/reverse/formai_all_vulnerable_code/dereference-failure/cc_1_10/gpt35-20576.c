//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 32

typedef struct {
    unsigned char data[8];
} watermark_t;

typedef struct {
    watermark_t watermark;
    unsigned long offset;
    unsigned long length;
} watermark_metadata_t;

watermark_t generate_watermark(char* message) {
    watermark_t watermark = {0};
    int message_length = strlen(message);

    int index = 0;
    for(int i = 0; i < WATERMARK_SIZE; i++) {
        if(index >= message_length) {
            index = 0;
        }
        watermark.data[i % 8] |= (message[index] << (i % 8));
        index++;
    }

    return watermark;
}

void embed_watermark(char* input_filename, char* output_filename, char* watermark_message) {
    FILE* input_file = fopen(input_filename, "rb");
    FILE* output_file = fopen(output_filename, "wb");

    if(input_file == NULL) {
        printf("Unable to open input file\n");
        return;
    }

    if(output_file == NULL) {
        printf("Unable to open output file\n");
        fclose(input_file);
        return;
    }

    watermark_t watermark = generate_watermark(watermark_message);

    fwrite(&watermark, sizeof(watermark_t), 1, output_file);

    unsigned char buffer[1024];
    size_t bytes_read;
    size_t total_bytes_read = 0;
    while((bytes_read = fread(buffer, sizeof(unsigned char), 1024, input_file)) > 0) {
        fwrite(buffer, sizeof(unsigned char), bytes_read, output_file);
        total_bytes_read += bytes_read;
    }

    watermark_metadata_t metadata = {
        .watermark = watermark,
        .offset = sizeof(watermark_t),
        .length = total_bytes_read
    };

    fseek(output_file, 0, SEEK_SET);
    fwrite(&metadata, sizeof(watermark_metadata_t), 1, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Watermark embedded successfully\n");
}

char* extract_watermark(char* filename) {
    FILE* file = fopen(filename, "rb");

    if(file == NULL) {
        printf("Unable to open file\n");
        return NULL;
    }

    watermark_metadata_t metadata;
    fread(&metadata, sizeof(watermark_metadata_t), 1, file);
    rewind(file);

    unsigned char* buffer = malloc(metadata.length);
    fread(buffer, sizeof(unsigned char), metadata.length, file);

    unsigned char* watermark_buffer = malloc(WATERMARK_SIZE);
    memcpy(watermark_buffer, metadata.watermark.data, WATERMARK_SIZE);
    
    char* watermark_message = malloc(WATERMARK_SIZE / 8);
    memset(watermark_message, 0, WATERMARK_SIZE / 8);

    int index = 0;
    for(int i = 0; i < WATERMARK_SIZE; i++) {
        watermark_message[index] |= ((watermark_buffer[i % 8] >> (i % 8)) & 1) << (i / 8);
    }

    fclose(file);
    
    printf("Watermark extracted successfully\n");

    return watermark_message;
}

int main(int argc, char** argv) {
    if(argc < 3) {
        printf("Usage: %s <input file> <output file> [message]\n", argv[0]);
        return 0;
    }

    if(argc == 4) {
        char* message = argv[3];
        embed_watermark(argv[1], argv[2], message);
    } else {
        char* message = extract_watermark(argv[1]);
        printf("Extracted message: %s\n", message);
        free(message);
    }

    return 0;
}