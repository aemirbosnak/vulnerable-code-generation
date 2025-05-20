//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 256
#define MAX_TAG_NAME_SIZE 50
#define MAX_ATTRIBUTE_SIZE 50

// function to get the tag name from a line
char* get_tag_name(char* line) {
    int i = 1;
    char* tag_name = (char*)malloc(MAX_TAG_NAME_SIZE*sizeof(char));
    while (line[i] != '>' && !isspace(line[i]) && i < MAX_TAG_NAME_SIZE) {
        tag_name[i-1] = line[i];
        i++;
    }
    tag_name[i-1] = '\0';
    return tag_name;
}

// function to parse attributes from a line
void parse_attributes(char* line, char** attribute_names, char** attribute_values, int* num_attr) {
    int i = 1;
    int curr_attr = 0;
    char* curr_attr_name = (char*)malloc(MAX_ATTRIBUTE_SIZE*sizeof(char));
    char* curr_attr_value = (char*)malloc(MAX_ATTRIBUTE_SIZE*sizeof(char));
    
    while (line[i] != '>') {
        if (!isspace(line[i])) {
            curr_attr = 1;
            int j = 0;
            while (line[i] != '=') {
                curr_attr_name[j] = line[i];
                j++;
                i++;
            }
            curr_attr_name[j] = '\0';
            i++;
            j = 0;
            while (line[i] != '\"') {
                curr_attr_value[j] = line[i];
                j++;
                i++;
            }
            curr_attr_value[j] = '\0';
            attribute_names[*num_attr] = curr_attr_name;
            attribute_values[*num_attr] = curr_attr_value;
            (*num_attr)++;
            curr_attr_name = (char*)malloc(MAX_ATTRIBUTE_SIZE*sizeof(char));
            curr_attr_value = (char*)malloc(MAX_ATTRIBUTE_SIZE*sizeof(char));
        } else {
            i++;
        }
    }
}

// main function
int main() {
    char* tag_name;
    char* line = (char*)malloc(MAX_LINE_SIZE*sizeof(char));
    char** attribute_names = (char**)malloc(MAX_LINE_SIZE*sizeof(char*));
    char** attribute_values = (char**)malloc(MAX_LINE_SIZE*sizeof(char*));
    int num_attr = 0;
    
    while (fgets(line, MAX_LINE_SIZE, stdin) != NULL) {
        tag_name = get_tag_name(line);
        if (line[1] == '/') {
            printf("End tag: %s\n", tag_name);
        } else {
            printf("Start tag: %s\n", tag_name);
            parse_attributes(line, attribute_names, attribute_values, &num_attr);
            for (int i = 0; i < num_attr; i++) {
                printf("Attribute name: %s | Value: %s\n", attribute_names[i], attribute_values[i]);
            }
        }
        num_attr = 0;
        free(tag_name);
    }
    
    for (int i = 0; i < MAX_LINE_SIZE; i++) {
        free(attribute_names[i]);
        free(attribute_values[i]);
    }

    free(line);
    free(attribute_names);
    free(attribute_values);
    
    return 0;
}