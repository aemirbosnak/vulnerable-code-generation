//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000

typedef enum {
    JSON_INT,
    JSON_STR,
    JSON_BOOL,
    JSON_ARRAY,
    JSON_OBJECT
} json_type;

typedef struct JNode {
    json_type type;
    union {
        int int_val;
        char *str_val;
        int bool_val;
        struct JNode *array_val;
        struct JNode *object_val;
    } data;
    struct JNode *next;
    char key[50];
} JNode;

JNode *parse_value(char *str, int *i);
JNode *parse_array(char *str, int *i);
JNode *parse_object(char *str, int *i);
JNode *new_node(json_type type);
void free_node(JNode *node);

char *trim(char *str) {
    char *end;
    while (isspace(*str)) str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    *(end+1) = 0;
    return str;
}

int is_int(char *str) {
    while (*str) {
        if (*str < '0' || *str > '9') return 0;
        str++;
    }
    return 1;
}

char *get_token(char *str, int *i) {
    char *token = malloc(MAX_SIZE * sizeof(char));
    int j = 0;
    while (str[*i] != '\0' && str[*i] != '"' && str[*i] != ',' && str[*i] != ']' && str[*i] != '}') {
        token[j] = str[*i];
        j++; (*i)++;
    }
    token[j] = '\0';
    return trim(token);
}

void skip_whitespace(char *str, int *i) {
    while (isspace(str[*i])) (*i)++;
}

JNode *new_node(json_type type) {
    JNode *node = malloc(sizeof(JNode));
    node->type = type;
    node->next = NULL;
    return node;
}

void free_node(JNode *node) {
    if (node->type == JSON_STR) free(node->data.str_val);
    if (node->type == JSON_ARRAY || node->type == JSON_OBJECT) {
        JNode *temp;
        while (node->data.object_val != NULL) {
            temp = node->data.object_val->next;
            free_node(node->data.object_val);
            node->data.object_val = temp;
        }
    }
    free(node);
}

JNode *parse_value(char *str, int *i) {
    skip_whitespace(str, i);
    char *token = get_token(str, i);
    JNode *node = NULL;
    if (strcmp(token, "null") == 0) {
        node = new_node(JSON_STR);
        node->data.str_val = NULL;
    } else if (is_int(token)) {
        node = new_node(JSON_INT);
        node->data.int_val = atoi(token);
    } else if (strcmp(token, "true") == 0 || strcmp(token, "false") == 0) {
        node = new_node(JSON_BOOL);
        node->data.bool_val = (strcmp(token, "true") == 0);
    } else {
        node = new_node(JSON_STR);
        node->data.str_val = malloc(strlen(token) * sizeof(char));
        strcpy(node->data.str_val, token);
    }
    free(token);
    return node;
}

JNode *parse_array(char *str, int *i) {
    JNode *head = NULL;
    JNode *tail = NULL;
    (*i)++;
    while (str[*i] != ']') {
        skip_whitespace(str, i);
        JNode *node = parse_value(str, i);
        if (head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = tail->next;
        }
        skip_whitespace(str, i);
        if (str[*i] == ',') (*i)++;
    }
    (*i)++;
    JNode *array_node = new_node(JSON_ARRAY);
    array_node->data.array_val = head;
    return array_node;
}

JNode *parse_object(char *str, int *i) {
    JNode *head = NULL;
    JNode *tail = NULL;
    (*i)++;
    while (str[*i] != '}') {
        skip_whitespace(str, i);
        char *key = get_token(str, i);
        skip_whitespace(str, i);
        (*i)++;
        JNode *node = parse_value(str, i);
        strcpy(node->key, key);
        free(key);
        skip_whitespace(str, i);
        if (head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = tail->next;
        }
        if (str[*i] == ',') (*i)++;
    }
    (*i)++;
    JNode *node = new_node(JSON_OBJECT);
    node->data.object_val = head;
    return node;
}

void print_node(JNode *node, int depth) {
    for (int i = 0; i < depth; i++) printf("  ");
    switch (node->type) {
        case JSON_INT:
            printf("%d\n", node->data.int_val);
            break;
        case JSON_STR:
            printf("\"%s\"\n", node->data.str_val);
            break;
        case JSON_BOOL:
            printf("%s\n", node->data.bool_val ? "true" : "false");
            break;
        case JSON_ARRAY:
            printf("[\n");
            JNode *temp = node->data.array_val;
            while (temp != NULL) {
                print_node(temp, depth+1);
                temp = temp->next;
            }
            for (int i = 0; i < depth; i++) printf("  ");
            printf("]\n");
            break;
        case JSON_OBJECT:
            printf("{\n");
            JNode *temp2 = node->data.object_val;
            while (temp2 != NULL) {
                for (int i = 0; i < depth+1; i++) printf("  ");
                printf("\"%s\": ", temp2->key);
                print_node(temp2, depth+1);
                temp2 = temp2->next;
            }
            for (int i = 0; i < depth; i++) printf("  ");
            printf("}\n");
            break;
    }
}

int main() {
    char json_str[] = "{\"name\":\"John\",\"age\":30,\"movies\":[\"Jaws\",\"Star Wars\"],\"married\":true}";
    int i = 0;
    JNode *node = parse_object(json_str, &i);
    print_node(node, 0);
    free_node(node);
    return 0;
}