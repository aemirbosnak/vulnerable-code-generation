//FormAI DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>

#define FILE_NAME "async_file_handling.txt"

void *write_to_file(void *arg){
    char *message = (char *)arg;
    char buffer[255];
    time_t timestamp;
    FILE *fp;
    int n;

    fp = fopen(FILE_NAME, "a");

    if(fp == NULL){
        printf("Error opening file %s: %s\n", FILE_NAME, strerror(errno));
        pthread_exit(NULL);
    }

    time(&timestamp);
    struct tm *t = localtime(&timestamp);
    strftime(buffer, sizeof(buffer), "%c", t);

    n = fprintf(fp, "[%s] This is an async message: %s\n", buffer, message);

    if(n < 0){
        printf("Error writing to file %s: %s\n", FILE_NAME, strerror(errno));
    }

    fclose(fp);

    pthread_exit(NULL);
}

int main(int argc, char **argv){
    pthread_t tid;
    int rc;

    // Create file if it doesn't exist
    int file = open(FILE_NAME, O_CREAT, 0644);
    if(file < 0){
        printf("Error creating file %s: %s\n", FILE_NAME, strerror(errno));
        return 1;
    }
    close(file);

    rc = pthread_create(&tid, NULL, write_to_file, "Hello World!");

    if(rc){
        printf("Error creating thread: %s\n", strerror(rc));
        return 1;
    }

    pthread_exit(NULL);
}