//Falcon2-11B DATASET v1.0 Category: Threading Library Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_MSG_LEN 100

char user_msg[MAX_MSG_LEN];
char ai_msg[MAX_MSG_LEN];

void* user_thread(void* arg) {
    char* user_input = (char*) arg;

    while (1) {
        printf("User: ");
        scanf("%s", user_msg);
        printf("AI: %s\n", ai_msg);
        usleep(2000000); // Wait 2 seconds before next input
    }

    return NULL;
}

void* ai_thread(void* arg) {
    char* user_input = (char*) arg;

    while (1) {
        sleep(1); // Simulate AI thinking
        sprintf(ai_msg, "AI: %s", user_input);
        usleep(2000000); // Wait 2 seconds before next input
    }

    return NULL;
}

int main() {
    pthread_t user_thread;
    pthread_t ai_thread;

    if (pthread_create(&user_thread, NULL, user_thread, (void*) user_msg)!= 0) {
        fprintf(stderr, "Error creating user thread\n");
        exit(1);
    }

    if (pthread_create(&ai_thread, NULL, ai_thread, (void*) user_msg)!= 0) {
        fprintf(stderr, "Error creating AI thread\n");
        exit(1);
    }

    pthread_join(user_thread, NULL);
    pthread_join(ai_thread, NULL);

    return 0;
}