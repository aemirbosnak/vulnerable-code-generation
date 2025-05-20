//FormAI DATASET v1.0 Category: HTML beautifier ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Struct to hold the line buffer
typedef struct line_buffer {
    char line[MAX_LINE_LENGTH];
    struct line_buffer* next;
} line_buffer;

// Reads the input file into a line buffer
line_buffer* read_file(char* input_file) {
    
    line_buffer* head = NULL;
    line_buffer* tail = NULL;
    char buffer[MAX_LINE_LENGTH];
    
    FILE *fp = fopen(input_file, "r");
    
    if (fp != NULL) {
        
        // Read each line from the file into a buffer
        while (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL) {
            
            // Allocate memory for a new line buffer
            line_buffer* lb = malloc(sizeof(line_buffer));
            
            // Copy the line into the line buffer
            strcpy(lb->line, buffer);
            lb->next = NULL;
            
            // Add the line buffer to the end of our linked list
            if (head == NULL) {
                head = lb;
                tail = lb;
            } else {
                tail->next = lb;
                tail = lb;
            }
        }
        
        fclose(fp);
    }
    
    return head;
}

// Writes the line buffer to the output file
void write_file(char* output_file, line_buffer* head) {
    
    FILE *fp = fopen(output_file, "w");
    
    while (head != NULL) {
        fprintf(fp, "%s", head->line);
        head = head->next;
    }
    
    fclose(fp);
}

// Removes leading and trailing whitespace from a line
void trim(char* line) {
    int start = 0;
    int end = strlen(line) - 1;
    
    while (line[start] == ' ' || line[start] == '\t' || line[start] == '\r' || line[start] == '\n') {
        start++;
    }
    
    while (line[end] == ' ' || line[end] == '\t' || line[end] == '\r' || line[end] == '\n') {
        end--;
    }
    
    line[end + 1] = '\0';
    
    if (start > 0) {
        memmove(line, line + start, strlen(line) - start + 1);
    }
}

// Counts the number of tabs at the beginning of a line
int count_tabs(char* line) {
    int count = 0;
    while (line[count] == '\t') {
        count++;
    }
    return count;
}

// Prints a line with the specified number of tabs
void print_tabs(int num_tabs) {
    for (int i = 0; i < num_tabs; i++) {
        printf("\t");
    }
}

// Main function
int main(int argc, char* argv[]) {
    
    // Check that the input and output files were specified
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    
    // Read the input file into a line buffer
    line_buffer* head = read_file(argv[1]);
    line_buffer* current = head;
    
    // Traverse the linked list and print each line with proper formatting
    while (current != NULL) {
        
        // Remove leading and trailing whitespace
        trim(current->line);
        
        // If the line is empty or a comment, print it as is
        if (current->line[0] == '\0' || current->line[0] == '/' && current->line[1] == '/') {
            printf("%s\n", current->line);
            current = current->next;
            continue;
        }
        
        // Count the number of tabs at the beginning of the line
        int num_tabs = count_tabs(current->line);
        printf("\n");
        print_tabs(num_tabs);
        
        // Print the first token (probably an HTML tag)
        char* token = strtok(current->line, " ");
        printf("%s ", token);
        
        // Print the rest of the line (probably attributes for the HTML tag)
        token = strtok(NULL, "");
        if (token != NULL) {
            printf("%s", token);
        }
        
        printf("\n");
        
        current = current->next;
    }
    
    // Write the line buffer to the output file
    write_file(argv[2], head);
    
    return 0;
}