//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#define MAX_CONSPIRACIES 100
#define MAX_LENGTH 50

typedef struct {
    char text[MAX_LENGTH];
    int length;
} Conspiracy;

void generate_conspiracy(Conspiracy* c) {
    const char* nouns[] = {"government", "aliens", "corporations", "secret societies", "illuminati", "lizard people", "deep state", "big pharma", "military", "CIA"};
    const char* verbs[] = {"controls", "manipulates", "suppresses", "conspires with", "covers up", "monitors", "influences", "dominates", "exploits", "suppresses"};
    const char* objects[] = {"the media", "the economy", "the environment", "the food supply", "the weather", "the stock market", "the internet", "the truth", "the population", "the world"};

    srand(time(NULL));
    int noun_index = rand() % sizeof(nouns) / sizeof(nouns[0]);
    int verb_index = rand() % sizeof(verbs) / sizeof(verbs[0]);
    int object_index = rand() % sizeof(objects) / sizeof(objects[0]);

    sprintf(c->text, "%s %s %s.", nouns[noun_index], verbs[verb_index], objects[object_index]);
    c->length = strlen(c->text);
}

void* generate_conspiracies(void* arg) {
    int id = *(int*) arg;
    Conspiracy* conspiracies = (Conspiracy*) malloc(MAX_CONSPIRACIES * sizeof(Conspiracy));

    for (int i = 0; i < MAX_CONSPIRACIES; ++i) {
        generate_conspiracy(&conspiracies[i]);
    }

    printf("Thread %d generated %d conspiracies:\n", id, MAX_CONSPIRACIES);
    for (int i = 0; i < MAX_CONSPIRACIES; ++i) {
        printf("%s\n", conspiracies[i].text);
    }

    free(conspiracies);
    return NULL;
}

int main() {
    pthread_t threads[10];

    for (int i = 0; i < 10; ++i) {
        pthread_create(&threads[i], NULL, generate_conspiracies, (void*) i);
    }

    for (int i = 0; i < 10; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}