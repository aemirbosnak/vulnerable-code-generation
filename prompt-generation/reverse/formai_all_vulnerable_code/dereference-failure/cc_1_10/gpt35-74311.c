//FormAI DATASET v1.0 Category: Data recovery tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_MAX_SIZE 256
#define BUFFER_SIZE 512

struct FileInfo {
    char* filename;
    char* filetype;
    long filesize;
};

void recover_data(char* source_file_path, char* destination_folder_path, char* search_file_extension) {
    FILE* source_file = fopen(source_file_path, "rb");
    if (!source_file) {
        printf("ERROR: Unable to open file at \"%s\"\n", source_file_path);
        return;
    }

    fseek(source_file, 0, SEEK_END);
    long file_size = ftell(source_file);
    fseek(source_file, 0, SEEK_SET);

    char source_file_name[FILENAME_MAX_SIZE];
    strcpy(source_file_name, strtok(source_file_path, "."));
    struct FileInfo* file_list = malloc(sizeof(struct FileInfo));
    int file_list_size = 0;

    while (ftell(source_file) < file_size) {
        char buffer[BUFFER_SIZE];
        fread(buffer, 1, BUFFER_SIZE, source_file);

        char* file_header = strtok(buffer, "\n");
        if (strstr(file_header, search_file_extension)) {
            char* file_name = strtok(NULL, "\n");
            char* file_size_str = strtok(NULL, "\n");
            long file_size = strtol(file_size_str, NULL, 10);

            char file_type[strlen(file_header) - strlen(search_file_extension) - 1];
            strncpy(file_type, file_header, strlen(file_header) - strlen(search_file_extension) - 1);

            char file_path[strlen(destination_folder_path) + strlen(file_name) + 2];
            sprintf(file_path, "%s/%s", destination_folder_path, file_name);

            struct FileInfo new_file = {file_name, file_type, file_size};
            file_list_size++;
            file_list = realloc(file_list, sizeof(struct FileInfo) * file_list_size);
            file_list[file_list_size - 1] = new_file;

            FILE* new_file_pointer = fopen(file_path, "wb");
            if (!new_file_pointer) {
                printf("ERROR: Unable to create new file at \"%s\"\n", file_path);
                continue;
            }

            fwrite(buffer + strlen(file_header) + strlen(file_name) + strlen(file_size_str) + 3, 1, file_size, new_file_pointer);
            fclose(new_file_pointer);
        }
    }

    fclose(source_file);

    printf("Recovered %d files from \"%s\"\n", file_list_size, source_file_name);
    printf("Details:\n");
    for (int i = 0; i < file_list_size; i++) {
        printf("\t%s.%s - %ld bytes\n", file_list[i].filename, file_list[i].filetype, file_list[i].filesize);
    }
}

int main(int argc, char const *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <source file> <destination folder> <search file extension>\n", argv[0]);
        return 1;
    }

    recover_data(argv[1], argv[2], argv[3]);

    return 0;
}