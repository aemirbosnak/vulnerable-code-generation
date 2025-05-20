//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} User;

typedef struct {
    User *users[MAX_USERS]; 
    int count;
} Database;

typedef struct {
    int id;      
    int index;   
} Index;

Database db;

Index *index_array[MAX_USERS];
int index_count = 0;

void init_database() {
    db.count = 0;
}

void add_user(int id, const char *name) {
    if (db.count >= MAX_USERS) {
        printf("Cannot add more users to the database.\n");
        return;
    }
    User *user = malloc(sizeof(User));
    user->id = id;
    strncpy(user->name, name, MAX_NAME_LENGTH - 1);
    user->name[MAX_NAME_LENGTH - 1] = '\0';

    db.users[db.count] = user;
    db.count++;

    Index *idx = malloc(sizeof(Index));
    idx->id = id;
    idx->index = db.count - 1;

    index_array[index_count] = idx;
    index_count++;
}

int find_user_index(int id) {
    for (int i = 0; i < index_count; i++) {
        if (index_array[i]->id == id) {
            return index_array[i]->index;
        }
    }
    return -1;
}

User *get_user_by_id(int id) {
    int index = find_user_index(id);
    if (index != -1) {
        return db.users[index];
    }
    return NULL;
}

void display_user(User *user) {
    if (user) {
        printf("User ID: %d, Name: %s\n", user->id, user->name);
    } else {
        printf("User not found.\n");
    }
}

void free_database() {
    for (int i = 0; i < db.count; i++) {
        free(db.users[i]);
    }
    for (int i = 0; i < index_count; i++) {
        free(index_array[i]);
    }
}

int main() {
    init_database();
    
    add_user(1, "Alice");
    add_user(2, "Bob");
    add_user(3, "Charlie");

    printf("Enter User ID to search: ");
    int id;
    scanf("%d", &id);

    User *user = get_user_by_id(id);
    display_user(user);

    free_database();
    return 0;
}