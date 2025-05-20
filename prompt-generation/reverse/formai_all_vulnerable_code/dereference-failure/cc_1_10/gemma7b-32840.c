//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Linus Torvalds
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX_SCHEDULER_ITEMS 10

typedef struct Task {
    char name[256];
    int prio;
    struct Task* next;
} Task;

Task* scheduler_add(Task* head, char* name, int prio)
{
    Task* new_task = malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->prio = prio;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        Task* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = new_task;
    }

    return head;
}

void scheduler_run(Task* head)
{
    while (head) {
        int current_time = time(NULL);
        int task_time = head->prio * 1000;
        if (current_time >= task_time) {
            printf("Task: %s, completed at: %d\n", head->name, current_time);
            free(head);
            head = head->next;
        } else {
            sleep(1);
        }
    }

    printf("All tasks completed.\n");
}

int main()
{
    Task* head = NULL;
    scheduler_add(head, "Task A", 1);
    scheduler_add(head, "Task B", 2);
    scheduler_add(head, "Task C", 3);

    scheduler_run(head);

    return 0;
}