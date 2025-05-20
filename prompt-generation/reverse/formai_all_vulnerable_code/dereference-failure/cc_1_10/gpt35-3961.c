//FormAI DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    char email[100];
} User;

typedef struct {
    User* users;
    int num_users;
} Database;

void add_user(Database* db, User user) {
    db->users = realloc(db->users, (db->num_users + 1) * sizeof(User));
    db->users[db->num_users++] = user;
    printf("User %s successfully added to the database!\n", user.name);
}

void print_users(Database* db) {
    for(int i = 0; i < db->num_users; i++) {
        printf("ID: %d \nName: %s \nEmail: %s \n\n", db->users[i].id, db->users[i].name, db->users[i].email);
    }
}

void index_users(Database* db) {
    for(int i = 0; i < db->num_users; i++) {
        db->users[i].id = i + 1;
    }
}

int main() {
    Database db = {0};
    
    User user1 = {.name = "John Smith", .email = "johnsmith@gmail.com"};
    User user2 = {.name = "Jane Doe", .email = "janedoe@yahoo.com"};
    User user3 = {.name = "Bob Johnson", .email = "bjohnson@hotmail.com"};
    
    add_user(&db, user1);
    add_user(&db, user2);
    add_user(&db, user3);
    
    index_users(&db);
    
    printf("List of Users:\n\n");
    print_users(&db);
    
    return 0;
}