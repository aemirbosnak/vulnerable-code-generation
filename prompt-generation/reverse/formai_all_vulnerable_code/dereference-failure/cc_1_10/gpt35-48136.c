//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#define KB 1024
#define MB 1048576
#define GB 1073741824

typedef struct file {
    char *name;
    off_t size;
} file;

int getFileSize(const char *path, off_t *size) {
    struct stat st;

    if (lstat(path, &st) == 0) {
        *size = st.st_size;
        return 0;
    } else {
        return -1;
    }
}

file *newFile(char *name, off_t size) {
    file *f = (file*) malloc(sizeof(file));
    if (f == NULL) {
        printf("Error: memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    f->name = strdup(name);
    f->size = size;

    return f;
}

void deleteFile(file *f) {
    free(f->name);
    free(f);
}

int compareFiles(const void *a, const void *b) {
    file *f1 = *(file**) a;
    file *f2 = *(file**) b;

    if (f1->size > f2->size) {
        return -1;
    } else if (f1->size < f2->size) {
        return 1;
    } else {
        return 0;
    }
}

void printFileSize(off_t size) {
    if (size < KB) {
        printf("%ld B", size);
    } else if (size < MB) {
        printf("%ld KB", size/KB);
    } else if (size < GB) {
        printf("%ld MB", size/MB);
    } else {
        printf("%ld GB", size/GB);
    }
}

void printUsage() {
    printf("Usage: disk-analyzer <directory> [--descending | --ascending]\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printUsage();
        return EXIT_FAILURE;
    }

    char *dirPath = argv[1];

    int sortDescending = 1;
    if (argc >= 3) {
        if (strcmp(argv[2], "--ascending") == 0) {
            sortDescending = 0;
        } else if (strcmp(argv[2], "--descending") != 0) {
            printUsage();
            return EXIT_FAILURE;
        }
    }

    DIR *dir = opendir(dirPath);
    if (dir == NULL) {
        printf("Error: could not open directory '%s'", dirPath);
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    char *filePath;
    off_t fileSize;
    file **files = (file**) malloc(sizeof(file*) * 100);
    int numFiles = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            filePath = (char*) malloc(strlen(dirPath) + strlen(entry->d_name) + 2);
            sprintf(filePath, "%s/%s", dirPath, entry->d_name);
            if (getFileSize(filePath, &fileSize) == 0) {
                files[numFiles++] = newFile(filePath, fileSize);
            }
        }
    }
    closedir(dir);

    qsort(files, numFiles, sizeof(file*), compareFiles);

    printf("%-70s %15s\n", "File", "Size");
    printf("------------------------------------------------------------------------\n");
    int i;
    for (i = 0; i < numFiles; i++) {
        printf("%-70s ", files[i]->name);
        printFileSize(files[i]->size);
        printf("\n");
    }

    for (i = 0; i < numFiles; i++) {
        deleteFile(files[i]);
    }
    free(files);

    return EXIT_SUCCESS;
}