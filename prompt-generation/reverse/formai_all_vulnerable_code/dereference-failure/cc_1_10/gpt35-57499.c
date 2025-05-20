//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

typedef struct _tagXmlNode
{
    char* tagName;
    char* content;
    int contentLength;
    struct _tagXmlNode* parent;
    struct _tagXmlNode* children;
} XmlNode;

void parseXmlNode(XmlNode* node, char* xmlString);
XmlNode* createXmlElement(char* tagName);
void addChildNode(XmlNode* parent, XmlNode* child);
void freeXmlNode(XmlNode* node);
void printXmlNode(XmlNode* node);

int main()
{
    char xmlString[BUFFER_SIZE] = "<bookstore><book><title>The Hitchhiker's Guide to the Galaxy</title><author>Douglas Adams</author><year>1979</year></book></bookstore>";
    
    XmlNode* root = createXmlElement("root");
    parseXmlNode(root, xmlString);
    printXmlNode(root);

    freeXmlNode(root);
    return 0;
}

void parseXmlNode(XmlNode* node, char* xmlString)
{
    char* tagNameStart = NULL;
    char* tagNameEnd = NULL;
    char* contentStart = NULL;
    char* contentEnd = NULL;
    XmlNode* currentElement = node;
    int contentLength = 0;

    for (int i = 0; i < strlen(xmlString); i++)
    {
        if (xmlString[i] == '<')
        {
            if (tagNameStart != NULL)
            {
                if (contentStart != NULL)
                {
                    contentEnd = &xmlString[i];
                    contentLength = (int)(contentEnd - contentStart - 1);
                    currentElement->content = (char*)malloc(sizeof(char)*(contentLength + 1));
                    strncpy(currentElement->content, contentStart, contentLength);
                    currentElement->content[contentLength] = '\0';
                    currentElement->contentLength = contentLength;
                    contentStart = NULL;
                    contentEnd = NULL;
                }
                else
                {
                    XmlNode* child = createXmlElement(tagNameStart);
                    addChildNode(currentElement, child);
                    currentElement = child;
                }
                tagNameStart = NULL;
                tagNameEnd = NULL;
            }
            tagNameStart = &xmlString[i+1];
        }
        else if (xmlString[i] == '>')
        {
            tagNameEnd = &xmlString[i - 1];
            if (*(tagNameEnd) == '/')
            {
                currentElement = currentElement->parent;
            }
            else if (*(tagNameStart) == '/')
            {
                if (contentStart != NULL)
                {
                    contentEnd = &xmlString[i - 1];
                    contentLength = (int)(contentEnd - contentStart);
                    currentElement->content = (char*)malloc(sizeof(char)*(contentLength + 1));
                    strncpy(currentElement->content, contentStart, contentLength);
                    currentElement->content[contentLength] = '\0';
                    currentElement->contentLength = contentLength;
                    contentStart = NULL;
                    contentEnd = NULL;
                }
                currentElement = currentElement->parent;
            }
            else
            {
                tagNameEnd = &xmlString[i - 1];
                if (tagNameEnd > tagNameStart)
                {
                    int tagNameLength = (int)(tagNameEnd - tagNameStart + 1);
                    currentElement->tagName = (char*)malloc(sizeof(char)*(tagNameLength + 1));
                    strncpy(currentElement->tagName, tagNameStart, tagNameLength);
                    currentElement->tagName[tagNameLength] = '\0';
                }
                contentStart = &xmlString[i + 1];
            }
        }
        else if (contentStart != NULL && tagNameStart != NULL && tagNameEnd == NULL)
        {
            if (xmlString[i] != ' ' && xmlString[i] != '\n' && xmlString[i] != '\t')
            {
                tagNameEnd = &xmlString[i - 1];
                if (tagNameEnd > tagNameStart)
                {
                    int tagNameLength = (int)(tagNameEnd - tagNameStart + 1);
                    currentElement->tagName = (char*)malloc(sizeof(char)*(tagNameLength + 1));
                    strncpy(currentElement->tagName, tagNameStart, tagNameLength);
                    currentElement->tagName[tagNameLength] = '\0';
                }
            }
        }
        else if (tagNameStart != NULL && tagNameEnd == NULL)
        {
            if (xmlString[i] == '/')
            {
                if (contentStart != NULL)
                {
                    contentEnd = &xmlString[i - 1];
                    contentLength = (int)(contentEnd - contentStart);
                    currentElement->content = (char*)malloc(sizeof(char)*(contentLength + 1));
                    strncpy(currentElement->content, contentStart, contentLength);
                    currentElement->content[contentLength] = '\0';
                    currentElement->contentLength = contentLength;
                    contentStart = NULL;
                    contentEnd = NULL;
                }
                currentElement = currentElement->parent;
                tagNameStart = NULL;
            }
            else if (xmlString[i] == ' ')
            {
                if (*(tagNameStart) != '/')
                {
                    tagNameEnd = &xmlString[i - 1];
                    if (tagNameEnd > tagNameStart)
                    {
                        int tagNameLength = (int)(tagNameEnd - tagNameStart + 1);
                        currentElement->tagName = (char*)malloc(sizeof(char)*(tagNameLength + 1));
                        strncpy(currentElement->tagName, tagNameStart, tagNameLength);
                        currentElement->tagName[tagNameLength] = '\0';
                    }
                }
                tagNameStart = NULL;
                tagNameEnd = NULL;
            }
        }
        else if (contentStart != NULL)
        {
            if (tagNameStart != NULL && tagNameEnd == NULL && contentStart == &xmlString[i])
            {
                continue;
            }
            if (currentElement->content == NULL)
            {
                currentElement->content = (char*)malloc(sizeof(char));
                currentElement->contentLength = 0;
            }
            currentElement->contentLength++;
            char* temp = (char*)realloc(currentElement->content, sizeof(char)*(currentElement->contentLength + 1));
            if (temp == NULL)
            {
                printf("Error: Failed to allocate memory for xml node content.\n");
                return;
            }
            currentElement->content = temp;
            currentElement->content[currentElement->contentLength - 1] = xmlString[i];
            currentElement->content[currentElement->contentLength] = '\0';
        }
    }
}

XmlNode* createXmlElement(char* tagName)
{
    XmlNode* element = (XmlNode*)malloc(sizeof(XmlNode));
    element->tagName = tagName;
    element->content = NULL;
    element->parent = NULL;
    element->children = NULL;
    return element;
}

void addChildNode(XmlNode* parent, XmlNode* child)
{
    if (parent->children == NULL)
    {
        parent->children = child;
        child->parent = parent;
    }
    else
    {
        XmlNode* current = parent->children;
        while (current->children != NULL)
        {
            current = current->children;
        }
        current->children = child;
        child->parent = current;
    }
}

void freeXmlNode(XmlNode* node)
{
    if (node->children != NULL)
    {
        freeXmlNode(node->children);
    }
    if (node->parent != NULL && node->parent->children == node)
    {
        node->parent->children = NULL;
    }
    if (node->tagName != NULL)
    {
        free(node->tagName);
    }
    if (node->content != NULL)
    {
        free(node->content);
    }
    free(node);
}

void printXmlNode(XmlNode* node)
{
    if (node != NULL)
    {
        printf("<%s>", node->tagName);
        if (node->content != NULL)
        {
            printf("%s", node->content);
        }
        printf("\n");
        if (node->children != NULL)
        {
            printXmlNode(node->children);
        }
        printf("</%s>\n", node->tagName);
        if (node->parent == NULL)
        {
            printf("\n");
        }
        if (node->children != NULL && node->children->children != NULL)
        {
            printXmlNode(node->children->children);
        }
    }
}