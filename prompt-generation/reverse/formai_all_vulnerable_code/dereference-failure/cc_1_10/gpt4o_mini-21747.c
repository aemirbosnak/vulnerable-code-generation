//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 64
#define MAX_CONTENT 256

typedef struct Node {
    char tag[MAX_TAG_NAME];
    char content[MAX_CONTENT];
    struct Node *next;
} Node;

Node *create_node(const char *tag, const char *content) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strncpy(new_node->tag, tag, MAX_TAG_NAME);
    strncpy(new_node->content, content, MAX_CONTENT);
    new_node->next = NULL;
    return new_node;
}

void append_node(Node **head, const char *tag, const char *content) {
    Node *new_node = create_node(tag, content);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void free_list(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void print_nodes(Node *head) {
    while (head != NULL) {
        printf("Tag: %s, Content: %s\n", head->tag, head->content);
        head = head->next;
    }
}

void parse_xml(FILE *file, Node **head) {
    char line[1024];
    char tag[MAX_TAG_NAME];
    char content[MAX_CONTENT];
    
    while (fgets(line, sizeof(line), file)) {
        char *open_tag = strstr(line, "<");
        char *close_tag = strstr(line, ">");
        
        if (open_tag && close_tag) {
            size_t tag_length = close_tag - open_tag - 1;
            if (tag_length < MAX_TAG_NAME) {
                strncpy(tag, open_tag + 1, tag_length);
                tag[tag_length] = '\0'; // Null terminate

                char *content_start = close_tag + 1;
                char *content_end = strstr(content_start, "<");
                
                if (content_end) {
                    size_t content_length = content_end - content_start;
                    if (content_length < MAX_CONTENT) {
                        strncpy(content, content_start, content_length);
                        content[content_length] = '\0'; // Null terminate

                        append_node(head, tag, content);
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    Node *head = NULL;
    parse_xml(file, &head);
    fclose(file);

    printf("Parsed XML content:\n");
    print_nodes(head);
    free_list(head);
    
    return 0;
}