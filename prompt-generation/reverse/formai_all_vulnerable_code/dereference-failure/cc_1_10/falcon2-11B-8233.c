//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_prompt(const char *prompt) {
    printf("%s", prompt);
    printf("\n");
}

int main(void) {
    char name[50];
    char choice;
    char *input;
    int choice_valid = 0;

    print_prompt("Welcome to the Adventure Game!\n");
    printf("What is your name? ");
    fgets(name, sizeof(name), stdin);
    printf("Hello, %s!\n", name);

    while (1) {
        print_prompt("What do you want to do? ");
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // remove newline character

        if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else if (strcmp(input, "help") == 0) {
            printf("Available commands:\n");
            printf("- quit: exit the game\n");
            printf("- help: display this message\n");
            choice_valid = 1;
        } else {
            printf("I don't understand that command.\n");
        }

        if (choice_valid == 1) {
            printf("Enter a command: ");
            scanf("%c", &choice);
            if (choice == 'q' || choice == 'Q') {
                printf("Goodbye!\n");
                exit(0);
            } else if (choice == 'h' || choice == 'H') {
                printf("Available commands:\n");
                printf("- quit: exit the game\n");
                printf("- help: display this message\n");
            } else {
                printf("I don't understand that command.\n");
            }
        }
    }

    return 0;
}