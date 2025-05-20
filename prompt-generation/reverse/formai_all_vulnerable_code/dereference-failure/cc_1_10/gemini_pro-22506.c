//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    double value;
    char unit;
} measurement;

typedef struct {
    measurement input;
    measurement output;
} conversion_result;

typedef struct {
    measurement measurement;
    char target_unit;
} conversion_request;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *conversion_thread(void *arg) {
    conversion_request *request = (conversion_request *)arg;

    pthread_mutex_lock(&mutex);
    while (request->target_unit != request->measurement.unit) {
        pthread_cond_wait(&cond, &mutex);
    }
    pthread_mutex_unlock(&mutex);

    double result = request->measurement.value;
    switch (request->measurement.unit) {
    case 'C':
        if (request->target_unit == 'F') {
            result = result * 9 / 5 + 32;
        }
        break;
    case 'F':
        if (request->target_unit == 'C') {
            result = (result - 32) * 5 / 9;
        }
        break;
    }

    conversion_result *result_struct = malloc(sizeof(conversion_result));
    result_struct->input = request->measurement;
    result_struct->output.value = result;
    result_struct->output.unit = request->target_unit;

    return result_struct;
}

int main() {
    pthread_t threads[10];
    conversion_request requests[10];
    conversion_result *results[10];

    for (int i = 0; i < 10; i++) {
        requests[i].measurement.value = rand() % 100;
        requests[i].measurement.unit = 'C' + (rand() % 2);
        requests[i].target_unit = 'C' + (rand() % 2);
        pthread_create(&threads[i], NULL, conversion_thread, &requests[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], (void **)&results[i]);
        printf("%f%c -> %f%c\n", results[i]->input.value, results[i]->input.unit, results[i]->output.value, results[i]->output.unit);
        free(results[i]);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}