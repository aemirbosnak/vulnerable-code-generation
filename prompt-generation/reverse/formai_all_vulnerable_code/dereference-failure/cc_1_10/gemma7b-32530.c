//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: future-proof
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#define MAX_PROC_NUM 256

typedef struct ProcInfo {
    char name[256];
    int pid;
    long uptime;
    struct ProcInfo* next;
} ProcInfo;

ProcInfo* head = NULL;

void addProc(char* name, int pid, long uptime) {
    ProcInfo* newProc = malloc(sizeof(ProcInfo));
    strcpy(newProc->name, name);
    newProc->pid = pid;
    newProc->uptime = uptime;
    newProc->next = NULL;

    if (head == NULL) {
        head = newProc;
    } else {
        ProcInfo* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newProc;
    }
}

long getCPUUsage() {
    long totalTime = 0;
    ProcInfo* current = head;
    while (current) {
        long uptime = current->uptime;
        long cpuTime = uptime * 2;
        totalTime += cpuTime;
        current = current->next;
    }
    return totalTime;
}

int main() {
    addProc("firefox", 1234, 1000);
    addProc("chrome", 5678, 800);
    addProc("gnome-shell", 3210, 600);

    long totalTime = getCPUUsage();
    printf("Total CPU usage: %ld seconds\n", totalTime);

    return 0;
}