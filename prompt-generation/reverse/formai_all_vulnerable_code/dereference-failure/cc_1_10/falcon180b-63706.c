//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_NUM_THREADS 10
#define MAX_NUM_DIGITS 32

typedef struct {
    int id;
    char* input;
    char* output;
} thread_data_t;

sem_t mutex;
sem_t input_ready;
sem_t output_ready;

void* convert_binary(void* arg) {
    thread_data_t* data = (thread_data_t*) arg;

    sem_wait(&input_ready);
    sem_wait(&mutex);

    char* binary_str = data->input;
    char* decimal_str = data->output;

    int len = strlen(binary_str);
    int decimal = 0;
    int power = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (binary_str[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    sprintf(decimal_str, "%d", decimal);

    sem_post(&mutex);
    sem_post(&output_ready);

    pthread_exit(0);
}

int main(int argc, char** argv) {
    pthread_t threads[MAX_NUM_THREADS];
    thread_data_t data[MAX_NUM_THREADS];

    sem_init(&mutex, 0, 1);
    sem_init(&input_ready, 0, 0);
    sem_init(&output_ready, 0, MAX_NUM_THREADS);

    int num_threads = 0;

    while (num_threads < MAX_NUM_THREADS && argc > 1) {
        data[num_threads].id = num_threads;
        data[num_threads].input = argv[1];
        data[num_threads].output = (char*) malloc(MAX_NUM_DIGITS);

        pthread_create(&threads[num_threads], NULL, convert_binary, &data[num_threads]);
        num_threads++;
        argv++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&input_ready);
    sem_destroy(&output_ready);

    return 0;
}