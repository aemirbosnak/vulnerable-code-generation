//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 4096

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_VALUE_STRING,
    JSON_VALUE_NUMBER,
    JSON_VALUE_TRUE,
    JSON_VALUE_FALSE,
    JSON_VALUE_NULL
} json_type_t;

typedef union {
    char* string;
    int integer;
    double floating_point;
    json_type_t type;
} json_value_t;

typedef struct {
    json_type_t type;
    json_value_t value;
} json_element_t;

int json_parse(char* json_data, json_element_t** ptr);

int main(int argc, char** argv) {
    char json_data[MAX_JSON_SIZE] = "{\"name\":\"John Doe\",\"age\":30,\"city\":\"New York\"}";

    json_element_t* root = NULL;
    json_parse(json_data, &root);

    if (root != NULL && root->type == JSON_OBJECT) {
        printf("JSON Object:\n");

        json_element_t* name_property = NULL;
        json_element_t* age_property = NULL;
        json_element_t* city_property = NULL;

        int property_count = 0;

        for (int i = 0; i < 3; i++) {
            json_element_t* child = (json_element_t*) root->value.string[i];

            if (strcmp(child->value.string, "name") == 0) {
                name_property = child;
                property_count++;
            } else if (strcmp(child->value.string, "age") == 0) {
                age_property = child;
                property_count++;
            } else if (strcmp(child->value.string, "city") == 0) {
                city_property = child;
                property_count++;
            }
        }

        if (property_count == 3 && name_property->type == JSON_VALUE_STRING && age_property->type == JSON_VALUE_NUMBER && city_property->type == JSON_VALUE_STRING) {
            printf("- name: %s\n", name_property->value.string);
            printf("- age: %d\n", age_property->value.integer);
            printf("- city: %s\n", city_property->value.string);
        }
    }

    return 0;
}

