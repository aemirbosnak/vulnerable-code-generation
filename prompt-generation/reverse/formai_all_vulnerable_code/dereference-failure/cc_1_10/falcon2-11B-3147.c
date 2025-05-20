//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

typedef struct {
    char path[1024];
    char filename[1024];
    int size;
} FileInfo;

void scan_directory(const char* path, FileInfo* file_info) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char* sub_path = malloc(strlen(path) + strlen(ent->d_name) + 1);
            strcpy(sub_path, path);
            strcat(sub_path, "/");
            strcat(sub_path, ent->d_name);
            scan_directory(sub_path, file_info);
            free(sub_path);
        } else if (ent->d_type == DT_REG) {
            char* filename = malloc(strlen(path) + strlen(ent->d_name) + 1);
            strcpy(filename, path);
            strcat(filename, "/");
            strcat(filename, ent->d_name);
            struct stat file_stat;
            if (stat(filename, &file_stat) == -1) {
                printf("Corrupted file: %s\n", filename);
            } else {
                char* recovered_filename = malloc(file_stat.st_size + 1);
                strcpy(recovered_filename, filename);
                memset(recovered_filename + strlen(filename), 0, file_stat.st_size);
                char* recovered_file = malloc(file_stat.st_size + 1);
                read(fileno(stdin), recovered_filename, file_stat.st_size);
                write(fileno(stdout), recovered_file, file_stat.st_size);
                printf("Recovered file: %s\n", filename);
            }
            free(filename);
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    const char* directory = argv[1];
    FileInfo file_info[100];
    scan_directory(directory, file_info);
    return 0;
}