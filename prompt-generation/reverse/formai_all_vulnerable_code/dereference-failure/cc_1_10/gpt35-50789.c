//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

typedef enum {
    JSON_NULL,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} json_value_type;

typedef struct {
    json_value_type type;
    union {
        double number;
        char *string;
        struct {
            struct json_node_t *head;
            struct json_node_t *tail;
        } array;
        struct {
            struct json_member_t *head;
            struct json_member_t *tail;
        } object;
    } value;
} json_value_t;

typedef struct json_node_t {
    json_value_t value;
    struct json_node_t *next;
} json_node_t;

typedef struct {
    char *key;
    int key_len;
    json_value_t value;
    struct json_member_t *next;
} json_member_t;

char *json_str;
char *pos;

json_value_t json_parse_value();

void skip_space() {
    while (*pos == ' ' || *pos == '\n' || *pos == '\r' || *pos == '\t') {
        pos++;
    }
}

void next_expect(char c) {
    skip_space();
    if (*pos != c) {
        printf("Expecting '%c' but found '%c'\n", c, *pos);
        exit(1);
    }
    pos++;
}

void parse_error(char *msg) {
    printf("Error: %s\n", msg);
    exit(1);
}

void parse_number(json_value_t *value) {
    char *start = pos;
    if (*pos == '-') {
        pos++;
    }
    if (*pos == '0') {
        pos++;
    } else if (*pos >= '1' && *pos <= '9') {
        pos++;
        while (*pos >= '0' && *pos <= '9') {
            pos++;
        }
    } else {
        parse_error("Invalid number format");
    }
    if (*pos == '.') {
        pos++;
        if (*pos >= '0' && *pos <= '9') {
            pos++;
            while (*pos >= '0' && *pos <= '9') {
                pos++;
            }
        } else {
            parse_error("Invalid number format");
        }
    }
    if (*pos == 'e' || *pos == 'E') {
        pos++;
        if (*pos == '+' || *pos == '-') {
            pos++;
        }
        if (*pos >= '0' && *pos <= '9') {
            pos++;
            while (*pos >= '0' && *pos <= '9') {
                pos++;
            }
        } else {
            parse_error("Invalid number format");
        }
    }
    double number = atof(start);
    value->type = JSON_NUMBER;
    value->value.number = number;
}

void parse_string(json_value_t *value) {
    char *start = ++pos;
    char *cur = pos;
    while (*cur != '\"' && *cur != '\0') {
        if (*cur == '\\') {
            cur++;
        }
        cur++;
    }
    if (*cur == '\0') {
        parse_error("Expecting '\"' but found EOF");
    }
    int len = cur - start;
    value->type = JSON_STRING;
    value->value.string = (char *) malloc(len);
    memcpy(value->value.string, start, len);
    value->value.string[len] = '\0';
    pos = cur + 1;
}

void parse_array(json_value_t *value) {
    pos++;
    json_node_t *head = NULL;
    json_node_t *tail = NULL;
    while (*pos != ']') {
        json_node_t *node = (json_node_t *) malloc(sizeof(json_node_t));
        node->value = json_parse_value();
        node->next = NULL;
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        skip_space();
        if (*pos == ',') {
            pos++;
        } else if (*pos != ']') {
            parse_error("Invalid syntax");
        }
    }
    pos++;
    value->type = JSON_ARRAY;
    value->value.array.head = head;
    value->value.array.tail = tail;
}

void parse_object(json_value_t *value) {
    pos++;
    json_member_t *head = NULL;
    json_member_t *tail = NULL;
    while (*pos != '}') {
        char *key;
        int key_len;
        json_value_t key_value;
        skip_space();
        if (*pos != '\"') {
            parse_error("Expecting '\"'");
        }
        key = ++pos;
        while (*pos != '\"' && *pos != '\0') {
            if (*pos == '\\') {
                pos++;
            }
            pos++;
        }
        if (*pos == '\0') {
            parse_error("Expecting '\"' but found EOF");
        }
        key_len = pos - key;
        key_value.type = JSON_STRING;
        key_value.value.string = (char *) malloc(key_len);
        memcpy(key_value.value.string, key, key_len);
        key_value.value.string[key_len] = '\0';
        pos++;
        next_expect(':');
        json_value_t value_value = json_parse_value();
        json_member_t *member = (json_member_t *) malloc(sizeof(json_member_t));
        member->key = key_value.value.string;
        member->key_len = key_len;
        member->value = value_value;
        member->next = NULL;
        if (head == NULL) {
            head = member;
            tail = member;
        } else {
            tail->next = member;
            tail = member;
        }
        skip_space();
        if (*pos == ',') {
            pos++;
        } else if (*pos != '}') {
            parse_error("Invalid syntax");
        }
    }
    pos++;
    value->type = JSON_OBJECT;
    value->value.object.head = head;
    value->value.object.tail = tail;
}

