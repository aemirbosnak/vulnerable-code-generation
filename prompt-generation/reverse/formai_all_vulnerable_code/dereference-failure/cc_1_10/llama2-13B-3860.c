//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: secure
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_STR_LEN 1024

void secure_strcpy(char *dest, const char *src) {
    size_t src_len = strlen(src);
    size_t dest_len = strlen(dest);
    assert(dest_len + src_len < MAX_STR_LEN);
    memcpy(dest, src, src_len);
}

void secure_strcat(char *dest, const char *src) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);
    assert(dest_len + src_len < MAX_STR_LEN);
    memcpy(dest + dest_len, src, src_len);
    dest_len += src_len;
}

void secure_strndup(char **str, const char *src, size_t len) {
    size_t src_len = strlen(src);
    assert(len <= MAX_STR_LEN);
    if (src_len <= len) {
        *str = malloc(len + 1);
        memcpy(*str, src, len);
        (*str)[len] = '\0';
    } else {
        *str = NULL;
    }
}

int main() {
    char *dest;
    char *src;

    // Securely copy a string
    secure_strcpy(dest, src);

    // Securely concatenate two strings
    secure_strcat(dest, src);

    // Securely allocate a string with a maximum length
    secure_strndup(&dest, src, MAX_STR_LEN);

    printf("Destination string: %s\n", dest);

    return 0;
}