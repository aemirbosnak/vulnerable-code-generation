//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 30

// Function to remove punctuations and convert to lowercase
void process_word(char* word) {
    int i = 0;
    while(word[i]) {
        if(isalnum(word[i])) {
            word[i] = tolower(word[i]);
        } else {
            word[i] = '\0';
        }
        i++;
    }
}

// Function to split a string into words
int split_string(char* str, char** words) {
    char* token = strtok(str, ",.?!;:");
    int count = 0;
    while(token!= NULL) {
        process_word(token);
        words[count] = token;
        count++;
        token = strtok(NULL, ",.?!;:");
    }
    return count;
}

// Function to check if a word is a spam word
int is_spam_word(char* word) {
    FILE* fp = fopen("spam_words.txt", "r");
    char line[MAX_WORD_LENGTH];
    while(fgets(line, MAX_WORD_LENGTH, fp)) {
        char* spam_word = line;
        while(isspace(*spam_word)) {
            spam_word++;
        }
        if(strcmp(word, spam_word) == 0) {
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// Function to check if an email is spam
int is_spam_email(char* email, char** words, int word_count) {
    int spam_count = 0;
    for(int i = 0; i < word_count; i++) {
        if(is_spam_word(words[i])) {
            spam_count++;
        }
    }
    if(spam_count >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char email[MAX_WORDS][MAX_WORD_LENGTH];
    int email_count = 0;

    // Read spam words from file
    FILE* fp = fopen("spam_words.txt", "r");
    char line[MAX_WORD_LENGTH];
    while(fgets(line, MAX_WORD_LENGTH, fp)) {
        char* spam_word = line;
        while(isspace(*spam_word)) {
            spam_word++;
        }
        strcpy(email[email_count], spam_word);
        email_count++;
    }
    fclose(fp);

    // Read emails from file
    FILE* fp2 = fopen("emails.txt", "r");
    char line2[MAX_WORDS][MAX_WORD_LENGTH];
    while(fgets(line2, MAX_WORDS*MAX_WORD_LENGTH, fp2)) {
        char* email_str = line2;
        char* word = strtok(email_str, ",.?!;:");
        int word_count = 0;
        while(word!= NULL) {
            process_word(word);
            strcpy(email[email_count], word);
            email_count++;
            word_count++;
            word = strtok(NULL, ",.?!;:");
        }
        if(is_spam_email(email_str, email, word_count)) {
            printf("Spam email: %s\n", email_str);
        }
    }
    fclose(fp2);

    return 0;
}