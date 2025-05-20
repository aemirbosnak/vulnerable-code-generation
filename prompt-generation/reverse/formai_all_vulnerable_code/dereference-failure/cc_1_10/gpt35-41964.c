//FormAI DATASET v1.0 Category: Spell checking ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

// Function prototype declarations
void check_spelling(char *input_string);

int main() {
    char input[MAX_SIZE];

    printf("Please enter the text you want to spell check:\n");
    fgets(input, MAX_SIZE, stdin);

    check_spelling(input);

    return 0;
}

void check_spelling(char *input_string) {
    // Open dictionary file
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    
    // Invalid file, return
    if (dictionary_file == NULL) {
        printf("Fatal error: Failed to open dictionary file.\n");
        return;
    }
    
    char *word;
    char *copy = strdup(input_string);

    printf("\n--------------------------------------\n");
    printf("   Spell checking in progress...   \n");
    printf("--------------------------------------\n");
    
    word = strtok(copy, " ,.;:'\"`~!@#$%^&*()-_+=|\\][{}?><\n");
    
    while (word != NULL) {
        // To lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word exists in the dictionary
        char line[MAX_SIZE];
        int found = 0;
        
        while(fgets(line, sizeof(line), dictionary_file) != NULL) {
            line[strcspn(line, "\n")] = '\0';
            if (strcmp(word, line) == 0) {
                found = 1;
                break;
            }
        }
        
        if (!found) {
            printf("   %s is spelled incorrectly.\n", word);
        }
        
        // Reset cursor position of dictionary file
        fseek(dictionary_file, 0, SEEK_SET);
        
        word = strtok(NULL, " ,.;:'\"`~!@#$%^&*()-_+=|\\][{}?><\n");
    }
    
    printf("\n--------------------------------------\n");
    printf("Spell checking completed successfully.\n");
    printf("--------------------------------------\n");

    fclose(dictionary_file);
}