//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct async_func
{
    void *(*function)(void *);
    void *arg;
    struct async_func *next;
} async_func_t;

typedef struct async_queue
{
    async_func_t *head;
    async_func_t *tail;
    pthread_mutex_t mutex;
    pthread_cond_t conditional;
} async_queue_t;

async_queue_t q;

void async_queue_init(async_queue_t *q)
{
    q->head = NULL;
    q->tail = NULL;
    pthread_mutex_init(&q->mutex, NULL);
    pthread_cond_init(&q->conditional, NULL);
}

void async_queue_push(async_queue_t *q, void *(*function)(void *), void *arg)
{
    async_func_t *entry = (async_func_t *)malloc(sizeof(async_func_t));
    entry->function = function;
    entry->arg = arg;
    entry->next = NULL;

    pthread_mutex_lock(&q->mutex);

    if (q->head == NULL)
    {
        q->head = entry;
        q->tail = entry;
    }
    else
    {
        q->tail->next = entry;
        q->tail = entry;
    }

    pthread_cond_signal(&q->conditional);
    pthread_mutex_unlock(&q->mutex);
}

async_func_t *async_queue_pop(async_queue_t *q)
{
    async_func_t *entry;

    pthread_mutex_lock(&q->mutex);

    while (q->head == NULL)
    {
        pthread_cond_wait(&q->conditional, &q->mutex);
    }

    entry = q->head;
    q->head = q->head->next;

    if (q->head == NULL)
    {
        q->tail = NULL;
    }

    pthread_mutex_unlock(&q->mutex);

    return entry;
}

void *async_worker(void *arg)
{
    while (true)
    {
        async_func_t *entry = async_queue_pop(&q);
        entry->function(entry->arg);
        free(entry);
    }
}

void async_init()
{
    async_queue_init(&q);
    pthread_t worker;
    pthread_create(&worker, NULL, async_worker, NULL);
}

void *test_function(void *arg)
{
    int value = *((int *)arg);
    printf("Running thread with value: %d\n", value);
    return NULL;
}

int main()
{
    async_init();

    for (int i = 0; i < 10; i++)
    {
        int *arg = (int *)malloc(sizeof(int));
        *arg = i;
        async_queue_push(&q, test_function, arg);
    }

    pthread_exit(NULL);
}