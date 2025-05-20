//FormAI DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNUSED(x) (void)(x)

#define PASS_MAX_LEN 50

struct Password 
{
    char *name;
    char *username;
    char *password;
};

struct Password *create_password(const char *name, const char *username, const char *password) 
{
    struct Password *p = malloc(sizeof(*p));
    if (!p) {
        printf("Error: could not allocate memory for password.\n");
        exit(1);
    }

    p->name = strdup(name);
    p->username = strdup(username);
    p->password = strdup(password);

    if (!p->name || !p->username || !p->password) {
        printf("Error: could not allocate memory for password fields.\n");
        exit(1);
    }

    return p;
}

void delete_password(struct Password *p)
{
    if (!p) {
        return;
    }

    free(p->name);
    free(p->username);
    free(p->password);
    free(p);
}

struct Password *get_user_password() 
{
    char *name = malloc(PASS_MAX_LEN + 1);
    char *username = malloc(PASS_MAX_LEN + 1);
    char *password = malloc(PASS_MAX_LEN + 1);

    if (!name || !username || !password) {
        printf("Error: could not allocate memory for user input.\n");
        free(name);
        free(username);
        free(password);
        return NULL;
    }

    printf("Enter website or application name: ");
    fgets(name, PASS_MAX_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter username or email: ");
    fgets(username, PASS_MAX_LEN, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(password, PASS_MAX_LEN, stdin);
    password[strcspn(password, "\n")] = '\0';

    struct Password *p = create_password(name, username, password);

    free(name);
    free(username);
    free(password);

    return p;
}

void print_password(struct Password *p)
{
    printf("Name: %s\nUsername/Email: %s\nPassword: %s\n", p->name, p->username, p->password);
}

int main(int argc, char *argv[]) 
{
    UNUSED(argc);
    UNUSED(argv);

    struct Password *p = get_user_password();

    if (p) {
        print_password(p);
        delete_password(p);
    }

    return 0;
}