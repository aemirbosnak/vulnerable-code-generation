//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} json_type;

typedef union {
    char *str;
    double num;
} json_value;

typedef struct json_node {
    json_type type;
    json_value value;
    int size;
    struct json_node **children;
} json_node;

void printJson(json_node *node, int indent) {
    switch(node->type) {
        case JSON_OBJECT:
            printf("{\n");
            for(int i = 0; i < node->size; i++) {
                printf("%*s\"%s\": ", indent, "", node->children[i]->value.str);
                printJson(node->children[i+1], indent+2);
                if(i < node->size-1) printf(",\n");
            }
            printf("\n%*s}", indent-2, "");
            break;
        case JSON_ARRAY:
            printf("[\n");
            for(int i = 0; i < node->size; i++) {
                printJson(node->children[i], indent+2);
                if(i < node->size-1) printf(",\n");
            }
            printf("\n%*s]", indent-2, "");
            break;
        case JSON_STRING:
            printf("\"%s\"", node->value.str);
            break;
        case JSON_NUMBER:
            printf("%f", node->value.num);
            break;
        case JSON_TRUE:
            printf("true");
            break;
        case JSON_FALSE:
            printf("false");
            break;
        case JSON_NULL:
            printf("null");
            break;
    }
}

void freeJson(json_node *node) {
    switch(node->type) {
        case JSON_OBJECT:
        case JSON_ARRAY:
            for(int i = 0; i < node->size; i++) {
                freeJson(node->children[i]);
            }
            free(node->children);
            break;
        case JSON_STRING:
            free(node->value.str);
            break;
    }
    free(node);
}

int main() {
    char json[] = "{\"name\": \"John Smith\", \"age\": 30, \"pets\": [\"cat\", \"dog\", \"fish\"]}";

    json_node *root = malloc(sizeof(json_node));
    root->type = JSON_OBJECT;
    root->size = 3;
    root->children = malloc(sizeof(json_node*)*6);

    char *name = malloc(sizeof(char)*11);
    strcpy(name, "name");
    root->children[0] = malloc(sizeof(json_node));
    root->children[0]->type = JSON_STRING;
    root->children[0]->value.str = name;
    root->children[1] = malloc(sizeof(json_node));
    root->children[1]->type = JSON_STRING;
    root->children[1]->value.str = "John Smith";

    char *age = malloc(sizeof(char)*4);
    strcpy(age, "age");
    root->children[2] = malloc(sizeof(json_node));
    root->children[2]->type = JSON_NUMBER;
    root->children[2]->value.num = 30;

    root->children[3] = malloc(sizeof(json_node));
    root->children[3]->type = JSON_STRING;
    root->children[3]->value.str = "pets";

    root->children[4] = malloc(sizeof(json_node));
    root->children[4]->type = JSON_ARRAY;
    root->children[4]->size = 3;
    root->children[4]->children = malloc(sizeof(json_node*)*3);

    root->children[5] = NULL;

    json_node *cat = malloc(sizeof(json_node));
    cat->type = JSON_STRING;
    cat->value.str = "cat";
    root->children[4]->children[0] = cat;

    json_node *dog = malloc(sizeof(json_node));
    dog->type = JSON_STRING;
    dog->value.str = "dog";
    root->children[4]->children[1] = dog;

    json_node *fish = malloc(sizeof(json_node));
    fish->type = JSON_STRING;
    fish->value.str = "fish";
    root->children[4]->children[2] = fish;

    printJson(root, 0);
    printf("\n");

    freeJson(root);

    return 0;
}