//Falcon2-11B DATASET v1.0 Category: Password management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct password_entry {
    char* user;
    char* password;
};

struct password_entry* find_password(const char* user, struct password_entry* password_entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(password_entries[i].user, user) == 0) {
            return &password_entries[i];
        }
    }
    return NULL;
}

int main() {
    int num_entries = 5;
    struct password_entry* password_entries = malloc(num_entries * sizeof(struct password_entry));

    password_entries[0].user = "user1";
    password_entries[0].password = "pass1";

    password_entries[1].user = "user2";
    password_entries[1].password = "pass2";

    password_entries[2].user = "user3";
    password_entries[2].password = "pass3";

    password_entries[3].user = "user4";
    password_entries[3].password = "pass4";

    password_entries[4].user = "user5";
    password_entries[4].password = "pass5";

    char user[50];
    printf("Enter username: ");
    scanf("%s", user);

    struct password_entry* entry = find_password(user, password_entries, num_entries);

    if (entry!= NULL) {
        printf("Password for %s: %s\n", entry->user, entry->password);
    } else {
        printf("No password found for %s\n", user);
    }

    free(password_entries);
    return 0;
}