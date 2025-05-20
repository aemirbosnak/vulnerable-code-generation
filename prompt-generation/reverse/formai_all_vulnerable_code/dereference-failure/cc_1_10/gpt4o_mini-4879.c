//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024
#define MAX_SUMMARY_LENGTH 256

void welcome_message() {
    printf("Welcome, dear soul, to the world of Love Text Summarizer!\n");
    printf("Let us embark on a journey where words dance and romance blooms.\n");
    printf("Please share your enchanting tale with us, and we shall transform it into a beautiful summary.\n\n");
}

void get_input(char *text) {
    printf("Enter your romantic text (up to %d characters):\n", MAX_TEXT_LENGTH);
    fgets(text, MAX_TEXT_LENGTH, stdin);
    
    // Removing trailing newline if present
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
}

int count_words(const char *text) {
    int count = 0;
    char *token = strtok(strdup(text), " ,.;!?\n");
    
    while (token) {
        if (strlen(token) > 0) {
            count++;
        }
        token = strtok(NULL, " ,.;!?\n");
    }
    return count;
}

void create_summary(const char *text, char *summary) {
    char *token = strtok(strdup(text), " ,.;!?\n");
    int word_count = 0;

    summary[0] = '\0';
    
    while (token && word_count < 10) { // Getting a max of 10 words for the summary
        strcat(summary, token);
        strcat(summary, " ");
        token = strtok(NULL, " ,.;!?\n");
        word_count++;
    }
    
    // Clean up trailing space
    summary[strlen(summary) - 1] = '\0';
}

void print_summary(const char *summary) {
    printf("\nBehold! The essence of your words captured:\n");
    printf("\"%s\"\n", summary);
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char summary[MAX_SUMMARY_LENGTH];

    welcome_message();
    get_input(text);

    int words = count_words(text);
    printf("Your romantic tale contains %d words.\n", words);

    create_summary(text, summary);
    print_summary(summary);

    printf("\nMay your words continue to inspire love and passion!\n");
    return 0;
}