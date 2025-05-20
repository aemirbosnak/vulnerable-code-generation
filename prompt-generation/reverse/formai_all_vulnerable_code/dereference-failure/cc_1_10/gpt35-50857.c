//FormAI DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

void error_handler(int sig_num)
{
    printf("\nReceived Signal: %d\n", sig_num);
    switch(sig_num)
    {
        case SIGABRT:
            printf("Program was aborted.\n");
            break;
        case SIGFPE:
            printf("Floating point exception.\n");
            break;
        case SIGILL:
            printf("Illegal instruction.\n");
            break;
        case SIGINT:
            printf("Program interrupted.\n");
            break;
        case SIGSEGV:
            printf("Segmentation fault.\n");
            break;
        case SIGTERM:
            printf("Termination request.\n");
            break;
        default:
            printf("Unknown error occurred.\n");
    }
    exit(1);
}

int main()
{
    if (signal(SIGABRT, error_handler) == SIG_ERR)
    {
        printf("Error handling SIGABRT\n");
        exit(1);
    }
    if (signal(SIGFPE, error_handler) == SIG_ERR)
    {
        printf("Error handling SIGFPE\n");
        exit(1);
    }
    if (signal(SIGILL, error_handler) == SIG_ERR)
    {
        printf("Error handling SIGILL\n");
        exit(1);
    }
    if (signal(SIGINT, error_handler) == SIG_ERR)
    {
        printf("Error handling SIGINT\n");
        exit(1);
    }
    if (signal(SIGSEGV, error_handler) == SIG_ERR)
    {
        printf("Error handling SIGSEGV\n");
        exit(1);
    }
    if (signal(SIGTERM, error_handler) == SIG_ERR)
    {
        printf("Error handling SIGTERM\n");
        exit(1);
    }

    // Sample error that can occur in this program
    int* ptr = NULL;
    *ptr = 10;

    return 0;
}