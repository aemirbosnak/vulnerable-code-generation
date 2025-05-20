//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 256

/* Struct for holding file/directory info */
typedef struct {
    char path[MAX_PATH];
    off_t size;
} FileInfo;

int compare(const void *p, const void *q) { 
    return (((FileInfo *)q)->size - ((FileInfo *)p)->size);
}

int main(int argc, char *argv[]) {
    char *dir_path;
    if (argc > 1) {
        dir_path = argv[1];
    } else {
        dir_path = ".";
    }

    int num_files = 0;
    struct dirent *dptr;
    DIR *dir = opendir(dir_path);

    if (dir == NULL) {
        printf("Could not open directory.\n");
        exit(1);
    }

    /* Count number of files in directory */
    while ((dptr = readdir(dir)) != NULL) {
        if (dptr->d_type == DT_REG) {
            num_files++;
        }
    }

    FileInfo *files = malloc(sizeof(FileInfo) * num_files);
    int i = 0;

    rewinddir(dir); /* Reset directory stream */

    /* Fill FileInfo struct with file info */
    while ((dptr = readdir(dir)) != NULL) {
        if (dptr->d_type == DT_REG) {
            strcpy(files[i].path, dir_path);
            strcat(files[i].path, "/");
            strcat(files[i].path, dptr->d_name);

            struct stat st;
            if (stat(files[i].path, &st) == 0) {
                files[i].size = st.st_size;
            } else {
                files[i].size = -1;
            }

            i++;
        }
    }

    qsort(files, num_files, sizeof(FileInfo), compare); /* Sort by size */

    /* Print top 10 largest files */
    for (i = 0; i < 10; i++) {
        if (files[i].size == -1) {
            break; /* End of files */
        }

        printf("%s: %ld bytes\n", files[i].path, files[i].size);
    }

    free(files);
    closedir(dir);

    return 0;
}