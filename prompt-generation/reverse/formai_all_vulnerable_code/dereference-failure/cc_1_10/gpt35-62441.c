//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10000

typedef struct xml_element {
    char tag[50];
    char content[1000];
    struct xml_element *child;
    struct xml_element *sibling;
} XmlElement;

int current_pos = 0;
char xml[MAX_SIZE];
XmlElement* root = NULL;

void parse_element(XmlElement *parent, char *tag_name, char *content) {
    XmlElement *child = malloc(sizeof(XmlElement));
    strcpy(child->tag, tag_name);
    strcpy(child->content, content);
    child->child = NULL;
    child->sibling = NULL;

    if (parent->child == NULL) {
        parent->child = child;
    } else {
        XmlElement *sibling = parent->child;
        while (sibling->sibling != NULL) {
            sibling = sibling->sibling;
        }
        sibling->sibling = child;
    }
}

void parse_xml(XmlElement *parent) {
    while (current_pos < strlen(xml)) {
        if (xml[current_pos] == '<') {
            char tag_name[50] = {0};
            char content[1000] = {0};
            int i = 1;
            while (xml[current_pos+i] != '>') {
                tag_name[i-1] = xml[current_pos+i];
                i++;
            }
            current_pos += i;
            if (xml[current_pos+1] != '<') {
                i = 0;
                while (xml[current_pos+i] != '<') {
                    content[i] = xml[current_pos+i];
                    i++;
                }
                current_pos += i-1;
            } else {
                current_pos--;
                parse_element(parent, tag_name, "");
                XmlElement *child = parent->child;
                while (child->sibling != NULL) {
                    child = child->sibling;
                }
                parse_xml(child);
            }
        }
        current_pos++;
    }
}

void print_element(XmlElement *e) {
    printf("<%s>", e->tag);
    if (strlen(e->content) > 0) {
        printf("%s", e->content);
    }
    if (e->child != NULL) {
        print_element(e->child);
    }
    printf("</%s>", e->tag);
    if (e->sibling != NULL) {
        print_element(e->sibling);
    }
}

int main() {
    FILE *fp;
    char filename[50];
    printf("Enter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(0);
    }
    fgets(xml, MAX_SIZE, fp);
    root = malloc(sizeof(XmlElement));
    strcpy(root->tag, "root");
    strcpy(root->content, "");
    root->child = NULL;
    root->sibling = NULL;

    parse_xml(root);
    print_element(root->child);
    return 0;
}