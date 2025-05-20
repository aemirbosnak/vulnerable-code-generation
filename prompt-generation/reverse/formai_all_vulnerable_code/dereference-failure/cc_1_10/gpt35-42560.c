//FormAI DATASET v1.0 Category: System process viewer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdbool.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ctype.h>

#define MAX_TITLE_LEN 25
#define MAX_PID_STR_LEN 10

typedef struct PNode { // Define process node struct
    pid_t pid;
    char *title;
    struct PNode* next;
} PNode;

typedef struct ProcessList { // Define process list struct
    PNode* head;
    PNode* tail;
    int length;
} ProcessList;

void printHeader() { // Print the header
    printf("%-10s%-25s\n", "PID", "Title");
    printf("%-10s%-25s\n", "---", "-----");
}

void printNode(PNode *node) { // Print the node
    printf("%-10d%-25s\n", node->pid, node->title);
}

void printList(ProcessList *list) { // Print the process list
    if (list->length <= 0) { // If the list is empty
        printf("No processes found.\n");
    } else { // Otherwise, print list
        printHeader();  
        PNode *currentNode = list->head;
        while (currentNode != NULL) {
            printNode(currentNode);
            currentNode = currentNode->next;
        }
    }
}

void addNode(ProcessList *list, pid_t pid, char* title) { // Add the node to the process list
    PNode *newNode = (PNode*)malloc(sizeof(PNode));
    newNode->pid = pid;
    newNode->title = (char*)malloc(sizeof(char)*MAX_TITLE_LEN);
    memset(newNode->title, '\0', sizeof(newNode->title));
    strncpy(newNode->title, title, MAX_TITLE_LEN);

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        list->length = 1;
        newNode->next = NULL;
    } else {
        newNode->next = NULL;
        list->tail->next = newNode;
        list->tail = newNode;
        list->length++;
    }
}

void clearList(ProcessList *list) { // Clear the process list
    if (list->length <= 0) { // If the list is empty
        return;
    } else {
        PNode *currentNode = list->head;
        while (currentNode != NULL) {
            PNode *tempNode = currentNode;
            free(tempNode->title);
            currentNode = currentNode->next;
            free(tempNode);
        }
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
    }
}

void getProcessList(ProcessList *list) { // Get the process list
    DIR *dirp;
    struct dirent *direntp;
    char proc_path[128], pid_str[16];

    if ((dirp = opendir("/proc")) == NULL) { // If opendir() fails, print error message
        perror("Could not open the /proc directory");
        return;
    } else {
        clearList(list);
        
        while ((direntp = readdir(dirp)) != NULL) { // Loop through the /proc directory
            if (isdigit(direntp->d_name[0])) { // If the directory name is a number (i.e., a process)

                pid_t pid = atoi(direntp->d_name);
                memset(proc_path, '\0', sizeof(proc_path));
                memset(pid_str, '\0', sizeof(pid_str));
                sprintf(pid_str, "%d", pid);
                strncpy(proc_path, "/proc/", 6);
                strcat(proc_path, pid_str);
                strcat(proc_path, "/comm");
                
                int fd = open(proc_path, O_RDONLY);
                if (fd != -1) { // If open() was successful, then process comm file
                    char buf[MAX_TITLE_LEN];
                    memset(buf, '\0', MAX_TITLE_LEN);
                    if (read(fd, buf, MAX_TITLE_LEN - 1)) {
                        addNode(list, pid, buf);
                    }
                    close(fd);
                }
            }
        }
        closedir(dirp);
    }
}

void sigintHandler(int signum) { // Signal Handler for SIGINT
    printf("Terminating program\n");
    exit(signum);
}

int main() { // Main function
    ProcessList list = { NULL, NULL, 0 }; // Initialize the process list
    getProcessList(&list); // Get process list

    printList(&list); // Print process list

    signal(SIGINT, sigintHandler); // Set SIGINT signal handler

    while (true) { // Main program loop
        sleep(3);
        getProcessList(&list);
        printf("\033[2J\033[H"); // ANSI escape code to clear screen
        printf("PID viewer\n");
        printf("===========================\n");
        printList(&list);
    }

    return 0;
}