//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_WEBSITE_COUNT 10
#define MAX_WEBSITE_LENGTH 100
#define INTERVAL 30 // Check interval in seconds

pthread_mutex_t mutex;

struct website {
    char url[MAX_WEBSITE_LENGTH];
    bool is_up;
};

struct website websites[MAX_WEBSITE_COUNT];
int website_count = 0;

void *check_website(void *arg) {
    int index = *(int *) arg;
    free(arg);

    while (true) {
        // TODO: Send HTTP request to the URL and check response status
        // For now we just generate a random number
        int rand_num = rand() % 2;
        pthread_mutex_lock(&mutex);
        websites[index].is_up = rand_num;
        pthread_mutex_unlock(&mutex);
        sleep(INTERVAL);
    }

    return NULL;
}

int main() {
    int i;
    char url[MAX_WEBSITE_LENGTH];

    printf("Welcome to the website uptime monitor!\n");
    printf("Enter the URLs of the websites you want to monitor (up to %d), separated by spaces.\n", MAX_WEBSITE_COUNT);

    fgets(url, MAX_WEBSITE_LENGTH, stdin);
    char *token = strtok(url, " ");

    while (token != NULL && website_count < MAX_WEBSITE_COUNT) {
        strcpy(websites[website_count].url, token);
        websites[website_count].is_up = true;

        pthread_t tid;
        int *arg = malloc(sizeof(*arg));
        *arg = website_count;
        pthread_create(&tid, NULL, check_website, arg);

        website_count++;

        token = strtok(NULL, " ");
    }

    // Main thread loop
    while (true) {
        printf("\033[2J"); // Clear console
        printf("\033[H"); // Move cursor to top-left corner

        printf("Website uptime status:\n\n");

        pthread_mutex_lock(&mutex);
        for (i = 0; i < website_count; i++) {
            printf("%s: ", websites[i].url);
            if (websites[i].is_up) {
                printf("\033[32mUP\033[0m\n");
            } else {
                printf("\033[31mDOWN\033[0m\n");
            }
        }
        pthread_mutex_unlock(&mutex);

        sleep(INTERVAL);
    }

    return 0;
}