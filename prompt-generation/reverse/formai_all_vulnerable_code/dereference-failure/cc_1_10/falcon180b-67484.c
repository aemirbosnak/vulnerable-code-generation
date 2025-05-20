//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <elf.h>
#include <sys/ptrace.h>

#define PAGE_SIZE 4096

int main(int argc, char **argv) {
    int pid;
    char *filename;
    if (argc < 2) {
        printf("Usage: %s <process-id>\n", argv[0]);
        exit(1);
    }
    pid = atoi(argv[1]);
    filename = "/proc/";
    strcat(filename, argv[1]);
    strcat(filename, "/maps");
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, 1024, fp)!= NULL) {
        char *start = strtok(line, " ");
        char *end = strtok(NULL, " ");
        char *perms = strtok(NULL, " ");
        char *offset = strtok(NULL, " ");
        char *dev = strtok(NULL, " ");
        char *inode = strtok(NULL, " ");
        printf("Start: %p\n", (void *)atoi(start));
        printf("End: %p\n", (void *)atoi(end));
        printf("Perms: %s\n", perms);
        printf("Offset: %p\n", (void *)atoi(offset));
        printf("Device: %s\n", dev);
        printf("Inode: %s\n", inode);
        printf("\n");
    }
    fclose(fp);

    return 0;
}