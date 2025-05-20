//FormAI DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    int age;
} User;

int main() {
    User *users = malloc(sizeof(User) * 5);

    // Initialize the data
    users[0].id = 1;
    users[0].name = "John";
    users[0].age = 25;

    users[1].id = 2;
    users[1].name = "Jane";
    users[1].age = 30;

    users[2].id = 3;
    users[2].name = "Bob";
    users[2].age = 40;

    users[3].id = 4;
    users[3].name = "Alice";
    users[3].age = 20;

    users[4].id = 5;
    users[4].name = "Tom";
    users[4].age = 35;

    // Query users by age
    int age_threshold = 30;

    for (int i = 0; i < 5; i++) {
        if (users[i].age >= age_threshold) {
            printf("User with id %d has age %d and name %s\n", users[i].id, users[i].age, users[i].name);
        }
    }

    // Query user by name
    char *name_query = "Tom";

    for (int i = 0; i < 5; i++) {
        if (strcmp(users[i].name, name_query) == 0) {
            printf("User with id %d has age %d and name %s\n", users[i].id, users[i].age, users[i].name);
        }
    }

    // Free the memory
    for (int i = 0; i < 5; i++) {
        free(users[i].name);
    }
    free(users);

    return 0;
}