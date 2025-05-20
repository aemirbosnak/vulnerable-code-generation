//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_SIZE 100
#define ERROR_EXIT 123

sigjmp_buf env;
volatile sig_atomic_t flag;

void handler(int signum) {
    siglongjmp(env, signum);
}

int main() {
    signal(SIGSEGV, handler);
    signal(SIGFPE, handler);
    signal(SIGABRT, handler);

    int *ptr = NULL;
    int i, j, k;
    char str[MAX_SIZE];

    printf("Donald Knuth's Error Handling Program\n");

    // Allocating memory with malloc
    ptr = (int *) malloc(sizeof(int) * MAX_SIZE);
    if (ptr == NULL) {
        perror("Error allocating memory");
        siglongjmp(env, ERROR_EXIT);
    }

    for (i = 0; i < MAX_SIZE; i++) {
        // Accessing invalid memory location
        if (i > MAX_SIZE) {
            ptr = &ptr[i];
            errno = 0;
            siglongjmp(env, SIGSEGV);
        }
        ptr[i] = i;
    }

    printf("Array initialized successfully!\n");

    // String manipulation with invalid index
    strcpy(str, "This is a string");
    for (i = 0; i < MAX_SIZE; i++) {
        if (i > strlen(str)) {
            str[i] = 'X';
            errno = 0;
            siglongjmp(env, SIGSEGV);
        }
        str[i] = str[i] + 1;
    }

    printf("String manipulation successful!\n");

    // Performing invalid arithmetic operation
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            for (k = 0; k < MAX_SIZE; k++) {
                if ((i + j + k) > MAX_SIZE) {
                    int result = i / (j + k);
                    errno = 0;
                    siglongjmp(env, SIGFPE);
                }
                ptr[i] += ptr[j] * ptr[k];
            }
        }
    }

    printf("Array calculated successfully!\n");

    free(ptr);

    // Exiting program with abort()
    abort();

    // Reaching here is a success
    printf("Program executed successfully!\n");

    return 0;
}