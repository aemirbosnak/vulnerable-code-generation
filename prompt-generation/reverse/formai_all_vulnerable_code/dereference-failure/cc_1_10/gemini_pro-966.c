//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

typedef struct {
    char *name;
    long int size;
} file_t;

int compare_files(const void *a, const void *b)
{
    file_t *fa = (file_t *)a;
    file_t *fb = (file_t *)b;

    return fb->size - fa->size;
}

int main()
{
    DIR *dir;
    struct dirent *ent;
    char path[256];
    file_t files[1024];
    int file_count = 0;
    long int total_size = 0;

    printf("C Disk Space Analyzer\n");
    printf("---------------------\n");

    getcwd(path, sizeof(path));
    dir = opendir(path);

    if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }

            files[file_count].name = strdup(ent->d_name);
            files[file_count].size = 0;

            if (ent->d_type == DT_DIR) {
                // Recursively analyze subdirectories
                char subdir_path[256];
                sprintf(subdir_path, "%s/%s", path, ent->d_name);
                DIR *subdir = opendir(subdir_path);

                if (subdir != NULL) {
                    while ((ent = readdir(subdir)) != NULL) {
                        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                            continue;
                        }

                        char file_path[256];
                        sprintf(file_path, "%s/%s", subdir_path, ent->d_name);
                        FILE *file = fopen(file_path, "rb");

                        if (file != NULL) {
                            fseek(file, 0, SEEK_END);
                            files[file_count].size += ftell(file);
                            fclose(file);
                        }
                    }

                    closedir(subdir);
                }
            } else if (ent->d_type == DT_REG) {
                // Get the file size
                char file_path[256];
                sprintf(file_path, "%s/%s", path, ent->d_name);
                FILE *file = fopen(file_path, "rb");

                if (file != NULL) {
                    fseek(file, 0, SEEK_END);
                    files[file_count].size = ftell(file);
                    fclose(file);
                }
            }

            total_size += files[file_count].size;
            file_count++;
        }

        closedir(dir);
    }

    // Sort the files by size
    qsort(files, file_count, sizeof(file_t), compare_files);

    // Print the results
    printf("Total Size: %.2f MB\n", (double)total_size / 1024 / 1024);
    printf("---------------------\n");
    for (int i = 0; i < file_count; i++) {
        printf("%-20s %.2f MB\n", files[i].name, (double)files[i].size / 1024 / 1024);
        free(files[i].name);
    }

    return 0;
}