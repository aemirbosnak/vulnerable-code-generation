//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <string.h>

//Struct to hold metadata information
struct Metadata {
    char name[50];
    char type[20];
    struct Metadata *next;
    struct Metadata *children;
};

//Function to create new metadata node
struct Metadata *createMetadata(char *name, char *type) {
    struct Metadata *node = (struct Metadata*) malloc(sizeof(struct Metadata));
    strcpy(node->name, name);
    strcpy(node->type, type);
    node->next = NULL;
    node->children = NULL;
    return node;
}

//Function to add child metadata to parent metadata node
void addChild(struct Metadata *parent, struct Metadata *child) {
    if(parent == NULL || child == NULL) {
        return;
    }
    if(parent->children == NULL) {
        parent->children = child;
    } else {
        struct Metadata *temp = parent->children;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

//Function to recursively print metadata information
void printMetadata(struct Metadata *node, int level) {
    if(node == NULL) {
        return;
    }
    printf("Name: %s, Type: %s, Level: %d\n", node->name, node->type, level);
    if(node->children != NULL) {
        printMetadata(node->children, level + 1);
    }
    if(node->next != NULL) {
        printMetadata(node->next, level);
    }
}

//Function to extract metadata from given file
void extractMetadata(char *filename, struct Metadata *parent) {
    //Code to read file and extract metadata goes here
    //For demo purpose, we will create sample metadata information
    addChild(parent, createMetadata("Title", "String"));
    addChild(parent, createMetadata("Author", "String"));
    struct Metadata *book = createMetadata("Book", "Object");
    addChild(book, createMetadata("Chapter1", "Object"));
    addChild(book, createMetadata("Chapter2", "Object"));
    addChild(parent, book);
}

int main() {
    //Create root metadata node
    struct Metadata *root = createMetadata("Root", "Object");

    //Extract metadata from file and add to root node
    extractMetadata("myfile.txt", root);

    //Print metadata information recursively
    printMetadata(root, 0);

    return 0;
}