//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_ELEMENTS 10

typedef struct {
    char symbol[3];
    char name[20];
} Element;

Element periodic_table[NUM_ELEMENTS] = {
    {"H", "Hydrogen"},
    {"He", "Helium"},
    {"Li", "Lithium"},
    {"Be", "Beryllium"},
    {"B", "Boron"},
    {"C", "Carbon"},
    {"N", "Nitrogen"},
    {"O", "Oxygen"},
    {"F", "Fluorine"},
    {"Ne", "Neon"}
};

pthread_mutex_t lock;
int score = 0;

void *ask_question(void *arg) {
    int index = *((int *)arg);
    free(arg);
    char answer[20];

    printf("What is the name of the element with symbol '%s'?\n", periodic_table[index].symbol);
    printf("Your answer: ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;  // Remove newline character

    pthread_mutex_lock(&lock);
    if (strcmp(answer, periodic_table[index].name) == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is: %s\n", periodic_table[index].name);
    }
    pthread_mutex_unlock(&lock);

    return NULL;
}

void *display_score(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        printf("Current Score: %d\n", score);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_ELEMENTS];
    pthread_t score_thread;

    pthread_mutex_init(&lock, NULL);

    // Start score display thread
    pthread_create(&score_thread, NULL, display_score, NULL);

    // Create question threads
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        int *index = malloc(sizeof(int));
        *index = i;
        pthread_create(&threads[i], NULL, ask_question, index);
        sleep(1); // To space out the questions a bit
    }

    // Wait for question threads to finish
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Kill score display thread (not ideal but for simplicity)
    pthread_cancel(score_thread);
    pthread_join(score_thread, NULL);

    pthread_mutex_destroy(&lock);
    printf("Final Score: %d\n", score);
    return 0;
}