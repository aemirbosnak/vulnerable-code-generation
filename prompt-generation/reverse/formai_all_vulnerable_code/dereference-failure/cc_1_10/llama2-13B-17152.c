//LLAMA2-13B DATASET v1.0 Category: Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LENGTH 1024
#define MAX_USERS 10

typedef struct {
    char name[50];
    int age;
} user_t;

user_t users[MAX_USERS];
int num_users = 0;

void add_user(char *name, int age) {
    if (num_users >= MAX_USERS) {
        printf("Error: Maximum number of users reached\n");
        return;
    }

    strcpy(users[num_users].name, name);
    users[num_users].age = age;
    num_users++;

    printf("User %s added with age %d\n", name, age);
}

void print_users() {
    int i;

    for (i = 0; i < num_users; i++) {
        printf("%d. %s (%d)\n", i + 1, users[i].name, users[i].age);
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        char name[50];
        int age = rand() % 50 + 1;

        add_user(name, age);
    }

    print_users();

    return 0;
}