//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 4

typedef struct {
    char *str;
    int len;
    int is_palindrome;
} palindrome_check_args;

void *palindrome_check(void *args) {
    palindrome_check_args *a = (palindrome_check_args *)args;

    int i = 0;
    int j = a->len - 1;
    while (i < j) {
        if (a->str[i] != a->str[j]) {
            a->is_palindrome = 0;
            return NULL;
        }
        i++;
        j--;
    }

    a->is_palindrome = 1;
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string1> <string2> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num_strings = argc - 1;
    pthread_t threads[MAX_THREADS];
    palindrome_check_args args[MAX_THREADS];

    int num_threads_created = 0;
    for (int i = 0; i < num_strings; i++) {
        args[i].str = argv[i + 1];
        args[i].len = strlen(argv[i + 1]);
        args[i].is_palindrome = -1;

        if (num_threads_created < MAX_THREADS) {
            pthread_create(&threads[num_threads_created], NULL, palindrome_check, &args[num_threads_created]);
            num_threads_created++;
        } else {
            for (int j = 0; j < num_threads_created; j++) {
                pthread_join(threads[j], NULL);
            }
            num_threads_created = 0;
            pthread_create(&threads[num_threads_created], NULL, palindrome_check, &args[num_threads_created]);
            num_threads_created++;
        }
    }

    for (int i = 0; i < num_threads_created; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_strings; i++) {
        if (args[i].is_palindrome == 1) {
            printf("%s is a palindrome\n", args[i].str);
        } else if (args[i].is_palindrome == 0) {
            printf("%s is not a palindrome\n", args[i].str);
        } else {
            fprintf(stderr, "Error checking palindrome for string %s\n", args[i].str);
        }
    }

    return EXIT_SUCCESS;
}