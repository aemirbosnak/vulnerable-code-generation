//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 50
#define MAX_VAL_LEN 100

typedef struct xml_node {
    char tag[MAX_TAG_LEN];
    char value[MAX_VAL_LEN];
    struct xml_node* children;
    struct xml_node* next;
} xml_node;

xml_node* parse_xml(char* xml_str);
xml_node* parse_node(char* xml_str, int* index);
void add_node(xml_node** cur, xml_node* new_node);

int main(){
     char* xml_str = "<people><person><name>John Smith</name><age>35</age></person><person><name>Emily Jones</name><age>28</age></person></people>";

     xml_node* root = parse_xml(xml_str);
     
    return 0;
}

xml_node* parse_xml(char* xml_str) {
    int index = 0;
    return parse_node(xml_str, &index);
}

xml_node* parse_node(char* xml_str, int* index) {
    xml_node* node = (xml_node*) malloc(sizeof(xml_node));
    node->children = node->next = NULL;
    
    // Getting the tag name
    int tag_len = strcspn(&xml_str[*index], ">");
    strncpy(node->tag, &xml_str[*index], tag_len);
    node->tag[tag_len] = '\0';
    *index += tag_len + 1;
    
    // Getting the value
    int val_len = strcspn(&xml_str[*index], "<");
    strncpy(node->value, &xml_str[*index], val_len);
    node->value[val_len] = '\0';
    *index += val_len;
    
    // Parsing children
    while(xml_str[*index] != '\0' && xml_str[*index+1] != '/' && xml_str[*index+1] != '\0') {
        *index++;
        xml_node* child_node = parse_node(xml_str, index);
        add_node(&node->children, child_node);
    }

    *index += 2 + strlen(node->tag);

    // Adding sibling 
    if(xml_str[*index] == '<') {
        *index -= strlen(node->tag) + 3;
        free(node);
        return NULL;
    } else if(xml_str[*index] == '/') {
        *index += strlen(node->tag) + 3;
        free(node);
        return NULL;
    } else {
        xml_node* sibling_node = parse_node(xml_str, index);
        add_node(&node->next, sibling_node);
        return node;
    }
}

void add_node(xml_node** cur, xml_node* new_node) {
    if(*cur == NULL) {
        *cur = new_node;
    } else {
        add_node(&(*cur)->next, new_node);
    }
}