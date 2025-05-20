//Falcon2-11B DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define BUFSIZE 1024
#define MAX_FD 256

struct file_desc {
    int fd;
    char filename[1024];
    struct file_desc *next;
};

struct file_desc *head, *tail;

int get_ram_usage(char *filename) {
    FILE *fp;
    char buf[BUFSIZE];
    int bytes_read, bytes_left;
    int fd;
    int i;
    int ram_usage = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while (fgets(buf, BUFSIZE, fp)!= NULL) {
        bytes_read = fread(buf, sizeof(char), BUFSIZE, fp);
        if (bytes_read == 0) {
            break;
        }

        for (i = 0; i < bytes_read; i++) {
            if (buf[i] == '\n') {
                bytes_left = bytes_read - i - 1;
                ram_usage += (bytes_left * sizeof(char));
            }
        }
    }

    fclose(fp);

    return ram_usage;
}

void print_ram_usage() {
    struct file_desc *p;
    int i;

    printf("RAM usage: %d bytes\n", get_ram_usage("proc/meminfo"));

    for (p = head; p!= NULL; p = p->next) {
        if (p->fd < 0 || p->fd >= MAX_FD) {
            printf("ERROR: fd=%d\n", p->fd);
        } else {
            printf("File: %s, fd=%d\n", p->filename, p->fd);
        }
    }
}

int main(int argc, char *argv[]) {
    int i;
    struct file_desc *p;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    if (access(argv[1], F_OK)!= 0) {
        printf("File does not exist: %s\n", argv[1]);
        exit(1);
    }

    head = tail = NULL;

    for (i = 0; i < MAX_FD; i++) {
        p = malloc(sizeof(struct file_desc));
        p->fd = -1;
        p->next = NULL;
        p->filename[0] = '\0';
        tail = p;
    }

    p = malloc(sizeof(struct file_desc));
    p->fd = open(argv[1], O_RDONLY);
    if (p->fd == -1) {
        perror("Error opening file");
        exit(1);
    }
    p->filename[0] = '\0';
    p->next = NULL;
    tail = p;

    while (1) {
        if (p->fd!= -1 && p->fd < MAX_FD) {
            printf("File: %s, fd=%d\n", p->filename, p->fd);
        }

        p = tail;
        tail = tail->next;
        free(p);

        if (tail == NULL) {
            break;
        }
    }

    print_ram_usage();

    return 0;
}