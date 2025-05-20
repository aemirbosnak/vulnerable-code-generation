//FormAI DATASET v1.0 Category: Task Scheduler ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

typedef struct Task{
    char task_name[20];
    int priority;
    int time_required;
}Task;

typedef struct TaskScheduler{
    int max_tasks;
    int current_tasks;
    int quantum;
    Task** tasks;
}TaskScheduler;

TaskScheduler* create_scheduler(int max_tasks, int quantum);
Task* create_task(char task_name[], int priority, int time_required);
void add_task(TaskScheduler* scheduler, Task* task);
void remove_task(TaskScheduler* scheduler, int task_index);
void run_scheduler(TaskScheduler* scheduler);

int main() {

    TaskScheduler* scheduler = create_scheduler(5, 2);

    Task* task1 = create_task("Study for exams", 4, 3);
    Task* task2 = create_task("Do laundry", 2, 1);
    Task* task3 = create_task("Clean the house", 3, 2);

    add_task(scheduler, task1);
    add_task(scheduler, task2);
    add_task(scheduler, task3);

    run_scheduler(scheduler);

    remove_task(scheduler, 2);

    Task* task4 = create_task("Finish project", 5, 4);

    add_task(scheduler, task4);
    add_task(scheduler, task3);

    run_scheduler(scheduler);

    remove_task(scheduler, 0);
    remove_task(scheduler, 0);

    Task* task5 = create_task("Go to grocery store", 1, 2);

    add_task(scheduler, task5);

    run_scheduler(scheduler);

    free(scheduler);

    return 0;
}

TaskScheduler* create_scheduler(int max_tasks, int quantum) {
    TaskScheduler* scheduler = (TaskScheduler*)malloc(sizeof(TaskScheduler));
    scheduler->max_tasks = max_tasks;
    scheduler->quantum = quantum;
    scheduler->tasks = (Task**)malloc(max_tasks*sizeof(Task*));
    scheduler->current_tasks = 0;
    return scheduler;
}

Task* create_task(char task_name[], int priority, int time_required) {
    Task* task = (Task*)malloc(sizeof(Task));
    task->priority = priority;
    task->time_required = time_required;
    for(int i = 0; i<20; i++){
        task->task_name[i] = task_name[i];
    }
    return task;
}

void add_task(TaskScheduler* scheduler, Task* task){
    if(scheduler->current_tasks == scheduler->max_tasks){
        printf("Error: Task Scheduler is full, cannot add task\n");
    } else {
        scheduler->tasks[scheduler->current_tasks++] = task;
    }
}

void remove_task(TaskScheduler* scheduler, int task_index){
    if(task_index >= scheduler->current_tasks || task_index < 0){
        printf("Error: Invalid index, cannot remove task\n");
    } else {
        free(scheduler->tasks[task_index]);
        for(int i=task_index; i<scheduler->current_tasks-1; i++){
            scheduler->tasks[i] = scheduler->tasks[i+1];
        }
        scheduler->current_tasks--;
    }
}

void run_scheduler(TaskScheduler* scheduler){
    printf("--Task Scheduler Report--\n");
    printf("Quantum size: %d\n", scheduler->quantum);
    printf("Number of tasks: %d\n", scheduler->current_tasks);
    printf("------------------------------\n");

    int time_elapsed = 0;

    while(scheduler->current_tasks > 0){
        for(int i=0; i<scheduler->current_tasks;i++){

            if(scheduler->tasks[i]->priority == 1){
                printf("Running high priority task: %s\n", scheduler->tasks[i]->task_name);
            } else {
                printf("Running task: %s\n", scheduler->tasks[i]->task_name);
            }

            if(scheduler->tasks[i]->time_required <= scheduler->quantum){
                time_elapsed += scheduler->tasks[i]->time_required;
                free(scheduler->tasks[i]);
                for(int j=i; j<scheduler->current_tasks-1;j++){
                    scheduler->tasks[j] = scheduler->tasks[j+1];
                }
                scheduler->current_tasks--;
            } else {
                time_elapsed += scheduler->quantum;
                scheduler->tasks[i]->time_required -= scheduler->quantum;
            }

            printf("Time elapsed so far: %d\n", time_elapsed);
            printf("------------------------------\n");

            if(scheduler->current_tasks == 0){
                return;
            }
        }
    }
}