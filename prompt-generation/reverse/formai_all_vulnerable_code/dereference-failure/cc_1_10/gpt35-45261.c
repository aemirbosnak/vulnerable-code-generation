//FormAI DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declare functions
int load_dict(const char *file, char ***words);
int spellcheck(const char *word, char **words, const int dict_size);

int main(int argc, char *argv[]) {
    // Check for file input
    if(argc != 2) {
        printf("Please enter a file name as input.");
        return 1;
    }
    
    // Load dictionary file
    char **dictionary = NULL;
    int dict_size = load_dict(argv[1], &dictionary);
    if(dict_size == -1) {
        printf("Error loading dictionary file.");
        return 1;
    }
    
    // Prompt user input
    printf("Enter a word to spell-check: ");
    char input[100];
    scanf("%s", input);
    
    // Convert input to lowercase
    char word[100];
    strcpy(word, input);
    for(int i=0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
    
    // Spell check input
    if(spellcheck(word, dictionary, dict_size)) {
        printf("The word '%s' was found in the dictionary.", input);
    }
    else {
        printf("The word '%s' was not found in the dictionary.", input);
    }
    
    // Free memory
    for(int i=0; i<dict_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
    
    return 0;
}

// Load dictionary file into memory
int load_dict(const char *file, char ***words) {
    FILE *fp = fopen(file, "r");
    if(fp == NULL) {
        return -1; // Error opening file
    }
    
    // Count number of lines in file
    int line_count = 0;
    char ch;
    while((ch = fgetc(fp)) != EOF) {
        if(ch == '\n') {
            line_count++;
        }
    }
    rewind(fp);
    
    // Allocate memory for dictionary words
    char **dict_words = (char **) malloc(line_count * sizeof(char *));
    if(dict_words == NULL) {
        return -1; // Error allocating memory
    }
    
    // Read each line of the file
    char line[100];
    int index = 0;
    while(fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\r\n")] = '\0'; // Removes newline characters
        
        // Allocate memory for each word and add to dictionary
        dict_words[index] = (char *) malloc(strlen(line) + 1);
        strcpy(dict_words[index], line);
        index++;
    }
    
    // Close file and return dictionary size
    fclose(fp);
    *words = dict_words;
    return line_count;
}

// Spell check a given word against dictionary
int spellcheck(const char *word, char **words, const int dict_size) {
    for(int i=0; i<dict_size; i++) {
        if(strcmp(word, words[i]) == 0) {
            return 1; // Word is in dictionary
        }
    }
    return 0; // Word not found in dictionary
}