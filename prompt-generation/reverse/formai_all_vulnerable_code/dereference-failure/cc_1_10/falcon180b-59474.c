//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* name;
    char* value;
    struct tag_t* child;
    struct tag_t* next;
} tag_t;

tag_t* new_tag(char* name, char* value) {
    tag_t* tag = (tag_t*)malloc(sizeof(tag_t));
    tag->name = strdup(name);
    tag->value = strdup(value);
    tag->child = NULL;
    tag->next = NULL;
    return tag;
}

void add_child(tag_t* parent, tag_t* child) {
    child->next = parent->child;
    parent->child = child;
}

tag_t* get_tag(tag_t* root, char* path) {
    char* token = strtok(path, "/");
    tag_t* tag = root;
    while (token!= NULL) {
        tag_t* child = tag->child;
        while (child!= NULL) {
            if (strcmp(child->name, token) == 0) {
                tag = child;
                break;
            }
            child = child->next;
        }
        if (child == NULL) {
            return NULL;
        }
        token = strtok(NULL, "/");
    }
    return tag;
}

void print_tag(tag_t* tag, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s=%s\n", tag->name, tag->value);
    tag_t* child = tag->child;
    while (child!= NULL) {
        print_tag(child, depth + 1);
        child = child->next;
    }
}

int main() {
    char xml[] = "<root><person name=\"John\"><age>30</age></person><person name=\"Jane\"><age>25</age></person></root>";
    tag_t* root = new_tag("root", "");
    char* token = strtok(xml, "<");
    while (token!= NULL) {
        if (strcmp(token, "/") == 0) {
            token = strtok(NULL, "<");
            continue;
        }
        char* name = strtok(NULL, " ");
        char* value = strtok(NULL, ">");
        tag_t* tag = new_tag(name, value);
        add_child(root, tag);
        token = strtok(NULL, "<");
    }
    tag_t* person = get_tag(root, "/root/person[age=25]");
    if (person!= NULL) {
        print_tag(person, 0);
    } else {
        printf("Tag not found.\n");
    }
    return 0;
}