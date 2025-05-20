//GEMINI-pro DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 100

typedef struct password {
    char *name;
    char *password;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *name, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        fprintf(stderr, "Error: Too many passwords\n");
        return;
    }

    passwords[num_passwords].name = strdup(name);
    passwords[num_passwords].password = strdup(password);
    num_passwords++;
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

void free_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        free(passwords[i].name);
        free(passwords[i].password);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [args]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];

    if (strcmp(command, "add") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Usage: %s add <name> <password>\n", argv[0]);
            return 1;
        }

        add_password(argv[2], argv[3]);
    } else if (strcmp(command, "list") == 0) {
        print_passwords();
    } else if (strcmp(command, "delete") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s delete <name>\n", argv[0]);
            return 1;
        }

        for (int i = 0; i < num_passwords; i++) {
            if (strcmp(passwords[i].name, argv[2]) == 0) {
                free(passwords[i].name);
                free(passwords[i].password);
                for (int j = i; j < num_passwords - 1; j++) {
                    passwords[j] = passwords[j + 1];
                }
                num_passwords--;
                break;
            }
        }
    } else {
        fprintf(stderr, "Unknown command: %s\n", command);
        return 1;
    }

    free_passwords();

    return 0;
}