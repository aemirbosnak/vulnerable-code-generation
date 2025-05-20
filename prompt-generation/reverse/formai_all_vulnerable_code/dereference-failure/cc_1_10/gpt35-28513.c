//FormAI DATASET v1.0 Category: Memory management ; Style: multi-threaded
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

#define THREADS 5
#define MEMORY_SIZE 50

pthread_mutex_t mutex;
char memory[MEMORY_SIZE];

void* threadFunction(void* args){
    int thread_num = *(int*)args;
    char* data = (char*)malloc(sizeof(char)*10);
    sprintf(data,"Thread %d",thread_num);
    int start = rand() % MEMORY_SIZE;

    pthread_mutex_lock(&mutex);
    printf("Thread %d is writing '%s' to memory starting from index %d\n",thread_num,data,start);
    for(int i = 0;i<10;i++){
        if(start + i < MEMORY_SIZE){
            memory[start+i] = data[i];
            sleep(1);
        }
    }
    printf("Thread %d has finished writing '%s'\n",thread_num,data);
    pthread_mutex_unlock(&mutex);

    free(data);
    pthread_exit(NULL);
}

int main(){

    pthread_t threads[THREADS];
    int thread_num[THREADS];
    pthread_mutex_init(&mutex,NULL);

    for(int i = 0;i<THREADS;i++){
        thread_num[i] = i+1;
        if(pthread_create(&threads[i],NULL,threadFunction,(void*)&thread_num[i]))
            printf("Error in thread %d creation!\n",i);

    }

    for(int i = 0;i<THREADS;i++){
        if(pthread_join(threads[i],NULL))
            printf("Error in thread %d joining!\n",i);

    }

    printf("Final Memory: ");

    for(int i=0;i<MEMORY_SIZE;i++){
        printf("%c",memory[i]);
    }
    printf("\n");

    pthread_mutex_destroy(&mutex);
    return 0;
}