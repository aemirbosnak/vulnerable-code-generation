//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>

#define MAX_THREADS 100
#define STACK_SIZE 1024

struct thread_data {
    pthread_t thread_id;
    int thread_num;
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int i = 0;
    char *ptr = (char *) malloc(1024);

    while (true) {
        memset(ptr, 'a', 1024);
        printf("Thread %d allocated %d bytes\n", data->thread_num, i);
        i += 1024;
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];
    struct thread_data thread_data[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        thread_data[i].thread_num = i;
        pthread_create(&threads[i], NULL, thread_func, (void *) &thread_data[i]);
    }

    while (true) {
        system("free -m > ram_usage.txt");
        FILE *fp = fopen("ram_usage.txt", "r");
        char line[1024];
        while (fgets(line, sizeof(line), fp)!= NULL) {
            printf("%s", line);
        }
        fclose(fp);
        remove("ram_usage.txt");
        sleep(5);
    }

    return 0;
}