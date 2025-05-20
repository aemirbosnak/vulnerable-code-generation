//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 2
#define MAX_WORDS 100

// function to generate random words for typing test
char* generate_word() {
    char* words[MAX_WORDS] = {"apple", "banana", "cherry", "dog", "elephant", "flower", "guitar", "hospital", "internet", "jacket", "kangaroo", "lemon", "mountain", "notebook", "orange", "pencil", "queen", "rabbit", "sunflower", "telephone", "umbrella", "violin", "watermelon", "xylophone", "yacht", "zebra"};
    int n = rand() % MAX_WORDS;
    return words[n];
}

// function executed by each thread
void* type_text(void* threadid) {
    long tid;
    tid = (long)threadid;
    int num_words = 10;
    int correct_words = 0;
    char* typed_words[num_words];
    clock_t start = clock();

    for (int i = 0; i < num_words; i++) {
        char* word = generate_word();
        printf("Type the word: %s\n", word);
        scanf("%s", typed_words[i]);
        if (strcmp(word, typed_words[i]) == 0) {
            correct_words++;
        }
    }

    clock_t end = clock();
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Thread %ld: Correct Words = %d, Time taken = %f seconds\n", tid, correct_words, time_taken);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, type_text, (void*) t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
    return 0;
}