int json_parse(char* json_data, json_element_t** ptr) {
    if (json_data == NULL || ptr == NULL) {
        return -1;
    }

    json_element_t* root = NULL;
    char* cursor = json_data;

    if (*cursor != '{') {
        return -1;
    }

    cursor++;

    root = malloc(sizeof(json_element_t));

    root->type = JSON_OBJECT;
    root->value.type = JSON_OBJECT;

    while (*cursor != '\0') {
        if (*cursor == '"') {
            cursor++;

            int parsed_string_length = 0;
            char* parsed_string = NULL;

            while (*cursor != '\0' && *cursor != '"') {
                if (*cursor == '\\') {
                    cursor++;

                    switch (*cursor) {
                        case 'b':
                            parsed_string_length++;
                            cursor++;
                            break;
                        case 'f':
                            parsed_string_length++;
                            cursor++;
                            break;
                        case 'n':
                            parsed_string_length++;
                            cursor++;
                            break;
                        case 'r':
                            parsed_string_length++;
                            cursor++;
                            break;
                        case 't':
                            parsed_string_length++;
                            cursor++;
                            break;
                        case 'u':
                            parsed_string_length += 4;
                            cursor += 5;
                            break;
                        default:
                            return -1;
                    }
                } else {
                    parsed_string_length++;
                    cursor++;
                }
            }

            if (parsed_string_length == 0) {
                return -1;
            }

            parsed_string = malloc(parsed_string_length + 1);

            cursor = cursor - parsed_string_length - 1;

            int parsed_string_index = 0;

            while (*cursor != '\0' && *cursor != '"') {
                if (*cursor == '\\') {
                    cursor++;

                    switch (*cursor) {
                        case 'b':
                            parsed_string[parsed_string_index] = '\b';
                            parsed_string_index++;
                            cursor++;
                            break;
                        case 'f':
                            parsed_string[parsed_string_index] = '\f';
                            parsed_string_index++;
                            cursor++;
                            break;
                        case 'n':
                            parsed_string[parsed_string_index] = '\n';
                            parsed_string_index++;
                            cursor++;
                            break;
                        case 'r':
                            parsed_string[parsed_string_index] = '\r';
                            parsed_string_index++;
                            cursor++;
                            break;
                        case 't':
                            parsed_string[parsed_string_index] = '\t';
                            parsed_string_index++;
                            cursor++;
                            break;
                        case 'u':
                            parsed_string_index += 4;
                            cursor += 5;
                            break;
                        default:
                            return -1;
                    }
                } else {
                    parsed_string[parsed_string_index] = *cursor;
                    parsed_string_index++;
                    cursor++;
                }
            }

            cursor++;

            json_element_t* property_name_element = malloc(sizeof(json_element_t));

            property_name_element->type = JSON_VALUE_STRING;
            property_name_element->value.string = parsed_string;

            json_element_t* property_value_element = NULL;

            if (*cursor == ':') {
                cursor++;

                if (*cursor == '{') {
                    property_value_element = malloc(sizeof(json_element_t));

                    json_parse(cursor, &property_value_element);

                    while (*cursor != '\0' && *cursor != '}') {
                        cursor++;
                    }
                } else if (*cursor == '[') {
                    property_value_element = malloc(sizeof(json_element_t));

                    json_parse(cursor, &property_value_element);

                    while (*cursor != '\0' && *cursor != ']') {
                        cursor++;
                    }
                } else if (*cursor == '"') {
                    cursor++;

                    int parsed_string_length = 0;
                    char* parsed_string = NULL;

                    while (*cursor != '\0' && *cursor != '"') {
                        if (*cursor == '\\') {
                            cursor++;

                            switch (*cursor) {
                                case 'b':
                                    parsed_string_length++;
                                    cursor++;
                                    break;
                                case 'f':
                                    parsed_string_length++;
                                    cursor++;
                                    break;
                                case 'n':
                                    parsed_string_length++;
                                    cursor++;
                                    break;
                                case 'r':
                                    parsed_string_length++;
                                    cursor++;
                                    break;
                                case 't':
                                    parsed_string_length++;
                                    cursor++;
                                    break;
                                case 'u':
                                    parsed_string_length += 4;
                                    cursor += 5;
                                    break;
                                default:
                                    return -1;
                            }
                        } else {
                            parsed_string_length++;
                            cursor++;
                        }
                    }

                    if (parsed_string_length == 0) {
                        return -1;
                    }

                    parsed_string = malloc(parsed_string_length + 1);

                    cursor = cursor - parsed_string_length - 1;

                    int parsed_string_index = 0;

                    while (*cursor != '\0' && *cursor != '"') {
                        if (*cursor == '\\') {
                            cursor++;

                            switch (*cursor) {
                                case 'b':
                                    parsed_string[parsed_string_index] = '\b';
                                    parsed_string_index++;
                                    cursor++;
                                    break;
                                case 'f':
                                    parsed_string[parsed_string_index] = '\f';
                                    parsed_string_index++;
                                    cursor++;
                                    break;
                                case 'n':
                                    parsed_string[parsed_string_index] = '\n';
                                    parsed_string_index++;
                                    cursor++;
                                    break;
                                case 'r':
                                    parsed_string[parsed_string_index] = '\r';
                                    parsed_string_index++;
                                    cursor++;
                                    break;
                                case 't':
                                    parsed_string[parsed_string_index] = '\t';
                                    parsed_string_index++;
                                    cursor++;
                                    break;
                                case 'u':
                                    parsed_string_index += 4;
                                    cursor += 5;
                                    break;
                                default:
                                    return -1;
                            }
                        } else {
                            parsed_string[parsed_string_index] = *cursor;
                            parsed_string_index++;
                            cursor++;
                        }
                    }

                    cursor++;

                    property_value_element = malloc(sizeof(json_element_t));

                    property_value_element->type = JSON_VALUE_STRING;
                    property_value_element->value.string = parsed_string;
                } else if (*cursor >= '0' && *cursor <= '9') {
                    int integer_value = 0;
                    double floating_point_value = 0.0;
                    int digits_after_decimal_point = 0;
                    int is_negative = 0;
                    int has_digits_after_decimal_point = 0;

                    if (*cursor == '-') {
                        is_negative = 1;
                        cursor++;
                    }

                    while (*cursor >= '0' && *cursor <= '9') {
                        integer_value *= 10;
                        integer_value += *cursor - '0';
                        cursor++;
                    }

                    if (*cursor == '.') {
                        cursor++;

                        while (*cursor >= '0' && *cursor <= '9') {
                            floating_point_value *= 10.0;
                            floating_point_value += *cursor - '0';
                            digits_after_decimal_point++;
                            cursor++;
                        }

                        has_digits_after_decimal_point = 1;
                    }

                    if (*cursor == 'e' || *cursor == 'E') {
                        int exponent_value = 0;
                        int is_negative_exponent = 0;

                        cursor++;

                        if (*cursor == '-') {
                            is_negative_exponent = 1;
                            cursor++;
                        }

                        while (*cursor >= '0' && *cursor <= '9') {
                            exponent_value *= 10;
                            exponent_value += *cursor - '0';
                            cursor++;
                        }

                        if (is_negative_exponent) {
                            exponent_value = -exponent_value;
                        }

                        floating_point_value *= pow(10.0, (double) exponent_value);
                    }

                    if (has_digits_after_decimal_point) {
                        floating_point_value /= pow(10.0, (double) digits_after_decimal_point);
                    }

                    if (is_negative) {
                        integer_value = -integer_value;
                        floating_point_value = -floating_point_value;
                    }

                    property_value_element = malloc(sizeof(json_element_t));

                    property_value_element->type = JSON_VALUE_NUMBER;
                    property_value_element->value.floating_point = floating_point_value;
                } else if (strcmp(cursor, "true") == 0) {
                    property_value_element = malloc(sizeof(json_element_t));

                    property_value_element->type = JSON_VALUE_TRUE;
                    property_value_element->value.type = JSON_VALUE_TRUE;

                    cursor += 4;
                } else if (strcmp(cursor, "false") == 0) {
                    property_value_element = malloc(sizeof(json_element_t));

                    property_value_element->type = JSON_VALUE_FALSE;
                    property_value_element->value.type = JSON_VALUE_FALSE;

                    cursor += 5;
                } else if (strcmp(cursor, "null") == 0) {
                    property_value_element = malloc(sizeof(json_element_t));

                    property_value_element->type = JSON_VALUE_NULL;
                    property_value_element->value.type = JSON_VALUE_NULL;

                    cursor += 4;
                } else {
                    return -1;
                }
            } else {
                return -1;
            }

            if (*cursor == ',' || *cursor == '}') {
                json_element_t* property_element = malloc(sizeof(json_element_t));

                property_element->type = JSON_OBJECT;

                char* property_name_buffer = malloc(strlen(property_name_element->value.string) + 1);

                strcpy(property_name_buffer, property_name_element->value.string);

                property_element->value.string = malloc(2 * sizeof(json_element_t*));

                property_element->value.string[0] = property_name_element;
                property_element->value.string[1] = property_value_element;

                int property_index = 0;

                while (root->value.string[property_index] != NULL) {
                    property_index++;
                }

                root->value.string[property_index] = property_element;
            } else {
                return -1;
            }
        } else {
            return -1;
        }

        cursor++;

        if (*cursor == '}') {
            break;
        } else if (*cursor == ',') {
            cursor++;
            continue;
        } else {
            return -1;
        }
    }

    *ptr = root;

    return 0;
}