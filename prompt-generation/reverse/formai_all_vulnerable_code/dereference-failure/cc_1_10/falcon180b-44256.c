//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_STRING_LENGTH 1000

typedef struct {
    char *string;
    int length;
} String;

void *check_palindrome(void *arg) {
    String *s = (String *) arg;
    bool is_palindrome = true;

    for (int i = 0; i < s->length / 2; i++) {
        if (s->string[i]!= s->string[s->length - i - 1]) {
            is_palindrome = false;
            break;
        }
    }

    if (is_palindrome) {
        printf("Palindrome found: %s\n", s->string);
    } else {
        printf("Not a palindrome: %s\n", s->string);
    }

    free(s->string);
    free(s);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    String strings[MAX_THREADS];

    int num_strings = 0;
    char buffer[MAX_STRING_LENGTH];

    printf("Enter strings to check for palindromes. Enter an empty string to finish.\n");

    while (fgets(buffer, MAX_STRING_LENGTH, stdin)!= NULL) {
        if (buffer[0] == '\n') {
            break;
        }

        strings[num_strings].string = strdup(buffer);
        strings[num_strings].length = strlen(buffer);

        pthread_create(&threads[num_strings], NULL, check_palindrome, &strings[num_strings]);

        num_strings++;
    }

    for (int i = 0; i < num_strings; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}