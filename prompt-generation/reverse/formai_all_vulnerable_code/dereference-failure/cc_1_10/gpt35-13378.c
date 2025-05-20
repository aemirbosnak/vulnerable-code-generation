//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: happy
// Welcome to the happy XML Parser program!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the XML string that can be parsed
#define MAX_XML_SIZE 1000

// Define the structure of an XML node
typedef struct XMLNode {
    char* nodeName;
    char* nodeValue;
    struct XMLNode* child;
    struct XMLNode* next;
} XMLNode;

// Declare function for parsing XML string
XMLNode* parseXML(char* xmlString);

int main() {
    printf("I am a happy XML Parser program!\n");
    
    // Declare an example XML String to be parsed
    char xmlString[MAX_XML_SIZE] = "<root><node1>Hello</node1><node2>World!</node2></root>";
    
    // Call the parseXML function to parse the XML string
    XMLNode* rootNode = parseXML(xmlString);
    
    // Print out the parsed XML tree
    printf("\nParsed XML Tree:\n");
    printf("Node Name: %s, Node Value: %s\n", rootNode->nodeName, rootNode->nodeValue);
    printf("Node Name: %s, Node Value: %s\n", rootNode->child->nodeName, rootNode->child->nodeValue);
    printf("Node Name: %s, Node Value: %s\n", rootNode->child->next->nodeName, rootNode->child->next->nodeValue);
    
    return 0;
}

// Function for parsing the XML string recursively
XMLNode* parseXML(char* xmlString) {
    // Allocate memory for a new XML node
    XMLNode* newNode = (XMLNode*)malloc(sizeof(XMLNode));
    newNode->nodeName = NULL;
    newNode->nodeValue = NULL;
    newNode->child = NULL;
    newNode->next = NULL;
    
    // Find the starting and ending positions of the opening and closing tags
    char* startOpeningTag = strstr(xmlString, "<");
    char* endOpeningTag = strstr(startOpeningTag, ">");
    char* startClosingTag = strstr(endOpeningTag, "</");
    char* endClosingTag = strstr(startClosingTag, ">");
    
    // Extract the node name from the opening tag
    int nodeNameLength = endOpeningTag - startOpeningTag - 1;
    newNode->nodeName = (char*)malloc(nodeNameLength + 1);
    strncpy(newNode->nodeName, startOpeningTag + 1, nodeNameLength);
    newNode->nodeName[nodeNameLength] = '\0';
    
    // Extract the node value between the opening and closing tags (if any)
    int nodeValueLength = startClosingTag - endOpeningTag - 1;
    if (nodeValueLength > 0) {
        newNode->nodeValue = (char*)malloc(nodeValueLength + 1);
        strncpy(newNode->nodeValue, endOpeningTag + 1, nodeValueLength);
        newNode->nodeValue[nodeValueLength] = '\0';
    }
    
    // Recursively parse any child nodes (if any)
    char* nextChildString = endOpeningTag + 1;
    while (nextChildString < startClosingTag) {
        if (*nextChildString == '<') {
            XMLNode* childNode = parseXML(nextChildString);
            if (newNode->child == NULL) {
                newNode->child = childNode;
            }
            else {
                XMLNode* lastChild = newNode->child;
                while (lastChild->next != NULL) {
                    lastChild = lastChild->next;
                }
                lastChild->next = childNode;
            }
            nextChildString = strstr(nextChildString, ">");
        }
        else {
            ++nextChildString;
        }
    }
    
    // Return the parsed node
    return newNode;
}