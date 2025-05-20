//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xml_attribute {
    char *name;
    char *value;
} xml_attribute;

typedef struct xml_tag {
    char *name;
    xml_attribute *attributes;
    char *text;
    struct xml_tag *children;
} xml_tag;

xml_tag* parse_xml(char* xml_string) {
    int index = 0;
    int tag_count = 0;
    xml_tag *tags = malloc(sizeof(xml_tag));
    
    while (xml_string[index] != '\0') {
        if (xml_string[index] == '<') {
            // Handle tag
            index++;
            char *tag_name = malloc(sizeof(char) * 100);
            int attribute_count = 0;
            xml_attribute *attributes = malloc(sizeof(xml_attribute));
            
            // Get tag name
            int name_index = 0;
            while (xml_string[index] != '>') {
                if (xml_string[index] == ' ') {
                    // Handle attribute
                    index++;
                    char *attribute_name = malloc(sizeof(char) * 100);
                    char *attribute_value = malloc(sizeof(char) * 100);
                    
                    // Get attribute name
                    int attribute_name_index = 0;
                    while (xml_string[index] != '=') {
                        attribute_name[attribute_name_index] = xml_string[index];
                        attribute_name_index++;
                        index++;
                    }
                    attribute_name[attribute_name_index] = '\0';
                    
                    // Get attribute value
                    index++;
                    int attribute_value_index = 0;
                    while (xml_string[index] != '\"') {
                        attribute_value[attribute_value_index] = xml_string[index];
                        attribute_value_index++;
                        index++;
                    }
                    attribute_value[attribute_value_index] = '\0';
                    
                    // Add attribute to tag
                    attributes = realloc(attributes, sizeof(xml_attribute) * (attribute_count + 1));
                    attributes[attribute_count].name = attribute_name;
                    attributes[attribute_count].value = attribute_value;
                    attribute_count++;
                } else {
                    tag_name[name_index] = xml_string[index];
                    name_index++;
                }
                index++;
            }
            tag_name[name_index] = '\0';
            
            // Get tag text
            index++;
            char *tag_text = malloc(sizeof(char) * 100);
            int text_index = 0;
            while (xml_string[index] != '<') {
                tag_text[text_index] = xml_string[index];
                text_index++;
                index++;
            }
            tag_text[text_index] = '\0';
            
            // Create tag
            tags = realloc(tags, sizeof(xml_tag) * (tag_count + 1));
            tags[tag_count].name = tag_name;
            tags[tag_count].attributes = attributes;
            tags[tag_count].text = tag_text;
            tag_count++;
        }
        index++;
    }
    
    return tags;
}

int main() {
    char xml[] = "<root><person name=\"John\" age=\"23\">Hello world!</person></root>";
    xml_tag *tags = parse_xml(xml);
    
    // Print tags
    for (int i = 0; i < sizeof(tags) / sizeof(xml_tag); i++) {
        printf("Tag: %s\n", tags[i].name);
        printf("Attributes:\n");
        for (int j = 0; j < sizeof(tags[i].attributes) / sizeof(xml_attribute); j++) {
            printf("%s=%s\n", tags[i].attributes[j].name, tags[i].attributes[j].value);
        }
        printf("Text: %s\n", tags[i].text);
    }
    
    return 0;
}