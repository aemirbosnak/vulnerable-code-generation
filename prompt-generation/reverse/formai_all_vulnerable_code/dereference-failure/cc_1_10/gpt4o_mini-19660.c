//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 100
#define MAX_CMD_HISTORY 10

char *cmd_history[MAX_CMD_HISTORY];
int history_count = 0;
pthread_mutex_t history_mutex;

void *execute_command(void *arg) {
    char **args = (char **)arg;
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return NULL;
    } 
    
    if (pid == 0) {
        // In child process
        if (execvp(args[0], args) == -1) {
            perror("Execvp failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // In parent process
        wait(NULL);
    }
    
    return NULL;
}

void add_to_history(const char *cmd) {
    pthread_mutex_lock(&history_mutex);
    
    if (history_count < MAX_CMD_HISTORY) {
        cmd_history[history_count] = strdup(cmd);
        history_count++;
    } else {
        free(cmd_history[0]);
        for (int i = 1; i < MAX_CMD_HISTORY; i++) {
            cmd_history[i - 1] = cmd_history[i];
        }
        cmd_history[MAX_CMD_HISTORY - 1] = strdup(cmd);
    }
    
    pthread_mutex_unlock(&history_mutex);
}

void print_history() {
    pthread_mutex_lock(&history_mutex);
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, cmd_history[i]);
    }
    pthread_mutex_unlock(&history_mutex);
}

void cleanup_history() {
    pthread_mutex_lock(&history_mutex);
    for (int i = 0; i < history_count; i++) {
        free(cmd_history[i]);
    }
    history_count = 0;
    pthread_mutex_unlock(&history_mutex);
}

int main() {
    char cmd[MAX_CMD_LEN];
    pthread_mutex_init(&history_mutex, NULL);

    while (1) {
        printf("> ");
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            perror("fgets failed");
            break;
        }
        
        cmd[strcspn(cmd, "\n")] = '\0';  // Remove newline character
        
        if (strcmp(cmd, "exit") == 0) {
            cleanup_history();
            break;
        }
        
        if (strcmp(cmd, "history") == 0) {
            print_history();
            continue;
        }

        add_to_history(cmd);

        char *args[MAX_ARGS];
        char *token = strtok(cmd, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, execute_command, args) != 0) {
            perror("Failed to create thread");
        }
        pthread_detach(thread_id);
    }
    
    pthread_mutex_destroy(&history_mutex);
    return 0;
}