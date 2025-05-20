//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_LOG_SIZE 1024
#define MAX_LOG_FILES 100

typedef struct {
    char filename[1024];
    time_t last_modified;
    int size;
} log_file_t;

int compare_log_files(const void *a, const void *b) {
    log_file_t *file_a = (log_file_t *)a;
    log_file_t *file_b = (log_file_t *)b;

    if (file_a->last_modified > file_b->last_modified) {
        return -1;
    } else if (file_a->last_modified < file_b->last_modified) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    DIR *dir;
    struct dirent *ent;
    log_file_t log_files[MAX_LOG_FILES];
    int num_log_files = 0;

    dir = opendir("./logs");

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                if (num_log_files >= MAX_LOG_FILES) {
                    break;
                }

                strcpy(log_files[num_log_files].filename, ent->d_name);
                log_files[num_log_files].last_modified = 0;
                log_files[num_log_files].size = 0;

                struct stat file_stat;
                stat(log_files[num_log_files].filename, &file_stat);
                log_files[num_log_files].last_modified = file_stat.st_mtime;
                log_files[num_log_files].size = file_stat.st_size;

                num_log_files++;
            }
        }

        closedir(dir);

        qsort(log_files, num_log_files, sizeof(log_file_t), compare_log_files);

        for (int i = 0; i < num_log_files; i++) {
            printf("Filename: %s\n", log_files[i].filename);
            printf("Last Modified: %s", ctime(&log_files[i].last_modified));
            printf("Size: %d bytes\n\n", log_files[i].size);
        }
    } else {
        perror("");
        exit(EXIT_FAILURE);
    }

    return 0;
}