//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_LENGTH 1024
#define MAGIC_NUMBER 0xDEADBEEF

struct node {
    char *str;
    size_t len;
    struct node *next;
};

struct node *parse_string(const char *str) {
    struct node *root = NULL;
    char *ptr = (char *)str;
    size_t len = strlen(str);

    while (len > 0) {
        size_t next_len = len;
        char *next_ptr = ptr;

        if (next_len > MAX_LENGTH) {
            next_len = MAX_LENGTH;
            next_ptr = ptr + next_len - 1;
        }

        char c = *ptr++;
        if (c == ' ') {
            continue;
        }

        struct node *node = (struct node *)malloc(sizeof(struct node));
        node->str = next_ptr;
        node->len = next_len;
        node->next = root;
        root = node;

        len -= next_len;
        ptr += next_len;
    }

    return root;
}

int main(void) {
    char str[] = "Hello, world!";
    struct node *node = parse_string(str);

    assert(node != NULL);
    assert(node->str == str);
    assert(node->len == strlen(str));

    struct node *current = node;
    while (current != NULL) {
        printf("%s\n", current->str);
        current = current->next;
    }

    free(node);
    return 0;
}