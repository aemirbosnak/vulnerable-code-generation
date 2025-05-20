//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024

int main() {
    char filename[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    FILE *fp;
    struct statvfs statvfs;
    size_t size;
    int i, j;

    printf("Enter the filename to monitor: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    if (fstatvfs(fileno(fp), &statvfs)!= 0) {
        printf("Error: Unable to get file information.\n");
        exit(1);
    }

    size = statvfs.f_blocks * statvfs.f_frsize;

    printf("File Size: %lu bytes\n", size);
    printf("RAM Usage: ");

    while (1) {
        fseek(fp, 0, SEEK_SET);
        size = 0;
        while ((i = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
            size += i;
        }
        if (ferror(fp)) {
            printf("Error: Unable to read file.\n");
            exit(1);
        }
        printf("%lu bytes", size);
        for (j = 0; j < 50 - strlen(filename); j++) {
            printf(" ");
        }
        printf(" %s\n", filename);
        sleep(1);
    }

    return 0;
}