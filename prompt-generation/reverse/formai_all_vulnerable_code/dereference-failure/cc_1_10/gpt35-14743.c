//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef __unix__
    #include <unistd.h>
    #include <sys/resource.h>
#elif defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
    #include <windows.h>
#endif

#define MAX_PROCESS_NAME 1024

struct ProcessInfo {
    char name[MAX_PROCESS_NAME];
    int pid;
    double ram;
    struct ProcessInfo *next;
};

struct ListNode {
    struct ProcessInfo *data;
    struct ListNode *next;
};

typedef struct ProcessInfo ProcessInfo;
typedef struct ListNode ListNode;

ListNode* createNode(ProcessInfo* pi) {
    ListNode* tmp = (ListNode*) malloc(sizeof(ListNode));
    tmp->data = pi;
    tmp->next = NULL;
    return tmp;
}

int processExists(ListNode* head, int pid) {
    ListNode* tmp = head;
    while (tmp != NULL) {
        if (tmp->data->pid == pid) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

ProcessInfo* readProcessInfo(int pid) {
    ProcessInfo* pi = (ProcessInfo*) malloc(sizeof(ProcessInfo));
    char path[MAX_PROCESS_NAME];
    sprintf(path, "/proc/%d/statm", pid);
    FILE* fp = fopen(path, "r");
    if (!fp) {
        free(pi);
        return NULL;
    }
    char name[MAX_PROCESS_NAME];
    sprintf(name, "/proc/%d/cmdline", pid);
    FILE* fpname = fopen(name, "r");
    if (!fpname) {
        fclose(fp);
        free(pi);
        return NULL;
    }
    if (fgets(pi->name, MAX_PROCESS_NAME, fpname)) {
        char* p = strrchr(pi->name, ' ');
        if (p) {
            *p = '\0';
        }
    }
    fclose(fpname);
    fscanf(fp, "%*s %lf", &pi->ram);
    fclose(fp);
    pi->pid = pid;
    return pi;
}

void printProcessInfo(ProcessInfo* pi) {
    printf("%-20s %5d %10.2lf MB\n", pi->name, pi->pid, pi->ram / 1024.0);
}

void printAllProcesses(ListNode* head) {
    ListNode* tmp = head;
    printf("%-20s %5s %10s\n", "Process Name", "PID", "RAM Usage");
    while (tmp != NULL) {
        printProcessInfo(tmp->data);
        tmp = tmp->next;
    }
}

int rl_scan(char* dest, int maxlen) {
    int c, i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (i < maxlen - 1) {
            dest[i++] = (char) c;
        } else {
            break;
        }
    }
    dest[i] = '\0';
    return i;
}

void wait(int sec) {
#ifdef __unix__
    sleep(sec);
#elif defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
    Sleep(sec * 1000);
#endif
}

ListNode* cleanupProcesses(ListNode* head) {
    ListNode* tmp = head;
    while (tmp != NULL) {
        ProcessInfo* pi = tmp->data;
        if (readProcessInfo(pi->pid) == NULL) {
            printf("Process %d has terminated.\n", pi->pid);
            if (tmp == head) {
                head = tmp->next;
                free(pi);
                free(tmp);
                tmp = head;
            } else {
                ListNode* p = head;
                while (p->next != tmp) {
                    p = p->next;
                }
                p->next = tmp->next;
                free(pi);
                free(tmp);
                tmp = p->next;
            }
        } else {
            tmp = tmp->next;
        }
    }
    return head;
}

ListNode* updateProcessInfo(ListNode* head) {
    int pid;
    printf("Enter PID to track memory usage: ");
    scanf("%d", &pid);
    getchar();
    if (processExists(head, pid)) {
        printf("Process with PID %d is already being monitored.\n", pid);
        return head;
    }
    ProcessInfo* pi = readProcessInfo(pid);
    if (pi == NULL) {
        printf("No process with PID %d found.\n", pid);
        return head;
    }
    ListNode* node = createNode(pi);
    if (head == NULL) {
        head = node;
    } else {
        ListNode* tmp = head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
    return head;
}

int main() {
    ListNode *processList = NULL;
    int choice;
    do {
        printf("\nMemory Monitor\n");
        printf("==============\n");
        printf("1. List Tracked Processes\n");
        printf("2. Track a Process\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
        case 1:
            cleanupProcesses(processList);
            printAllProcesses(processList);
            break;
        case 2:
            processList = updateProcessInfo(processList);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
        wait(2);
        system("clear");
    } while (choice != 3);
    return 0;
}