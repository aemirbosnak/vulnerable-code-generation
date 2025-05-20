//Falcon2-11B DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>

#define MAX_PASSWORDS 10
#define MAX_LEN 50

#define FILE_NAME "passwords.txt"

typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void *password_manager(void *args) {
    char *username = (char *)args;
    int i;
    
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", passwords[i].password);
            break;
        }
    }

    return NULL;
}

int main() {
    int fd, i, ret;
    char *username;

    pthread_t thread;
    pthread_attr_t attr;

    password_t *new_password = NULL;

    fd = open(FILE_NAME, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    ret = pthread_attr_init(&attr);
    if (ret) {
        perror("Error initializing thread attribute");
        exit(1);
    }

    ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    if (ret) {
        perror("Error setting thread attribute");
        exit(1);
    }

    for (i = 0; i < MAX_PASSWORDS; i++) {
        memset(passwords[i].username, 0, MAX_LEN);
        memset(passwords[i].password, 0, MAX_LEN);
        strcpy(passwords[i].username, "User");
        strcpy(passwords[i].password, "Password");
        printf("%s %s\n", passwords[i].username, passwords[i].password);
    }

    printf("Enter your username: ");
    fgets(username, MAX_LEN, stdin);
    username[strlen(username) - 1] = '\0';

    new_password = malloc(sizeof(password_t));
    if (new_password == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    memset(new_password->username, 0, MAX_LEN);
    memset(new_password->password, 0, MAX_LEN);
    strcpy(new_password->username, username);
    strcpy(new_password->password, "Password");
    printf("New password: %s %s\n", new_password->username, new_password->password);

    strcpy(FILE_NAME, "passwords.txt");
    ret = pthread_create(&thread, &attr, password_manager, (void *)new_password->username);
    if (ret) {
        perror("Error creating thread");
        exit(1);
    }

    ret = pthread_join(thread, NULL);
    if (ret) {
        perror("Error joining thread");
        exit(1);
    }

    printf("Username not found\n");
    free(new_password);

    close(fd);
    ret = pthread_attr_destroy(&attr);
    if (ret) {
        perror("Error destroying thread attribute");
        exit(1);
    }

    return 0;
}