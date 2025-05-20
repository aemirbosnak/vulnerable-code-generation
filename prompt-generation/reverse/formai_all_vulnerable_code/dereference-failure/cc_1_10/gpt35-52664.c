//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct XMLNode{
    struct XMLNode *child;
    struct XMLNode *next;
    char *name;
    char *value;
    int attributes_size;
    char **attributes;
}XMLNode;

XMLNode* create_node(char *name){
    XMLNode *node = (XMLNode*) malloc(sizeof(XMLNode));
    node->attributes = NULL;
    node->attributes_size = 0;
    node->child = NULL;
    node->next = NULL;
    node->name = (char*) malloc(strlen(name) + 1);
    strcpy(node->name, name);
    return node;
}

void add_child(XMLNode *parent, XMLNode *child){
    child->next = parent->child;
    parent->child = child;
}

void add_attribute(XMLNode *node, char *attribute){
    node->attributes = (char**) realloc(node->attributes, sizeof(char*) * (node->attributes_size + 1));
    node->attributes[node->attributes_size++] = attribute;
}

void free_node(XMLNode *node){
    if(node->child){
        free_node(node->child);
    }
    if(node->next){
        free_node(node->next);
    }
    if(node->name){
        free(node->name);
    }
    if(node->value){
        free(node->value);
    }
    if(node->attributes){
        for(int i = 0; i < node->attributes_size; i++){
            free(node->attributes[i]);
        }
        free(node->attributes);
    }
    free(node);
}

void print_node(XMLNode *node, int depth){
    for(int i = 0; i < depth; i++){
        printf("  ");
    }
    printf("<%s", node->name);
    for(int i = 0; i < node->attributes_size; i++){
        printf(" %s", node->attributes[i]);
    }
    if(!node->child && !node->value){
        printf("/>\n");
        return;
    }
    printf(">");
    if(node->value){
        printf("%s", node->value);
    }
    printf("\n");
    if(node->child){
        print_node(node->child, depth + 1);
    }
    for(XMLNode *current = node->child; current; current = current->next){
        print_node(current, depth + 1);
    }
    for(int i = 0; i < depth; i++){
        printf("  ");
    }
    printf("</%s>\n", node->name);
}

void parse_attribute(char *attribute, char **name, char **value){
    *name = strtok(attribute, "=");
    *value = strtok(NULL, "=");
    if(*value == NULL){
        *name = attribute;
        *value = "";
    } else {
        if(*value[0] == '\"'){
            (*value)++;
            (*value)[strlen(*value) - 1] = 0;
        }
    }
}

void parse_node(XMLNode *parent){
    while(1){
        char buffer[1024];
        fgets(buffer, 1024, stdin);
        if(feof(stdin)){
            break;
        }
        int length = strlen(buffer);
        if(buffer[length - 1] == '\n'){
            buffer[--length] = 0;
        }
        if(buffer[length - 1] == '\r'){
            buffer[--length] = 0;
        }
        if(length == 0){
            continue;
        }
        if(buffer[0] == '<' && buffer[1] == '/'){
            return;
        }
        if(buffer[0] == '<'){
            XMLNode *node = create_node(buffer + 1);
            char *next = buffer + 1;
            while(*next != ' ' && *next != '>'){
                next++;
            }
            *next = 0;
            next++;
            while(*next){
                char *name;
                char *value;
                parse_attribute(next, &name, &value);
                add_attribute(node, strdup(next));
                next += strlen(name) + strlen(value) + 2;
            }
            if(parent){
                add_child(parent, node);
            }
            parse_node(node);
        }
        else {
            if(parent){
                parent->value = strdup(buffer);
            }
        }
    }
}

int main(){
    XMLNode *root = create_node("xml");
    parse_node(root);
    print_node(root, 0);
    free_node(root);
    return 0;
}