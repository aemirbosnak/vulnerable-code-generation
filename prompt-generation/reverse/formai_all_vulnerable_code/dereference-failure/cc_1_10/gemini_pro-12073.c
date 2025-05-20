//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFF_SIZE 1024

// Function to get current timestamp
char *get_timestamp() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *timestamp = malloc(20);
    strftime(timestamp, 20, "%Y%m%d%H%M%S", tm);
    return timestamp;
}

// Function to backup a file
int backup_file(const char *src_file, const char *dst_file) {
    FILE *src, *dst;
    char buff[BUFF_SIZE];
    int n;

    // Open source file for reading
    src = fopen(src_file, "r");
    if (src == NULL) {
        perror("Error opening source file");
        return -1;
    }

    // Open destination file for writing
    dst = fopen(dst_file, "w");
    if (dst == NULL) {
        perror("Error opening destination file");
        return -1;
    }

    // Copy data from source to destination file
    while ((n = fread(buff, 1, BUFF_SIZE, src)) > 0) {
        fwrite(buff, 1, n, dst);
    }

    // Close files
    fclose(src);
    fclose(dst);

    return 0;
}

int main() {
    char *timestamp = get_timestamp();
    char *src_file = "file.txt";
    char *dst_file = malloc(strlen(src_file) + strlen(timestamp) + 5);
    sprintf(dst_file, "%s.%s.bak", src_file, timestamp);

    // Backup the file
    if (backup_file(src_file, dst_file) == 0) {
        printf("File backed up successfully to %s\n", dst_file);
    } else {
        printf("Error backing up file\n");
    }

    // Free allocated memory
    free(timestamp);
    free(dst_file);

    return 0;
}