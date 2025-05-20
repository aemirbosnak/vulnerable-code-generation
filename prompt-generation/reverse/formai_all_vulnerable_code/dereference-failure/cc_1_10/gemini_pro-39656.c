//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    void *ptr;
    size_t size;
} mem_req_t;

typedef struct {
    pthread_mutex_t lock;
    pthread_cond_t cond;
    mem_req_t *req;
} mem_pool_t;

mem_pool_t mem_pool;

void mem_pool_init() {
    pthread_mutex_init(&mem_pool.lock, NULL);
    pthread_cond_init(&mem_pool.cond, NULL);
    mem_pool.req = NULL;
}

void mem_pool_destroy() {
    pthread_mutex_destroy(&mem_pool.lock);
    pthread_cond_destroy(&mem_pool.cond);
}

void *mem_pool_alloc(size_t size) {
    mem_req_t req = { NULL, size };

    pthread_mutex_lock(&mem_pool.lock);
    mem_pool.req = &req;
    pthread_cond_wait(&mem_pool.cond, &mem_pool.lock);
    pthread_mutex_unlock(&mem_pool.lock);

    return req.ptr;
}

void mem_pool_free(void *ptr) {
    pthread_mutex_lock(&mem_pool.lock);
    mem_pool.req->ptr = ptr;
    pthread_cond_signal(&mem_pool.cond);
    pthread_mutex_unlock(&mem_pool.lock);
}

void *mem_pool_alloc_async(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        return NULL;
    }

    mem_pool_free(ptr);
    return ptr;
}

void *mem_pool_free_async(void *ptr) {
    free(ptr);
    return NULL;
}

void *mem_pool_worker(void *arg) {
    while (1) {
        pthread_mutex_lock(&mem_pool.lock);
        while (mem_pool.req == NULL) {
            pthread_cond_wait(&mem_pool.cond, &mem_pool.lock);
        }

        mem_req_t *req = mem_pool.req;
        mem_pool.req = NULL;
        pthread_mutex_unlock(&mem_pool.lock);

        req->ptr = malloc(req->size);
        if (req->ptr == NULL) {
            fprintf(stderr, "Failed to allocate memory of size %zu\n", req->size);
            exit(1);
        }

        pthread_mutex_lock(&mem_pool.lock);
        pthread_cond_signal(&mem_pool.cond);
        pthread_mutex_unlock(&mem_pool.lock);
    }

    return NULL;
}

int main() {
    mem_pool_init();

    pthread_t worker;
    pthread_create(&worker, NULL, mem_pool_worker, NULL);

    void *ptr1 = mem_pool_alloc_async(1024);
    void *ptr2 = mem_pool_alloc_async(2048);

    printf("Allocated memory of size %zu at %p\n", 1024, ptr1);
    printf("Allocated memory of size %zu at %p\n", 2048, ptr2);

    mem_pool_free_async(ptr1);
    mem_pool_free_async(ptr2);

    pthread_join(worker, NULL);
    mem_pool_destroy();

    return 0;
}