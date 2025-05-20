//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_REQUESTS 1000

typedef struct {
    char *request;
    int request_len;
    char *response;
} request_t;

request_t requests[MAX_REQUESTS];
int num_requests = 0;

void *handle_request(void *arg) {
    int i;
    for (i = 0; i < num_requests; i++) {
        if (strcmp(requests[i].request, "GET") == 0) {
            sprintf(requests[i].response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n", strlen("Hello, world!"));
        } else {
            sprintf(requests[i].response, "HTTP/1.1 404 Not Found\r\nContent-Length: %d\r\n\r\n", strlen("404 Not Found"));
        }
    }
    return NULL;
}

int main() {
    int i, ret;
    pthread_t threads[MAX_THREADS];

    for (i = 0; i < MAX_REQUESTS; i++) {
        requests[i].request = malloc(1024);
        requests[i].response = malloc(1024);
        memset(requests[i].request, 0, 1024);
        memset(requests[i].response, 0, 1024);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        ret = pthread_create(&threads[i], NULL, handle_request, NULL);
        if (ret!= 0) {
            printf("Error: Unable to create thread, %d\n", ret);
            exit(-1);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < num_requests; i++) {
        printf("Request: %s\nResponse: %s\n", requests[i].request, requests[i].response);
    }

    return 0;
}