//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to hold XML elements
typedef struct Element{
    char name[50];
    char content[100];
    struct Element *child;
    struct Element *sibling;
}Element;

// Function to create a new element
Element *new_element(char *name, char *content){
    Element *new = (Element*)malloc(sizeof(Element));
    strcpy(new->name, name);
    strcpy(new->content, content);
    new->child = NULL;
    new->sibling = NULL;
    return new;
}

// Function to parse XML document
void parse(Element *root, char *xml){
    char *token;
    token = strtok(xml, "<>");
    while(token != NULL){
        if(token[0] == '/'){
            root = root->sibling;
        }else{
            if(root->child == NULL){
                root->child = new_element(token, "");
                root = root->child;
            }else{
                root->sibling = new_element(token, "");
                root = root->sibling;
            }
        }
        token = strtok(NULL, "<>");
    }
}

int main(){
    Element *root = new_element("root", "");
    char *xml = "<root><section1><title>Example</title><paragraph>This is an example paragraph</paragraph></section1></root>";
    parse(root, xml);
    printf("Parsed XML:\n");
    printf("Root: %s\n", root->name);
    printf("Child: %s\n", root->child->name);
    printf("Title: %s\n", root->child->child->name);
    printf("Content: %s\n", root->child->child->content);
    printf("Paragraph: %s\n", root->child->child->sibling->name);
    printf("Content: %s\n", root->child->child->sibling->content);

    return 0;
}