json_value_t json_parse_value() {
    skip_space();
    switch (*pos) {
        case 'n':
            if (strncmp(pos, "null", 4) == 0) {
                pos += 4;
                return (json_value_t) {JSON_NULL, {0}};
            } else {
                parse_error("Invalid syntax");
            }
            break;
        case 't':
            if (strncmp(pos, "true", 4) == 0) {
                pos += 4;
                return (json_value_t) {JSON_TRUE, {1}};
            } else {
                parse_error("Invalid syntax");
            }
            break;
        case 'f':
            if (strncmp(pos, "false", 5) == 0) {
                pos += 5;
                return (json_value_t) {JSON_FALSE, {0}};
            } else {
                parse_error("Invalid syntax");
            }
            break;
        case '\"':
            {
                json_value_t value;
                parse_string(&value);
                return value;
            }
        case '[':
            {
                json_value_t value;
                parse_array(&value);
                return value;
            }
        case '{':
            {
                json_value_t value;
                parse_object(&value);
                return value;
            }
        case '-':
        case '0' ... '9':
            {
                json_value_t value;
                parse_number(&value);
                return value;
            }
        default:
            parse_error("Invalid syntax");
    }
}

json_value_t json_parse(char *str) {
    json_str = str;
    pos = json_str;
    return json_parse_value();
}

int main() {
    char str[MAX_LENGTH] = "{\"a\":\"foo\",\"b\":42.123,\"c\":{\"d\":[1,2,3],\"e\":false}}";
    json_value_t value = json_parse(str);
    printf("Type: %d\n", value.type);
    switch (value.type) {
        case JSON_NULL:
            printf("NULL\n");
            break;
        case JSON_TRUE:
            printf("TRUE\n");
            break;
        case JSON_FALSE:
            printf("FALSE\n");
            break;
        case JSON_NUMBER:
            printf("NUMBER: %f\n", value.value.number);
            break;
        case JSON_STRING:
            printf("STRING: %s\n", value.value.string);
            break;
        case JSON_ARRAY:
            {
                printf("ARRAY:\n");
                json_node_t *p = value.value.array.head;
                while (p != NULL) {
                    printf("  - ");
                    switch (p->value.type) {
                        case JSON_NULL:
                            printf("NULL\n");
                            break;
                        case JSON_TRUE:
                            printf("TRUE\n");
                            break;
                        case JSON_FALSE:
                            printf("FALSE\n");
                            break;
                        case JSON_NUMBER:
                            printf("NUMBER: %f\n", p->value.value.number);
                            break;
                        case JSON_STRING:
                            printf("STRING: %s\n", p->value.value.string);
                            break;
                        case JSON_ARRAY:
                            printf("ARRAY (length %d):\n", 0);
                            break;
                        case JSON_OBJECT:
                            printf("OBJECT (keys %d):\n", 0);
                            break;
                    }
                    p = p->next;
                }
            }
            break;
        case JSON_OBJECT:
            {
                printf("OBJECT:\n");
                json_member_t *p = value.value.object.head;
                while (p != NULL) {
                    printf("  %.*s: ", p->key_len, p->key);
                    switch (p->value.type) {
                        case JSON_NULL:
                            printf("NULL\n");
                            break;
                        case JSON_TRUE:
                            printf("TRUE\n");
                            break;
                        case JSON_FALSE:
                            printf("FALSE\n");
                            break;
                        case JSON_NUMBER:
                            printf("NUMBER: %f\n", p->value.value.number);
                            break;
                        case JSON_STRING:
                            printf("STRING: %s\n", p->value.value.string);
                            break;
                        case JSON_ARRAY:
                            printf("ARRAY (length %d):\n", 0);
                            break;
                        case JSON_OBJECT:
                            printf("OBJECT (keys %d):\n", 0);
                            break;
                    }
                    p = p->next;
                }
            }
            break;
    }
    return 0;
}