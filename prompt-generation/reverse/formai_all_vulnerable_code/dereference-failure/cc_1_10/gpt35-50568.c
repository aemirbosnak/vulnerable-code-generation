//FormAI DATASET v1.0 Category: Task Scheduler ; Style: excited
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>

// Function for task execution
void taskExecution(){
    printf("Task executed successfully!\n");
}

int main(){
    int taskCounter=0;
    int taskId[10];
    time_t now;
    time_t startTime[10];
    time_t timeDiff;
    struct tm timeinfo;
    char timeString[9];
    int timeInterval[10];
    int taskTimeFlag[10]={0};
    int i;

    // Setting up tasks
    taskId[0]=1;
    taskId[1]=2;
    taskId[2]=3;
    taskId[3]=4;
    taskId[4]=5;
    taskId[5]=6;
    taskId[6]=7;
    taskId[7]=8;
    taskId[8]=9;
    taskId[9]=10;

    timeInterval[0]=2;
    timeInterval[1]=4;
    timeInterval[2]=6;
    timeInterval[3]=8;
    timeInterval[4]=10;
    timeInterval[5]=12;
    timeInterval[6]=14;
    timeInterval[7]=16;
    timeInterval[8]=18;
    timeInterval[9]=20;

    printf("C Task scheduler starting...\n");

    // Loop for scheduling tasks
    while(1){
        // Get current time
        now = time(NULL);
        timeinfo = *localtime(&now);
        strftime(timeString, sizeof(timeString), "%H:%M:%S", &timeinfo);
        printf("Current time: %s\n", timeString);

        // Check if any task is scheduled to run
        for(i=0;i<10;i++){
            if(taskTimeFlag[i]==1)
                continue;
            if(timeInterval[i]==timeDiff){
                taskTimeFlag[i]=1;
                taskCounter++;
            }
        }

        // Execute any scheduled task
        if(taskCounter>0){
            printf("Task(s) scheduled to run!\n");
            for(i=0;i<10;i++){
                if(taskTimeFlag[i]){
                    printf("Executing Task %d...\n", taskId[i]);
                    taskExecution();
                    startTime[i] = time(NULL);
                    timeDiff = 0;
                    taskTimeFlag[i] = 0;
                    taskCounter--;
                }
            }
        }

        // Wait for a second
        sleep(1);

        // Calculate time difference
        for(i=0;i<10;i++){
            if(taskTimeFlag[i])
                continue;
            timeDiff = now - startTime[i];
        }
    }

    return 0;
}