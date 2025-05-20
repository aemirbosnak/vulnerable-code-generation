//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum json_type {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
};

struct json_value {
    enum json_type type;
    union {
        char *string;
        double number;
        struct json_value **members;
    } data;
};

char *read_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp)
        return NULL;

    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char *buffer = (char*) malloc(size+1);
    fread(buffer, size, 1, fp);
    buffer[size] = '\0';

    fclose(fp);
    return buffer;
}

void parse_whitespace(char **str) {
    while (**str == ' ' || **str == '\t' || **str == '\r' || **str == '\n')
        ++(*str);
}

struct json_value *parse_string(char **str) {
    char *ptr = ++(*str); // Skip opening "
    char *end = ptr;
    while (*end != '\0' && *end != '"') {
        if (*end == '\\' && *(end+1) == '"') {
            memcpy(ptr, end, 1);
            ++ptr; ++end;
        }
        if (*end != '\0') {
            memcpy(ptr, end, 1);
            ++ptr; ++end;
        }
    }
    ptr[-1] = '\0'; // Replace closing " with \0
    ++(*str); // Skip closing "
    struct json_value *value = malloc(sizeof(struct json_value));
    value->type = JSON_STRING;
    value->data.string = ptr - (end - ptr - 1);
    return value;
}

struct json_value *parse_number(char **str) {
    double number = strtod(*str, str);
    struct json_value *value = malloc(sizeof(struct json_value));
    value->type = JSON_NUMBER;
    value->data.number = number;
    return value;
}

struct json_value *parse_constant(char **str, const char *constant, enum json_type type) {
    int len = strlen(constant);
    if (memcmp(*str, constant, len) == 0) {
        *str += len;
        struct json_value *value = malloc(sizeof(struct json_value));
        value->type = type;
        return value;
    }
    return NULL;
}

struct json_value *parse_value(char **str);

struct json_value *parse_array(char **str) {
    ++(*str); // Skip opening [
    parse_whitespace(str);

    struct json_value **members = NULL;
    int count = 0;
    while (**str != '\0' && **str != ']') {
        struct json_value *value = parse_value(str);
        if (!value)
            return NULL;
        members = realloc(members, sizeof(struct json_value*) * ++count);
        members[count-1] = value;
        parse_whitespace(str);
        if (**str == ',') {
            ++(*str);
            parse_whitespace(str);
        }
    }
    ++(*str); // Skip closing ]
    struct json_value *value = malloc(sizeof(struct json_value));
    value->type = JSON_ARRAY;
    value->data.members = members;
    return value;
}

struct json_value *parse_object(char **str) {
    ++(*str); // Skip opening {
    parse_whitespace(str);

    struct json_value **members = NULL;
    char *key;
    int count = 0;
    while (**str != '\0' && **str != '}') {
        key = NULL;
        struct json_value *value = NULL;
        parse_whitespace(str);
        if (**str != '"')
            return NULL;
        key = (*str)++; // Skip opening "
        while (**str != '\0' && **str != '"')
            ++(*str);
        if (**str == '\0')
            return NULL;
        (*str)++; // Skip closing "
        parse_whitespace(str);
        if (**str != ':')
            return NULL;
        (*str)++; // Skip :
        parse_whitespace(str);
        value = parse_value(str);
        if (!value)
            return NULL;
        members = realloc(members, sizeof(struct json_value*) * (count+2));
        members[count] = malloc(sizeof(struct json_value));
        members[count]->type = JSON_STRING;
        members[count]->data.string = key;
        members[count+1] = value;
        count += 2;
        parse_whitespace(str);
        if (**str == ',') {
            ++(*str);
            parse_whitespace(str);
        }
    }
    ++(*str); // Skip closing }
    struct json_value *value = malloc(sizeof(struct json_value));
    value->type = JSON_OBJECT;
    value->data.members = members;
    return value;
}

struct json_value *parse_value(char **str) {
    parse_whitespace(str);
    switch (**str) {
        case 't': return parse_constant(str, "true", JSON_TRUE);
        case 'f': return parse_constant(str, "false", JSON_FALSE);
        case 'n': return parse_constant(str, "null", JSON_NULL);
        case '\"': return parse_string(str);
        case '[': return parse_array(str);
        case '{': return parse_object(str);
        default: return parse_number(str);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2)
        return 1;
    char *json_str = read_file(argv[1]);
    if (!json_str)
        return 1;
    struct json_value *json = parse_value(&json_str);
    free(json_str);
    // Do stuff with parsed JSON here...
    return 0;
}