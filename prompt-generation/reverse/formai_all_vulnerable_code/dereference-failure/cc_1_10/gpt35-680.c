//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUF_LEN 1024

typedef struct {
    char* data;
    int len;
} str_t;

void trim(str_t* s) {
    int i, j;
    for (i = 0; isspace(s->data[i]); i++);
    for (j = s->len - 1; isspace(s->data[j]); j--);
    s->data[j + 1] = '\0';
    s->data += i;
    s->len = j - i + 1;
}

typedef struct xml_node_s xml_node_t;
typedef struct xml_attribute_s xml_attribute_t;

struct xml_node_s {
    char* name;
    char* content;
    xml_node_t* first_child;
    xml_node_t* last_child;
    xml_attribute_t* first_attribute;
    xml_attribute_t* last_attribute;
    xml_node_t* next;
};

struct xml_attribute_s {
    char* name;
    char* value;
    xml_attribute_t* next;
};

xml_node_t* parse_xml(const char* filename);
xml_node_t* parse_node(FILE* fp, char* buf);
xml_attribute_t* parse_attribute(FILE* fp, char* buf);
void free_node(xml_node_t* node);

xml_node_t* parse_xml(const char* filename) {
    FILE* fp;
    char buf[MAX_BUF_LEN];
    xml_node_t* root = NULL;
    xml_node_t** stack = malloc(sizeof(xml_node_t*));
    int i, depth = 0, max_depth = 0;
    fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }
    while (fgets(buf, MAX_BUF_LEN, fp)) {
        for (i = 0; buf[i] && isspace(buf[i]); i++);
        if (buf[i] != '<') {
            if (root && root->last_child && root->last_child->content) {
                str_t s = { root->last_child->content, strlen(root->last_child->content) };
                trim(&s);
            }
            continue;
        }
        if (buf[i + 1] == '/') {
            if (--depth < 0) {
                printf("Error: syntax error\n");
                exit(1);
            }
            while (stack[depth + 1]->first_child != NULL) {
                xml_node_t* child = stack[depth + 1]->first_child;
                stack[depth + 1]->first_child = child->next;
                if (stack[depth]->last_child)
                    stack[depth]->last_child->next = child;
                else
                    stack[depth]->first_child = child;
                stack[depth]->last_child = child;
                child->next = NULL;
            }
            free_node(stack[depth + 1]);
            continue;
        }
        stack = realloc(stack, (depth + 2) * sizeof(xml_node_t*));
        if (++depth > max_depth) {
            max_depth = depth;
        }
        stack[depth] = parse_node(fp, buf + i);
        if (root == NULL) {
            root = stack[1];
        }
        if (stack[depth - 1]->last_child) {
            stack[depth - 1]->last_child->next = stack[depth];
        } else {
            stack[depth - 1]->first_child = stack[depth];
        }
        stack[depth - 1]->last_child = stack[depth];
    }
    free(stack);
    if (depth != 0) {
        printf("Error: syntax error\n");
        exit(1);
    }
    fclose(fp);
    return root;
}

xml_node_t* parse_node(FILE* fp, char* buf) {
    char* p = buf;
    xml_node_t* node = malloc(sizeof(xml_node_t));
    node->first_child = node->last_child = NULL;
    node->first_attribute = node->last_attribute = NULL;
    node->next = NULL;
    while (*p && !isspace(*p) && (*p != '>')) p++;
    *p = '\0';
    node->name = strdup(buf);
    buf = p + 1;
    while (*buf) {
        while (*buf && isspace(*buf)) buf++;
        if (*buf == '>') break;
        node->first_attribute = parse_attribute(fp, buf);
        if (node->last_attribute == NULL) {
            node->last_attribute = node->first_attribute;
        } else {
            node->last_attribute->next = node->first_attribute;
            node->last_attribute = node->first_attribute;
        }
    }
    if (*buf) {
        *buf = '\0';
        buf++;
        if (*buf) {
            node->content = strdup(buf);
            trim(&(str_t){ node->content, strlen(node->content) });
        }
    }
    return node;
}

xml_attribute_t* parse_attribute(FILE* fp, char* buf) {
    char* p = buf;
    xml_attribute_t* attribute = malloc(sizeof(xml_attribute_t));
    attribute->next = NULL;
    while (*p && !isspace(*p) && (*p != '=')) p++;
    *p++ = '\0';
    attribute->name = strdup(buf);
    while (*p && isspace(*p)) p++;
    if (*p++ != '=') {
        printf("Error: syntax error\n");
        exit(1);
    }
    while (*p && isspace(*p)) p++;
    if (*p == '\"' || *p == '\'') {
        char quote = *p++;
        char* q = strchr(p, quote);
        if (q == NULL) {
            printf("Error: syntax error\n");
            exit(1);
        }
        *q = '\0';
        attribute->value = strdup(p);
        *q = quote;
        p = q + 1;
    } else {
        attribute->value = strdup(p);
        while (*p && !isspace(*p)) p++;
        *p = '\0';
    }
    return attribute;
}

void free_node(xml_node_t* node) {
    xml_node_t* child;
    xml_attribute_t* attribute;
    free(node->name);
    free(node->content);
    while (node->first_attribute) {
        attribute = node->first_attribute;
        node->first_attribute = attribute->next;
        free(attribute->name);
        free(attribute->value);
        free(attribute);
    }
    while (node->first_child) {
        child = node->first_child;
        node->first_child = child->next;
        free_node(child);
    }
    free(node);
}

int main() {
    xml_node_t* root = parse_xml("test.xml");
    return 0;
}