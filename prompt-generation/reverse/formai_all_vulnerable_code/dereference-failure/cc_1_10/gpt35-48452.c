//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg){
    char *message = (char *)arg;
    printf("%s thread starting..\n", message);
    int *result = malloc(sizeof(int));
    if(result == NULL){
        printf("Error: Could not allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    *result = 42;
    printf("%s thread exiting..\n", message);
    pthread_exit(result);
}

int main(){
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int *result1, *result2;
    int status1, status2;
    printf("Creating Thread 1..\n");
    status1 = pthread_create(&thread1, NULL, thread_function, (void *)message1);
    if(status1 != 0){
        printf("Error: Thread 1 creation failed!\n");
        exit(EXIT_FAILURE);
    }
    printf("Creating Thread 2..\n");
    status2 = pthread_create(&thread2, NULL, thread_function, (void *)message2);
    if(status2 != 0){
        printf("Error: Thread 2 creation failed!\n");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for Thread 1 to finish..\n");
    status1 = pthread_join(thread1, (void **)&result1);
    if(status1 != 0){
        printf("Error: Thread 1 join failed!\n");
        exit(EXIT_FAILURE);
    }
    printf("Thread 1 returned: %d\n", *result1);
    free(result1);
    printf("Waiting for Thread 2 to finish..\n");
    status2 = pthread_join(thread2, (void **)&result2);
    if(status2 != 0){
        printf("Error: Thread 2 join failed!\n");
        exit(EXIT_FAILURE);
    }
    printf("Thread 2 returned: %d\n", *result2);
    free(result2);
    printf("Exiting program..\n");
    pthread_exit(NULL);
}