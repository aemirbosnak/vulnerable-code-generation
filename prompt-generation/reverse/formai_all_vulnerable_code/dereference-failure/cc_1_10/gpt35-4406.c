//FormAI DATASET v1.0 Category: Data recovery tool ; Style: synchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 4096

typedef struct file_s {
    char* name;
    int size;
    struct file_s* next;
} file_t;

void recover_files(char* disk_image_path) {
    FILE* disk_image_file = fopen(disk_image_path, "rb");
    if (!disk_image_file) {
        printf("Failed to open disk image file\n");
        exit(1);
    }

    int total_blocks;
    fread(&total_blocks, sizeof(int), 1, disk_image_file);

    file_t* head = NULL;
    file_t* tail = NULL;

    for (int block_index = 0; block_index < total_blocks; block_index++) {
        char block_data[BLOCK_SIZE];
        fread(block_data, BLOCK_SIZE, 1, disk_image_file);

        for (int i = 0; i < BLOCK_SIZE - 3; i++) {
            if (block_data[i] == 'F' && block_data[i + 1] == 'I' && block_data[i + 2] == 'L' && block_data[i + 3] == 'E') {
                char* file_name = malloc(sizeof(char) * 50);
                int file_size;
                memcpy(file_name, &block_data[i + 5], 50);
                memcpy(&file_size, &block_data[i + 55], sizeof(int));
                file_size = file_size < BLOCK_SIZE ? file_size : BLOCK_SIZE - 100;

                file_t* new_file = malloc(sizeof(file_t));
                new_file->name = file_name;
                new_file->size = file_size;
                new_file->next = NULL;

                if (!head) {
                    head = new_file;
                    tail = new_file;
                } else {
                    tail->next = new_file;
                    tail = new_file;
                }

                char file_data[BLOCK_SIZE - 100];
                memcpy(file_data, &block_data[i + 59], file_size);

                int remaining_size = file_size - (BLOCK_SIZE - 100);
                while (remaining_size > 0) {
                    fread(block_data, BLOCK_SIZE, 1, disk_image_file);
                    if (remaining_size < BLOCK_SIZE) {
                        memcpy(file_data + file_size - remaining_size, block_data, remaining_size);
                        remaining_size = 0;
                    } else {
                        memcpy(file_data + file_size - remaining_size, block_data, BLOCK_SIZE);
                        remaining_size -= BLOCK_SIZE;
                    }
                }

                FILE* file = fopen(file_name, "wb");
                fwrite(file_data, file_size, 1, file);
                fclose(file);
            }
        }
    }

    file_t* current_file = head;
    while (current_file) {
        printf("Recovered file: %s\n", current_file->name);
        file_t* next_file = current_file->next;
        free(current_file);
        current_file = next_file;
    }

    fclose(disk_image_file);
}

int main() {
    printf("Attempting to recover files...\n");
    recover_files("disk_image.bin");
    printf("File recovery completed!\n");
    return 0;
}