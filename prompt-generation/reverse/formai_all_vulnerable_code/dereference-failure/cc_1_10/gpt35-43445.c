//FormAI DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

typedef struct {
    char *username;
    char *password;
} credential;

bool isLoggedIn = false;
credential *loggedInUser;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

credential *generateRandomCredentials() {
    srand(time(NULL));
    char *username = malloc(sizeof(char) * 10);
    char *password = malloc(sizeof(char) * 10);
    int i;
    for (i = 0; i < 9; i++) {
        int r = rand() % 62;
        if (r < 26)
            username[i] = 'a' + r;
        else if (r < 52)
            username[i] = 'A' + (r - 26);
        else
            username[i] = '0' + (r - 52);
        
        r = rand() % 62;
        if (r < 26)
            password[i] = 'a' + r;
        else if (r < 52)
            password[i] = 'A' + (r - 26);
        else
            password[i] = '0' + (r - 52);
    }
    username[9] = '\0';
    password[9] = '\0';
    credential *cred = malloc(sizeof(credential));
    cred->username = username;
    cred->password = password;
    return cred;
}

void *printMessage(void *msg) {
    printf("%s", (char *) msg);
    return NULL;
}

void setPassword(credential *cred, char *password) {
    pthread_mutex_lock(&mutex);
    cred->password = password;
    pthread_mutex_unlock(&mutex);
}

bool login(char *username, char *password) {
    credential *cred = malloc(sizeof(credential));
    cred->username = username;
    cred->password = password;
    if (isLoggedIn) {
        pthread_t thread;
        char *msg = "ERROR: Already logged in.\n";
        pthread_create(&thread, NULL, printMessage, msg);
        pthread_join(thread, NULL);
        return false;
    }
    pthread_mutex_lock(&mutex);
    if (strcmp(loggedInUser->username, username) == 0 && strcmp(loggedInUser->password, password) == 0) {
        isLoggedIn = true;
    } else {
        pthread_t thread;
        char *msg = "ERROR: Invalid credentials.\n";
        pthread_create(&thread, NULL, printMessage, msg);
        pthread_join(thread, NULL);
    }
    pthread_mutex_unlock(&mutex);
    return isLoggedIn;
}

bool logout() {
    if (!isLoggedIn) {
        pthread_t thread;
        char *msg = "ERROR: Not logged in.\n";
        pthread_create(&thread, NULL, printMessage, msg);
        pthread_join(thread, NULL);
        return false;
    }
    pthread_mutex_lock(&mutex);
    loggedInUser = NULL;
    isLoggedIn = false;
    pthread_mutex_unlock(&mutex);
    return true;
}

int main() {
    credential *cred = generateRandomCredentials();
    printf("Generated Random Credentials:\n" );
    printf("Username: %s\n", cred->username);
    printf("Password: %s\n", cred->password);
    printf("=====================================\n");
    setPassword(cred, "newPassword");
    printf("Changed password to 'newPassword'.\n");
    printf("New password: %s\n", cred->password);
    printf("=====================================\n");
    loggedInUser = cred;
    printf("Logging in as '%s'...\n", cred->username);
    if (login(cred->username, cred->password)) {
        printf("Logged in successfully!\n");
        printf("=====================================\n");
        printf("Logging out...\n");
        if (logout())
            printf("Logged out successfully!\n");
    } else {
        printf("Could not log in.\n");
    }
    printf("=====================================\n");
    return 0;
}