//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define MAX_TAG_NAME 100
#define MAX_NODE 100

typedef struct XMLNode {
    char tag[MAX_TAG_NAME];
    char content[MAX_BUFFER];
    struct XMLNode* children[MAX_NODE];
    int childCount;
} XMLNode;

XMLNode* createNode(const char* tag, const char* content) {
    XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));
    strncpy(node->tag, tag, MAX_TAG_NAME);
    strncpy(node->content, content, MAX_BUFFER);
    node->childCount = 0;
    return node;
}

void addChild(XMLNode* parent, XMLNode* child) {
    if (parent->childCount < MAX_NODE) {
        parent->children[parent->childCount++] = child;
    } else {
        fprintf(stderr, "Maximum child limit reached for tag: %s\n", parent->tag);
    }
}

void printXML(XMLNode* node, int indent) {
    for (int i = 0; i < indent; i++) printf("  ");
    printf("<%s>", node->tag);
    if (strlen(node->content) > 0) {
        printf("%s", node->content);
    }
    printf("\n");

    for (int i = 0; i < node->childCount; i++) {
        printXML(node->children[i], indent + 1);
    }

    for (int i = 0; i < indent; i++) printf("  ");
    printf("</%s>\n", node->tag);
}

void freeXML(XMLNode* node) {
    for (int i = 0; i < node->childCount; i++) {
        freeXML(node->children[i]);
    }
    free(node);
}

char* getTag(const char* buffer, int* index) {
    char tag[MAX_TAG_NAME];
    int i = *index;

    while (buffer[i] != '>' && buffer[i] != '\0') {
        tag[i - *index] = buffer[i];
        i++;
    }
    tag[i - *index] = '\0';
    *index = i + 1; // Move past '>'
    
    return strdup(tag);
}

char* getContent(const char* buffer, int* index) {
    char content[MAX_BUFFER] = {0};
    int i = *index;

    while (buffer[i] != '<' && buffer[i] != '\0') {
        content[i - *index] = buffer[i];
        i++;
    }
    
    content[i - *index] = '\0';
    *index = i; // Move to the next '<'

    // Trim leading whitespace
    char* trimmedContent = strdup(content);
    for (int j = 0; j < strlen(trimmedContent); j++) {
        if (trimmedContent[j] == '\n' || trimmedContent[j] == '\t') {
            trimmedContent[j] = ' ';
        }
    }
    
    return trimmedContent;
}

XMLNode* parseXML(const char* buffer) {
    XMLNode* root = NULL;
    XMLNode* current = NULL;
    
    int index = 0;
    while (buffer[index] != '\0') {
        // Skip whitespace
        while (buffer[index] == ' ' || buffer[index] == '\n' || buffer[index] == '\t') {
            index++;
        }

        if (buffer[index] == '<' && buffer[index + 1] != '/') {
            index++;
            char* tag = getTag(buffer, &index);
            char* content = getContent(buffer, &index);
            
            XMLNode* newNode = createNode(tag, content);

            if (root == NULL) {
                root = newNode; // First node is the root
            }
            
            if (current) {
                addChild(current, newNode);
            }
            current = newNode; // Current becomes the new node
            free(tag);
            free(content);
        } else if (buffer[index] == '<' && buffer[index + 1] == '/') {
            index += 2; // Skip </
            char endTag[MAX_TAG_NAME];
            char* tag = getTag(buffer, &index);
            current = current->childCount > 0 ? current : NULL; // Pop to parent
            free(tag);
        }
    }

    return root;
}

int main() {
    const char* xmlData = 
        "<cyberpunk>\n"
        "  <city>Neon District</city>\n"
        "  <street>Shadow Alley</street>\n"
        "  <market>\n"
        "    <item>Neural Implants</item>\n"
        "    <item>HoloDisks</item>\n"
        "  </market>\n"
        "</cyberpunk>\n";

    XMLNode* xmlTree = parseXML(xmlData);
    printXML(xmlTree, 0);
    freeXML(xmlTree);

    return 0;
}