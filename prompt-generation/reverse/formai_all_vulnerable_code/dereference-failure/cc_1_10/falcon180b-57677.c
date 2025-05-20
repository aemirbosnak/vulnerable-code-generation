//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_CONSPIRACIES 100

typedef struct {
    char *name;
    int index;
} ConspiracyTheory;

ConspiracyTheory conspiracies[MAX_CONSPIRACIES];

void *generate_conspiracy(void *arg) {
    int i, j, k;
    char *adjective, *noun, *verb, *preposition, *article;
    ConspiracyTheory *theory = (ConspiracyTheory *) arg;

    srand(time(NULL) + theory->index);

    adjective = (char *) malloc(sizeof(char) * 10);
    noun = (char *) malloc(sizeof(char) * 10);
    verb = (char *) malloc(sizeof(char) * 10);
    preposition = (char *) malloc(sizeof(char) * 10);
    article = (char *) malloc(sizeof(char) * 10);

    for (i = 0; i < 10; i++) {
        adjective[i] = 'a' + rand() % 26;
        noun[i] = 'a' + rand() % 26;
        verb[i] = 'a' + rand() % 26;
        preposition[i] = 'a' + rand() % 26;
        article[i] = 'a' + rand() % 26;
    }

    theory->name = (char *) malloc(sizeof(char) * 100);
    sprintf(theory->name, "%s %s %s %s %s %s", adjective, noun, verb, preposition, article, "conspiracy theory");

    pthread_exit(0);
}

int main() {
    int i, j;
    pthread_t threads[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        ConspiracyTheory theory;
        theory.index = i;
        pthread_create(&threads[i], NULL, generate_conspiracy, (void *) &theory);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < MAX_CONSPIRACIES; i++) {
        printf("%s\n", conspiracies[i].name);
    }

    return 0;
}