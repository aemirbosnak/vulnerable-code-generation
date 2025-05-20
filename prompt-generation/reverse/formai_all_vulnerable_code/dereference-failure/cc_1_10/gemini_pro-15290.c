//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct url_node {
    char *url;
    struct url_node *next;
} url_node;

url_node *sanitize(char *url) {
    url_node *node = malloc(sizeof(url_node));
    if (!node) return NULL;

    node->next = NULL;
    node->url = strdup(url);

    char *ptr = node->url;
    while (*ptr) {
        if (*ptr == '%') {
            char *hex = ptr + 1;
            if (strlen(hex) != 2) {
                // invalid URL
                free(node);
                return NULL;
            }

            int code = 0;
            for (int i = 0; i < 2; i++) {
                if (hex[i] >= '0' && hex[i] <= '9') {
                    code = code * 16 + (hex[i] - '0');
                } else if (hex[i] >= 'a' && hex[i] <= 'f') {
                    code = code * 16 + (hex[i] - 'a' + 10);
                } else if (hex[i] >= 'A' && hex[i] <= 'F') {
                    code = code * 16 + (hex[i] - 'A' + 10);
                } else {
                    // invalid URL
                    free(node);
                    return NULL;
                }
            }
            *ptr = code;
            memmove(ptr + 1, ptr + 3, strlen(ptr + 3) + 1);
        }
        ptr++;
    }

    return node;
}

void print_url(url_node *node) {
    printf("%s\n", node->url);
}

void free_url(url_node *node) {
    if (!node) return;

    free_url(node->next);
    free(node->url);
    free(node);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    url_node *node = sanitize(argv[1]);
    if (!node) {
        printf("Invalid URL: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    print_url(node);
    free_url(node);

    return EXIT_SUCCESS;
}