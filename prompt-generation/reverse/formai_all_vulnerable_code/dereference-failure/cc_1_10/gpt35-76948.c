//FormAI DATASET v1.0 Category: Task Scheduler ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 20

typedef struct{
    int hours;
    int minutes;
}Time;

typedef struct{
    char name[MAX_NAME_LENGTH];
    Time time;
    int priority;
}Task;

Task taskList[MAX_TASKS];
int taskCount = 0;

void addTask(char* name, int hours, int minutes, int priority){
    if(taskCount == MAX_TASKS){
        printf("Task list is full!\n");
        return;
    }
    Task newTask;
    strcpy(newTask.name, name);
    newTask.time.hours = hours;
    newTask.time.minutes = minutes;
    newTask.priority = priority;
    taskList[taskCount++] = newTask;
}

void printTaskList(){
    for(int i=0; i<taskCount; i++){
        printf("Task #%d: %s, Time: %02d:%02d, Priority: %d\n", i+1, taskList[i].name, taskList[i].time.hours, taskList[i].time.minutes, taskList[i].priority);
    }
}

void runTasks(){
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    int currentHour = localTime->tm_hour;
    int currentMinute = localTime->tm_min;
    
    int earliestTaskIndex = -1;
    int earliestTaskTimeDiff = -1;
    
    for(int i=0; i<taskCount; i++){
        int taskHour = taskList[i].time.hours;
        int taskMinute = taskList[i].time.minutes;
        int taskTimeDiff = ((taskHour - currentHour) * 60) + (taskMinute - currentMinute);
        if(taskTimeDiff < 0){
            taskTimeDiff += 1440;
        }
        if(earliestTaskIndex == -1 || taskTimeDiff < earliestTaskTimeDiff){
            earliestTaskIndex = i;
            earliestTaskTimeDiff = taskTimeDiff;
        }
    }
    
    if(earliestTaskIndex == -1){
        printf("No pending tasks found.\n");
        return;
    }
    
    printf("Next task: %s at %02d:%02d\n", taskList[earliestTaskIndex].name, taskList[earliestTaskIndex].time.hours, taskList[earliestTaskIndex].time.minutes);
}

int main(){
    addTask("Task 1", 10, 30, 3);
    addTask("Task 2", 16, 0, 1);
    addTask("Task 3", 20, 30, 2);
    
    printf("Task list:\n");
    printTaskList();
    
    printf("Running task scheduler...\n");
    runTasks();
    
    return 0;
}