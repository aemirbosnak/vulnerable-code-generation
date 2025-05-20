//MISTRAL-7B DATASET v1.0 Category: Task Scheduler ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_TASKS 100
#define MAX_CMD_LEN 100

typedef struct {
    pid_t pid;
    char cmd[MAX_CMD_LEN];
    struct Node *next;
} Task;

typedef struct Node {
    Task task;
    struct Node *next;
} Node;

Node *head = NULL;
Node *current = NULL;

void add_task(char *cmd) {
    Task *new_task = malloc(sizeof(Task));
    strcpy(new_task->cmd, cmd);

    if (head == NULL) {
        head = malloc(sizeof(Node));
        head->next = NULL;
        head->task = *new_task;
        current = head;
    } else {
        Node *new_node = malloc(sizeof(Node));
        new_node->next = NULL;
        new_node->task = *new_task;
        current->next = new_node;
        current = new_node;
    }
}

void execute_task() {
    if (head == NULL) return;

    Task *task = &head->task;
    pid_t pid = fork();

    if (pid == 0) { // child process
        execlp(strtok(task->cmd, " "), strtok(task->cmd, " "), NULL);
        perror("Error executing command");
        exit(EXIT_FAILURE);
    } else if (pid > 0) { // parent process
        waitpid(pid, NULL, 0);
        free(head->task.cmd);
        Node *to_remove = head;
        head = head->next;
        free(to_remove);
    }
}

void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("Interrupted, shutting down scheduler.\n");
        while (head != NULL) {
            Node *to_remove = head;
            head = head->next;
            waitpid(to_remove->task.pid, NULL, 0);
            free(to_remove);
        }
        exit(EXIT_SUCCESS);
    }
}

int main() {
    sigset(SIGINT, signal_handler);

    char cmd[MAX_CMD_LEN];

    while (1) {
        printf("Enter command (or type 'quit' to exit): ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        if (strstr(cmd, "quit") != NULL) break;

        add_task(strtok(cmd, " "));
        execute_task();
    }

    while (head != NULL) {
        Node *to_remove = head;
        head = head->next;
        waitpid(to_remove->task.pid, NULL, 0);
        free(to_remove);
    }

    return 0;
}