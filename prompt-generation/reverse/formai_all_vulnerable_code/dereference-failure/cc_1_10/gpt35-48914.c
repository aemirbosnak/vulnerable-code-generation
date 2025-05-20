//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 100
#define MAX_ATTR_LEN 100
#define MAX_ATTR_COUNT 10

typedef struct xml_attribute {
    char name[MAX_ATTR_LEN];
    char value[MAX_ATTR_LEN];
} xml_attribute;

typedef struct xml_element {
    char tag[MAX_TAG_LEN];
    int attr_count;
    xml_attribute attrs[MAX_ATTR_COUNT];
    char content[MAX_TAG_LEN];
    struct xml_element* children;
} xml_element;

xml_element* parse_element(char* xml_str);
char* get_tag_name(char* xml_str);
int get_attr_count(char* xml_str);
xml_attribute* get_attrs(char* xml_str, int attr_count);
int get_tag_end_pos(char* xml_str);
int get_tag_content(char* xml_str, char* tag, char* content);
void free_element(xml_element* element);
void print_element(xml_element* element, int indent);

int main() {
    char xml_str[] = "<root><person name=\"John\" age=\"30\">Hello world!</person></root>";
    xml_element* root = parse_element(xml_str);
    if (root != NULL) {
        print_element(root, 0);
        free_element(root);
    }
    return 0;
}

xml_element* parse_element(char* xml_str) {
    char* tag_name = get_tag_name(xml_str);
    if (tag_name == NULL) {
        return NULL;
    }
    xml_element* element = (xml_element*) malloc(sizeof(xml_element));
    strcpy(element->tag, tag_name);
    element->attr_count = get_attr_count(xml_str);
    xml_attribute* attrs = get_attrs(xml_str, element->attr_count);
    for (int i = 0; i < element->attr_count; i++) {
        element->attrs[i] = attrs[i];
    }
    free(attrs);
    char content[MAX_TAG_LEN];
    int content_len = get_tag_content(xml_str, tag_name, content);
    if (content_len > 0) {
        strcpy(element->content, content);
        element->children = NULL;
    } else {
        char* tag_end = xml_str + get_tag_end_pos(xml_str);
        char* child_start = tag_end + strlen(tag_name) + 3; // 3 is for "</>"
        int child_count = 0;
        while (child_start < xml_str + strlen(xml_str) - 3) {
            xml_element* child = parse_element(child_start);
            if (child != NULL) {
                if (child_count == 0) {
                    element->children = child;
                } else {
                    xml_element* last_child = element->children;
                    while (last_child->children != NULL) {
                        last_child = last_child->children;
                    }
                    last_child->children = child;
                }
                child_count++;
            }
            child_start = child_start + strlen(child->tag) + strlen(child->content) + 5; // 5 is for "<></>"
            free_element(child);
        }
    }
    return element;
}

char* get_tag_name(char* xml_str) {
    if (xml_str == NULL) {
        return NULL;
    }
    char* start = strchr(xml_str, '<');
    if (start == NULL || *(start+1) == '/') {
        return NULL;
    }
    char* end = strchr(start, '>');
    if (end == NULL) {
        return NULL;
    }
    int len = end - start - 1;
    if (len > MAX_TAG_LEN) {
        len = MAX_TAG_LEN;
    }
    char* tag_name = (char*) malloc(len+1);
    strncpy(tag_name, start+1, len);
    *(tag_name+len) = '\0';
    return tag_name;
}

int get_attr_count(char* xml_str) {
    if (xml_str == NULL) {
        return 0;
    }
    int count = 0;
    char* curr = strchr(xml_str, ' ');
    while (curr != NULL && curr < strchr(xml_str, '>')) {
        count++;
        curr = strchr(curr+1, ' ');
    }
    return count;
}

xml_attribute* get_attrs(char* xml_str, int attr_count) {
    if (xml_str == NULL) {
        return NULL;
    }
    xml_attribute* attrs = (xml_attribute*) malloc(attr_count * sizeof(xml_attribute));
    int i = 0;
    char* curr = strchr(xml_str, ' ');
    while (curr != NULL && i < attr_count) {
        char* name_start = curr + 1;
        char* name_end = strchr(name_start, '=');
        if (name_end == NULL) {
            return NULL;
        }
        int name_len = name_end - name_start;
        if (name_len > MAX_ATTR_LEN) {
            name_len = MAX_ATTR_LEN;
        }
        char* attr_name = (char*) malloc(name_len+1);
        strncpy(attr_name, name_start, name_len);
        *(attr_name+name_len) = '\0';
        strcpy(attrs[i].name, attr_name);
        free(attr_name);
        char* value_start = name_end + 2;
        char* value_end = strchr(value_start, '"');
        if (value_end == NULL) {
            return NULL;
        }
        int value_len = value_end - value_start;
        if (value_len > MAX_ATTR_LEN) {
            value_len = MAX_ATTR_LEN;
        }
        char* attr_value = (char*) malloc(value_len+1);
        strncpy(attr_value, value_start, value_len);
        *(attr_value+value_len) = '\0';
        strcpy(attrs[i].value, attr_value);
        free(attr_value);
        i++;
        curr = strchr(curr+1, ' ');
    }
    return attrs;
}

int get_tag_end_pos(char* xml_str) {
    if (xml_str == NULL) {
        return -1;
    }
    char* pos = strstr(xml_str, "</");
    if (pos == NULL) {
        return -1;
    }
    return pos - xml_str;
}

int get_tag_content(char* xml_str, char* tag, char* content) {
    if (xml_str == NULL || tag == NULL || content == NULL) {
        return -1;
    }
    char start_str[MAX_TAG_LEN];
    char end_str[MAX_TAG_LEN];
    sprintf(start_str, "<%s>", tag);
    sprintf(end_str, "</%s>", tag);
    char* start = strstr(xml_str, start_str);
    if (start == NULL) {
        return -1;
    }
    char* end = strstr(xml_str, end_str);
    if (end == NULL) {
        return -1;
    }
    int len = end - start - strlen(start_str);
    if (len > MAX_TAG_LEN) {
        len = MAX_TAG_LEN;
    }
    strncpy(content, start+strlen(start_str), len);
    *(content+len) = '\0';
    return len;
}

void free_element(xml_element* element) {
    if (element == NULL) {
        return;
    }
    free_element(element->children);
    free(element);
}

void print_element(xml_element* element, int indent) {
    if (element == NULL) {
        return;
    }
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    printf("<%s", element->tag);
    for (int i = 0; i < element->attr_count; i++) {
        printf(" %s=\"%s\"", element->attrs[i].name, element->attrs[i].value);
    }
    printf(">");
    if (strlen(element->content) > 0) {
        printf("%s", element->content);
    } else {
        printf("\n");
        print_element(element->children, indent+2);
        for (int i = 0; i < indent; i++) {
            printf(" ");
        }
    }
    printf("</%s>\n", element->tag);
}