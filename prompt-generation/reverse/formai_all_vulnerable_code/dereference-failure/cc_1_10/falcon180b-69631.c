//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10MB

typedef struct {
    char *name;
    unsigned long size;
    char *data;
} FILE_INFO;

void read_file(FILE *fp, FILE_INFO *file_info) {
    char buffer[1024];
    unsigned long file_size = 0;

    while (fread(buffer, 1, 1024, fp) > 0) {
        file_size += 1024;

        if (file_size > MAX_FILE_SIZE) {
            break;
        }

        file_info->data = realloc(file_info->data, file_size + 1);
        memcpy(file_info->data + file_info->size, buffer, 1024);
        file_info->size += 1024;
    }

    file_info->data[file_info->size] = '\0';
}

int is_virus(char *data) {
    char *virus_signature = "This is a virus";
    int virus_signature_length = strlen(virus_signature);

    for (int i = 0; i < strlen(data) - virus_signature_length + 1; i++) {
        if (strncmp(data + i, virus_signature, virus_signature_length) == 0) {
            return 1;
        }
    }

    return 0;
}

void print_file_info(FILE_INFO *file_info) {
    printf("File name: %s\n", file_info->name);
    printf("File size: %lu bytes\n", file_info->size);

    if (is_virus(file_info->data)) {
        printf("Virus found!\n");
    } else {
        printf("No virus found.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    FILE_INFO file_info = {0};

    read_file(fp, &file_info);

    fclose(fp);

    print_file_info(&file_info);

    free(file_info.data);

    return 0;
}