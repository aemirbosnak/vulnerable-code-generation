//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_OBJ_MAX_DEPTH 64
#define JSON_TOKEN_MAX_LEN 128

typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} json_type_t;

typedef struct json_token json_token_t;
struct json_token {
    char *str;
    json_type_t type;
};

typedef struct json_node json_node_t;
struct json_node {
    json_token_t key;
    json_token_t value;
    json_node_t *child;
    int child_count;
};

void parse_object(char *json_str, json_node_t *parent, int depth);
void parse_array(char *json_str, json_node_t *parent, int depth);

json_node_t *parse_json(char *json_str) {
    json_node_t *root = (json_node_t *) malloc(sizeof(json_node_t));
    root->key.str = NULL;
    root->key.type = JSON_NULL;
    root->value.str = NULL;
    root->value.type = JSON_NULL;
    root->child_count = 0;
    parse_object(json_str, root, 0);
    return root;
}

void parse_object(char *json_str, json_node_t *parent, int depth) {
    if (depth > JSON_OBJ_MAX_DEPTH) {
        printf("Error: Maximum object depth exceeded.\n");
        exit(1);
    }
    if (json_str[0] != '{' || json_str[strlen(json_str)-1] != '}') {
        printf("Error: Invalid object format.\n");
        exit(1);
    }
    json_str++;
    char *key_start = json_str, *key_end, *colon, *value_start;
    json_node_t *new_node;
    while (*json_str != '}') {
        if (parent->child_count != 0) {
            if (*json_str++ != ',') {
                printf("Error: Invalid object format.\n");
                exit(1);
            }
        }
        key_start = json_str;
        while (*json_str++ != ':');
        key_end = json_str-2;
        colon = json_str-1;
        value_start = json_str;
        new_node = (json_node_t *) malloc(sizeof(json_node_t));
        new_node->key.str = (char *) malloc(JSON_TOKEN_MAX_LEN*sizeof(char));
        strncpy(new_node->key.str, key_start, key_end-key_start+1);
        new_node->key.str[key_end-key_start+1] = '\0';
        new_node->key.type = JSON_STRING;
        switch (*value_start) {
            case '{':
                new_node->child = (json_node_t *) malloc(sizeof(json_node_t));
                new_node->child_count = 1;
                parse_object(value_start, new_node->child, depth+1);
                new_node->value.str = NULL;
                new_node->value.type = JSON_OBJECT;
                break;
            case '[':
                new_node->child = (json_node_t *) malloc(sizeof(json_node_t));
                new_node->child_count = 1;
                parse_array(value_start, new_node->child, depth+1);
                new_node->value.str = NULL;
                new_node->value.type = JSON_ARRAY;
                break;
            case 't':
            case 'f':
                new_node->value.str = (char *) malloc(JSON_TOKEN_MAX_LEN*sizeof(char));
                strncpy(new_node->value.str, value_start, 4);
                new_node->value.str[4] = '\0';
                new_node->value.type = JSON_BOOLEAN;
                break;
            case 'n':
                new_node->value.str = NULL;
                new_node->value.type = JSON_NULL;
                break;
            case '"':
                new_node->value.str = (char *) malloc(JSON_TOKEN_MAX_LEN*sizeof(char));
                char *str_end = strchr(value_start+1, '"');
                strncpy(new_node->value.str, value_start+1, str_end-value_start-1);
                new_node->value.str[str_end-value_start-1] = '\0';
                new_node->value.type = JSON_STRING;
                json_str = str_end+1;
                break;
            default:
                new_node->value.str = (char *) malloc(JSON_TOKEN_MAX_LEN*sizeof(char));
                char *num_end = value_start+1;
                while (*num_end >= '0' && *num_end <= '9') {
                    num_end++;
                }
                strncpy(new_node->value.str, value_start, num_end-value_start);
                new_node->value.str[num_end-value_start] = '\0';
                new_node->value.type = JSON_NUMBER;
                json_str = num_end-1;
        }
        parent->child_count++;
        parent->child = (json_node_t *) realloc(parent->child, parent->child_count*sizeof(json_node_t));
        memcpy(&(parent->child[parent->child_count-1]), new_node, sizeof(json_node_t));
        free(new_node);
    }
}

