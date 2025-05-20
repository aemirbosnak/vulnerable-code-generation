//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define BLOCK_SIZE 512

typedef struct {
    char filename[100];
    int blocks;
    int file_size;
    int data_start;
    int data_end;
    int lost_blocks;
    int lost_data;
} FileInfo;

void search_lost_blocks(FileInfo* file_info) {
    FILE* file = fopen(file_info->filename, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", file_info->filename);
        exit(1);
    }

    int lost_count = 0;
    int lost_data_count = 0;
    int data_start = 0;
    int data_end = 0;

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    if (file_info->data_start > file_size) {
        printf("Data start position is invalid\n");
        exit(1);
    }

    if (file_info->data_end > file_size) {
        printf("Data end position is invalid\n");
        exit(1);
    }

    if (file_info->data_start >= file_info->data_end) {
        printf("Data range is invalid\n");
        exit(1);
    }

    fseek(file, file_info->data_start, SEEK_SET);
    char buffer[BLOCK_SIZE];
    int block_count = 0;

    while (fread(buffer, BLOCK_SIZE, 1, file) == 1) {
        if (memcmp(buffer, "LOST", 4) == 0) {
            lost_count++;
            lost_data_count += BLOCK_SIZE;
        }

        data_start = ftell(file);

        if (data_start >= file_info->data_start && data_start <= file_info->data_end) {
            if (memcmp(buffer, "DATA", 4) == 0) {
                lost_data_count -= BLOCK_SIZE;
            }
        }

        block_count++;
        data_end = data_start + BLOCK_SIZE - 1;

        if (data_end >= file_info->data_end) {
            break;
        }
    }

    if (lost_count > 0) {
        printf("Lost blocks found: %d\n", lost_count);
    }

    if (lost_data_count > 0) {
        printf("Lost data found: %d bytes\n", lost_data_count);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <data_start> <data_end>\n", argv[0]);
        return 1;
    }

    FileInfo file_info;
    strcpy(file_info.filename, argv[1]);
    file_info.data_start = atoi(argv[2]);
    file_info.data_end = atoi(argv[3]);

    search_lost_blocks(&file_info);

    return 0;
}