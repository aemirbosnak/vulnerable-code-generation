//FormAI DATASET v1.0 Category: File Synchronizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 1024

// function to synchronize two given files
void *file_sync(void *arg) {
    char *file1 = ((char **)arg)[0];
    char *file2 = ((char **)arg)[1];
    char buf[BUF_SIZE];
    struct stat st1, st2;
    int fd1, fd2, bytes_read;

    // get the file stat info
    if(stat(file1, &st1) < 0) {
        perror(file1);
        pthread_exit(NULL);
    }

    if(stat(file2, &st2) < 0) {
        if((fd2 = creat(file2, st1.st_mode)) < 0) {
            perror(file2);
            pthread_exit(NULL);
        }
        else {
            close(fd2);
        }
    }

    // open file descriptors for reading and writing
    if((fd1 = open(file1, O_RDONLY)) < 0) {
        perror(file1);
        pthread_exit(NULL);
    }

    if((fd2 = open(file2, O_WRONLY)) < 0) {
        perror(file2);
        pthread_exit(NULL);
    }

    // read data from file1 and write to file2
    while((bytes_read = read(fd1, buf, BUF_SIZE)) > 0) {
        write(fd2, buf, bytes_read);
    }

    // close file descriptors
    close(fd1);
    close(fd2);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int i, num_files, num_threads;
    char **file_arr;
    pthread_t *threads;

    // check for correct number of arguments
    if(argc < 3) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    num_files = argc - 1;
    num_threads = num_files / 2;  // each thread will synchronize two files

    // allocate memory for array of file names and threads
    file_arr = (char **)malloc(num_files * sizeof(char *));
    threads = (pthread_t *)malloc(num_threads * sizeof(pthread_t));

    // copy file names into array
    for(i = 0; i < num_files; i++) {
        file_arr[i] = strdup(argv[i+1]);
    }

    // create threads to synchronize files
    for(i = 0; i < num_threads; i++) {
        char **thread_arg = (char **)malloc(2 * sizeof(char *));
        thread_arg[0] = file_arr[2*i];
        thread_arg[1] = file_arr[2*i + 1];
        pthread_create(&threads[i], NULL, file_sync, (void *)thread_arg);
    }

    // wait for threads to finish
    for(i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // free memory for file array and threads
    for(i = 0; i < num_files; i++) {
        free(file_arr[i]);
    }
    free(file_arr);
    free(threads);

    printf("Files synchronized successfully!\n");

    return 0;
}