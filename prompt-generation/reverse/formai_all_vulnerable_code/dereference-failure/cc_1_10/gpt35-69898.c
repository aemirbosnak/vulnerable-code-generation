//FormAI DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <ctype.h>

#define PATH_MAX 512
#define BUF_MAX 1024

void on_alarm() {
    printf("\nUser did not input anything in 10 seconds, exiting program.\n");
    exit(0);
}

int main(int argc, char *argv[]) {

    char prompt[4] = "> ";
    char *command;

    // Initialize variables for input and output
    char input[BUF_MAX], output[BUF_MAX];
    int input_len = 0, output_len = 0;
    char *arg_list[BUF_MAX];

    // Welcome message and prompting user to enter command
    printf("Welcome to Async String Manipulator!\n");
    printf("Type 'help' to see a list of available commands.\n");

    // Set up alarm clock to prevent program from running indefinitely if user doesn't input anything
    signal(SIGALRM, on_alarm);

    while (1) {
        input_len = 0;
        printf("%s", prompt);
        fflush(stdout);
        alarm(10);
        while (fgets(input, BUF_MAX, stdin) != NULL) {
            // Remove newline character from input
            input_len = strlen(input);
            if (input[input_len-1] == '\n') {
                input[input_len-1] = '\0';
                input_len--;
            }
            if (input_len == 0) {
                printf("%s", prompt);
                fflush(stdout);
            } else {
                break;
            }
        }
        alarm(0);

        // Tokenize input and save into arg_list
        int argc = 0, i = 0, j = 0;
        while (i < input_len) {
            j = i;
            while (j < input_len && input[j] != ' ') {
                j++;
            }
            arg_list[argc] = (char*) malloc(j-i+1);
            memcpy(arg_list[argc], &input[i], j-i);
            arg_list[argc][j-i] = '\0';
            argc++;
            i = j + 1;
        }
        arg_list[argc] = NULL;

        // Execute commands based on user input
        if (strcmp(arg_list[0], "help") == 0) {
            printf("Available commands:\n");
            printf("  help: show available commands\n");
            printf("  echo [message]: print message to console\n");
            printf("  reverse [string]: reverse a string\n");
            printf("  upper [string]: convert string to uppercase\n");
            printf("  lower [string]: convert string to lowercase\n");
            printf("  exit: exit program\n");
        } else if (strcmp(arg_list[0], "echo") == 0) {
            output_len = snprintf(output, BUF_MAX, "%s\n", arg_list[1]);
            write(1, output, output_len);
        } else if (strcmp(arg_list[0], "reverse") == 0) {
            char *s = arg_list[1];
            int n = strlen(s);
            for (int i = 0; i < (n / 2); ++i) {
                char temp = s[i];
                s[i] = s[n - i - 1];
                s[n - i - 1] = temp;
            }
            output_len = snprintf(output, BUF_MAX, "%s\n", s);
            write(1, output, output_len);
        } else if (strcmp(arg_list[0], "upper") == 0) {
            char *s = arg_list[1];
            for (int i = 0; s[i]; i++){
                s[i] = toupper(s[i]);
            }
            output_len = snprintf(output, BUF_MAX, "%s\n", s);
            write(1, output, output_len);
        } else if (strcmp(arg_list[0], "lower") == 0) {
            char *s = arg_list[1];
            for (int i = 0; s[i]; i++){
                s[i] = tolower(s[i]);
            }
            output_len = snprintf(output, BUF_MAX, "%s\n", s);
            write(1, output, output_len);
        } else if (strcmp(arg_list[0], "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid command. Type 'help' to see a list of available commands.\n");
        }

        // Free memory allocated for arg_list
        for (i = 0; i < argc; ++i) {
            free(arg_list[i]);
        }
    }   
    return 0;
}