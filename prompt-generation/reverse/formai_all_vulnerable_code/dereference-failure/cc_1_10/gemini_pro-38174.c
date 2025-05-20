//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_PATH_LEN 1024

typedef struct FileInfo {
    char path[MAX_PATH_LEN];
    time_t mtime;
    size_t size;
} FileInfo;

// Function to compare two FileInfo structures based on mtime
int compareFiles(const void *a, const void *b) {
    const FileInfo *fa = (const FileInfo *)a;
    const FileInfo *fb = (const FileInfo *)b;

    return (fa->mtime - fb->mtime);
}

// Function to get the file information for a given path
void getFileInfo(const char *path, FileInfo *info) {
    struct stat buf;
    if (stat(path, &buf) == -1) {
        perror("stat");
        exit(1);
    }

    strcpy(info->path, path);
    info->mtime = buf.st_mtime;
    info->size = buf.st_size;
}

// Function to copy a file from one path to another
void copyFile(const char *src, const char *dst) {
    FILE *f1, *f2;
    int c;

    f1 = fopen(src, "rb");
    if (f1 == NULL) {
        perror("fopen");
        exit(1);
    }

    f2 = fopen(dst, "wb");
    if (f2 == NULL) {
        perror("fopen");
        exit(1);
    }

    while ((c = fgetc(f1)) != EOF) {
        fputc(c, f2);
    }

    fclose(f1);
    fclose(f2);
}

// Function to synchronize two directories
void syncDirs(const char *dir1, const char *dir2) {
    DIR *d1, *d2;
    struct dirent *ent1, *ent2;
    FileInfo *files1, *files2;
    int numFiles1, numFiles2;
    int i, j, k;

    // Open the directories
    d1 = opendir(dir1);
    if (d1 == NULL) {
        perror("opendir");
        exit(1);
    }

    d2 = opendir(dir2);
    if (d2 == NULL) {
        perror("opendir");
        exit(1);
    }

    // Get the list of files in the first directory
    numFiles1 = 0;
    while ((ent1 = readdir(d1)) != NULL) {
        if (strcmp(ent1->d_name, ".") == 0 || strcmp(ent1->d_name, "..") == 0) {
            continue;
        }

        numFiles1++;
    }
    rewinddir(d1);

    files1 = malloc(sizeof(FileInfo) * numFiles1);
    if (files1 == NULL) {
        perror("malloc");
        exit(1);
    }

    i = 0;
    while ((ent1 = readdir(d1)) != NULL) {
        if (strcmp(ent1->d_name, ".") == 0 || strcmp(ent1->d_name, "..") == 0) {
            continue;
        }

        getFileInfo(ent1->d_name, &files1[i]);
        i++;
    }
    closedir(d1);

    // Get the list of files in the second directory
    numFiles2 = 0;
    while ((ent2 = readdir(d2)) != NULL) {
        if (strcmp(ent2->d_name, ".") == 0 || strcmp(ent2->d_name, "..") == 0) {
            continue;
        }

        numFiles2++;
    }
    rewinddir(d2);

    files2 = malloc(sizeof(FileInfo) * numFiles2);
    if (files2 == NULL) {
        perror("malloc");
        exit(1);
    }

    j = 0;
    while ((ent2 = readdir(d2)) != NULL) {
        if (strcmp(ent2->d_name, ".") == 0 || strcmp(ent2->d_name, "..") == 0) {
            continue;
        }

        getFileInfo(ent2->d_name, &files2[j]);
        j++;
    }
    closedir(d2);

    // Sort the arrays of files by mtime
    qsort(files1, numFiles1, sizeof(FileInfo), compareFiles);
    qsort(files2, numFiles2, sizeof(FileInfo), compareFiles);

    // Synchronize the directories
    i = 0;
    j = 0;
    while (i < numFiles1 && j < numFiles2) {
        if (strcmp(files1[i].path, files2[j].path) == 0) {
            // The files are the same, so skip them
            i++;
            j++;
        } else if (files1[i].mtime > files2[j].mtime) {
            // The file in the first directory is newer, so copy it to the second directory
            copyFile(files1[i].path, files2[j].path);
            j++;
        } else {
            // The file in the second directory is newer, so copy it to the first directory
            copyFile(files1[i].path, files2[j].path);
            i++;
        }
    }

    // Copy any remaining files from the first directory to the second directory
    while (i < numFiles1) {
        copyFile(files1[i].path, files2[j].path);
        j++;
        i++;
    }

    // Copy any remaining files from the second directory to the first directory
    while (j < numFiles2) {
        copyFile(files2[j].path, files1[j].path);
        i++;
        j++;
    }

    // Free the memory allocated for the arrays of files
    free(files1);
    free(files2);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s dir1 dir2\n", argv[0]);
        exit(1);
    }

    syncDirs(argv[1], argv[2]);

    return 0;
}