//GEMINI-pro DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PASSWORDS 100

typedef struct {
    char *username;
    char *password;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

pthread_mutex_t lock;

void add_password(char *username, char *password) {
    pthread_mutex_lock(&lock);

    if (num_passwords == MAX_PASSWORDS) {
        printf("Error: Password list is full.\n");
        pthread_mutex_unlock(&lock);
        return;
    }

    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);
    num_passwords++;

    pthread_mutex_unlock(&lock);
}

char *get_password(char *username) {
    pthread_mutex_lock(&lock);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            pthread_mutex_unlock(&lock);
            return passwords[i].password;
        }
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

void *thread_func(void *arg) {
    char *username = (char *)arg;
    char *password = get_password(username);
    if (password != NULL) {
        printf("Username: %s, Password: %s\n", username, password);
    } else {
        printf("Error: Username not found.\n");
    }
    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    pthread_mutex_init(&lock, NULL);

    add_password("alice", "password1");
    add_password("bob", "password2");
    add_password("charlie", "password3");

    pthread_create(&tid1, NULL, thread_func, "alice");
    pthread_create(&tid2, NULL, thread_func, "bob");

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}