void parse_array(char *json_str, json_node_t *parent, int depth) {
    if (depth > JSON_OBJ_MAX_DEPTH) {
        printf("Error: Maximum object depth exceeded.\n");
        exit(1);
    }
    if (json_str[0] != '[' || json_str[strlen(json_str)-1] != ']') {
        printf("Error: Invalid array format.\n");
        exit(1);
    }
    json_str++;
    char *elem_start = json_str;
    json_node_t *new_node;
    while (*json_str != ']') {
        if (parent->child_count != 0) {
            if (*json_str++ != ',') {
                printf("Error: Invalid array format.\n");
                exit(1);
            }
        }
        elem_start = json_str;
        switch (*json_str) {
            case '{':
                new_node = (json_node_t *) malloc(sizeof(json_node_t));
                new_node->child = (json_node_t *) malloc(sizeof(json_node_t));
                new_node->child_count = 1;
                parse_object(json_str, new_node->child, depth+1);
                new_node->key.str = NULL;
                new_node->key.type = JSON_NULL;
                new_node->value.str = NULL;
                new_node->value.type = JSON_OBJECT;
                break;
            case '[':
                new_node = (json_node_t *) malloc(sizeof(json_node_t));
                new_node->child = (json_node_t *) malloc(sizeof(json_node_t));
                new_node->child_count = 1;
                parse_array(json_str, new_node->child, depth+1);
                new_node->key.str = NULL;
                new_node->key.type = JSON_NULL;
                new_node->value.str = NULL;
                new_node->value.type = JSON_ARRAY;
                break;
            case 't':
            case 'f':
                new_node = (json_node_t *) malloc(sizeof(json_node_t));
                new_node->key.str = NULL;
                new_node->key.type = JSON_NULL;
                new_node->value.str = (char *) malloc(JSON_TOKEN_MAX_LEN*sizeof(char));
                strncpy(new_node->value.str, elem_start, 4);
                new_node->value.str[4] = '\0';
                new_node->value.type = JSON_BOOLEAN;
                break;
            case 'n':
                new_node = (json_node_t *) malloc(sizeof(json_node_t));
                new_node->key.str = NULL;
                new_node->key.type = JSON_NULL;
                new_node->value.str = NULL;
                new_node->value.type = JSON_NULL;
                break;
            case '"':
                new_node = (json_node_t *) malloc(sizeof(json_node_t));
                new_node->key.str = NULL;
                new_node->key.type = JSON_NULL;
                new_node->value.str = (char *) malloc(JSON_TOKEN_MAX_LEN*sizeof(char));
                char *str_end = strchr(elem_start+1, '"');
                strncpy(new_node->value.str, elem_start+1, str_end-elem_start-1);
                new_node->value.str[str_end-elem_start-1] = '\0';
                new_node->value.type = JSON_STRING;
                json_str = str_end+1;
                break;
            default:
                new_node = (json_node_t *) malloc(sizeof(json_node_t));
                new_node->key.str = NULL;
                new_node->key.type = JSON_NULL;
                new_node->value.str = (char *) malloc(JSON_TOKEN_MAX_LEN*sizeof(char));
                char *num_end = elem_start+1;
                while (*num_end >= '0' && *num_end <= '9') {
                    num_end++;
                }
                strncpy(new_node->value.str, elem_start, num_end-elem_start);
                new_node->value.str[num_end-elem_start] = '\0';
                new_node->value.type = JSON_NUMBER;
                json_str = num_end-1;
                break;
        }
        parent->child_count++;
        parent->child = (json_node_t *) realloc(parent->child, parent->child_count*sizeof(json_node_t));
        memcpy(&(parent->child[parent->child_count-1]), new_node, sizeof(json_node_t));
        free(new_node);
    }
}

int main() {
    char json[] = "{"
                  "    \"name\": \"John\", "
                  "    \"age\": 30, "
                  "    \"height\": 175.5, "
                  "    \"isMarried\": true, "
                  "    \"hobbies\": [\"reading\", \"music\", \"sports\"], "
                  "    \"address\": { "
                  "        \"street\": \"West Lane\", "
                  "        \"city\": \"New York\" "
                  "    }"
                  "}";
    json_node_t *root = parse_json(json);
    printf("Root:\n"
           "    Key: (null)\n"
           "    Value: (null)\n"
           "    Child Count: %d\n", root->child_count);
    for (int i = 0; i < root->child_count; i++) {
        printf("  Child %d:\n"
               "    Key: %s\n"
               "    Value: %s\n"
               "    Child Count: %d\n", i+1, root->child[i].key.str, root->child[i].value.str, root->child[i].child_count);
        for (int j = 0; j < root->child[i].child_count; j++) {
            printf("    Child %d:\n"
                   "      Key: %s\n"
                   "      Value: %s\n"
                   "      Child Count: %d\n", j+1, root->child[i].child[j].key.str, root->child[i].child[j].value.str, root->child[i].child[j].child_count);
        }
    }
    return 0;
}