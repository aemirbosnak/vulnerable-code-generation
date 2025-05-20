//Falcon-180B DATASET v1.0 Category: Email Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LINE 1000
#define MAX_SUBJECT 100

typedef struct {
    char name[MAX_LINE];
    char subject[MAX_SUBJECT];
    char message[MAX_LINE];
} email;

typedef struct {
    int thread_id;
    int index;
    email *emails;
} thread_data;

void *thread_func(void *arg) {
    thread_data *data = (thread_data *) arg;
    email *email = data->emails + data->index;

    printf("Thread %d processing email %s\n", data->thread_id, email->name);

    // do some processing here...

    printf("Thread %d done processing email %s\n", data->thread_id, email->name);
    return NULL;
}

int main() {
    int num_emails = 0;
    email *emails = NULL;
    char line[MAX_LINE];
    FILE *fp;

    // open input file
    fp = fopen("emails.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // read emails from input file
    while (fgets(line, MAX_LINE, fp)!= NULL) {
        strcpy(emails[num_emails].name, line);
        fgets(line, MAX_LINE, fp);
        strcpy(emails[num_emails].subject, line);
        fgets(line, MAX_LINE, fp);
        strcpy(emails[num_emails].message, line);
        num_emails++;
    }

    // close input file
    fclose(fp);

    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    // create threads
    for (int i = 0; i < num_emails; i++) {
        data[i].thread_id = i;
        data[i].index = i;
        data[i].emails = emails;

        // create thread
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    // join threads
    for (int i = 0; i < num_emails; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}