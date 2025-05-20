//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

// Function prototypes
char* extract_word(char* line);
void parse_line(char* line, char* first_name, char* last_name, char* email, char* phone);

int main() {
    FILE* file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char first_name[MAX_WORD_SIZE] = "";
        char last_name[MAX_WORD_SIZE] = "";
        char email[MAX_WORD_SIZE] = "";
        char phone[MAX_WORD_SIZE] = "";

        parse_line(line, first_name, last_name, email, phone);

        printf("First Name: %s\n", first_name);
        printf("Last Name: %s\n", last_name);
        printf("Email: %s\n", email);
        printf("Phone: %s\n\n", phone);
    }

    fclose(file);
    return 0;
}

// Extracts a word from a line
char* extract_word(char* line) {
    char* word = strtok(line, " ");
    return word;
}

// Parses a line and extracts the first name, last name, email, and phone number
void parse_line(char* line, char* first_name, char* last_name, char* email, char* phone) {
    // Extract the first name
    char* word = extract_word(line);
    strcpy(first_name, word);

    // Extract the last name
    word = extract_word(line);
    strcpy(last_name, word);

    // Extract the email
    word = extract_word(line);
    strcpy(email, word);

    // Extract the phone number
    word = extract_word(line);
    strcpy(phone, word);
}