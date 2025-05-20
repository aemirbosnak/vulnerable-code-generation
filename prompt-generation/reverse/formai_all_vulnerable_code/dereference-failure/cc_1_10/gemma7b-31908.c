//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define SCHEDULER_MAX 10

struct task {
    char name[20];
    int priority;
    struct task* next;
};

struct task* head = NULL;

void schedule_add(char* name, int priority)
{
    struct task* new_task = malloc(sizeof(struct task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        struct task* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = new_task;
    }
}

void schedule_run()
{
    struct task* current = head;
    while (current) {
        struct timespec ts;
        ts.tv_sec = current->priority;
        ts.tv_nsec = 0;
        nanosleep(ts);

        printf("%s is running...\n", current->name);
        sleep(1);
        printf("%s has finished.\n", current->name);

        current = current->next;
    }
}

int main()
{
    schedule_add("Task A", 5);
    schedule_add("Task B", 2);
    schedule_add("Task C", 4);
    schedule_add("Task D", 3);

    schedule_run();

    return 0;
}