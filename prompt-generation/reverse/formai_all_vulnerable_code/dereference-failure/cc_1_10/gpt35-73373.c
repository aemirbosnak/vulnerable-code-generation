//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTRIBUTES 10
#define MAX_CHILDREN 10

typedef struct {
    char tag[20];
    char attributes[MAX_ATTRIBUTES][2][20];
    int num_attributes;
    char text[50];
    struct node_t* children[MAX_CHILDREN];
    int num_children;
} node_t;

node_t* parse_xml(FILE* fp) {
    char buffer[100];
    int i = 0, j = 0;
    node_t* root = NULL;
    node_t* curr = NULL;
    while (fgets(buffer, 100, fp) != NULL) {
        if (buffer[0] == '<' && buffer[1] != '/') {
            // New tag opened
            node_t* new_node = (node_t*)malloc(sizeof(node_t));
            if (root == NULL) {
                root = new_node;
            }
            curr = new_node;
            int k = 1;
            while (buffer[k] != ' ' && buffer[k] != '>') {
                curr->tag[j++] = buffer[k++];
            }
            curr->tag[j] = '\0';
            j = 0;
            if (buffer[k] == ' ') {
                k++;
                while (buffer[k] != '>') {
                    if (j == MAX_ATTRIBUTES) {
                        printf("Too many attributes!\n");
                        exit(1);
                    }
                    // Attribute name
                    int l = 0;
                    while (buffer[k] != '=') {
                        curr->attributes[j][0][l++] = buffer[k++];
                    }
                    curr->attributes[j][0][l] = '\0';
                    k++; // skip '='
                    // Attribute value
                    l = 0;
                    int inside_quotes = 0;
                    while (buffer[k] != '>' && !(inside_quotes && buffer[k] == '"')) {
                        if (buffer[k] == '"') {
                            inside_quotes = !inside_quotes;
                        }
                        curr->attributes[j][1][l++] = buffer[k++];
                    }
                    curr->attributes[j][1][l] = '\0';
                    j++;
                }
            }
            curr->num_attributes = j;
            j = 0;
        }
        else if (buffer[0] == '<' && buffer[1] == '/') {
            // End tag
            curr = NULL;
        }
        else {
            // Text node
            if (curr->text[0] == '\0') {
                strcpy(curr->text, buffer);
            }
            else {
                strcat(curr->text, buffer);
            }
        }
    }
    return root;
}

int main() {
    FILE* fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Could not open file!\n");
        exit(1);
    }
    node_t* root = parse_xml(fp);
    printf("XML parsed successfully!\n");
    return 0;
}