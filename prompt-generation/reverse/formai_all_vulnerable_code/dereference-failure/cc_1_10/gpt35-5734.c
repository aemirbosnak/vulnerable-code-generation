//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_LENGTH 100

struct xml_node {
    char tag[MAX_LENGTH];
    char value[MAX_LENGTH];
    int level;
    struct xml_node *children[MAX_NODES];
    struct xml_node *parent;
};

struct xml_node *root_node;
struct xml_node *current_node;

void parse_xml(FILE *fp);
void print_tree(struct xml_node *node, int level);
void free_tree(struct xml_node *node);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <xml_file>\n", argv[0]);
        exit(1);
    }
    
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Unable to open file: %s\n", argv[1]);
        exit(1);
    }
    
    parse_xml(fp);
    fclose(fp);
    
    printf("\n\n\n--- XML Tree ---\n\n");
    print_tree(root_node, 0);
    
    free_tree(root_node);
    return 0;
}

void parse_xml(FILE *fp) {
    char buffer[MAX_LENGTH];
    int level = 0;
    int ind = 0;
    int i;
    char c;

    while ((c = fgetc(fp)) !=EOF) {

        if (c == '<') {
            if ((c = fgetc(fp)) == '/') {
                level--;
                ind = 0;
                current_node = current_node->parent;
            } else {
                struct xml_node *node = (struct xml_node *) malloc(sizeof(struct xml_node));
                node->parent = current_node;
                node->level = level;
                node->value[0] = '\0';
                node->children[0] = NULL;
                
                while (c != '>') {
                    node->tag[ind++] = c;
                    c = fgetc(fp);
                }
                node->tag[ind] = '\0';
                ind = 0;
                
                if (!root_node) {
                    root_node = node;
                    current_node = node;
                    level++;
                    continue;
                }
                
                current_node->children[0] = node;
                current_node = node;
                level++;
            }
        } else if (c == '>') {
            ;
        } else {
            while (c != '<') {
                current_node->value[ind++] = c;
                c = fgetc(fp);
            }
            current_node->value[ind] = '\0';
            ind = 0;
        }
    }
}

void print_tree(struct xml_node *node, int level) {
    int i;
    
    if (!node) {
        return;
    }
    
    for (i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%s: %s\n", node->tag, node->value);
    
    for (i = 0; node->children[i] != NULL; i++) {
        print_tree(node->children[i], level + 1);
    }
}

void free_tree(struct xml_node *node) {
    int i;
    if (!node) {
        return;
    }
    
    for (i = 0; node->children[i] != NULL; i++) {
        free_tree(node->children[i]);
    }
    
    free(node);
}