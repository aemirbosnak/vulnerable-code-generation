//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT_SIZE 100
#define MAX_VALUE_SIZE 100
#define MAX_LINE_LENGTH 512

typedef struct XmlElement {
    char name[MAX_ELEMENT_SIZE];
    char value[MAX_VALUE_SIZE];
    struct XmlElement *next;
    struct XmlElement *child;
} XmlElement;

XmlElement* create_element(const char *name, const char *value) {
    XmlElement *element = (XmlElement *)malloc(sizeof(XmlElement));
    if (element == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(element->name, name, MAX_ELEMENT_SIZE);
    strncpy(element->value, value, MAX_VALUE_SIZE);
    element->next = NULL;
    element->child = NULL;
    return element;
}

void free_element(XmlElement *element) {
    if (element) {
        free_element(element->child);
        free_element(element->next);
        free(element);
    }
}

void print_element(XmlElement *element, int depth) {
    if (element) {
        for (int i = 0; i < depth; ++i) {
            printf("  ");
        }
        printf("Element Name: %s\n", element->name);
        if (strlen(element->value) > 0) {
            for (int i = 0; i < depth + 1; ++i) {
                printf("  ");
            }
            printf("Value: %s\n", element->value);
        }
        print_element(element->child, depth + 1);
        print_element(element->next, depth);
    }
}

char* trim_whitespace(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    return str;
}

XmlElement* parse_xml(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    XmlElement *root = NULL, *current = NULL;
    XmlElement *lastChild = NULL;

    while (fgets(line, sizeof(line), file)) {
        char *start = strchr(line, '<');
        if (start) {
            char *end = strchr(start, '>');
            if (end) {
                *end = '\0';
                char *elementName = trim_whitespace(start + 1);
                char *valuePart = end + 1;

                if (strncmp(elementName, "/", 1) != 0) { // Opening tag
                    char *spacePos = strchr(elementName, ' ');
                    if (spacePos) {
                        *spacePos = '\0';
                    }
                    XmlElement *newElem = create_element(elementName, "");
                    if (current) {
                        if (!current->child) {
                            current->child = newElem;
                        } else {
                            current->next = newElem;
                        }
                    } else {
                        root = newElem;
                    }
                    current = newElem;

                    if (spacePos) {
                        *spacePos = ' ';
                    }
                } else { // Closing tag
                    current = current->next;
                }

                if (*valuePart) {
                    strncpy(current->value, trim_whitespace(valuePart), MAX_VALUE_SIZE);
                }
            }
        }
    }

    fclose(file);
    return root;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    XmlElement *xmlTree = parse_xml(argv[1]);
    if (!xmlTree) {
        return EXIT_FAILURE;
    }

    print_element(xmlTree, 0);
    free_element(xmlTree);
    return EXIT_SUCCESS;
}