//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an HTML tag
typedef struct {
    char *name;
    char **attributes;
    int num_attributes;
    char *content;
} HTMLTag;

// Function to create a new HTML tag
HTMLTag *new_tag(char *name) {
    HTMLTag *tag = malloc(sizeof(HTMLTag));
    tag->name = strdup(name);
    tag->attributes = NULL;
    tag->num_attributes = 0;
    tag->content = NULL;
    return tag;
}

// Function to add an attribute to an HTML tag
void add_attribute(HTMLTag *tag, char *name, char *value) {
    tag->attributes = realloc(tag->attributes, (tag->num_attributes + 1) * sizeof(char *));
    tag->attributes[tag->num_attributes] = malloc(strlen(name) + strlen(value) + 2);
    sprintf(tag->attributes[tag->num_attributes], "%s=\"%s\"", name, value);
    tag->num_attributes++;
}

// Function to set the content of an HTML tag
void set_content(HTMLTag *tag, char *content) {
    tag->content = strdup(content);
}

// Function to print an HTML tag
void print_tag(HTMLTag *tag) {
    printf("<%s", tag->name);
    for (int i = 0; i < tag->num_attributes; i++) {
        printf(" %s", tag->attributes[i]);
    }
    printf(">%s</%s>", tag->content, tag->name);
}

// Function to free the memory allocated for an HTML tag
void free_tag(HTMLTag *tag) {
    free(tag->name);
    for (int i = 0; i < tag->num_attributes; i++) {
        free(tag->attributes[i]);
    }
    free(tag->attributes);
    free(tag->content);
    free(tag);
}

// Function to beautify an HTML document
char *beautify_html(char *html) {
    // Create a new array to store the beautified HTML
    char *beautified_html = malloc(strlen(html) * 2);
    int beautified_html_length = 0;

    // Create a stack to store the tags that are currently open
    HTMLTag **stack = malloc(sizeof(HTMLTag *) * 100);
    int stack_size = 0;

    // Iterate over the characters in the HTML document
    for (int i = 0; i < strlen(html); i++) {
        char c = html[i];

        // If the character is the start of a tag
        if (c == '<') {
            // Get the name of the tag
            char *tag_name = malloc(100);
            int tag_name_length = 0;
            i++;
            while (html[i] != '>' && html[i] != ' ') {
                tag_name[tag_name_length++] = html[i++];
            }
            tag_name[tag_name_length] = '\0';

            // Create a new tag
            HTMLTag *tag = new_tag(tag_name);
            free(tag_name);

            // If the tag is self-closing
            if (html[i] == '/') {
                i++;
                if (html[i] == '>') {
                    // Print the tag
                    print_tag(tag);
                    beautified_html[beautified_html_length++] = '\n';
                }
                else {
                    // Add the tag to the stack
                    stack[stack_size++] = tag;
                }
            }
            // If the tag is not self-closing
            else {
                // Add the tag to the stack
                stack[stack_size++] = tag;
            }
        }
        // If the character is the end of a tag
        else if (c == '>') {
            // Get the name of the tag
            char *tag_name = malloc(100);
            int tag_name_length = 0;
            i++;
            while (html[i] != '<' && html[i] != '\0') {
                tag_name[tag_name_length++] = html[i++];
            }
            tag_name[tag_name_length] = '\0';

            // Find the matching tag in the stack
            int j;
            for (j = stack_size - 1; j >= 0; j--) {
                if (strcmp(stack[j]->name, tag_name) == 0) {
                    break;
                }
            }

            // If the matching tag was found
            if (j >= 0) {
                // Print the content of the tag
                print_tag(stack[j]);
                beautified_html[beautified_html_length++] = '\n';

                // Remove the tag from the stack
                free_tag(stack[j]);
                for (int k = j; k < stack_size - 1; k++) {
                    stack[k] = stack[k + 1];
                }
                stack_size--;
            }
            // If the matching tag was not found
            else {
                // Add the tag to the stack
                stack[stack_size++] = new_tag(tag_name);
            }
            free(tag_name);
        }
        // If the character is text
        else {
            // Add the character to the content of the current tag
            int j;
            for (j = stack_size - 1; j >= 0; j--) {
                if (stack[j]->content == NULL) {
                    stack[j]->content = malloc(100);
                    stack[j]->content[0] = '\0';
                }
                strcat(stack[j]->content, &c);
                break;
            }
        }
    }

    // Free the stack
    for (int i = 0; i < stack_size; i++) {
        free_tag(stack[i]);
    }
    free(stack);

    // Return the beautified HTML
    beautified_html[beautified_html_length] = '\0';
    return beautified_html;
}

// Main function
int main() {
    // Read the HTML document from a file
    FILE *fp = fopen("input.html", "r");
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *html = malloc(fsize + 1);
    fread(html, fsize, 1, fp);
    fclose(fp);
    html[fsize] = '\0';

    // Beautify the HTML document
    char *beautified_html = beautify_html(html);
    free(html);

    // Write the beautified HTML document to a file
    fp = fopen("output.html", "w");
    fprintf(fp, "%s", beautified_html);
    fclose(fp);

    // Free the beautified HTML document
    free(beautified_html);

    return 0;
}