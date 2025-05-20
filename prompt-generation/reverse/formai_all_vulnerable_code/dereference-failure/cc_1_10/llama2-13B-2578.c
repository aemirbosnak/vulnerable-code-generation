//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: protected
#include <string.h>
#include <stdlib.h>

#define MAX_STRLEN 1024

struct string {
    char *data;
    size_t len;
};

void string_init(struct string *s, const char *str) {
    s->data = malloc(strlen(str) + 1);
    strcpy(s->data, str);
    s->len = strlen(str) + 1;
}

void string_free(struct string *s) {
    free(s->data);
}

void string_concat(struct string *s1, const char *s2) {
    size_t len = s1->len + strlen(s2) + 1;
    char *new_data = realloc(s1->data, len);
    if (!new_data) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(new_data + s1->len, s2);
    s1->data = new_data;
    s1->len = len;
}

void string_insert(struct string *s1, size_t pos, const char *s2) {
    size_t len = s1->len + strlen(s2) + 1;
    char *new_data = realloc(s1->data, len);
    if (!new_data) {
        printf("Memory allocation failed\n");
        return;
    }
    memmove(new_data + pos + strlen(s2), s1->data + pos, s1->len - pos + 1);
    strcpy(new_data + pos, s2);
    s1->data = new_data;
    s1->len = len;
}

int main() {
    struct string s1, s2, s3;

    string_init(&s1, "Hello, ");
    string_init(&s2, "world!");
    string_init(&s3, NULL);

    string_concat(&s1, "C++ is a");
    string_insert(&s2, 2, "great");
    string_concat(&s3, "programming language");

    printf("s1: %s\ns2: %s\ns3: %s\n", s1.data, s2.data, s3.data);

    string_free(&s1);
    string_free(&s2);
    string_free(&s3);

    return 0;
}