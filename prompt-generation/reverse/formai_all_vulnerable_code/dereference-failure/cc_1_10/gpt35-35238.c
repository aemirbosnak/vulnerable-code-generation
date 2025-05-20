//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

//Structures
typedef struct task {
    int task_number;
    int sleep_time;
} Task;

typedef struct node {
    Task *task;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

typedef struct threadpool {
    Queue *queue;
    pthread_t *threads;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int thread_count;
    int working_threads;
    int task_count;
} ThreadPool;

//Function declarations
Task *create_task(int task_number, int sleep_time);
Node *create_node(Task *task);
Queue *create_queue();
void enqueue(Queue *queue, Task *task);
Task *dequeue(Queue *queue);
void *thread_work(void *pool);
ThreadPool *create_threadpool(int thread_count);
void add_task(ThreadPool *pool, Task *task);
void wait_all_tasks(ThreadPool *pool);
void destroy_threadpool(ThreadPool *pool);

Task *create_task(int task_number, int sleep_time) {
    Task *task = (Task *) malloc(sizeof(Task));
    task->task_number = task_number;
    task->sleep_time = sleep_time;
    return task;
}

Node *create_node(Task *task) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->task = task;
    node->next = NULL;
    return node;
}

Queue *create_queue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, Task *task) {
    Node *node = create_node(task);
    if(queue->rear == NULL) {
        queue->front = node;
        queue->rear = node;
    }
    else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

Task *dequeue(Queue *queue) {
    if(queue->front == NULL)
        return NULL;
    Task *task = queue->front->task;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if(queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return task;
}

void *thread_work(void *pool) {
    ThreadPool *t_pool = (ThreadPool *) pool;
    while(1) {
        pthread_mutex_lock(&t_pool->mutex);
        while(t_pool->task_count == 0 && t_pool->working_threads == t_pool->thread_count)
            pthread_cond_wait(&t_pool->cond, &t_pool->mutex);
        if(t_pool->task_count == 0 && t_pool->working_threads < t_pool->thread_count) {
            pthread_mutex_unlock(&t_pool->mutex);
            break;
        }
        t_pool->working_threads++;
        Task *task = dequeue(t_pool->queue);
        t_pool->task_count--;
        pthread_mutex_unlock(&t_pool->mutex);
        if(task != NULL) {
            printf("Task %d processing for %d seconds in thread %lu\n", task->task_number, task->sleep_time, pthread_self());
            sleep(task->sleep_time);
            printf("Task %d processed in thread %lu\n", task->task_number, pthread_self());
            free(task);
        }
        t_pool->working_threads--;
    }
    pthread_exit(NULL);
}

ThreadPool *create_threadpool(int thread_count) {
    ThreadPool *pool = (ThreadPool *) malloc(sizeof(ThreadPool));
    pool->queue = create_queue();
    pool->threads = (pthread_t *) malloc(sizeof(pthread_t) * thread_count);
    pthread_mutex_init(&pool->mutex, NULL);
    pthread_cond_init(&pool->cond, NULL);
    pool->thread_count = thread_count;
    pool->working_threads = 0;
    pool->task_count = 0;
    int i;
    for(i = 0; i < thread_count; i++)
        pthread_create(&pool->threads[i], NULL, thread_work, pool);
    return pool;
}

void add_task(ThreadPool *pool, Task *task) {
    pthread_mutex_lock(&pool->mutex);
    enqueue(pool->queue, task);
    pool->task_count++;
    pthread_cond_signal(&pool->cond);
    pthread_mutex_unlock(&pool->mutex);
}

void wait_all_tasks(ThreadPool *pool) {
    int i;
    for(i = 0; i < pool->thread_count; i++)
        pthread_join(pool->threads[i], NULL);
}

void destroy_threadpool(ThreadPool *pool) {
    pthread_mutex_destroy(&pool->mutex);
    pthread_cond_destroy(&pool->cond);
    free(pool->threads);
    Node *curr = pool->queue->front;
    while(curr != NULL) {
        Node *temp = curr;
        curr = curr->next;
        free(temp->task);
        free(temp);
    }
    free(pool->queue);
    free(pool);
}

int main() {
    ThreadPool *pool = create_threadpool(3);
    int i;
    for(i = 0; i < 10; i++)
        add_task(pool, create_task(i + 1, rand() % 5 + 1));
    wait_all_tasks(pool);
    destroy_threadpool(pool);
    return 0;
}