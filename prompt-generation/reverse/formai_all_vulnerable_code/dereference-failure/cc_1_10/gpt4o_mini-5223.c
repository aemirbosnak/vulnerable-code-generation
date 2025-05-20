//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_FILES 2048

typedef struct {
    char **files;
    int count;
} FileList;

void initializeFileList(FileList *fl) {
    fl->files = malloc(MAX_FILES * sizeof(char *));
    fl->count = 0;
}

void destroyFileList(FileList *fl) {
    for (int i = 0; i < fl->count; i++) {
        free(fl->files[i]);
    }
    free(fl->files);
}

void addFile(FileList *fl, const char *file) {
    if (fl->count < MAX_FILES) {
        fl->files[fl->count] = malloc(strlen(file) + 1);
        strcpy(fl->files[fl->count], file);
        fl->count++;
    } else {
        printf("File list exceeded maximum limit!\n");
    }
}

int compareFiles(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "rb");
    FILE *f2 = fopen(file2, "rb");
    if (f1 == NULL || f2 == NULL) {
        return -1; // Error opening files
    }

    int result = 0;
    char ch1, ch2;

    while (!feof(f1) && !feof(f2)) {
        ch1 = fgetc(f1);
        ch2 = fgetc(f2);
        if (ch1 != ch2) {
            result = 1; // Files are different
            break;
        }
    }

    if (!feof(f1) || !feof(f2)) {
        result = 1; // Files are of different lengths
    }

    fclose(f1);
    fclose(f2);
    return result;
}

void synchronizeFiles(const char *srcDir, const char *dstDir) {
    DIR *dir = opendir(srcDir);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Failed to open source directory");
        return;
    }

    FileList srcFiles, dstFiles;
    initializeFileList(&srcFiles);
    initializeFileList(&dstFiles);

    // Gather files from source directory
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char fullPath[MAX_PATH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", srcDir, entry->d_name);
            addFile(&srcFiles, fullPath);
        }
    }
    closedir(dir);

    // Gather files from destination directory
    dir = opendir(dstDir);
    if (dir == NULL) {
        perror("Failed to open destination directory");
        destroyFileList(&srcFiles);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char fullPath[MAX_PATH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", dstDir, entry->d_name);
            addFile(&dstFiles, fullPath);
        }
    }
    closedir(dir);

    // Synchronizing Files
    for (int i = 0; i < srcFiles.count; i++) {
        char *srcFileName = strrchr(srcFiles.files[i], '/') + 1;
        char dstFull[MAX_PATH];
        snprintf(dstFull, sizeof(dstFull), "%s/%s", dstDir, srcFileName);

        int found = 0;
        for (int j = 0; j < dstFiles.count; j++) {
            if (strcmp(dstFiles.files[j], dstFull) == 0) {
                found = 1;
                break;
            }
        }

        if (!found || compareFiles(srcFiles.files[i], dstFull) != 0) {
            FILE *srcFile = fopen(srcFiles.files[i], "rb");
            FILE *dstFile = fopen(dstFull, "wb");
            if (srcFile && dstFile) {
                char buffer[1024];
                size_t bytesRead;

                while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
                    fwrite(buffer, 1, bytesRead, dstFile);
                }

                fclose(srcFile);
                fclose(dstFile);
                printf("Synchronized: %s -> %s\n", srcFiles.files[i], dstFull);
            } else {
                perror("Error opening files for copy");
            }
        }
    }

    destroyFileList(&srcFiles);
    destroyFileList(&dstFiles);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    synchronizeFiles(argv[1], argv[2]);

    return 0;
}