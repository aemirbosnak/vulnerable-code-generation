//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <unistd.h>

#define MAX_STRINGS 100
#define MAX_STRING_LEN 100

typedef struct {
    char *str;
    int len;
    int id;
} String;

String strings[MAX_STRINGS];
pthread_t threads[MAX_STRINGS];

sem_t lock;

void *thread_func(void *param) {
    String *str = param;
    int id = str->id;
    char *input = malloc(MAX_STRING_LEN);

    printf("Thread %d is waiting for input...\n", id);
    fgets(input, MAX_STRING_LEN, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    sem_wait(&lock);
    strcpy(str->str, input);
    str->len = strlen(str->str);
    printf("Thread %d has modified string %d.\n", id, str->len);
    sem_post(&lock);

    free(input);
    return NULL;
}

int main() {
    int num_strings;
    printf("Enter number of strings: ");
    scanf("%d", &num_strings);

    for (int i = 0; i < num_strings; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(strings[i].str, MAX_STRING_LEN, stdin);
        strings[i].len = strlen(strings[i].str);
        strings[i].id = i + 1;
    }

    sem_init(&lock, 0, 1);

    for (int i = 0; i < num_strings; i++) {
        pthread_create(&threads[i], NULL, thread_func, &strings[i]);
    }

    for (int i = 0; i < num_strings; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}