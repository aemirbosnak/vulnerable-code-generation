//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

// Function to get human-readable file size
void getReadableSize(double size, char *buf)
{
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int i;
    double fraction;

    for (i = 0; size >= 1024 && i < 4; i++, size /= 1024);

    fraction = size - (int)size;
    if (fraction > 0.1) {
        sprintf(buf, "%.1f %s", size, units[i]);
    } else {
        sprintf(buf, "%.0f %s", size, units[i]);
    }
}

// Function to list files in a directory
void listFiles(char *dirPath, int *numFilesPtr, struct dirent ***filesPtr)
{
    int numFiles = 0;
    struct dirent **files;
    struct stat st;

    DIR *dir = opendir(dirPath);

    if (dir == NULL) {
        fprintf(stderr, "Unable to open directory: %s\n", dirPath);
        exit(EXIT_FAILURE);
    }

    while (1) {
        struct dirent *entry = readdir(dir);

        if (entry == NULL) {
            break;
        }

        // Skip hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        char fullPath[1024];
        sprintf(fullPath, "%s/%s", dirPath, entry->d_name);

        if (stat(fullPath, &st) == -1) {
            fprintf(stderr, "Unable to stat file: %s\n", fullPath);
            exit(EXIT_FAILURE);
        }

        if (S_ISDIR(st.st_mode)) {
            listFiles(fullPath, &numFiles, &files);
        } else {
            numFiles++;
            files = realloc(files, numFiles * sizeof(*files));
            files[numFiles - 1] = entry;
        }
    }

    closedir(dir);

    *numFilesPtr = numFiles;
    *filesPtr = files;
}

// Function to sort files based on size (descending)
int compareSizes(const void *p1, const void *p2)
{
    struct stat *st1 = (struct stat *)((*(struct dirent **)p1)->d_name);
    struct stat *st2 = (struct stat *)((*(struct dirent **)p2)->d_name);

    if (st1->st_size < st2->st_size) {
        return 1;
    } else if (st1->st_size > st2->st_size) {
        return -1;
    }

    return 0;
}

// Output file size and timestamp information
void outputFileInfo(char *fileName, struct stat st)
{
    char sizeBuf[32];
    char timeStr[32];

    getReadableSize(st.st_size, sizeBuf);
    strftime(timeStr, 32, "%Y-%m-%d %H:%M:%S", localtime(&st.st_ctime));

    printf("%-60s %10s %s\n", fileName, sizeBuf, timeStr);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *dirPath = argv[1];
    struct dirent **files;
    int numFiles;

    listFiles(dirPath, &numFiles, &files);

    printf("Total files: %d\n", numFiles);

    qsort(files, numFiles, sizeof(*files), compareSizes);

    double sizeTotal = 0;

    for (int i = 0; i < numFiles; i++) {
        char fullPath[1024];
        sprintf(fullPath, "%s/%s", dirPath, files[i]->d_name);

        struct stat st;
        if (stat(fullPath, &st) == -1) {
            fprintf(stderr, "Unable to stat file: %s\n", fullPath);
            exit(EXIT_FAILURE);
        }

        outputFileInfo(files[i]->d_name, st);

        sizeTotal += st.st_size;
    }

    char sizeBuf[32];
    getReadableSize(sizeTotal, sizeBuf);
    printf("\nTotal size: %s\n", sizeBuf);

    return 0;
}