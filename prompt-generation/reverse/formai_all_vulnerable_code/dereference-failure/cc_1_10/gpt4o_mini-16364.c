//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A noble struct to hold our fair lines
typedef struct Line {
    char *content;
    struct Line *next;
} Line;

// A worthy head of the linked list
typedef struct LineList {
    Line *head;
} LineList;

// Function to create a new line
Line *create_line(const char *text) {
    Line *new_line = (Line *)malloc(sizeof(Line));
    new_line->content = (char *)malloc(strlen(text) + 1);
    strcpy(new_line->content, text);
    new_line->next = NULL;
    return new_line;
}

// Function to add a line to the list
void add_line(LineList *list, const char *text) {
    Line *new_line = create_line(text);
    if (list->head == NULL) {
        list->head = new_line;
    } else {
        Line *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_line;
    }
}

// Function to beautify the HTML code
void beautify_html(LineList *list) {
    Line *current = list->head;
    while (current != NULL) {
        printf("%s\n", current->content); // Print the unmodified line
        current = current->next;
    }
}

// Function to free the memory of the list
void free_list(LineList *list) {
    Line *current = list->head;
    while (current != NULL) {
        Line *temp = current;
        current = current->next;
        free(temp->content);
        free(temp);
    }
}

// Function to read HTML from a file and beautify it
void read_html_from_file(const char *file_name, LineList *list) {
    FILE *file = fopen(file_name, "r");
    if (!file) {
        printf("Alas! The file cannot be found!\n");
        exit(1);
    }
    
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        // Adding the line to our noble list
        add_line(list, buffer);
    }
    
    fclose(file);
}

// The main bard of our program
int main(int argc, char *argv[]) {
    // If aided by improper arguments, call for the knight!
    if (argc < 2) {
        printf("Sir! You must provide the path to the HTML file!\n");
        return 1;
    }
    
    // Declaring our royal list of lines
    LineList list;
    list.head = NULL;

    // Constuct the HTML beautifier from the grand file!
    read_html_from_file(argv[1], &list);
    
    // Making it beautiful!
    printf("Behold! The beautified code:\n\n");
    beautify_html(&list);
    
    // Freeing the memory from the noble lands
    free_list(&list);
    return 0;
}