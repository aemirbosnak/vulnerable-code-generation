//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PASSWORDS 100
#define MAX_ENTRIES 50
#define PASSWORD_LEN 32

struct password_entry {
    char *username;
    char *password;
    struct password_entry *next;
};

struct password_db {
    struct password_entry *head;
    struct password_entry *tail;
};

void init_password_db(struct password_db *db) {
    db->head = NULL;
    db->tail = NULL;
}

int add_password(struct password_db *db, char *username, char *password) {
    struct password_entry *new_entry = (struct password_entry *) malloc(sizeof(struct password_entry));
    new_entry->username = username;
    new_entry->password = password;
    new_entry->next = NULL;

    if (db->head == NULL) {
        db->head = new_entry;
        db->tail = new_entry;
    } else {
        db->tail->next = new_entry;
        db->tail = new_entry;
    }

    return 0;
}

int get_password(struct password_db *db, char *username) {
    struct password_entry *current = db->head;
    struct password_entry *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            return current->password;
        }
        previous = current;
        current = current->next;
    }

    return NULL;
}

int main() {
    struct password_db db;
    char *username, *password;

    init_password_db(&db);

    // Add some passwords
    add_password(&db, "user1", "password1");
    add_password(&db, "user2", "password2");
    add_password(&db, "user3", "password3");

    // Get some passwords
    username = "user1";
    password = get_password(&db, username);
    if (password != NULL) {
        printf("Password for %s is %s\n", username, password);
    } else {
        printf("No password found for %s\n", username);
    }

    username = "user2";
    password = get_password(&db, username);
    if (password != NULL) {
        printf("Password for %s is %s\n", username, password);
    } else {
        printf("No password found for %s\n", username);
    }

    return 0;
}