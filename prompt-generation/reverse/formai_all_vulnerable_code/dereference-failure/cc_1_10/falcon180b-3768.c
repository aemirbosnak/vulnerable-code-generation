//Falcon-180B DATASET v1.0 Category: Email Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024 // Maximum length of a line
#define MAX_SUBJECT_LENGTH 1024 // Maximum length of a subject
#define MAX_BODY_LENGTH 1024 // Maximum length of a body

// Define the structure of an email message
typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char from[MAX_LINE_LENGTH];
    char to[MAX_LINE_LENGTH];
    char body[MAX_BODY_LENGTH];
    int body_length; // Length of the body (excluding null terminator)
} EmailMessage;

// Function to read a line from the input file
char* read_line(FILE* input_file) {
    char* line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, input_file) == NULL) {
        return NULL;
    }
    return line;
}

// Function to parse an email message from a line
EmailMessage* parse_email_message(char* line) {
    EmailMessage* message = malloc(sizeof(EmailMessage));
    if (line == NULL) {
        return NULL;
    }
    char* token = strtok(line, ":");
    strcpy(message->subject, token);
    token = strtok(NULL, ":");
    strcpy(message->from, token);
    token = strtok(NULL, ":");
    strcpy(message->to, token);
    message->body_length = strlen(message->body);
    return message;
}

// Function to write an email message to the output file
void write_email_message(FILE* output_file, EmailMessage* message) {
    fprintf(output_file, "Subject: %s\n", message->subject);
    fprintf(output_file, "From: %s\n", message->from);
    fprintf(output_file, "To: %s\n", message->to);
    fprintf(output_file, "Content-Length: %d\n", message->body_length);
    fprintf(output_file, "\n");
    fprintf(output_file, "%s", message->body);
    fprintf(output_file, "\n");
}

// Function to process the input file and write the messages to the output file
void process_input_file(FILE* input_file, FILE* output_file) {
    char* line = read_line(input_file);
    while (line!= NULL) {
        EmailMessage* message = parse_email_message(line);
        if (message!= NULL) {
            write_email_message(output_file, message);
        }
        free(line);
        line = read_line(input_file);
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    process_input_file(input_file, output_file);
    fclose(input_file);
    fclose(output_file);
    return 0;
}