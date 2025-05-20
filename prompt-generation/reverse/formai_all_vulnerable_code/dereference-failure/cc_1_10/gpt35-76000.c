//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    char *name;
    char *content;
} XmlElement;

typedef struct XmlElementNode {
    XmlElement *element;
    struct XmlElementNode *next;
} XmlElementNode;

typedef struct {
    XmlElementNode *head;
    XmlElementNode *tail;
    int size;
} XmlElementList;

XmlElement *createXmlElement(char *name, char *content) {
    XmlElement *element = (XmlElement *) malloc(sizeof(XmlElement));
    element->name = strdup(name);
    element->content = strdup(content);
    return element;
}

void freeXmlElement(XmlElement *element) {
    free(element->name);
    free(element->content);
    free(element);
}

XmlElementNode *createXmlElementNode(XmlElement *element) {
    XmlElementNode *node = (XmlElementNode *) malloc(sizeof(XmlElementNode));
    node->element = element;
    node->next = NULL;
    return node;
}

void freeXmlElementNode(XmlElementNode *node) {
    freeXmlElement(node->element);
    free(node);
}

XmlElementList *createXmlElementList() {
    XmlElementList *list = (XmlElementList *) malloc(sizeof(XmlElementList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void freeXmlElementList(XmlElementList *list) {
    XmlElementNode *node = list->head;
    while (node != NULL) {
        XmlElementNode *temp = node;
        node = node->next;
        freeXmlElementNode(temp);
    }
    free(list);
}

void addXmlElement(XmlElementList *list, XmlElement *element) {
    XmlElementNode *node = createXmlElementNode(element);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void printXmlElement(XmlElement *element) {
    printf("<%s>%s</%s>\n", element->name, element->content, element->name);
}

void printXmlElementList(XmlElementList *list) {
    XmlElementNode *node = list->head;
    while (node != NULL) {
        printXmlElement(node->element);
        node = node->next;
    }
}

void parseXmlElement(XmlElementList *list, char *xml) {
    char *token = strtok(xml, "<>");
    char *name = NULL;
    char *content = NULL;

    while (token != NULL) {
        if (token[0] == '/') {
            free(name);
            free(content);
        } else if (token[0] == '?') {
            // Do nothing, ignore XML declaration
        } else if (name == NULL) {
            name = strdup(token);
        } else {
            content = strdup(token);
            XmlElement *element = createXmlElement(name, content);
            addXmlElement(list, element);
        }
        token = strtok(NULL, "<>");
    }
}

int main() {
    char xml[MAX_SIZE] = "<root><name>John</name><age>25</age></root>";
    XmlElementList *list = createXmlElementList();

    parseXmlElement(list, xml);
    printXmlElementList(list);

    freeXmlElementList(list);

    return 0;
}