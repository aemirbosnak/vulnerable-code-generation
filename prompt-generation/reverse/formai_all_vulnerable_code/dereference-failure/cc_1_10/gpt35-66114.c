//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 100
#define MAX_TAG_LEN 20

struct xml_tag {
    char tag[MAX_TAG_LEN];
    char value[MAX_STR_LEN];
    struct xml_tag *next;
};

void parse_xml(char *xml_str, struct xml_tag *root) {
    char *start_tag, *end_tag, tag[MAX_TAG_LEN], value[MAX_STR_LEN];
    struct xml_tag *current_tag = root;

    start_tag = strstr(xml_str, "<");
    while (start_tag != NULL) {
        end_tag = strstr(start_tag, ">");
        if (end_tag == NULL) {
            printf("Invalid XML");
            exit(1);
        }
        int tag_len = end_tag - start_tag - 1;
        memcpy(tag, &start_tag[1], tag_len);
        tag[tag_len] = '\0';
        start_tag = end_tag + 1;

        end_tag = strstr(start_tag, "<");
        if (end_tag == NULL) {
            printf("Invalid XML");
            exit(1);
        }
        int value_len = end_tag - start_tag;
        memcpy(value, start_tag, value_len);
        value[value_len] = '\0';
        start_tag = end_tag;

        struct xml_tag *new_tag = malloc(sizeof(struct xml_tag));
        strcpy(new_tag->tag, tag);
        strcpy(new_tag->value, value);
        new_tag->next = NULL;
        current_tag->next = new_tag;
        current_tag = new_tag;

        start_tag = strstr(start_tag, "<");
    }
}

int main() {
    char xml_str[] = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
    struct xml_tag root;
    parse_xml(xml_str, &root);

    struct xml_tag *current_tag = root.next;
    while (current_tag != NULL) {
        printf("%s: %s\n", current_tag->tag, current_tag->value);
        current_tag = current_tag->next;
    }

    return 0;
}