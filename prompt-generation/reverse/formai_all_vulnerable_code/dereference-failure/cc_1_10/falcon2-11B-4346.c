//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

typedef struct node_t {
    char *name;
    struct node_t *next;
    struct node_t *parent;
    struct node_t *children;
} node_t;

typedef struct {
    node_t *start;
    node_t *current;
    node_t *root;
    bool in_element;
} parser_t;

parser_t *create_parser() {
    parser_t *parser = (parser_t*)malloc(sizeof(parser_t));
    parser->start = NULL;
    parser->current = NULL;
    parser->root = NULL;
    parser->in_element = FALSE;
    return parser;
}

void free_parser(parser_t *parser) {
    if (parser == NULL)
        return;
    node_t *cur;
    node_t *next;
    while (parser->start!= NULL) {
        cur = parser->start;
        while (cur->next!= NULL) {
            next = cur->next;
            free(cur->name);
            free(cur);
            cur = next;
        }
        free(parser->start);
        parser->start = NULL;
        parser->current = NULL;
        parser->root = NULL;
        parser->in_element = FALSE;
    }
    free(parser);
}

bool xml_parse_element(node_t *cur, char *data) {
    char *s;
    char *end;
    s = data;
    while ((end = strchr(s, '>'))!= NULL) {
        *end = '\0';
        if (cur->children == NULL) {
            cur->children = (node_t*)malloc(sizeof(node_t));
            cur = cur->children;
        } else {
            node_t *next = cur->children;
            while (next->next!= NULL)
                next = next->next;
            next->next = (node_t*)malloc(sizeof(node_t));
            next = next->next;
            cur = cur->children;
            cur = cur->next;
        }
        cur->name = strndup(s, end - s);
        s = end + 1;
        end = strchr(s, '>');
    }
    if (end == NULL)
        return FALSE;
    *end = '\0';
    cur->name = strndup(s, end - s);
    return TRUE;
}

bool xml_parse(parser_t *parser, char *data) {
    node_t *cur;
    char *s;
    s = data;
    while (*s!= '\0') {
        if (*s == '<' && isalpha(*(s + 1))) {
            cur = (node_t*)malloc(sizeof(node_t));
            cur->name = strndup(s, *(s + 1) == '/'? s + 2 : s + 3);
            cur->next = NULL;
            cur->parent = parser->current;
            if (parser->root == NULL)
                parser->root = cur;
            else
                parser->current->next = cur;
            parser->current = cur;
            parser->in_element = TRUE;
        } else if (*s == '/' && parser->in_element == TRUE) {
            parser->in_element = FALSE;
        }
        s++;
    }
    if (parser->in_element == TRUE) {
        if (xml_parse_element(parser->current, data + *(s - 1) + 1) == FALSE) {
            parser->current->name = strdup("Error parsing element.");
            return FALSE;
        }
    }
    return TRUE;
}

int main(int argc, char *argv[]) {
    char *xml_file = "example.xml";
    parser_t *parser = create_parser();
    FILE *f = fopen(xml_file, "r");
    if (f == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), f)!= NULL)
        if (xml_parse(parser, buffer) == FALSE)
            break;
    free_parser(parser);
    fclose(f);
    return 0;
}