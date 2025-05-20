//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: lively
// Welcome to my XML Parser program!
// This program takes in an XML file and extracts information from it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 100
#define MAX_ATT_LEN 100
#define MAX_ATT_VAL_LEN 100
#define MAX_VAL_LEN 1000

// This function reads in the XML file into a string
char* readXMLFile(char* file_name) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: cannot open file %s\n", file_name);
        exit(0);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* xml_str = malloc(file_size * sizeof(char));
    fread(xml_str, sizeof(char), file_size, file);
    fclose(file);

    return xml_str;
}

// This function parses out the tag name
char* parseTagName(char* xml_str, int* index) {
    int start_index = *index;
    while (xml_str[*index] != '<' && xml_str[*index] != '>') (*index)++;
    int tag_len = *index - start_index;
    char* tag_name = malloc((tag_len + 1) * sizeof(char));
    for (int i = 0; i < tag_len; i++) tag_name[i] = xml_str[start_index + i];
    tag_name[tag_len] = '\0';
    return tag_name;
}

// This function parses out the attribute name and value
void parseAttribute(char* xml_str, int* index, char* attribute_name, char* attribute_value) {
    int start_index = *index;
    while (xml_str[*index] != '=') (*index)++;
    int att_name_len = *index - start_index;
    for (int i = 0; i < att_name_len; i++) attribute_name[i] = xml_str[start_index + i];
    attribute_name[att_name_len] = '\0';

    int quote_count = 0;
    while (xml_str[*index] != '"' || quote_count == 1) {
        if (xml_str[*index] == '"') quote_count++;
        else attribute_value[strlen(attribute_value)] = xml_str[*index];
        (*index)++;
    }
}

// This function parses out the tag's attributes
void parseAttributes(char* xml_str, int* index, char* attribute_names[], char* attribute_values[], int* num_atts) {
    // Initialize variables
    *num_atts = 0;
    char* attribute_name = malloc(MAX_ATT_LEN * sizeof(char));
    char* attribute_value = malloc(MAX_ATT_VAL_LEN * sizeof(char));

    // Loop through the attribute list
    while (xml_str[*index] != '>') {
        if (xml_str[*index] == '/' && xml_str[*index + 1] == '>') return; // No attributes

        // Parse out the next attribute
        parseAttribute(xml_str, index, attribute_name, attribute_value);
        attribute_names[*num_atts] = malloc(MAX_ATT_LEN * sizeof(char));
        attribute_values[*num_atts] = malloc(MAX_ATT_VAL_LEN * sizeof(char));
        strcpy(attribute_names[*num_atts], attribute_name);
        strcpy(attribute_values[*num_atts], attribute_value);
        (*num_atts)++;
        attribute_name = malloc(MAX_ATT_LEN * sizeof(char));
        attribute_value = malloc(MAX_ATT_VAL_LEN * sizeof(char));
        (*index)++;
    }
}

// This function parses out the tag's value (if it exists)
char* parseValue(char* xml_str, int* index) {
    int start_index = *index;
    while (xml_str[*index] != '<') (*index)++;
    int val_len = *index - start_index;
    char* value = malloc((val_len + 1) * sizeof(char));
    for (int i = 0; i < val_len; i++) value[i] = xml_str[start_index + i];
    value[val_len] = '\0';
    return value;
}

// This function parses out a single tag (and its subtags)
void parseTag(char* xml_str, int* index) {
    // Parse out the tag name
    char* tag_name = parseTagName(xml_str, index);
    printf("Tag found: <%s>\n", tag_name);

    // Parse out the attributes (if they exist)
    char* attribute_names[MAX_ATT_LEN];
    char* attribute_values[MAX_ATT_VAL_LEN];
    int num_atts;
    parseAttributes(xml_str, index, attribute_names, attribute_values, &num_atts);
    for (int i = 0; i < num_atts; i++) {
        printf("\tAttribute found: %s=\"%s\"\n", attribute_names[i], attribute_values[i]);
        free(attribute_names[i]);
        free(attribute_values[i]);
    }

    // Parse out the tag value (if it exists)
    char* tag_value = parseValue(xml_str, index);
    if (strlen(tag_value) > 0) {
        printf("\tValue found: %s\n", tag_value);
        free(tag_value);
    }

    // Recursively call the function for any subtags
    while (xml_str[*index - 1] != '>' && xml_str[*index] != '<') (*index)++;
    while (xml_str[*index] == '<') {
        if (xml_str[*index + 1] == '/') {
            printf("End tag found: </%s>\n", tag_name);
            (*index) += strlen(tag_name) + 3;
            free(tag_name);
            return;
        }
        parseTag(xml_str, index);
    }

    printf("End tag found: </%s>\n", tag_name);
    free(tag_name);
}

int main() {
    // Read in the XML file
    char* xml_str = readXMLFile("example.xml");

    // Parse out each tag
    int index = 0;
    while (xml_str[index] != '\0')
        parseTag(xml_str, &index);

    free(xml_str);
    return 0;
}