//Falcon-180B DATASET v1.0 Category: File handling ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

#define MAX_THREADS 10
#define MAX_BUFFER_SIZE 100

pthread_mutex_t lock;

void *thread_function(void *arg)
{
    char *buffer = (char *) malloc(MAX_BUFFER_SIZE);
    int fd = *(int *) arg;

    while(1)
    {
        pthread_mutex_lock(&lock);
        if(read(fd, buffer, MAX_BUFFER_SIZE) == 0)
        {
            printf("Thread %d exiting...\n", *(int *) arg);
            pthread_mutex_unlock(&lock);
            free(buffer);
            return NULL;
        }
        printf("Thread %d read %s\n", *(int *) arg, buffer);
        pthread_mutex_unlock(&lock);
    }
}

int main()
{
    int fd, i;
    pthread_t threads[MAX_THREADS];

    fd = open("example.txt", O_RDONLY);

    if(fd == -1)
    {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    for(i=0; i<MAX_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, thread_function, (void *) &fd);
    }

    for(i=0; i<MAX_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    close(fd);

    return 0;
}