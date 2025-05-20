//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *tag;
    char *value;
} Element;

typedef struct {
    Element *elements;
    int num_elements;
} Document;

int search_element(char *tag, Element *elements, int num_elements) {
    int i;
    for(i = 0; i < num_elements; i++) {
        if(strcmp(tag, elements[i].tag) == 0) {
            return i;
        }
    }
    return -1;
}

Document* parse(char *xml) {
    int i, j, len;
    char *token;
    Element element;
    Document *doc = malloc(sizeof(Document));
    doc->elements = malloc(sizeof(Element) * 10);
    doc->num_elements = 0;

    token = strtok(xml, "<>");
    while(token != NULL) {
        len = strlen(token);
        if(len > 0 && token[0] == '/') {
            doc->num_elements--;
        } else if(len > 0) {
            element.tag = token;
            element.value = strtok(NULL, "<>");
            if(search_element(element.tag, doc->elements, doc->num_elements) == -1) {
                if(doc->num_elements % 10 == 0) {
                    doc->elements = realloc(doc->elements, (doc->num_elements + 10) * sizeof(Element));
                }
                doc->elements[doc->num_elements++] = element;
            }
        }
        token = strtok(NULL, "<>");
    }
    return doc;
}

int main() {
    char xml[] = "<person><name>John</name><age>25</age></person>";
    int i;
    Document *doc = parse(xml);
    for(i = 0; i < doc->num_elements; i++) {
        printf("%s: %s\n", doc->elements[i].tag, doc->elements[i].value);
    }
    free(doc->elements);
    free(doc);
    return 0;
}