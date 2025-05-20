//FormAI DATASET v1.0 Category: Data recovery tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

#define BUFSIZE 512

void *async_recover(void *args);

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please provide a filename to recover.\n");
        exit(1);
    }

    char *filename = argv[1];
    printf("Starting recovery of file \"%s\"...\n", filename);

    pthread_t thread;
    void *args[2] = { filename, NULL };

    if(pthread_create(&thread, NULL, async_recover, (void *)args) != 0) {
        printf("Failed to create thread: %s\n", strerror(errno));
        exit(1);
    }

    printf("Recovery started in a background thread. You can continue using the system, and you will be notified once the file is recovered.\n");

    pthread_join(thread, NULL);

    printf("File recovery completed successfully.\n");

    return 0;
}

void *async_recover(void *args) {
    char *filename = ((char **)args)[0];

    int fd;
    if((fd = open(filename, O_RDONLY)) < 0) {
        printf("Failed to open file %s: %s\n", filename, strerror(errno));
        pthread_exit(NULL);
    }

    char buf[BUFSIZE];
    ssize_t nread;
    FILE *output_file;

    char *output_filename = malloc(strlen(filename) + 5);
    strcpy(output_filename, filename);
    strcat(output_filename, ".rec");

    if((output_file = fopen(output_filename, "w")) == NULL) {
        printf("Failed to create output file %s: %s\n", output_filename, strerror(errno));
        close(fd);
        pthread_exit(NULL);
    }

    while((nread = read(fd, buf, BUFSIZE)) > 0) {
        fwrite(buf, 1, nread, output_file);
    }

    fclose(output_file);
    close(fd);

    free(output_filename);

    pthread_exit(NULL);
}