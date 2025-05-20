//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define THREAD_COUNT 2

char* english_to_cat(char* english);
void* translator(void* arg);

int main() {
    pthread_t threads[THREAD_COUNT];
    char input[BUFFER_SIZE];
    char* cat_speak;

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter English phrases to translate into Cat speak:\n");

    while(1) {
        fgets(input, BUFFER_SIZE, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character
        
        if(strcmp(input, "exit") == 0) {
            break;
        }

        pthread_create(&threads[0], NULL, translator, (void*)input);
        pthread_join(threads[0], (void**)&cat_speak);

        printf("Cat says: %s\n", cat_speak);
        free(cat_speak);
    }

    printf("Goodbye!\n");

    return 0;
}

void* translator(void* arg) {
    char* english = (char*) arg;
    char* cat_speak = english_to_cat(english);

    pthread_exit((void*) cat_speak);
}

char* english_to_cat(char* english) {
    char* cat_speak = (char*) malloc(sizeof(char) * BUFFER_SIZE);

    if(strlen(english) % 2 != 0) {
        strcat(english, " "); // add space to end of odd length strings
    }

    for(int i = 0; i < strlen(english); i += 2 ) {
        cat_speak[i] = english[i + 1];
        cat_speak[i + 1] = english[i];
    }

    cat_speak[strlen(english)] = '\0';

    return cat_speak;
}