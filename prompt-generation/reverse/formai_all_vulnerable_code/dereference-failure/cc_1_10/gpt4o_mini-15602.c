//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an XML element
typedef struct XMLNode {
    char *tag;
    char *content;
    struct XMLNode *next;
    struct XMLNode *child;
} XMLNode;

// Function to create a new XMLNode
XMLNode* createNode(const char* tag, const char* content) {
    XMLNode *newNode = (XMLNode *)malloc(sizeof(XMLNode));
    newNode->tag = strdup(tag);
    newNode->content = content ? strdup(content) : NULL;
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

// Function to print the XML structure in a Romeo and Juliet style
void printXML(XMLNode *node, int level) {
    if (node == NULL) return;
    
    for (int i = 0; i < level; i++) printf("\t");
    printf("<%s>", node->tag);
    if (node->content) {
        printf("%s", node->content);
    }
    printf("\n");
    
    if (node->child) printXML(node->child, level + 1);
    
    for (int i = 0; i < level; i++) printf("\t");
    printf("</%s>\n", node->tag);
    
    if (node->next) printXML(node->next, level);
}

// Function to free the memory allocated for the XMLNode
void freeXML(XMLNode *node) {
    if (node == NULL) return;
    freeXML(node->child);
    freeXML(node->next);
    free(node->tag);
    free(node->content);
    free(node);
}

// The play of XML begins, in Verona's eternal night.
int main() {
    // A house, a structure forged in noble purpose, 
    // That is the birth of XML within our noble hearts.
    
    XMLNode *root = createNode("Story", NULL);
    
    // That which we call a tag, by any other name would read as sweet, 
    // The tales of love, betrayal, fitted by fate's cruel hand.
    
    XMLNode *act1 = createNode("Act", "Two Households, both alike in dignity.");
    XMLNode *scene1 = createNode("Scene", "From ancient grudge break to new mutiny.");
    root->child = act1;
    act1->child = scene1;
    
    // O fair Juliet, a beauty unmatched by the stars, 
    // And noble Romeo, whose name bears the weight of love eternal.
    
    XMLNode *juliet = createNode("Juliet", "O, Romeo, Romeo! Wherefore art thou Romeo?");
    XMLNode *romeo = createNode("Romeo", "But, soft! What light through yonder window breaks?");
    
    scene1->child = juliet;
    juliet->next = romeo; // Romeo takes his place beside her steadfast spirit.
    
    // Ah! The tragedy unfolds beneath the pale moonlight.
    
    printXML(root, 0);
    
    // Thus, we close the curtain, for all within must return to dust.
    freeXML(root);
    return 0;
}