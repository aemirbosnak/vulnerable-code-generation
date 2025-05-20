//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 64

struct password {
    char *name;
    char *password;
};

typedef struct password password_t;

password_t passwords[MAX_PASSWORDS];
int curr_password = 0;

void init_passwords() {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = NULL;
        passwords[i].password = NULL;
    }
}

void add_password(const char *name, const char *password) {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (passwords[i].name == NULL) {
            passwords[i].name = name;
            passwords[i].password = password;
            break;
        }
    }
}

void print_passwords() {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (passwords[i].name != NULL) {
            printf("%s: %s\n", passwords[i].name, passwords[i].password);
        }
    }
}

void generate_password(const char *name, const char *pattern) {
    int i;
    for (i = 0; i < MAX_LENGTH; i++) {
        passwords[curr_password].password[i] = pattern[i % strlen(pattern)];
    }
    passwords[curr_password].name = name;
    curr_password = (curr_password + 1) % MAX_PASSWORDS;
}

int main() {
    srand(time(NULL));
    init_passwords();

    char name[] = "John Doe";
    char password[] = "123456";
    add_password(name, password);

    name[0] = 'J';
    name[1] = 'o';
    name[2] = 'h';
    name[3] = 'n';
    name[4] = 'D';
    name[5] = 'o';
    name[6] = 'e';
    generate_password(name, "0123456789abcdef");

    name[0] = 'J';
    name[1] = 'o';
    name[2] = 'h';
    name[3] = 'n';
    name[4] = 'D';
    name[5] = 'o';
    name[6] = 'e';
    generate_password(name, "fghijklmnopqrst");

    name[0] = 'J';
    name[1] = 'o';
    name[2] = 'h';
    name[3] = 'n';
    name[4] = 'D';
    name[5] = 'o';
    name[6] = 'e';
    generate_password(name, " ABCDEFGHIJKLMNOPQRST");

    print_passwords();
    return 0;
}