//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the XML tags we're interested in
#define TAG_NAME "name"
#define TAG_EMAIL "email"
#define TAG_AGE "age"

// Define the states of our parser
enum ParserState {
    STATE_START,
    STATE_TAG_START,
    STATE_TAG_NAME,
    STATE_TAG_END,
    STATE_DATA,
    STATE_COMMENT,
    STATE_CDATA,
    STATE_END
};

// Define the data structure for our parsed data
struct ParsedData {
    char *name;
    char *email;
    int age;
};

// Function to parse the XML document
struct ParsedData *parse_xml(const char *xml) {
    // Initialize our parser state
    enum ParserState state = STATE_START;

    // Initialize our parsed data
    struct ParsedData *data = malloc(sizeof(struct ParsedData));
    data->name = NULL;
    data->email = NULL;
    data->age = -1;

    // Loop through each character in the XML document
    for (const char *p = xml; *p != '\0'; p++) {
        // Switch on the current parser state
        switch (state) {
            case STATE_START:
                // If we encounter a '<', we're starting a tag
                if (*p == '<') {
                    state = STATE_TAG_START;
                }
                break;
            case STATE_TAG_START:
                // If we encounter a '/', we're ending a tag
                if (*p == '/') {
                    state = STATE_TAG_END;
                }
                // Otherwise, we're starting a tag name
                else {
                    state = STATE_TAG_NAME;
                }
                break;
            case STATE_TAG_NAME:
                // If we encounter a '>', we're ending a tag name
                if (*p == '>') {
                    state = STATE_DATA;
                }
                // Otherwise, we're still reading the tag name
                else {
                    // Allocate memory for the tag name
                    data->name = malloc(strlen(p) + 1);

                    // Copy the tag name into the data structure
                    strcpy(data->name, p);
                }
                break;
            case STATE_TAG_END:
                // If we encounter a '>', we're ending a tag
                if (*p == '>') {
                    state = STATE_START;
                }
                break;
            case STATE_DATA:
                // If we encounter a '<', we're starting a new tag
                if (*p == '<') {
                    state = STATE_TAG_START;
                }
                // Otherwise, we're still reading data
                else {
                    // Allocate memory for the data
                    data->email = malloc(strlen(p) + 1);

                    // Copy the data into the data structure
                    strcpy(data->email, p);
                }
                break;
            case STATE_COMMENT:
                // If we encounter a '-->', we're ending a comment
                if (*p == '-' && *(p+1) == '-' && *(p+2) == '>') {
                    state = STATE_START;
                }
                break;
            case STATE_CDATA:
                // If we encounter a ']]>', we're ending a CDATA section
                if (*p == ']' && *(p+1) == ']' && *(p+2) == '>') {
                    state = STATE_START;
                }
                break;
            case STATE_END:
                // We've reached the end of the XML document
                break;
        }
    }

    // Return the parsed data
    return data;
}

// Function to print the parsed data
void print_parsed_data(struct ParsedData *data) {
    printf("Name: %s\n", data->name);
    printf("Email: %s\n", data->email);
    printf("Age: %d\n", data->age);
}

// Main function
int main() {
    // Define the XML document
    const char *xml = "<person><name>John Doe</name><email>johndoe@example.com</email><age>30</age></person>";

    // Parse the XML document
    struct ParsedData *data = parse_xml(xml);

    // Print the parsed data
    print_parsed_data(data);

    // Free the memory allocated for the parsed data
    free(data->name);
    free(data->email);
    free(data);

    return 0;
}