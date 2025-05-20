//Falcon2-11B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

struct password {
    char* password;
    struct password* next;
};

struct password* root = NULL;

struct password* add_password(char* password) {
    struct password* new_password = (struct password*) malloc(sizeof(struct password));
    if (new_password == NULL) {
        perror("malloc");
        return NULL;
    }

    new_password->password = strdup(password);
    new_password->next = root;
    root = new_password;

    return root;
}

struct password* remove_password(char* password) {
    struct password* current = root;
    struct password* prev = NULL;

    while (current!= NULL) {
        if (strcmp(current->password, password) == 0) {
            if (prev!= NULL) {
                prev->next = current->next;
            } else {
                root = current->next;
            }
            free(current->password);
            free(current);
            return root;
        }

        prev = current;
        current = current->next;
    }

    return root;
}

int main() {
    char* password = "password123";
    struct password* p = add_password(password);
    printf("Password added: %s\n", p->password);

    p = remove_password(password);
    printf("Password removed: %s\n", p->password);

    return 0;
}