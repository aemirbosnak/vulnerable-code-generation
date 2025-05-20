//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char name[MAX_LINE_LENGTH];
    int age;
} User;

int main() {
    char local_db_filename[] = "local.db";
    FILE* local_db_file;
    User* users[3];
    int num_users = 3;

    local_db_file = fopen(local_db_filename, "w");
    if (local_db_file == NULL) {
        perror("Failed to open local database file");
        return 1;
    }

    for (int i = 0; i < num_users; i++) {
        users[i] = (User*)malloc(sizeof(User));
        strcpy(users[i]->name, "User");
        users[i]->age = i + 1;
        fprintf(local_db_file, "%s,%d\n", users[i]->name, users[i]->age);
    }

    fclose(local_db_file);

    local_db_file = fopen(local_db_filename, "r");
    if (local_db_file == NULL) {
        perror("Failed to open local database file");
        return 1;
    }

    for (int i = 0; i < num_users; i++) {
        User* user = (User*)malloc(sizeof(User));
        if (fscanf(local_db_file, "%s,%d\n", user->name, &user->age)!= 2) {
            fprintf(stderr, "Failed to read user from local database file\n");
            return 1;
        }
        printf("User %s is %d years old\n", user->name, user->age);
        free(user);
    }

    fclose(local_db_file);

    return 0;
}