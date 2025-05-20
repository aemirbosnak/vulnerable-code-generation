//GEMINI-pro DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>

#define MAX_PASSWORDS 100

struct password {
    char *username;
    char *password;
};

struct password_list {
    struct password passwords[MAX_PASSWORDS];
    int count;
};

struct password_list *password_list_new() {
    struct password_list *list = malloc(sizeof(struct password_list));
    if (list == NULL) {
        return NULL;
    }

    list->count = 0;

    return list;
}

void password_list_free(struct password_list *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->passwords[i].username);
        free(list->passwords[i].password);
    }

    free(list);
}

int password_list_add(struct password_list *list, char *username, char *password) {
    if (list->count >= MAX_PASSWORDS) {
        return -1;
    }

    list->passwords[list->count].username = strdup(username);
    list->passwords[list->count].password = strdup(password);
    list->count++;

    return 0;
}

int password_list_load(struct password_list *list, char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return -1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fd)) {
        char *username = strtok(line, ":");
        char *password = strtok(NULL, "\n");

        if (username != NULL && password != NULL) {
            password_list_add(list, username, password);
        }
    }

    close(fd);

    return 0;
}

int password_list_save(struct password_list *list, char *filename) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        return -1;
    }

    for (int i = 0; i < list->count; i++) {
        dprintf(fd, "%s:%s\n", list->passwords[i].username, list->passwords[i].password);
    }

    close(fd);

    return 0;
}

void password_list_print(struct password_list *list) {
    for (int i = 0; i < list->count; i++) {
        printf("%s:%s\n", list->passwords[i].username, list->passwords[i].password);
    }
}

int main() {
    struct password_list *list = password_list_new();
    if (list == NULL) {
        return 1;
    }

    if (password_list_load(list, "passwords.txt") == -1) {
        fprintf(stderr, "Error loading passwords from file.\n");
        return 1;
    }

    password_list_print(list);

    char username[1024];
    char password[1024];

    while (1) {
        printf("Enter username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = '\0';

        if (strcmp(username, "quit") == 0) {
            break;
        }

        printf("Enter password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';

        if (password_list_add(list, username, password) == -1) {
            fprintf(stderr, "Error adding password to list.\n");
            return 1;
        }
    }

    if (password_list_save(list, "passwords.txt") == -1) {
        fprintf(stderr, "Error saving passwords to file.\n");
        return 1;
    }

    password_list_free(list);

    return 0;
}