//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Node{
    char* tag;
    char* content;
    struct Node* children;
    struct Node* next;
} Node;

Node* root;

char* getTag(char* line){
    char* tag = (char*) malloc(strlen(line) * sizeof(char));
    int i = 0, j = 0;
    if(line[i++] != '<') return NULL;
    while(line[i] != '>' && j < strlen(line)){
        tag[j++] = line[i++];
    }
    tag[j] = '\0';
    return tag;
}

char* getContent(char* line){
    char* content = (char*) malloc(strlen(line) * sizeof(char));
    int i = 0, j = 0;
    while(line[i] != '<' && i < strlen(line)){
        content[j++] = line[i++];
    }
    content[j] = '\0';
    return content;
}

Node* createNode(char* tag, char* content){
    Node* node = (Node*) malloc(sizeof(Node));
    node->tag = tag;
    node->content = content;
    node->children = NULL;
    node->next = NULL;
    return node;
}

void addChild(Node* parent, Node* child){
    if(parent == NULL) return;
    if(parent->children == NULL){
        parent->children = child;
    }else{
        Node* temp = parent->children;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = child;
    }
}

void parseXMLFile(FILE* file){
    char line[MAX_SIZE];
    Node* currentNode = NULL;
    while(fgets(line, MAX_SIZE, file)){
        char* tag = getTag(line);
        char* content = getContent(line);
        if(tag == NULL) continue;
        if(tag[0] == '/'){
            if(currentNode != NULL){
                currentNode = currentNode->children;
            }
            continue;
        }
        Node* newNode = createNode(tag, content);
        if(currentNode == NULL){
            root = newNode;
            currentNode = newNode;
        }else{
            addChild(currentNode, newNode);
            currentNode = newNode;
        }
    }
}

void printTree(Node* node, int depth){
    printf("%*s<%s>%s\n", depth*2, "", node->tag, node->content);
    Node* temp = node->children;
    while(temp != NULL){
        printTree(temp, depth+1);
        temp = temp->next;
    }
    printf("%*s</%s>\n", depth*2, "", node->tag);
}

int main(){
    root = NULL;
    FILE* file = fopen("example.xml", "r");
    if(file == NULL){
        printf("Error: file not found.\n");
        return 0;
    }
    parseXMLFile(file);
    fclose(file);
    printTree(root, 0);
    return 0;
}