//FormAI DATASET v1.0 Category: Spell checking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to remove leading and trailing spaces from word
char *trim(char *word) {
    char *end;
    // Remove leading spaces
    while (isspace(*word)) {
        word++;
    }
    // Remove trailing spaces
    end = word + strlen(word) - 1;
    while (end > word && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0'; // Null terminate the word
    return word;
}

int main() {
    printf("Welcome to the hilarious C Spell Checker!\n");

    char dictionary[1000]; // Buffer to hold the dictionary words
    char word[100]; // Buffer to hold user input word
    int flag; // Flag variable to declare whether the word is spelled correctly or not

    // Read the contents of dictionary file into buffer
    FILE *fp;
    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open the dictionary file.\n");
        exit(1); // Exit out of program with error status
    }
    fgets(dictionary, 1000, fp);
    fclose(fp);

    // Strip new line character from dictionary buffer
    dictionary[strcspn(dictionary, "\n")] = '\0';

    // Start the spelling checking loop
    while (1) {
        printf("\nEnter a word to check its spelling: ");

        // Read user input and strip leading and trailing spaces
        fgets(word, 100, stdin);
        char *trimmed_word = trim(word);

        // Check if word is in dictionary
        flag = !strcasecmp(trimmed_word, dictionary);
        if (flag) {
            printf("\nYour word is spelled correctly! Hurray!\n");

        // If word is not in dictionary, suggest some alternatives in a funny way!
        } else {
            printf("\nOh no! Your word seems to be misspelled. Here are some suggestions:\n");
            printf("1. Try spelling it backwards and see if it's more correct: ");
            for (int i = strlen(trimmed_word) - 1; i >= 0; i--) {
                printf("%c", trimmed_word[i]);
            }
            printf("\n2. Maybe add some more vowels or consonants to it, you know,\n"
                   "   like how supercalifragilisticexpialidocious is spelled!\n");

            // Generate a random suggestion
            printf("3. Hmm, how about ");
            char random_word[10];
            for (int i = 0; i < 9; i++) {
                int rand_num = rand() % 26;
                random_word[i] = rand_num + 'a';
            }
            random_word[9] = '\0';
            printf("%s", random_word);

            // Ask user to confirm the suggestion
            printf("\n\nDo you like our suggestions? Press y for Yes or n for No: ");
            char choice;
            scanf("%c", &choice);
            getchar();

            if (choice == 'n') {
                printf("\nWe'll try to do better next time, sorry!\n");
            } else if (choice == 'y') {
                printf("\nYay! We're glad you liked it! Your word is spelled correctly now!\n");
            } else {
                printf("\nOops! Invalid choice, try again by running the program!\n");
                exit(1);
            }
        }

        // Ask user if they want to check another word
        printf("\nDo you want to check another word? Press y for Yes or n for No: ");
        char repeat_choice;
        scanf("%c", &repeat_choice);
        getchar();

        if (repeat_choice == 'n') {
            printf("\nThanks for using C Spell Checker! Exiting now. Goodbye!\n");
            exit(0); // Exit out of program with success status
        } else if (repeat_choice != 'y') {
            printf("\nOops! Invalid choice, try again by running the program!\n");
            exit(1);
        }
    }
    return 0;
}