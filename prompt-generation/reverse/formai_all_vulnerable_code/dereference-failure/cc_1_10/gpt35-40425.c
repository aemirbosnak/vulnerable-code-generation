//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 10
#define MAX_TAG_LEN 20
#define MAX_ATTR_LEN 20
#define MAX_ATTR_VAL_LEN 50
#define MAX_VALUE_LEN 50

typedef struct {
    char tag[MAX_TAG_LEN];
    char attr[MAX_ATTR_LEN][MAX_ATTR_VAL_LEN];
    char value[MAX_VALUE_LEN];
} Tag;

typedef struct {
    Tag *tags[MAX_DEPTH];
    int top;
} Stack;

void push(Stack *stack, Tag *tag) {
    if (stack->top < MAX_DEPTH) {
        stack->tags[stack->top++] = tag;
    } else {
        printf("Error: Stack overflow\n");
    }
}

Tag *pop(Stack *stack) {
    if (stack->top > 0) {
        return stack->tags[--stack->top];
    } else {
        printf("Error: Stack underflow\n");
        return NULL;
    }
}

void parse(const char *xml) {
    Stack stack = { .top = 0 };
    int i = 0;

    while (xml[i] != '\0') {
        if (xml[i] == '<') {
            i++;
            if (xml[i] == '/') {
                pop(&stack);
                i += strlen(stack.tags[stack.top-1]->tag) + 2;
            } else {
                Tag *tag = malloc(sizeof(Tag));
                int j = 0;

                while (xml[i] != '>') {
                    if (xml[i] == ' ') {
                        j++;
                        i++;
                    }

                    if (j == 0) {
                        tag->tag[strlen(tag->tag)] = xml[i];
                    } else {
                        int k = 0;
                        char attr[MAX_ATTR_VAL_LEN] = "";

                        while (xml[i] != ' ' && xml[i] != '=') {
                            attr[k++] = xml[i++];
                        }

                        i++;

                        if (xml[i] == '\"') {
                            i++;
                            k = 0;

                            while (xml[i] != '\"') {
                                tag->attr[j-1][k++] = xml[i++];
                            }

                            i++;
                        }

                        strcat(tag->attr[j-1], "=");
                        strcat(tag->attr[j-1], attr);
                    }
                }

                push(&stack, tag);
                i++;
            }
        } else if (xml[i] != '\n') {
            int j = 0;

            while (xml[i] != '<') {
                stack.tags[stack.top-1]->value[j++] = xml[i++];
            }

            stack.tags[stack.top-1]->value[j] = '\0';
        } else {
            i++;
        }
    }

    for (i = 0; i < stack.top; i++) {
        printf("Tag: %s\n", stack.tags[i]->tag);
        for (int j = 0; j < MAX_ATTR_LEN; j++) {
            if (strlen(stack.tags[i]->attr[j]) > 0) {
                printf("Attribute: %s\n", stack.tags[i]->attr[j]);
            }
        }
        printf("Value: %s\n", stack.tags[i]->value);
    }
}

int main() {
    const char *xml = "<bookstore>\n"
                      "<book category=\"cooking\">\n"
                      "  <title lang=\"en\">Everyday Italian</title>\n"
                      "  <author>Giada De Laurentiis</author>\n"
                      "  <year>2005</year>\n"
                      "  <price>30.00</price>\n"
                      "</book>\n"
                      "<book category=\"children\">\n"
                      "  <title lang=\"en\">Harry Potter</title>\n"
                      "  <author>J.K. Rowling</author>\n"
                      "  <year>2005</year>\n"
                      "  <price>29.99</price>\n"
                      "</book>\n"
                      "</bookstore>";

    parse(xml);

    return 0;
}