//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printArt(void *input);

int main(int argc, char *argv[]) {

    pthread_t thread_id;
    char *input = argv[1];

    if (argc != 2) {
        printf("Usage: %s string\n", argv[0]);
        return 1;
    }

    pthread_create(&thread_id, NULL, printArt, (void *) input);

    pthread_join(thread_id, NULL);
    
    return 0;
}

void *printArt(void *input) {
    char *s = (char *) input;

    int i, j;
    for (i = 0; s[i] != '\0'; i++) {

        switch (s[i]) {
            case 'a':
            case 'A':
                printf("  /\\ /\n");
                printf(" / / \\ \n");
                printf("/_/ _\\_\\ \n\n");
                break;

            case 'b':
            case 'B':
                printf("|¯¯¯\\\n");
                printf("|  _/---\\ \n");
                printf("|_/¯|___|\n\n");
                break;

            case 'c':
            case 'C':
                printf("   ___ \n");
                printf("  / __\\\n");
                printf(" / /   \n");
                printf(" \\\\___\\\n\n");
                break;

            case 'd':
            case 'D':
                printf("|¯¯\\ \n");
                printf("|  _\\---\\\n");
                printf("|_/¯|___/\n\n");
                break;

            //Add more ASCII art for each character

            default:
                printf("     ");
        }
    }
    return NULL;
}