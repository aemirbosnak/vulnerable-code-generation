//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_XML_SIZE 1024

struct xml_node {
    char *tag_name;
    char *content;
    struct xml_node *children;
    struct xml_node *next;
};

char* get_xml_data(const char* filename) {
    char* data = malloc(MAX_XML_SIZE);
    FILE *fp;
    fp = fopen(filename, "r");
    if(!fp) {
        printf("File not found\n");
        exit(1);
    }
    int i = 0;
    while((data[i] = fgetc(fp)) != EOF) {
        i++;
    }
    data[i] = '\0';
    fclose(fp);
    return data;
}

char* extract_tag_name(char *tag) {
    char *tag_name = malloc(MAX_XML_SIZE);
    int i = 0, j = 0;
    while(tag[i] != ' ' && tag[i] != '>') {
        tag_name[j] = tag[i];
        i++;
        j++;
    }
    tag_name[j] = '\0';
    return tag_name;
}

char* extract_attributes(char *tag) {
    char *attributes = malloc(MAX_XML_SIZE);
    int i = 0, j = 0, skip = 0;
    while(tag[i] != '>') {
        if(tag[i] == ' ') {
            skip = 1;
        } else if(skip == 0) {
            i++;
            continue;
        }
        attributes[j] = tag[i];
        i++;
        j++;
    }
    attributes[j] = '\0';
    return attributes;
}

char* extract_content(char *tag) {
    int i = 0, j = 0;
    while(tag[i] != '>') {
        i++;
    }
    i++;
    char *content = malloc(MAX_XML_SIZE);
    while(tag[i] != '<') {
        content[j] = tag[i];
        i++;
        j++;
    }
    content[j] = '\0';
    return content;
}

void add_node(struct xml_node *parent, struct xml_node *child) {
    if(parent->children == NULL) {
        parent->children = child;
    } else {
        struct xml_node *current = parent->children;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = child;
    }
}

void print_node(struct xml_node *node, int depth) {
    int i;
    for(i = 0; i < depth; i++) {
        printf("\t");
    }
    printf("%s:\n", node->tag_name);
    if(node->content[0] != '\0') {
        for(i = 0; i <= depth; i++) {
            printf("\t");
        }
        printf("%s\n", node->content);
    }
    struct xml_node *current = node->children;
    while(current != NULL) {
        print_node(current, depth + 1);
        current = current->next;
    }
}

void parse_xml(char* xml_data) {
    int i = 0;
    struct xml_node *current_node = NULL, *parent_node = NULL;
    while(xml_data[i] != '\0') {
        if(xml_data[i] == '<' && xml_data[i + 1] != '/') {
            i++;
            char *tag = malloc(MAX_XML_SIZE);
            int j = 0;
            while(xml_data[i] != '>') {
                tag[j] = xml_data[i];
                i++;
                j++;
            }
            tag[j] = '>';
            tag[j + 1] = '\0';
            struct xml_node *new_node = malloc(sizeof(struct xml_node));
            new_node->tag_name = extract_tag_name(tag);
            new_node->content = extract_content(tag);
            new_node->children = NULL;
            new_node->next = NULL;
            if(current_node == NULL) {
                current_node = new_node;
            } else {
                add_node(current_node, new_node);
            }
            if(parent_node != NULL) {
                add_node(parent_node, new_node);
            }
            parent_node = new_node;
        } else if(xml_data[i] == '<' && xml_data[i + 1] == '/') {
            i += 2;
            char *end_tag = malloc(MAX_XML_SIZE);
            int j = 0;
            while(xml_data[i] != '>') {
                end_tag[j] = xml_data[i];
                i++;
                j++;
            }
            end_tag[j] = '>';
            end_tag[j + 1] = '\0';
            if(parent_node != NULL && strcmp(parent_node->tag_name, extract_tag_name(end_tag)) == 0) {
                parent_node = NULL;
            }
        } else {
            i++;
        }
    }
    print_node(current_node, 0);
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: ./xml_parser [filename]");
        return 1;
    }
    char* xml_data = get_xml_data(argv[1]);
    parse_xml(xml_data);
    free(xml_data);
    return 0;
}