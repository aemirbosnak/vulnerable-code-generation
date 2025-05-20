//FormAI DATASET v1.0 Category: File Backup System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 1024

void backup(char *src, char *dst) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    char date[BUFSIZE];
    strftime(date, sizeof(date), "%Y-%m-%d_%H-%M-%S", tm);

    char *backupFile = (char*)malloc(BUFSIZE * sizeof(char));
    snprintf(backupFile, BUFSIZE, "%s_%s", dst, date);

    FILE *srcFile = fopen(src, "r");
    FILE *dstFile = fopen(backupFile, "w");

    if (srcFile == NULL || dstFile == NULL) {
        printf("Could not open files\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFSIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFSIZE, srcFile)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, dstFile);
    }

    fclose(srcFile);
    fclose(dstFile);
    free(backupFile);

    printf("Backup successful!\n");
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <dest_dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *src = argv[1];
    char *dst = argv[2];

    backup(src, dst);

    return 0;
}