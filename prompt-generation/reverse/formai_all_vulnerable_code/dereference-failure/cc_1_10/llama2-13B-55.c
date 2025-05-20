//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 64

struct password {
    char *username;
    char *password;
};

struct password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached (%d).\n", MAX_PASSWORDS);
        return;
    }

    passwords[num_passwords].username = username;
    passwords[num_passwords].password = password;
    num_passwords++;
}

void list_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("%d: %s (%s)\n", i, passwords[i].username, passwords[i].password);
    }
}

void remove_password(int index) {
    if (index < 0 || index >= num_passwords) {
        printf("Error: Invalid index (%d).\n", index);
        return;
    }

    memmove(passwords + index, passwords + index + 1, (num_passwords - index - 1) * sizeof(struct password));
    num_passwords--;
}

int main() {
    char *username, *password;

    initscr();
    cbreak();

    while (1) {
        printf("Username: ");
        fgets(username, MAX_LENGTH, stdin);
        printf("Password: ");
        fgets(password, MAX_LENGTH, stdin);

        add_password(username, password);
        list_passwords();

        printf("\nAdd another password? (y/n): ");
        char answer = getchar();

        if (answer == 'n') {
            break;
        }
    }

    endwin();

    return 0;
}