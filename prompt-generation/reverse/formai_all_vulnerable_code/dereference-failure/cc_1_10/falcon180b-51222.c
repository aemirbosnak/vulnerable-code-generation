//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 1024
#define MAX_FILE_PATH_LENGTH 2048
#define VIRUS_NAME "virus.txt"
#define VIRUS_SIZE 1024

typedef struct {
    char *file_path;
    char *file_name;
    int file_size;
} FileInfo;

void search_directory(char *directory_path, int depth) {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_FILE_PATH_LENGTH];

    if ((dir = opendir(directory_path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                if (depth > 0) {
                    sprintf(path, "%s/%s", directory_path, ent->d_name);
                    search_directory(path, depth - 1);
                }
            } else {
                FileInfo file_info;
                sprintf(path, "%s/%s", directory_path, ent->d_name);
                file_info.file_path = strdup(path);
                file_info.file_name = strdup(ent->d_name);
                file_info.file_size = ent->d_reclen;

                if (is_virus(file_info)) {
                    printf("Virus found in file: %s\n", file_info.file_path);
                }

                free(file_info.file_path);
                free(file_info.file_name);
            }
        }

        closedir(dir);
    }
}

int is_virus(FileInfo file_info) {
    FILE *file;
    char buffer[VIRUS_SIZE];

    file = fopen(file_info.file_path, "rb");

    if (file == NULL) {
        return 0;
    }

    fseek(file, 0, SEEK_SET);
    fread(buffer, VIRUS_SIZE, 1, file);

    if (memcmp(buffer, VIRUS_NAME, strlen(VIRUS_NAME)) == 0) {
        return 1;
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [directory_path]\n", argv[0]);
        return 1;
    }

    search_directory(argv[1], 999);

    return 0;
}