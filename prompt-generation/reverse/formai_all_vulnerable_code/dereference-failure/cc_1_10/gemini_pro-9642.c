//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: Cyberpunk
// NeonSigns: A Cyberpunk String Manipulation Odyssey

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Terminal Emulation
#define ANSI_RESET     "\033[0m"
#define ANSI_BRIGHT    "\033[1m"
#define ANSI_RED       "\033[31m"
#define ANSI_GREEN     "\033[32m"
#define ANSI_YELLOW    "\033[33m"
#define ANSI_BLUE      "\033[34m"
#define ANSI_MAGENTA   "\033[35m"
#define ANSI_CYAN      "\033[36m"
#define ANSI_WHITE     "\033[37m"

// Constants
#define MAX_LINE_LEN 1024
#define MAX_ARGS      5

// Graffiti Painter
void paintGraffiti(char *input) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            printf("%s%c%s", ANSI_RED, input[i], ANSI_RESET);
        } else {
            printf("%s%c%s", ANSI_GREEN, input[i], ANSI_RESET);
        }
    }
    printf("\n");
}

// Neon Scroller
void scrollNeon(char *input) {
    int len = strlen(input);
    int offset = 0;
    while (offset < len) {
        printf("\r%s%s%s", ANSI_BLUE, input + offset, ANSI_RESET);
        offset++;
        usleep(50000);
    }
}

// Data Fortress Matrix
void printMatrix(char *input) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            printf("%s%c%s", ANSI_YELLOW, input[i], ANSI_RESET);
        } else {
            printf("%s%c%s", ANSI_MAGENTA, input[i], ANSI_RESET);
        }
    }
    printf("\n");
}

// Cybernetic Surgeon
void chopAndSplice(char *input, char *args[], int argc) {
    if (argc < 3) {
        printf("Insufficient arguments for chopAndSplice operation.\n");
        return;
    }
    int start = atoi(args[1]);
    int end = atoi(args[2]);
    if (start < 0 || end < 0 || start > strlen(input) || end > strlen(input)) {
        printf("Invalid range for chopAndSplice operation.\n");
        return;
    }
    int newLen = strlen(input) - (end - start + 1);
    char *newInput = malloc(newLen + 1);
    strncpy(newInput, input, start);
    newInput[start] = '\0';
    strncat(newInput, input + end + 1, strlen(input) - end - 1);
    printf("%s\n", newInput);
    free(newInput);
}

// Interface Handler
int main() {
    char input[MAX_LINE_LEN];
    char *args[MAX_ARGS];
    int argc = 0;
    printf("\nWelcome to NeonSigns, where strings become cyberpunk masterpieces.\n");
    while (1) {
        printf("\n>> ");
        fgets(input, MAX_LINE_LEN, stdin);
        strtok(input, "\n");
        argc = 0;
        args[argc++] = strtok(input, " ");
        while (args[argc-1] != NULL) {
            args[argc++] = strtok(NULL, " ");
        }
        argc--;
        if (strcmp(args[0], "graffiti") == 0) {
            paintGraffiti(input + strlen("graffiti") + 1);
        } else if (strcmp(args[0], "neon") == 0) {
            scrollNeon(input + strlen("neon") + 1);
        } else if (strcmp(args[0], "matrix") == 0) {
            printMatrix(input + strlen("matrix") + 1);
        } else if (strcmp(args[0], "splice") == 0) {
            chopAndSplice(input + strlen("splice") + 1, args + 1, argc - 1);
        } else if (strcmp(args[0], "exit") == 0) {
            break;
        } else {
            printf("Unknown command. Try 'graffiti', 'neon', 'matrix', 'splice', or 'exit'.\n");
        }
    }
    printf("\nExiting NeonSigns. Remember, the future is yours to hack.\n");
    return 0;
}