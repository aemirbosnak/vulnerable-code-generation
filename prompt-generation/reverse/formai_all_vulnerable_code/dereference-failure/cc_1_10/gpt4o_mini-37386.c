//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define INITIAL_CAPACITY 10

typedef struct {
    char **words;
    int size;
    int capacity;
} WordList;

// Function prototypes
WordList* create_word_list();
void free_word_list(WordList *list);
int add_word(WordList *list, const char *word);
void display_words(const WordList *list);
int search_word(const WordList *list, const char *word);
void expand_capacity(WordList *list);
void to_lower_case(char *str);

int main() {
    WordList *list = create_word_list();
    char input[MAX_WORD_LENGTH];
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Word\n");
        printf("2. Display Words\n");
        printf("3. Search Word\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter a word to add: ");
                fgets(input, MAX_WORD_LENGTH, stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove newline character
                if (add_word(list, input)) {
                    printf("'%s' added to the list.\n", input);
                } else {
                    printf("Error adding word '%s'. It may already exist.\n", input);
                }
                break;
            case 2:
                display_words(list);
                break;
            case 3:
                printf("Enter a word to search: ");
                fgets(input, MAX_WORD_LENGTH, stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove newline character
                if (search_word(list, input)) {
                    printf("The word '%s' is in the list.\n", input);
                } else {
                    printf("The word '%s' is not in the list.\n", input);
                }
                break;
            case 4:
                free_word_list(list);
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

WordList* create_word_list() {
    WordList *list = (WordList *)malloc(sizeof(WordList));
    if (!list) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    list->words = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
    if (!list->words) {
        free(list);
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    return list;
}

void free_word_list(WordList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->words[i]);
    }
    free(list->words);
    free(list);
}

int add_word(WordList *list, const char *word) {
    to_lower_case((char *)word); // Convert to lowercase for uniqueness check
    if (search_word(list, word)) {
        return 0; // Word already exists
    }
    if (list->size >= list->capacity) {
        expand_capacity(list);
    }
    list->words[list->size] = (char *)malloc((strlen(word) + 1) * sizeof(char));
    strcpy(list->words[list->size], word);
    list->size++;
    return 1; // Successfully added
}

void display_words(const WordList *list) {
    if (list->size == 0) {
        printf("The word list is empty.\n");
        return;
    }
    printf("Words in the list:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%s\n", list->words[i]);
    }
}

int search_word(const WordList *list, const char *word) {
    char lower_case_word[MAX_WORD_LENGTH];
    strcpy(lower_case_word, word);
    to_lower_case(lower_case_word);
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->words[i], lower_case_word) == 0) {
            return 1; // Found
        }
    }
    return 0; // Not found
}

void expand_capacity(WordList *list) {
    list->capacity *= 2;
    list->words = (char **)realloc(list->words, list->capacity * sizeof(char *));
    if (!list->words) {
        fprintf(stderr, "Memory reallocation error\n");
        exit(EXIT_FAILURE);
    }
}

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}