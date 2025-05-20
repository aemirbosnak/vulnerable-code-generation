//GEMINI-pro DATASET v1.0 Category: Password management ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct password {
    char *password;
    int length;
    time_t creationDate;
};

struct passwordManager {
    struct password *passwords;
    int numPasswords;
};

struct passwordManager *createPasswordManager() {
    struct passwordManager *manager = malloc(sizeof(struct passwordManager));
    manager->passwords = NULL;
    manager->numPasswords = 0;
    return manager;
}

void addPassword(struct passwordManager *manager, char *password) {
    manager->passwords = realloc(manager->passwords, (manager->numPasswords + 1) * sizeof(struct password));
    manager->passwords[manager->numPasswords].password = strdup(password);
    manager->passwords[manager->numPasswords].length = strlen(password);
    manager->passwords[manager->numPasswords].creationDate = time(NULL);
    manager->numPasswords++;
}

char *getPassword(struct passwordManager *manager, int index) {
    if (index < 0 || index >= manager->numPasswords) {
        return NULL;
    }
    return manager->passwords[index].password;
}

void removePassword(struct passwordManager *manager, int index) {
    if (index < 0 || index >= manager->numPasswords) {
        return;
    }
    free(manager->passwords[index].password);
    manager->numPasswords--;
    for (int i = index; i < manager->numPasswords; i++) {
        manager->passwords[i] = manager->passwords[i + 1];
    }
    manager->passwords = realloc(manager->passwords, manager->numPasswords * sizeof(struct password));
}

void printPasswordManager(struct passwordManager *manager) {
    for (int i = 0; i < manager->numPasswords; i++) {
        printf("Password %d: %s (created on %s)\n", i, manager->passwords[i].password, ctime(&manager->passwords[i].creationDate));
    }
}

void freePasswordManager(struct passwordManager *manager) {
    for (int i = 0; i < manager->numPasswords; i++) {
        free(manager->passwords[i].password);
    }
    free(manager->passwords);
    free(manager);
}

int main() {
    struct passwordManager *manager = createPasswordManager();

    addPassword(manager, "abc123");
    addPassword(manager, "def456");
    addPassword(manager, "ghi789");

    printPasswordManager(manager);

    char *password = getPassword(manager, 1);
    printf("Password 1: %s\n", password);

    removePassword(manager, 1);

    printPasswordManager(manager);

    freePasswordManager(manager);

    return 0;
}