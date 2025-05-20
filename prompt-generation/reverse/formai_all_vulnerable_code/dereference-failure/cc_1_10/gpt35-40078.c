//FormAI DATASET v1.0 Category: Data recovery tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512 // size of each block to read

// struct to store information about a file
typedef struct file_info {
    char name[100];
    long long size;
} file_info;

// function to read file information from a disk image
int read_file_info(FILE* f, file_info* file_arr, int file_arr_len, int* valid_files) {
    int count = 0;
    int offset = 0;

    while (1) {
        char block[BLOCK_SIZE];
        fseek(f, offset, SEEK_SET);
        fread(block, BLOCK_SIZE, 1, f);

        // if the block is empty, we have reached the end of the valid file entries
        if (block[0] == '\0') {
            break;
        }

        // check if the first byte is a null terminator, indicating a deleted file
        if (block[0] == 0xe5) {
            offset += BLOCK_SIZE;
            continue;
        }

        // check if the file is a valid file
        if (block[11] == 0x20 || block[11] == 0x10) {
            // get the file name and size
            char name[100];
            long long size = *((long long*)(block + 28));

            int i;
            for (i = 0; i < 8; i++) {
                if (block[i] == ' ') {
                    break;
                }
                name[i] = block[i];
            }
            if (block[8] != ' ') {
                name[i++] = '.';
                for (; i < 11; i++) {
                    name[i] = block[i - 1];
                }
            }
            name[i] = '\0';

            // ignore directories
            if (block[11] == 0x10) {
                offset += BLOCK_SIZE;
                continue;
            }

            // store the file information
            file_info* info = file_arr + count++;
            strncpy(info->name, name, 100);
            info->size = size;

            // if we have found all the valid files, stop searching
            if (count == file_arr_len) {
                break;
            }
        }

        offset += BLOCK_SIZE;
    }

    *valid_files = count;
    return fseek(f, 0, SEEK_SET);
}

// function to retrieve the content of a file
int read_file_data(FILE* f, file_info file, char* buffer) {
    int offset = 0;
    int blocks = file.size / BLOCK_SIZE + 1;

    // read the file blocks
    for (int i = 0; i < blocks; i++) {
        fseek(f, (int)((file.size / BLOCK_SIZE) + 1) * i, SEEK_SET);
        fread(buffer + i * BLOCK_SIZE, BLOCK_SIZE, 1, f);
    }

    return 0;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <disk_image> <file_name>\n", argv[0]);
        return 1;
    }

    // open the disk image
    FILE* f = fopen(argv[1], "rb");
    if (f == NULL) {
        fprintf(stderr, "Unable to open file %s\n", argv[1]);
        return 1;
    }

    // read the file information
    int file_count;
    file_info file_arr[100];
    read_file_info(f, file_arr, 100, &file_count);

    // search for the file
    char* file_name = argv[2];
    int found_file = 0;
    file_info file;
    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_arr[i].name, file_name) == 0) {
            file = file_arr[i];
            found_file = 1;
            break;
        }
    }

    if (!found_file) {
        fprintf(stderr, "Unable to find file %s\n", file_name);
        return 1;
    }

    // retrieve the file data and print it to stdout
    char* buffer = malloc(file.size);
    read_file_data(f, file, buffer);
    fwrite(buffer, file.size, 1, stdout);

    free(buffer);
    fclose(f);

    return 0;
}