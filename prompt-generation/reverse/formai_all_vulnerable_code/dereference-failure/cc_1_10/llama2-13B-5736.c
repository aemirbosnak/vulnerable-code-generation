//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_ATTEMPTS 3

struct password {
    char *name;
    char *password;
    int attempts;
};

struct password *passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *name, char *password) {
    passwords[num_passwords] = malloc(sizeof(struct password));
    passwords[num_passwords]->name = name;
    passwords[num_passwords]->password = password;
    passwords[num_passwords]->attempts = 0;
    num_passwords++;
}

int verify_password(char *name, char *password) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i]->name, name) == 0 &&
                strcmp(passwords[i]->password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

int get_password(char *name) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i]->name, name) == 0) {
            return passwords[i]->password;
        }
    }
    return NULL;
}

void update_password(char *name, char *new_password) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i]->name, name) == 0) {
            passwords[i]->password = new_password;
            break;
        }
    }
}

void reset_password(char *name) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i]->name, name) == 0) {
            passwords[i]->attempts = 0;
            break;
        }
    }
}

void log_attempts(char *name) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i]->name, name) == 0) {
            printf("%s attempt %d: %s\n", name, passwords[i]->attempts, passwords[i]->password);
            break;
        }
    }
}

int main() {
    char *names[] = {"alice", "bob", "charlie"};
    char *passwords[] = {"secret", "password123", "ilovecats"};
    int i;

    for (i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
        add_password(names[i], passwords[i]);
    }

    for (i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
        char *name = names[i];
        char *password = get_password(name);
        if (password != NULL) {
            printf("Success: %s uses %s\n", name, password);
        } else {
            printf("Failed: %s does not use %s\n", name, passwords[i]);
        }

        log_attempts(name);

        if (strcmp(passwords[i], "password123") == 0) {
            reset_password(name);
        }
    }

    return 0;
}