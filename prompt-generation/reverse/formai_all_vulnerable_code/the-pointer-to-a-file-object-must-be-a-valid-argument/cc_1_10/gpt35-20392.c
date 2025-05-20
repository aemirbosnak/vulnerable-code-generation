//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 100      // maximum text length
#define MAX_TAG_LENGTH 20        // maximum tag length
#define MAX_ATTRIBUTES 10       // maximum number of attributes
#define MAX_ATTRIBUTE_LENGTH 20  // maximum attribute length

typedef struct {
    char tag[MAX_TAG_LENGTH+1];                  // tag name
    char attributes[MAX_ATTRIBUTES][MAX_ATTRIBUTE_LENGTH+1];    // attribute names
    char values[MAX_ATTRIBUTES][MAX_ATTRIBUTE_LENGTH+1];        // attribute values
    int num_attributes;                         // number of attributes for this tag
} XMLTag;

int parseXML(const char *filename, XMLTag *tags);
void printTag(XMLTag *tag);
void printTags(XMLTag *tags, int num_tags);

int main() {
    XMLTag tags[MAX_ATTRIBUTES];
    int num_tags = parseXML("example.xml", tags);
    printTags(tags, num_tags);
    return 0;
}

// Parse an XML file and store the tags in an array
int parseXML(const char *filename, XMLTag *tags) {
    int num_tags = 0;
    FILE *fp = fopen(filename, "r");
    char input[MAX_TEXT_LENGTH+1];
    char tag[MAX_TAG_LENGTH+1];
    char attribute[MAX_ATTRIBUTE_LENGTH+1];
    char value[MAX_ATTRIBUTE_LENGTH+1];
    int in_tag = 0;
    int in_attribute = 0;
    int i;

    while (fgets(input, MAX_TEXT_LENGTH+1, fp) != NULL) {
        for (i = 0; i < strlen(input); i++) {
            if (input[i] == '<') {      // entering tag
                in_tag = 1;
                tag[0] = '\0';
                attribute[0] = '\0';
                value[0] = '\0';
            }
            else if (input[i] == '>') {  // exiting tag
                in_tag = 0;
                if (num_tags < MAX_ATTRIBUTES) {
                    strcpy(tags[num_tags].tag, tag);
                    tags[num_tags].num_attributes = 0;
                }
                num_tags++;
            }
            else if (input[i] == '=') {  // entering attribute value
                in_attribute = 0;
            }
            else if (input[i] == '\"') { // exiting attribute value
                in_attribute = !in_attribute;
            }
            else {                       // adding to tag/attribute/value
                if (in_tag) {
                    strncat(tag, &input[i], 1);
                }
                else if (in_attribute) {
                    strncat(value, &input[i], 1);
                }
                else {
                    strncat(attribute, &input[i], 1);
                }
            }

            // checking for attributes
            if (num_tags > 0 && input[i] == ' ' && !in_attribute && !in_tag) {
                if (tags[num_tags-1].num_attributes < MAX_ATTRIBUTES) {
                    strcpy(tags[num_tags-1].attributes[tags[num_tags-1].num_attributes], attribute);
                    strcpy(tags[num_tags-1].values[tags[num_tags-1].num_attributes], value);
                    tags[num_tags-1].num_attributes++;
                    attribute[0] = '\0';
                    value[0] = '\0';
                }
            }
        }
    }

    fclose(fp);
    return num_tags;
}

// Print out the contents of a single tag
void printTag(XMLTag *tag) {
    int i;
    printf("<%s", tag->tag);
    for (i = 0; i < tag->num_attributes; i++) {
        printf(" %s=\"%s\"", tag->attributes[i], tag->values[i]);
    }
    printf(">\n");
}

// Print out all of the tags in the array
void printTags(XMLTag *tags, int num_tags) {
    int i;
    for (i = 0; i < num_tags; i++) {
        printTag(&tags[i]);
    }
}