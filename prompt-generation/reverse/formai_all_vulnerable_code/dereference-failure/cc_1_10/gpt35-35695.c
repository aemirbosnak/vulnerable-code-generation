//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xml_attribute {
    char *name;
    char *value;
} xml_attribute;

typedef struct xml_node {
    char *name;
    char *content;
    xml_attribute *attributes;
    int num_attributes;
} xml_node;

void parse_xml(char *xml) {
    xml_node *root = malloc(sizeof(xml_node));
    root->name = "root";
    root->content = "";
    root->attributes = NULL;
    root->num_attributes = 0;

    char *token;
    char *state;
    char *line;
    char *tag_name = NULL;
    int tag_open = 0;
    int level = 0;
    int n = 0;
    char **tag_stack = malloc(sizeof(char *));
    tag_stack[n] = root->name;

    while ((token = strtok_r(xml, "\n", &state)) != NULL) {
        xml_node *new_node = malloc(sizeof(xml_node));
        new_node->content = "";
        new_node->attributes = NULL;
        new_node->num_attributes = 0;

        if (strstr(token, "<?")) {
            continue;
        }

        if (strstr(token, "<!")) {
            continue;
        }

        if (strstr(token, "</")) {
            level--;
            continue;
        }

        if (strstr(token, "/>")) {
            continue;
        }

        if (strstr(token, "<")) {
            tag_open = 1;
            tag_name = strtok(token, "<>");
            int len = strlen(tag_name);
            if (tag_name[0] != '/' && tag_name[len - 1] != '/') {
                level++;
                n++;
                tag_stack = realloc(tag_stack, (n + 1) * sizeof(char *));
                tag_stack[n] = strdup(tag_name);
            }
            continue;
        }

        if (tag_open && strstr(token, ">")) {
            line = strtok(token, "<>");
            new_node->name = strdup(tag_name);
            int len = strlen(line);
            if (line[len - 1] == '/') {
                level--;
            }
            char *name = strtok(line, " ");
            char *value = strtok(NULL, "\"");
            while (value != NULL) {
                xml_attribute *attr = malloc(sizeof(xml_attribute));
                attr->name = strdup(name);
                attr->value = strdup(value);
                new_node->attributes = realloc(new_node->attributes, (new_node->num_attributes + 1) * sizeof(xml_attribute));
                new_node->attributes[new_node->num_attributes] = *attr;
                new_node->num_attributes++;
                name = strtok(NULL, " ");
                value = strtok(NULL, "\"");
            }
            if (level > n) {
                xml_node *parent = malloc(sizeof(xml_node));
                parent->content = "";
                parent->attributes = NULL;
                parent->num_attributes = 0;
                parent->name = strdup(tag_stack[n]);
                tag_stack = realloc(tag_stack, (n + 1) * sizeof(char *));
                n--;
                parent->content = strdup(new_node->content);
                parent->attributes = new_node->attributes;
                parent->num_attributes = new_node->num_attributes;
                parent->name = new_node->name;
            } else {
                xml_node *parent = malloc(sizeof(xml_node));
                parent = root;
                while (level < n - 1) {
                    parent = parent->attributes;
                    n--;
                }
                parent->content = strdup(new_node->content);
                parent->attributes = new_node->attributes;
                parent->num_attributes = new_node->num_attributes;
                parent->name = new_node->name;
            }
            tag_open = 0;
            continue;
        }

        if (tag_open) {
            new_node->content = strdup(token);
        }
    }

    printf("XML parse successful!\n");
}

int main(int argc, char **argv) {
    char *xml_input = "<root><person name=\"John Doe\" age=\"42\"/><person name=\"Jane Doe\" age=\"39\"/></root>";
    parse_xml(xml_input);
    return 0;
}