//FormAI DATASET v1.0 Category: Text processing ; Style: enthusiastic
// Welcome to the Text Processor!
// This program will take in a text file, perform various processing tasks, and output the results
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME 50
#define MAX_WORD_LENGTH 20

typedef struct word_node {
    char word[MAX_WORD_LENGTH];
    int frequency;
    struct word_node *next;
} WordNode;

void print_menu() {
    printf("Choose a processing task to perform:\n");
    printf("1. Count the number of words in the file\n");
    printf("2. Count the number of vowels in the file\n");
    printf("3. Count the number of sentences in the file\n");
    printf("4. Count the number of occurrences of a specific word\n");
    printf("5. Print a list of all words and their frequencies\n");
    printf("6. Quit\n");
}

char* get_filename() {
    char *filename = (char *) malloc(MAX_FILENAME * sizeof(char));
    printf("Enter filename to process (include extension): ");
    scanf("%s", filename);

    return filename;
}

void count_words(char *filename) {
    FILE *fp = fopen(filename, "r");
    char *word = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));
    int count = 0;

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word) != EOF) {
        count++;
    }

    printf("There are %d words in the file.\n", count);

    fclose(fp);
    free(word);
}

void count_vowels(char *filename) {
    FILE *fp = fopen(filename, "r");
    char c;
    int count = 0;

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while ((c = fgetc(fp)) != EOF) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }

    printf("There are %d vowels in the file.\n", count);

    fclose(fp);
}

void count_sentences(char *filename) {
    FILE *fp = fopen(filename, "r");
    char c;
    int count = 0;

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while ((c = fgetc(fp)) != EOF) {
        if (c == '.' || c == '!' || c == '?') {
            count++;
        }
    }

    printf("There are %d sentences in the file.\n", count);

    fclose(fp);
}

WordNode* add_word(WordNode *head, char *word) {
    WordNode *current = head;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->frequency++;
            return head;
        }
        current = current->next;
    }

    WordNode *new_node = (WordNode *) malloc(sizeof(WordNode));
    strcpy(new_node->word, word);
    new_node->frequency = 1;
    new_node->next = head;
    head = new_node;
    return head;
}

void count_word_occurrences(char *filename, char *target_word) {
    FILE *fp = fopen(filename, "r");
    char *word = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));
    WordNode *head = NULL;

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word) != EOF) {
        if (strcmp(word, target_word) == 0) {
            head = add_word(head, word);
        }
    }

    if (head == NULL) {
        printf("The word \"%s\" does not appear in the file.\n", target_word);
    } else {
        int count = 0;
        WordNode *current = head;
        while (current != NULL) {
            count += current->frequency;
            current = current->next;
        }
        printf("The word \"%s\" appears %d times in the file.\n", target_word, count);
    }

    fclose(fp);
    free(word);
}

void print_word_list(WordNode *head) {
    WordNode *current = head;

    printf("Word Frequency\n");
    printf("----------------\n");
    while (current != NULL) {
        printf("%-15s %d\n", current->word, current->frequency);
        current = current->next;
    }
}

void process_file() {
    char *filename = get_filename();
    int choice;
    char *target_word;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count_words(filename);
                break;
            case 2:
                count_vowels(filename);
                break;
            case 3:
                count_sentences(filename);
                break;
            case 4:
                printf("Enter word to search for: ");
                scanf("%s", target_word);
                count_word_occurrences(filename, target_word);
                break;
            case 5: {
                FILE *fp = fopen(filename, "r");
                char *word = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));
                WordNode *head = NULL;

                if (fp == NULL) {
                    printf("Error: could not open file.\n");
                    exit(1);
                }

                while (fscanf(fp, "%s", word) != EOF) {
                    head = add_word(head, word);
                }

                print_word_list(head);

                fclose(fp);
                free(word);
                break;
            }
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    free(filename);
}

int main() {
    printf("Welcome to the Text Processor!\n");
    printf("Let's get started...\n");
    process_file();
    return 0;
}