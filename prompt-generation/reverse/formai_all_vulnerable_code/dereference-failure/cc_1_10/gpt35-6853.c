//FormAI DATASET v1.0 Category: Text Summarizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_SUMMARY_LENGTH 200

char *read_file(const char *file_name);
int get_total_words(const char *text);
char **get_word_list(const char *text, int total_words);
char *clean_word(const char *word);
void summarize_text(char **word_list, int total_words);

int main(){
    char *file_name = "example.txt";
    char *text = NULL;
    int total_words;
    char **word_list;
    
    text = read_file(file_name);
    total_words = get_total_words(text);
    word_list = get_word_list(text, total_words);
    summarize_text(word_list, total_words);

    return 0;
}

/* Reads text from a file and returns it as a string */
char *read_file(const char *file_name){
    FILE *file = fopen(file_name, "r");
    char *text = NULL;
    int file_size;

    if(file == NULL){
        printf("Error opening file %s\n", file_name);
        exit(1);
    }
    
    // Get file size
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    // Allocate memory for text buffer
    text = (char*)malloc(sizeof(char) * (file_size + 1));
    
    // Read text from file
    fread(text, file_size, 1, file);

    // Add terminating null character
    text[file_size] = '\0';

    return text;
}

/* Returns the total number of words in the text */
int get_total_words(const char *text){
    int total_words = 0;
    int i;

    for(i = 0; text[i] != '\0'; i++){
        if(isspace(text[i])){
            total_words++;
        }
    }

    total_words++; // Add one for last word

    return total_words;
}

/* Returns an array of words from the text */
char **get_word_list(const char *text, int total_words){
    char **word_list = (char**)malloc(sizeof(char*) * total_words);
    char *word = (char*)malloc(sizeof(char) * MAX_WORD_LENGTH);
    int word_i = 0;
    int i, j;

    for(i = 0, j = 0; text[i] != '\0'; i++){
        if(isalpha(text[i])){
            word[word_i++] = text[i];
        }
        else if(word_i != 0){
            word[word_i] = '\0';
            word_list[j] = clean_word(word);
            j++;
            word_i = 0;
        }
    }

    word_list[total_words - 1] = clean_word(word);
    free(word);

    return word_list;
}

/* Cleans a word by removing leading/trailing white space and punctuation */
char *clean_word(const char *word){
    int i, j;
    char *cleaned_word = (char*)malloc(sizeof(char) * (strlen(word) + 1));

    // Remove leading white space
    for(i = 0; isspace(word[i]); i++);

    // Remove trailing white space
    for(j = strlen(word) - 1; j >= 0 && isspace(word[j]); j--);

    // Copy cleaned word to new string
    for(int k = i; k <= j; k++){
        cleaned_word[k - i] = word[k];
    }
    cleaned_word[j - i + 1] = '\0';

    // Remove punctuation from end of word
    int len = strlen(cleaned_word);
    while(len > 0 && ispunct(cleaned_word[len - 1])){
        cleaned_word[len - 1] = '\0';
        len--;
    }

    return cleaned_word;
}

/* Prints a summary of the text */
void summarize_text(char **word_list, int total_words){
    char summary[MAX_SUMMARY_LENGTH] = "";
    int summary_i = 0;

    for(int i = 0; i < total_words; i++){
        // If summary is approaching max length, stop adding words
        if(summary_i >= MAX_SUMMARY_LENGTH) break;

        char *word = word_list[i];

        if(strlen(word) > 3){
            strcat(summary, word);
            strcat(summary, " ");
            summary_i += strlen(word) + 1;
        }
    }

    printf("%s\n", summary);
}