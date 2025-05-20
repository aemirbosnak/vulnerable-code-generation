//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* convert_thread(void* arg);

struct date {
    int year;
    int month;
    int day;
};

struct thread_arg {
    char* date_str; 
    struct date* date_ptr;
};

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Please provide at least one date to convert.");
        return 1;
    }

    int num_dates = argc - 1;
    pthread_t* threads = malloc(sizeof(pthread_t) * num_dates);
    struct thread_arg* thread_args = malloc(sizeof(struct thread_arg) * num_dates);

    for (int i = 0; i < num_dates; i++) {
        thread_args[i].date_str = argv[i + 1];
        thread_args[i].date_ptr = malloc(sizeof(struct date));
        pthread_create(&threads[i], NULL, convert_thread, &thread_args[i]);
    }

    for (int i = 0; i < num_dates; i++) {
        pthread_join(threads[i], NULL);
        printf("%d-%02d-%02d\n", thread_args[i].date_ptr->year, thread_args[i].date_ptr->month, thread_args[i].date_ptr->day);
        free(thread_args[i].date_ptr);
    }

    free(thread_args);
    free(threads);

    return 0;
}

void* convert_thread(void* arg) {
    struct thread_arg* t_arg = (struct thread_arg*) arg;
    char* date_str = t_arg->date_str;
    struct date* date_ptr = t_arg->date_ptr;

    char* token;
    token = strtok(date_str, "-");
    date_ptr->year = atoi(token);

    token = strtok(NULL, "-");
    date_ptr->month = atoi(token);

    token = strtok(NULL, "-");
    date_ptr->day = atoi(token);

    pthread_exit(NULL);
}