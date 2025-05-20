//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char value[100];
} Attribute;

typedef struct {
    char tag_name[50];
    Attribute attributes[10];
    int num_attributes;
    char text[200];
} Tag;

void parse_xml(FILE *file);
int read_until(char *str, char c, FILE *file);
char* read_attribute_value(char *cursor);
void print_tag(Tag tag);

int main() {
    FILE *file = fopen("example.xml", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        exit(1);
    }
    
    parse_xml(file);
    fclose(file);
    
    return 0;
}

void parse_xml(FILE *file) {
    Tag tags[20];
    int current_tag_index = 0;
    char cursor;
    char buffer[50];
    
    while ((cursor = fgetc(file)) != EOF) {
        if (cursor == '<') {
            cursor = fgetc(file);
            if (cursor == '/') { // Closing tag detected
                read_until(buffer, '>', file); // read tag name
                current_tag_index--;
            } else { // Opening tag detected
                current_tag_index++;
                strcpy(tags[current_tag_index].tag_name, "");
                strcpy(tags[current_tag_index].text, "");
                tags[current_tag_index].num_attributes = 0;
                
                read_until(buffer, ' ' , file); // read tag name
                strcpy(tags[current_tag_index].tag_name, buffer);
                
                while ((cursor = fgetc(file)) != '>') { // read attributes
                    if (cursor == ' ') {
                        read_until(buffer, '=', file); // read attribute name
                        strcpy(tags[current_tag_index].attributes[tags[current_tag_index].num_attributes].name, buffer);
                        cursor = fgetc(file);
                        
                        if (cursor == '"') { // attribute value is enclosed in quotes
                            strcpy(tags[current_tag_index].attributes[tags[current_tag_index].num_attributes].value, read_attribute_value(&cursor));
                        } else { // attribute value is not enclosed in quotes
                            ungetc(cursor, file);
                            read_until(tags[current_tag_index].attributes[tags[current_tag_index].num_attributes].value, '>', file);
                        }
                        
                        tags[current_tag_index].num_attributes++;
                    }
                }
            }
        } else if (current_tag_index > 0) { // Text inside a tag
            strncat(tags[current_tag_index].text, &cursor, 1);
        }
    }
    
    for (int i = 1; i <= current_tag_index; i++) {
        print_tag(tags[i]);
    }
}

int read_until(char *str, char c, FILE *file) {
    char cursor;
    int i = 0;
    while ((cursor = fgetc(file)) != c) {
        str[i] = cursor;
        i++;
    }
    str[i] = '\0';
    return i;
}

char* read_attribute_value(char *cursor) {
    int i = 0;
    char value[100];
    while (*(cursor++) != '"') {
        value[i] = *cursor;
        i++;
    }
    value[i] = '\0';
    return strdup(value);
}

void print_tag(Tag tag) {
    printf("Tag name: %s\n", tag.tag_name);
    printf("Attributes:\n");
    for (int i = 0; i < tag.num_attributes; i++) {
        printf("  Name: %s\n", tag.attributes[i].name);
        printf("  Value: %s\n", tag.attributes[i].value);
    }
    printf("Text: %s\n", tag.text);
    printf("\n");
}