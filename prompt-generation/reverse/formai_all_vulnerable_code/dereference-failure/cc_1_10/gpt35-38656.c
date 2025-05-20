//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: realistic
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Function to convert size in bytes to human-readable format
char* convertSize(long size) {
    static const char* SIZES[] = { "B", "KB", "MB", "GB", "TB" };
    int div = 0;
    long rem = 0;

    while (size >= 1024 && div < (sizeof SIZES / sizeof *SIZES) - 1) {
        rem = (size % 1024);
        div++;
        size /= 1024;
    }

    static char output[200];
    sprintf(output, "%.1f %s", (float)size + (float)rem / 1024.0, SIZES[div]);
    return output;
}

// Function to scan directory recursively and collect disk space information
void scanDirectory(const char *path) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(path))) return;

    // Loop over all files/directories in the given directory
    while ((entry = readdir(dir)) != NULL) {
        char filePath[1024];
        sprintf(filePath, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (lstat(filePath, &statbuf) != 0) continue;

        if (S_ISDIR(statbuf.st_mode)) {
            // Recursively call scanDirectory on sub-directory
            if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) continue;
            scanDirectory(filePath);
        } else {
            // Print file name and size
            printf("%s\t\t%s\n", entry->d_name, convertSize(statbuf.st_size));
        }
    }

    closedir(dir);
}

int main() {
    char path[1024];

    printf("Enter the directory path to scan: ");
    scanf("%[^\n]", path);

    printf("File Name\tSize\n");
    printf("==================================\n");

    scanDirectory(path);

    return 0;
}