//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define MEGABYTE (1024 * 1024)

typedef struct {
    char *name;
    size_t size;
    size_t used;
    size_t available;
} FileSystem;

int main() {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;
    FileSystem fs;

    fp = fopen("/proc/mounts", "r");
    if (fp == NULL) {
        printf("Error: /proc/mounts cannot be opened.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= 100) {
            printf("Error: Too many file systems mounted.\n");
            exit(1);
        }

        token = strtok(line, " ");
        if (token == NULL)
            continue;

        if (i == 0) {
            strcpy(fs.name, token);
            i++;
            continue;
        }

        if (strcmp(token, "none") == 0) {
            fs.size = MEGABYTE;
            fs.used = 0;
            fs.available = fs.size;
            printf("RAM usage for %s:\n", fs.name);
            printf("Total: %lu MB\n", fs.size / MEGABYTE);
            printf("Used: %lu MB\n", fs.used / MEGABYTE);
            printf("Available: %lu MB\n", fs.available / MEGABYTE);
            printf("\n");
        }
    }

    fclose(fp);

    return 0;
}