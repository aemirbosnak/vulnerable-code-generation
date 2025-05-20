//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <grp.h>

#define MAX_GROUP_NAME_LEN 20
#define MAX_USER_NAME_LEN 20

void print_help(void);
void add_group(const char *group_name, const char *group_desc);
void add_user(const char *user_name, const char *user_desc);
void list_groups(void);
void list_users(void);
void remove_group(const char *group_name);
void remove_user(const char *user_name);

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("Welcome to the System Administration Tool!\n");
    printf("Please enter the command you would like to execute: ");

    char command[100];
    fgets(command, 100, stdin);

    if (strcmp(command, "help") == 0) {
        print_help();
    } else if (strcmp(command, "add-group") == 0) {
        add_group(command, NULL);
    } else if (strcmp(command, "add-user") == 0) {
        add_user(command, NULL);
    } else if (strcmp(command, "list-groups") == 0) {
        list_groups();
    } else if (strcmp(command, "list-users") == 0) {
        list_users();
    } else if (strcmp(command, "remove-group") == 0) {
        remove_group(command);
    } else if (strcmp(command, "remove-user") == 0) {
        remove_user(command);
    } else {
        printf("Invalid command. Please enter a valid command\n");
    }

    return 0;
}

void print_help(void) {
    printf("Available commands:\n");
    printf("  add-group <group_name> <group_desc>\n");
    printf("  add-user <user_name> <user_desc>\n");
    printf("  list-groups\n");
    printf("  list-users\n");
    printf("  remove-group <group_name>\n");
    printf("  remove-user <user_name>\n");
    printf("  help\n");
}

void add_group(const char *group_name, const char *group_desc) {
    char group_name_cpy[MAX_GROUP_NAME_LEN];
    char group_desc_cpy[MAX_GROUP_NAME_LEN];

    if (strlen(group_name) > MAX_GROUP_NAME_LEN) {
        printf("Group name cannot be longer than %d characters\n", MAX_GROUP_NAME_LEN);
        return;
    }

    strcpy(group_name_cpy, group_name);
    strcpy(group_desc_cpy, group_desc);

    // todo: add code to add group
    printf("Group %s added successfully\n", group_name_cpy);
}

void add_user(const char *user_name, const char *user_desc) {
    char user_name_cpy[MAX_USER_NAME_LEN];
    char user_desc_cpy[MAX_USER_NAME_LEN];

    if (strlen(user_name) > MAX_USER_NAME_LEN) {
        printf("User name cannot be longer than %d characters\n", MAX_USER_NAME_LEN);
        return;
    }

    strcpy(user_name_cpy, user_name);
    strcpy(user_desc_cpy, user_desc);

    // todo: add code to add user
    printf("User %s added successfully\n", user_name_cpy);
}

void list_groups(void) {
    // todo: list all groups
    printf("List of groups:\n");
}

void list_users(void) {
    // todo: list all users
    printf("List of users:\n");
}

void remove_group(const char *group_name) {
    // todo: remove group
    printf("Group %s removed successfully\n", group_name);
}

void remove_user(const char *user_name) {
    // todo: remove user
    printf("User %s removed successfully\n", user_name);
}