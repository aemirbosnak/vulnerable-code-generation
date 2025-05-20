//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum length of characters in each line
#define MAX_LINE_LENGTH 1024 

// define the XML tag structure
typedef struct xml_tag {
    char* name;
    char* value;
    struct xml_tag* parent;
    struct xml_tag* children;
    struct xml_tag* next;
} xml_tag;

// function to read a line from a file
char* read_line(FILE* fp) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, fp);
    if (read == -1) {
        free(line);
        return NULL;
    }
    return line;
}

// function to strip whitespace from a string
char* strip(char* str) {
    char* end;
    while (isspace(*str)) str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    *(end + 1) = 0;
    return str;
}

// function to parse the XML file
xml_tag* parse_xml(FILE* fp, xml_tag* parent) {
    char* line;
    while ((line = read_line(fp)) != NULL) {
        // strip the line of whitespace
        line = strip(line);
        // check if the line is a tag opening tag
        if (strncmp(line, "<", 1) == 0) {
            // create a new tag
            xml_tag* tag = malloc(sizeof(xml_tag));
            tag->parent = parent;
            tag->next = NULL;
            tag->children = NULL;
            // parse the tag name and value
            char* name_end = strchr(line, '>');
            size_t name_len = name_end - line - 1;
            tag->name = malloc(name_len + 1);
            strncpy(tag->name, line + 1, name_len);
            tag->name[name_len] = '\0';
            if (name_end[1] != '\0') {
                char* value_start = name_end + 1;
                char* value_end = strchr(value_start, '<');
                size_t value_len = value_end - value_start;
                tag->value = malloc(value_len + 1);
                strncpy(tag->value, value_start, value_len);
                tag->value[value_len] = '\0';
            }
            // recursively parse the tag's children
            tag->children = parse_xml(fp, tag);
            // add the tag to its parent's list of children
            if (parent) {
                xml_tag* last_child = parent->children;
                if (last_child) {
                    while (last_child->next != NULL) {
                        last_child = last_child->next;
                    }
                    last_child->next = tag;
                }
                else {
                    parent->children = tag;
                }
            }
            // return the tag
            return tag;
        }
    }
    // end of file reached
    return NULL;
}

// function to print the XML tag and its children recursively
void print_tag(xml_tag* tag, int indent) {
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    printf("<%s", tag->name);
    if (tag->value) {
        printf(">%s</%s>\n", tag->value, tag->name);
    }
    else {
        printf(">\n");
    }
    xml_tag* child = tag->children;
    while (child != NULL) {
        print_tag(child, indent + 2);
        child = child->next;
    }
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    printf("</%s>\n", tag->name);
}

int main() {
    // open the XML file
    FILE* fp = fopen("example.xml", "r");
    if (!fp) {
        fprintf(stderr, "Could not open file.\n");
        return 1;
    }
    // parse the XML file
    xml_tag* root = parse_xml(fp, NULL);
    // close the file
    fclose(fp);
    // print the XML tag and its children
    print_tag(root, 0);
    // free the XML tags
    xml_tag* tag = root;
    while (tag != NULL) {
        xml_tag* next = tag->next;
        free(tag->name);
        if (tag->value) {
            free(tag->value);
        }
        free(tag);
        tag = next;
    }
    return 0;
}