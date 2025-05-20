//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MIN_LENGTH 10

int main() {
    char *message = NULL;
    size_t length = 0;
    int option = 0;

    // Dynamic menu system
    do {
        printf("Welcome to the C Programming Challenge!\n");
        printf("Please select an option from the following menu:\n");
        printf("1. Print a message with a fixed length\n");
        printf("2. Print a message with a variable length\n");
        printf("3. Generate a random message\n");
        printf("4. Quit\n");

        scanf("%d", &option);

        switch (option) {
            case 1: {
                printf("Enter a message (%zu characters max): ", MAX_LENGTH);
                fgets(message, MAX_LENGTH, stdin);
                length = strlen(message);
                printf("Your message is: %s\n", message);
                break;
            }

            case 2: {
                printf("Enter a message (%zu characters min, %zu characters max): ", MIN_LENGTH, MAX_LENGTH);
                fgets(message, MAX_LENGTH, stdin);
                length = strlen(message);
                printf("Your message is: %s\n", message);
                break;
            }

            case 3: {
                // Generate a random message
                char *random_message = malloc(MAX_LENGTH * sizeof(char));
                for (size_t i = 0; i < MAX_LENGTH; i++) {
                    random_message[i] = 'a' + (rand() % 26);
                }
                printf("Your random message is: %s\n", random_message);
                free(random_message);
                break;
            }

            case 4:
                printf("Goodbye! Exiting...\n");
                return 0;
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 4);

    return 0;
}