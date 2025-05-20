//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *start;
    char *end;
} Token;

Token find_next_token(char *buffer);
void parse_attribute(char *buffer);

int main()
{
    FILE *file_ptr;
    char *buffer = NULL;
    long file_size;

    file_ptr = fopen("file.xml", "rb"); // Opening XML file
    if (!file_ptr) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(file_ptr, 0, SEEK_END); // Get the file size
    file_size = ftell(file_ptr);
    rewind(file_ptr);

    buffer = malloc((file_size + 1) * sizeof(char)); // Allocate memory for the buffer
    if (!buffer) {
        fclose(file_ptr);
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    fread(buffer, sizeof(char), file_size, file_ptr); // Read the file into the buffer
    buffer[file_size] = '\0';

    Token token;
    while ((token = find_next_token(buffer)).start != NULL) { // Loop through the buffer and find tokens
        if (*token.start == '<' && *(token.start + 1) != '/') { // Check if the token is an opening tag
            printf("Opening tag: %.*s\n", (int) (token.end - token.start), token.start + 1);
            if (strchr(token.start, '=') != NULL) {
                parse_attribute(token.start);
            }
        } else if (*token.start == '<' && *(token.start + 1) == '/') { // Check if the token is a closing tag
            printf("Closing tag: %.*s\n", (int) (token.end - token.start), token.start + 2);
        } else if (*token.start != '<' && *token.end != '>') { // Check if the token is content
            printf("Content: %.*s\n", (int) (token.end - token.start), token.start);
        }
        buffer = token.end;
    }

    free(buffer); // Deallocate memory and close the file
    fclose(file_ptr);
    return 0;
}

Token find_next_token(char *buffer)
{
    Token token = {NULL, NULL};
    char *temp_start = strchr(buffer, '<');
    char *temp_end = strchr(buffer, '>');

    if (temp_start != NULL && temp_end != NULL) {
        token.start = temp_start;
        token.end = temp_end + 1;
    }

    return token;
}

void parse_attribute(char *buffer)
{
    char *attribute_name = strtok(buffer, " \t\n=");
    while (attribute_name != NULL) {
        if (strcmp(attribute_name, "id") == 0) {
            printf("ID: %s\n", strtok(NULL, " \t\n="));
        } else if (strcmp(attribute_name, "name") == 0) {
            printf("Name: %s\n", strtok(NULL, " \t\n="));
        } else if (strcmp(attribute_name, "value") == 0) {
            printf("Value: %s\n", strtok(NULL, " \t\n="));
        }
        attribute_name = strtok(NULL, " \t\n=");
    }
}