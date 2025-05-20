//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1024

// Define the XML structure
typedef struct Element{
    char tagname[50];
    char **attributes;
    char *value;
    struct Element **children;
} Element;

// Define the stack structure
struct Stack {
    int top;
    int capacity;
    Element **array;
};

// Initialize the stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (Element**) malloc(stack->capacity * sizeof(Element*));
    return stack;
}

// Check to see if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Check to see if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Push an element to the stack
void push(struct Stack* stack, Element* element) {
    if(isFull(stack))
        return;
    stack->array[++stack->top] = element;
}

// Pop an element from the stack
Element* pop(struct Stack* stack) {
    if(isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

// Print the XML document
void printElement(Element* element) {
    printf("<%s ", element->tagname);
    for(int i = 0; element->attributes[i] != NULL; i += 2)
        printf("%s='%s' ", element->attributes[i], element->attributes[i + 1]);
    printf(">");
    if(element->value != NULL)
        printf("%s", element->value);
    for(int i = 0; element->children[i] != NULL; i++)
        printElement(element->children[i]);
    printf("</%s>", element->tagname);
}

// Parse the XML document
Element* parseXML(char* xml) {
    struct Stack* stack = createStack(MAXSIZE);
    Element* root = NULL;
    char* token = strtok(xml, "<>");
    while(token != NULL) {
        if(token[0] != '/') {
            Element* element = (Element*) malloc(sizeof(Element));
            strcpy(element->tagname, token);
            element->attributes = (char**) malloc(MAXSIZE * sizeof(char*));
            element->value = NULL;
            element->children = (Element**) malloc(MAXSIZE * sizeof(Element*));
            int attrIndex = 0, childIndex = 0;
            token = strtok(NULL, "<>");
            while(token != NULL && token[0] != '/') {
                if(token[0] == ' ') {
                    char* attr = strtok(token, " ='\"");
                    while(attr != NULL) {
                        if(attrIndex % 2 == 0)
                            element->attributes[attrIndex / 2] = attr;
                        else
                            element->attributes[attrIndex / 2 + 1] = attr;
                        attrIndex++;
                        attr = strtok(NULL, " ='\"");
                    }   
                }
                else {
                    Element* child = (Element*) malloc(sizeof(Element));
                    strcpy(child->tagname, token);
                    child->attributes = (char**) malloc(MAXSIZE * sizeof(char*));
                    child->value = NULL;
                    child->children = (Element**) malloc(MAXSIZE * sizeof(Element*));
                    push(stack, element);
                    element->children[childIndex++] = child;
                    element = child;
                }
                token = strtok(NULL, "<>");
            }
            element = pop(stack);
            if(!isEmpty(stack))
                element = stack->array[stack->top - 1];
            if(token != NULL && token[0] == '/') {
                token = strtok(NULL, "<>");
                strcpy(element->value, token);
            }
            if(root == NULL)
                root = element;
        }
        token = strtok(NULL, "<>");
    }
    return root;
}

int main() {
    char* xml = "<html><head><title>XML Parser Example</title></head><body><h1>Hello World!</h1><p>This is an example of an XML parser.</p></body></html>";
    Element* root = parseXML(xml);
    printElement(root);
    return 0;
}