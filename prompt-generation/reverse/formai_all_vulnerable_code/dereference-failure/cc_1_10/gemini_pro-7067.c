//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>
#include <semaphore.h>

// Request types.
enum request_type {
    REQUEST_TYPE_NONE,
    REQUEST_TYPE_BEAUTIFY,
    REQUEST_TYPE_EXIT
};

// Request structure.
struct request {
    enum request_type type;
    char *html;
    size_t html_len;
    char *beautified_html;
    sem_t sem;
};

// Global variables.
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
struct request *request_queue = NULL;
size_t request_queue_size = 0;

// Function to add a request to the queue.
void add_request(struct request *request) {
    pthread_mutex_lock(&mutex);
    request_queue = realloc(request_queue, sizeof(struct request) * (request_queue_size + 1));
    request_queue[request_queue_size++] = *request;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
}

// Function to get a request from the queue.
struct request *get_request() {
    pthread_mutex_lock(&mutex);
    while (request_queue_size == 0) {
        pthread_cond_wait(&cond, &mutex);
    }
    struct request *request = &request_queue[0];
    for (size_t i = 1; i < request_queue_size; i++) {
        request_queue[i - 1] = request_queue[i];
    }
    request_queue_size--;
    pthread_mutex_unlock(&mutex);
    return request;
}

// Function to beautify HTML.
char *beautify_html(char *html, size_t html_len) {
    // Allocate memory for the beautified HTML.
    char *beautified_html = malloc(html_len * 2);
    if (beautified_html == NULL) {
        return NULL;
    }

    // Beautify the HTML.
    size_t beautified_html_len = 0;
    for (size_t i = 0; i < html_len; i++) {
        char c = html[i];
        switch (c) {
            case '<':
                beautified_html[beautified_html_len++] = '<';
                beautified_html[beautified_html_len++] = '\n';
                break;
            case '>':
                beautified_html[beautified_html_len++] = '>';
                beautified_html[beautified_html_len++] = '\n';
                break;
            default:
                beautified_html[beautified_html_len++] = c;
                break;
        }
    }

    // Return the beautified HTML.
    return beautified_html;
}

// Function to handle a request.
void handle_request(struct request *request) {
    switch (request->type) {
        case REQUEST_TYPE_BEAUTIFY:
            request->beautified_html = beautify_html(request->html, request->html_len);
            sem_post(&request->sem);
            break;
        case REQUEST_TYPE_EXIT:
            exit(0);
            break;
        default:
            assert(0);
            break;
    }
}

// Function to run the worker thread.
void *worker_thread(void *arg) {
    while (1) {
        struct request *request = get_request();
        handle_request(request);
    }
    return NULL;
}

// Main function.
int main(int argc, char **argv) {
    // Create worker threads.
    pthread_t worker_threads[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&worker_threads[i], NULL, worker_thread, NULL);
    }

    // Main loop.
    while (1) {
        // Get input from the user.
        char *html = NULL;
        size_t html_len = 0;
        ssize_t nread = getline(&html, &html_len, stdin);
        if (nread == -1) {
            break;
        }

        // Create a request.
        struct request request;
        request.type = REQUEST_TYPE_BEAUTIFY;
        request.html = html;
        request.html_len = html_len;
        sem_init(&request.sem, 0, 0);

        // Add the request to the queue.
        add_request(&request);

        // Wait for the request to be completed.
        sem_wait(&request.sem);

        // Print the beautified HTML.
        printf("%s", request.beautified_html);

        // Free the memory allocated for the request.
        free(request.html);
        free(request.beautified_html);
        sem_destroy(&request.sem);
    }

    // Exit the program.
    struct request request;
    request.type = REQUEST_TYPE_EXIT;
    add_request(&request);

    for (int i = 0; i < 4; i++) {
        pthread_join(worker_threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}