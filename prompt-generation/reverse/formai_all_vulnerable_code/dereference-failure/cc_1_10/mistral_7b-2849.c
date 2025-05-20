//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_INPUT 1024
#define MAX_SAFE_INPUT 32
#define SHIFT_SIZE 5
#define SHIFT_CHAR '_'

char safe_input[MAX_SAFE_INPUT];
int safe_index = 0;

void print_usage() {
    printf("Usage: %s <safe_input>\n", __FILE__);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    strncpy(safe_input, argv[1], MAX_SAFE_INPUT);

    int len = strlen(safe_input);
    if (len > MAX_SAFE_INPUT) {
        printf("Error: Input too long\n");
        print_usage();
        return 1;
    }

    int i, j;
    for (i = 0; i < len; i++) {
        for (j = 0; j < SHIFT_SIZE && safe_index < MAX_INPUT; j++) {
            if (safe_input[i] == '_') {
                safe_input[safe_index++] = safe_input[i];
                break;
            }
            safe_input[safe_index++] = getchar();
            fgetc(stdin);
        }

        if (j == SHIFT_SIZE) {
            printf("Error: Input contains too many '%c'\n", SHIFT_CHAR);
            print_usage();
            return 1;
        }
    }

    safe_input[safe_index] = '\0';

    printf("Sanitized input: %s\n", safe_input);

    return 0;
}