//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <time.h>

typedef struct
{
    void *(*callback)(void *);
    void *arg;
} task;

typedef struct
{
    int num_threads;
    pthread_t *threads;
    int num_tasks;
    task *tasks;
    int num_tasks_completed;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} task_scheduler;

pthread_mutex_t global_lock;
pthread_cond_t global_cond;
int global_num_tasks_completed;
int global_num_tasks;

void *task_scheduler_thread(void *arg)
{
    task_scheduler *scheduler = (task_scheduler *)arg;

    while (1)
    {
        pthread_mutex_lock(&scheduler->lock);

        while (scheduler->num_tasks_completed == scheduler->num_tasks)
        {
            pthread_cond_wait(&scheduler->cond, &scheduler->lock);
        }

        for (int i = 0; i < scheduler->num_tasks; i++)
        {
            if (scheduler->tasks[i].arg == NULL)
            {
                scheduler->tasks[i].callback(NULL);
                scheduler->num_tasks_completed++;
                pthread_cond_signal(&scheduler->cond);
                break;
            }
        }

        pthread_mutex_unlock(&scheduler->lock);
    }

    return NULL;
}

void task_scheduler_init(task_scheduler *scheduler, int num_threads)
{
    scheduler->num_threads = num_threads;
    scheduler->threads = malloc(num_threads * sizeof(pthread_t));
    scheduler->num_tasks = 0;
    scheduler->tasks = NULL;
    scheduler->num_tasks_completed = 0;
    pthread_mutex_init(&scheduler->lock, NULL);
    pthread_cond_init(&scheduler->cond, NULL);

    for (int i = 0; i < num_threads; i++)
    {
        pthread_create(&scheduler->threads[i], NULL, task_scheduler_thread, scheduler);
    }
}

void task_scheduler_add_task(task_scheduler *scheduler, void *(*callback)(void *), void *arg)
{
    pthread_mutex_lock(&scheduler->lock);
    scheduler->tasks = realloc(scheduler->tasks, (scheduler->num_tasks + 1) * sizeof(task));
    scheduler->tasks[scheduler->num_tasks].callback = callback;
    scheduler->tasks[scheduler->num_tasks].arg = arg;
    scheduler->num_tasks++;
    pthread_cond_signal(&scheduler->cond);
    pthread_mutex_unlock(&scheduler->lock);
}

void task_scheduler_wait_for_completion(task_scheduler *scheduler)
{
    pthread_mutex_lock(&scheduler->lock);
    while (scheduler->num_tasks_completed != scheduler->num_tasks)
    {
        pthread_cond_wait(&scheduler->cond, &scheduler->lock);
    }
    pthread_mutex_unlock(&scheduler->lock);
}

void task_scheduler_destroy(task_scheduler *scheduler)
{
    pthread_mutex_lock(&scheduler->lock);
    for (int i = 0; i < scheduler->num_threads; i++)
    {
        pthread_cancel(scheduler->threads[i]);
    }
    free(scheduler->threads);
    free(scheduler->tasks);
    pthread_mutex_unlock(&scheduler->lock);
    pthread_mutex_destroy(&scheduler->lock);
    pthread_cond_destroy(&scheduler->cond);
}

void *task1(void *arg)
{
    printf("Task 1 executed\n");
    return NULL;
}

void *task2(void *arg)
{
    printf("Task 2 executed\n");
    return NULL;
}

void *task3(void *arg)
{
    printf("Task 3 executed\n");
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_mutex_init(&global_lock, NULL);
    pthread_cond_init(&global_cond, NULL);
    global_num_tasks = 3;
    global_num_tasks_completed = 0;

    task_scheduler scheduler;
    task_scheduler_init(&scheduler, 3);

    task_scheduler_add_task(&scheduler, task1, NULL);
    task_scheduler_add_task(&scheduler, task2, NULL);
    task_scheduler_add_task(&scheduler, task3, NULL);

    task_scheduler_wait_for_completion(&scheduler);

    task_scheduler_destroy(&scheduler);

    pthread_mutex_destroy(&global_lock);
    pthread_cond_destroy(&global_cond);

    return 0;
}