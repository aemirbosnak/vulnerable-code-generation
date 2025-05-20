//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_DEPTH 5
#define MAX_PROCESSES 10

struct node {
    int pid;
    int status;
    struct node *parent;
    struct node *children[MAX_DEPTH];
};

void print_process_tree(struct node *root) {
    if (root == NULL) {
        return;
    }

    printf("Process Tree:\n");
    print_process_tree(root->parent);
    printf("  %d (%s) %s\n", root->pid, (root->status == 0) ? "running" : "dead", root->children[0] == NULL ? "no children" : "");
    for (int i = 0; i < MAX_DEPTH; i++) {
        print_process_tree(root->children[i]);
    }
}

void create_process(int parent_pid, char *command) {
    int pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return;
    }

    if (pid == 0) {
        // Child process
        char *argv[] = { "/bin/sh", "-c", command, NULL };
        execvp(command, argv);
        perror("execvp failed");
        exit(1);
    } else {
        // Parent process
        struct node *new_node = malloc(sizeof(struct node));
        new_node->pid = pid;
        new_node->status = 0;
        new_node->parent = NULL;
        for (int i = 0; i < MAX_DEPTH; i++) {
            new_node->children[i] = NULL;
        }
        if (parent_pid > 0) {
            new_node->parent = malloc(sizeof(struct node));
            new_node->parent->pid = parent_pid;
            new_node->parent->status = 0;
            new_node->parent->children[0] = new_node;
        }
        print_process_tree(new_node);
    }
}

int main() {
    char *commands[] = {
        "ls",
        "cd /",
        "ls",
        "cd ..",
        "ls",
        NULL
    };
    for (int i = 0; commands[i] != NULL; i++) {
        create_process(0, commands[i]);
    }
    return 0;
}