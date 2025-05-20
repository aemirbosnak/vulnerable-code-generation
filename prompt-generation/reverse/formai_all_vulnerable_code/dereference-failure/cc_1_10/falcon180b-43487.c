//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_REQUESTS 100

struct request {
    char *date_str;
    time_t *result;
};

void *convert_date(void *arg) {
    struct request *req = (struct request *) arg;
    char *date_str = req->date_str;
    time_t *result = req->result;

    struct tm tm;
    strptime(date_str, "%Y-%m-%d", &tm);
    *result = mktime(&tm);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    struct request requests[MAX_REQUESTS];
    int num_requests = 0;

    char input_date[20];
    while (fgets(input_date, sizeof(input_date), stdin)!= NULL) {
        if (num_requests >= MAX_REQUESTS) {
            printf("Too many requests, please try again later.\n");
            break;
        }

        struct request *req = &requests[num_requests];
        req->date_str = strdup(input_date);
        req->result = malloc(sizeof(time_t));
        pthread_create(&threads[num_requests], NULL, convert_date, req);
        num_requests++;
    }

    for (int i = 0; i < num_requests; i++) {
        pthread_join(threads[i], NULL);
        printf("Converted date: %s\n", ctime(requests[i].result));
    }

    return 0;
}