//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_ACTIONS 5
#define MAX_LENGTH 100

pthread_t tid[MAX_ACTIONS];
int current_action = 0;
pthread_mutex_t lock;

void* action(void* arg) {
    int action_number = *(int*)arg;
    free(arg);
    
    switch(action_number) {
        case 0:
            printf("You encounter a friendly fairy in the forest.\n");
            printf("Do you wish to (1) talk to her or (2) ignore her? ");
            break;
        case 1:
            printf("You decide to talk to the fairy. She offers you a magical potion!\n");
            printf("Do you accept it? (yes/no) ");
            break;
        case 2:
            printf("The fairy looks sad as you walk away. You miss a chance to learn magic!\n");
            break;
        case 3:
            printf("You spot a treasure chest nearby. Do you want to (1) open it or (2) leave it? ");
            break;
        case 4:
            printf("Inside the chest, you find gold and jewels! You're rich now!\n");
            break;
        default:
            printf("Invalid action!\n");
    }

    pthread_exit(NULL);
}

void start_game() {
    while (current_action < MAX_ACTIONS) {
        int *action_num = malloc(sizeof(int));
        *action_num = current_action;
        pthread_mutex_lock(&lock);
        pthread_create(&tid[current_action], NULL, action, action_num);
        pthread_mutex_unlock(&lock);
        current_action++;
        sleep(1);  // Simulate some delay in action processing
    }
}

void clean_up() {
    for (int i = 0; i < MAX_ACTIONS; i++) {
        pthread_join(tid[i], NULL);
    }
}

int main() {
    pthread_mutex_init(&lock, NULL);

    printf("Welcome to the Mystical Forest Adventure!\n");
    printf("You have entered a magical forest filled with wonders.\n");

    start_game();
    clean_up();

    pthread_mutex_destroy(&lock);

    return 0;
}