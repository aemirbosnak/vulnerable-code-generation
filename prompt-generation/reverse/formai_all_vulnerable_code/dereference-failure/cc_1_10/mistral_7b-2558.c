//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <stddef.h>

typedef struct url_context {
    char *query_string;
    size_t query_length;
} url_context;

void url_parse(char *url, url_context *context) {
    char *query_start = NULL;
    char *query_end = NULL;

    context->query_length = 0;

    if ((query_start = strchr(url, '?')) != NULL) {
        context->query_string = query_start + 1;
        query_end = strchr(context->query_string, '#');

        if (query_end != NULL) {
            context->query_length = query_end - context->query_string;
            context->query_string[context->query_length] = '\0';
        } else {
            context->query_length = strlen(context->query_string);
        }
    }
}

void url_sanitize(url_context *context) {
    size_t i, j;
    char *sanitized_query = malloc(context->query_length + 1);

    for (i = 0, j = 0; i < context->query_length; i++) {
        switch (context->query_string[i]) {
            case '&':
                sanitized_query[j++] = '&';
                break;
            case '=':
                sanitized_query[j++] = '=';
                i++; // consume next character
                while (isspace(context->query_string[i])) {
                    i++;
                }
                break;
            default:
                sanitized_query[j++] = context->query_string[i];
                break;
        }
    }

    sanitized_query[j] = '\0';
    free(context->query_string);
    context->query_string = sanitized_query;
}

int main(int argc, char **argv) {
    url_context url_data;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    url_parse(argv[1], &url_data);
    url_sanitize(&url_data);

    printf("Sanitized query string: %s\n", url_data.query_string);

    free(url_data.query_string);

    return 0;
}