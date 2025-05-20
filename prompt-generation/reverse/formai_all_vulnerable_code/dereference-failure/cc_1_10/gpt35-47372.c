//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    char attribute[MAX_SIZE];
    char value[MAX_SIZE];
} Tag;

// function to check if a given tag is a closing tag
int is_closing_tag(char* tag) {
    if (tag[0] == '<' && tag[1] == '/' && tag[strlen(tag)-1] == '>') {
        return 1;
    }
    return 0;
}

// function to parse an XML file and extract data
void parse_XML(char* file_name) {

    FILE* fp;

    // open the file in read mode
    fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    char ch;

    // read the file character by character
    while ((ch = fgetc(fp)) != EOF) {

        // check if the current character is the start of a new tag
        if (ch == '<') {

            char tag[MAX_SIZE];
            Tag curr_tag;

            // read the entire tag
            fgets(tag, MAX_SIZE, fp);

            // remove any newline characters from the tag
            strtok(tag, "\n");

            // check if the tag is a closing tag
            if (is_closing_tag(tag)) {
                printf("Closing tag: %s\n", tag);
            }

            // if the tag is not a closing tag, extract the tag name, attribute, and value
            else {

                // extract the tag name
                char* p = strtok(tag, " <>");
                strcpy(curr_tag.name, p);

                // extract the attribute and its value (if any)
                while (p != NULL) {
                    p = strtok(NULL, " <>");
                    if (p != NULL) {
                        if (strstr(p, "=") != NULL) {
                            strcpy(curr_tag.attribute, p);
                            strtok(curr_tag.attribute, "=");
                            strcpy(curr_tag.value, strtok(NULL, "="));
                        }
                    }
                }

                printf("Tag name: %s\n", curr_tag.name);

                if (strlen(curr_tag.attribute) > 0) {
                    printf("Attribute: %s\n", curr_tag.attribute);
                    printf("Value: %s\n", curr_tag.value);
                }
            }
        }
    }

    // close the file
    fclose(fp);
}

int main() {

    // call the parse_XML function with the name of the XML file to be parsed
    parse_XML("example.xml");

    return 0;
}