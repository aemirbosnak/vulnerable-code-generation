//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024
#define MAX_PROCESS 64

void print_usage(void);
void run_command(char *cmd);
void create_user(char *username, char *password);
void list_users(void);
void delete_user(char *username);

int main(void)
{
    char *cmd;
    char username[20];
    char password[20];

    print_usage();

    while (1) {
        printf("> ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        if (cmd[0] == '\0')
            continue;

        if (strcmp(cmd, "create-user") == 0) {
            if (sscanf(cmd + 1, "%19s %19s", username, password) != 2) {
                printf("Usage: create-user <username> <password>\n");
                continue;
            }
            create_user(username, password);
        } else if (strcmp(cmd, "list-users") == 0) {
            list_users();
        } else if (strcmp(cmd, "delete-user") == 0) {
            if (sscanf(cmd + 1, "%19s", username) != 1) {
                printf("Usage: delete-user <username>\n");
                continue;
            }
            delete_user(username);
        } else {
            run_command(cmd);
        }
    }

    return 0;
}

void print_usage(void)
{
    printf("Available commands:\n");
    printf("  create-user <username> <password>     Create a new user\n");
    printf("  list-users                          List all users\n");
    printf("  delete-user <username>             Delete a user\n");
    printf("  run-command <command>             Run a command\n");
}

void run_command(char *cmd)
{
    int status;
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        // Child process
        execv(cmd, NULL);
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        wait(&status);
    } else {
        // Error
        perror("fork");
    }
}

void create_user(char *username, char *password)
{
    int status;
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        // Child process
        char *cmd = "/usr/sbin/useradd";
        char *args[] = {"-m", "-s", "/bin/bash", username, password, NULL};
        execv(cmd, args);
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        wait(&status);
    } else {
        // Error
        perror("fork");
    }
}

void list_users(void)
{
    int status;
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        // Child process
        char *cmd = "/usr/bin/lsusr";
        execv(cmd, NULL);
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        wait(&status);
    } else {
        // Error
        perror("fork");
    }
}

void delete_user(char *username)
{
    int status;
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        // Child process
        char *cmd = "/usr/sbin/userdel";
        char *args[] = {"-r", username, NULL};
        execv(cmd, args);
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        wait(&status);
    } else {
        // Error
        perror("fork");
    }
}