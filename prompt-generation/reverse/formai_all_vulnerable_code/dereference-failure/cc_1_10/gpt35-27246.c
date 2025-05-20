//FormAI DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_menu() {
    printf("Text processing program\n");
    printf("1. Count number of words\n");
    printf("2. Count number of characters\n");
    printf("3. Find and replace a word\n");
    printf("0. Exit\n\n");
}

int count_words(char *text) {
    int count = 0;

    while (*text) {
        while (*text == ' ' || *text == '\n' || *text == '\t') {
            text++;
        }

        if (*text) {
            count++;
        }

        while (*text && *text != ' ' && *text != '\n' && *text != '\t') {
            text++;
        }
    }

    return count;
}

int count_characters(char *text) {
    int count = 0;

    while (*text) {
        count++;
        text++;
    }

    return count;
}

char* find_and_replace(char *text, char *find, char *replace) {
    char *result = (char*) malloc (strlen(text) + 1);
    char *result_ptr = result;

    while (*text) {
        if (strstr(text, find) == text) {
            strcpy(result_ptr, replace);
            result_ptr += strlen(replace);
            text += strlen(find);
        } else {
            *result_ptr = *text;
            result_ptr++;
            text++;
        }
    }

    *result_ptr = '\0';

    return result;
}

int main() {
    char text[1000];
    int choice;

    printf("Enter some text:\n");
    fgets(text, 1000, stdin);

    while (1) {
        print_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting program...\n");
                exit(0);
            case 1:
                printf("Number of words: %d\n", count_words(text));
                break;
            case 2:
                printf("Number of characters: %d\n", count_characters(text));
                break;
            case 3: {
                char find[100], replace[100];

                printf("Enter word to find: ");
                scanf("%s", find);

                printf("Enter word to replace it with: ");
                scanf("%s", replace);

                char *result = find_and_replace(text, find, replace);
                printf("Result: %s\n", result);
                free(result);

                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}