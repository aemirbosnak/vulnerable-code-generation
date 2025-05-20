//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_MAX_LENGTH 20
#define SEED 42

typedef struct password_entry {
    char *password;
    int frequency;
} password_entry;

typedef struct password_list {
    password_entry *entries;
    int capacity;
    int size;
} password_list;

password_list *create_password_list(int capacity) {
    password_list *pl = malloc(sizeof(password_list));
    pl->capacity = capacity;
    pl->size = 0;
    pl->entries = malloc(capacity * sizeof(password_entry));
    return pl;
}

void add_password(password_list *pl, char *password) {
    if (pl->size == pl->capacity) {
        password_entry *new_entries = realloc(pl->entries, (pl->capacity *= 2) * sizeof(password_entry));
        memset(new_entries + pl->size, 0, (pl->capacity - pl->size) * sizeof(password_entry));
        pl->entries = new_entries;
    }
    pl->entries[pl->size].password = password;
    pl->entries[pl->size].frequency = 1;
    pl->size++;
}

void print_password_list(password_list *pl) {
    for (int i = 0; i < pl->size; i++) {
        printf("%d. %s\n", i + 1, pl->entries[i].password);
    }
}

int main() {
    srand(SEED);
    password_list *pl = create_password_list(10);
    char *passwords[] = {"password1", "password2", "password3", "password4", "password5"};
    for (int i = 0; i < sizeof(passwords) / sizeof(char *); i++) {
        add_password(pl, passwords[i]);
    }
    print_password_list(pl);
    return 0;
}