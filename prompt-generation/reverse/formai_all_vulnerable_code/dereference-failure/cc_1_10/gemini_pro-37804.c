//GEMINI-pro DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct password {
    char *username;
    char *password;
    char *website;
} password;

typedef struct password_list {
    password *passwords;
    int num_passwords;
} password_list;

password_list *create_password_list() {
    password_list *list = malloc(sizeof(password_list));
    list->passwords = NULL;
    list->num_passwords = 0;
    return list;
}

void add_password(password_list *list, char *username, char *password, char *website) {
    list->passwords = realloc(list->passwords, (list->num_passwords + 1) * sizeof(password));
    list->passwords[list->num_passwords].username = strdup(username);
    list->passwords[list->num_passwords].password = strdup(password);
    list->passwords[list->num_passwords].website = strdup(website);
    list->num_passwords++;
}

void print_password_list(password_list *list) {
    for (int i = 0; i < list->num_passwords; i++) {
        printf("Username: %s\n", list->passwords[i].username);
        printf("Password: %s\n", list->passwords[i].password);
        printf("Website: %s\n\n", list->passwords[i].website);
    }
}

void free_password_list(password_list *list) {
    for (int i = 0; i < list->num_passwords; i++) {
        free(list->passwords[i].username);
        free(list->passwords[i].password);
        free(list->passwords[i].website);
    }
    free(list->passwords);
    free(list);
}

int main() {
    password_list *list = create_password_list();

    add_password(list, "Bob", "123456", "www.example.com");
    add_password(list, "Alice", "abcdef", "www.example.org");
    add_password(list, "Charlie", "password", "www.example.net");

    print_password_list(list);

    free_password_list(list);

    return 0;
}