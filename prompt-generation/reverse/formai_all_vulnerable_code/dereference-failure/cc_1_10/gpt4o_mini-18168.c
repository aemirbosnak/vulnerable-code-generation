//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    char filename[256];
    char filetype[20];
    long filesize;
} MetaData;

void getFileMetadata(const char *filepath, MetaData *meta);
void printMetadata(MetaData *meta);
void exploreDirectory(const char *dirpath);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directoryPath = argv[1];
    exploreDirectory(directoryPath);

    return EXIT_SUCCESS;
}

void exploreDirectory(const char *dirpath) {
    DIR *d;
    struct dirent *dir;
    
    d = opendir(dirpath);
    if (d) {
        printf("Exploring directory: %s\n", dirpath);
        while ((dir = readdir(d)) != NULL) {
            // Skip the special directories '.' and '..'
            if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
                char fullpath[512];
                snprintf(fullpath, sizeof(fullpath), "%s/%s", dirpath, dir->d_name);

                struct stat fileStat;
                if (stat(fullpath, &fileStat) == 0) {
                    if (S_ISDIR(fileStat.st_mode)) {
                        exploreDirectory(fullpath); // Recursive call for directories
                    } else {
                        MetaData meta;
                        getFileMetadata(fullpath, &meta);
                        printMetadata(&meta);
                    }
                } else {
                    perror("stat failed");
                }
            }
        }
        closedir(d);
    } else {
        perror("Could not open directory");
    }
}

void getFileMetadata(const char *filepath, MetaData *meta) {
    struct stat fileStat;
    if (stat(filepath, &fileStat) == 0) {
        // Copying file name
        snprintf(meta->filename, sizeof(meta->filename), "%s", filepath);
        
        // Determine file type
        if (S_ISREG(fileStat.st_mode)) {
            strcpy(meta->filetype, "Regular File");
        } else if (S_ISDIR(fileStat.st_mode)) {
            strcpy(meta->filetype, "Directory");
        } else if (S_ISCHR(fileStat.st_mode)) {
            strcpy(meta->filetype, "Character Device");
        } else if (S_ISBLK(fileStat.st_mode)) {
            strcpy(meta->filetype, "Block Device");
        } else if (S_ISFIFO(fileStat.st_mode)) {
            strcpy(meta->filetype, "FIFO");
        } else if (S_ISLNK(fileStat.st_mode)) {
            strcpy(meta->filetype, "Symbolic Link");
        } else if (S_ISSOCK(fileStat.st_mode)) {
            strcpy(meta->filetype, "Socket");
        } else {
            strcpy(meta->filetype, "Unknown");
        }
        
        // Get file size
        meta->filesize = fileStat.st_size;
    } else {
        perror("stat failed");
        strcpy(meta->filename, "Unknown");
        strcpy(meta->filetype, "Unknown");
        meta->filesize = 0;
    }
}

void printMetadata(MetaData *meta) {
    printf("File Name: %s\n", meta->filename);
    printf("File Type: %s\n", meta->filetype);
    printf("File Size: %ld bytes\n", meta->filesize);
    printf("----------------------------------\n");
}