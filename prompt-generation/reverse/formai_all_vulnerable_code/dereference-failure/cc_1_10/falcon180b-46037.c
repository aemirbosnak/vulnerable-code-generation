//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_DIR_DEPTH 1000
#define MAX_FILES_PER_DIR 1000
#define MAX_THREADS 10

typedef struct {
    char path[1024];
    char *files[MAX_FILES_PER_DIR];
    int file_count;
} dir_info;

void *scan_dir_thread(void *arg) {
    dir_info *dir = (dir_info *)arg;
    DIR *d;
    struct dirent *ent;

    d = opendir(dir->path);
    if (d!= NULL) {
        while ((ent = readdir(d))!= NULL) {
            if (dir->file_count >= MAX_FILES_PER_DIR) {
                break;
            }

            if (ent->d_type == DT_REG) {
                dir->files[dir->file_count] = malloc(strlen(ent->d_name) + 1);
                strcpy(dir->files[dir->file_count], ent->d_name);
                dir->file_count++;
            }
        }
        closedir(d);
    }

    return NULL;
}

void scan_dir(char *path) {
    dir_info dir;
    pthread_t threads[MAX_THREADS];
    int i;

    strcpy(dir.path, path);
    dir.file_count = 0;

    for (i = 0; i < MAX_THREADS && dir.file_count < MAX_FILES_PER_DIR; i++) {
        pthread_create(&threads[i], NULL, scan_dir_thread, &dir);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Directory: %s\n", path);
    printf("Total files: %d\n", dir.file_count);

    for (i = 0; i < dir.file_count; i++) {
        printf("%s\n", dir.files[i]);
        free(dir.files[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    scan_dir(argv[1]);

    return 0;
}