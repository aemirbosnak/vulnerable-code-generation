//FormAI DATASET v1.0 Category: Error handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void catch_exit(int sig) {
    switch(sig) {
        case SIGABRT:
            printf("Abnormal termination of program!\n");
            break;
        case SIGFPE:
            printf("Arithmetic error, FPU exception occurred!\n");
            break;
        case SIGILL:
            printf("Illegal instruction detected or invalid memory reference!\n");
            break;
        case SIGSEGV:
            printf("Segmentation fault, invalid memory access!\n");
            break;
        case SIGTERM:
            printf("Termination request received!\n");
            break;
    }
    exit(1);
}

int main(int argc, char *argv[]) {
    int *p = NULL;
    int n = 10;
    int i;

    signal(SIGABRT, catch_exit);
    signal(SIGFPE, catch_exit);
    signal(SIGILL, catch_exit);
    signal(SIGSEGV, catch_exit);
    signal(SIGTERM, catch_exit);

    p = (int *) malloc (sizeof(int) * n);

    if (p == NULL) {
        printf("Memory allocation failed, exiting program!\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        p[i] = i+1;
    }

    free(p);

    // Generating SIGSEGV error by accessing invalid memory
    p[0] = 100;

    return 0;
}