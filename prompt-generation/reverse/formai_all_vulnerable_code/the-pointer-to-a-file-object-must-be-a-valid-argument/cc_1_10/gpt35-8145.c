//FormAI DATASET v1.0 Category: System process viewer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process {
    int pid;
    char name[20];
    char state[20];
};

int main() {
    printf("My love, welcome to our Process Viewer!\n");
    printf("I have created this program to show you our running processes.\n");
    printf("Let's see what we have...\n");

    FILE* fp;
    char buf[1024];
    char* pid;
    char* name;
    char* state;
    int i = 0;

    struct process arr[1024];

    fp = fopen("/proc/stat", "r");

    while(fgets(buf, sizeof(buf), fp) != NULL) {
        if(!strncmp(buf, "Pid", 3) || !strncmp(buf, "ppid", 4)) {
            pid = strtok(buf, " ");
            name = strtok(NULL, " ");
            state = strtok(NULL, " ");

            arr[i].pid = atoi(pid);
            strcpy(arr[i].name, name);
            strcpy(arr[i].state, state);
            i++;
        }
    }

    printf("PID\tNAME\t\tSTATE\n");
    for(int j = 0; j < i; j++) {
        printf("%d\t%s\t\t%s\n", arr[j].pid, arr[j].name, arr[j].state);
    }

    printf("There you have it, my love. Our running processes.\n");

    fclose(fp);

    return 0;
}