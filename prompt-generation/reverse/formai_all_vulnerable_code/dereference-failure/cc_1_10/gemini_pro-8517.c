//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILE_NAME_LENGTH 256

typedef struct file_header {
    char name[MAX_FILE_NAME_LENGTH];
    unsigned int size;
    unsigned int offset;
} file_header;

typedef struct data_recovery_tool {
    char *disk_image;
    unsigned int disk_image_size;
    file_header *files;
    unsigned int num_files;
} data_recovery_tool;

data_recovery_tool *create_data_recovery_tool(char *disk_image, unsigned int disk_image_size) {
    data_recovery_tool *tool = malloc(sizeof(data_recovery_tool));
    tool->disk_image = disk_image;
    tool->disk_image_size = disk_image_size;
    tool->files = NULL;
    tool->num_files = 0;
    return tool;
}

void destroy_data_recovery_tool(data_recovery_tool *tool) {
    free(tool->files);
    free(tool);
}

bool load_files(data_recovery_tool *tool) {
    unsigned int offset = 0;
    while (offset < tool->disk_image_size) {
        file_header *file = (file_header *)(tool->disk_image + offset);
        if (file->size == 0) {
            break;
        }
        tool->files = realloc(tool->files, (tool->num_files + 1) * sizeof(file_header));
        tool->files[tool->num_files] = *file;
        tool->num_files++;
        offset += sizeof(file_header) + file->size;
    }
    return true;
}

void print_files(data_recovery_tool *tool) {
    for (unsigned int i = 0; i < tool->num_files; i++) {
        file_header *file = &tool->files[i];
        printf("%s (%u bytes)\n", file->name, file->size);
    }
}

void recover_file(data_recovery_tool *tool, char *file_name) {
    for (unsigned int i = 0; i < tool->num_files; i++) {
        file_header *file = &tool->files[i];
        if (strcmp(file->name, file_name) == 0) {
            FILE *fp = fopen(file_name, "wb");
            if (fp == NULL) {
                perror("fopen");
                return;
            }
            fwrite(tool->disk_image + file->offset, file->size, 1, fp);
            fclose(fp);
            return;
        }
    }
    printf("File not found.\n");
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <disk image> <file name>\n", argv[0]);
        return 1;
    }

    char *disk_image = argv[1];
    char *file_name = argv[2];

    FILE *fp = fopen(disk_image, "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    unsigned int disk_image_size = ftell(fp);
    rewind(fp);

    char *disk_image_buffer = malloc(disk_image_size);
    if (disk_image_buffer == NULL) {
        perror("malloc");
        fclose(fp);
        return 1;
    }
    fread(disk_image_buffer, disk_image_size, 1, fp);
    fclose(fp);

    data_recovery_tool *tool = create_data_recovery_tool(disk_image_buffer, disk_image_size);
    load_files(tool);
    recover_file(tool, file_name);
    destroy_data_recovery_tool(tool);

    return 0;
}