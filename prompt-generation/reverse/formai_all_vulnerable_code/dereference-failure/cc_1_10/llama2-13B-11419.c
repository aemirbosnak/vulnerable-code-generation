//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 1024
#define STR_EMPTY "_______"

void str_cat(char *dest, const char *src) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);
    size_t total_len = dest_len + src_len;
    char *new_dest = realloc(dest, total_len + 1);
    if (!new_dest) {
        printf("Memory allocation failed\n");
        return;
    }
    memcpy(new_dest, dest, dest_len);
    memcpy(new_dest + dest_len, src, src_len);
    dest = new_dest;
}

void str_cpy(char *dest, const char *src) {
    strcpy(dest, src);
}

void str_trim(char *str) {
    size_t len = strlen(str);
    if (len == 0) {
        return;
    }
    char *ptr = str;
    while (*ptr == ' ' || *ptr == '\t') {
        ptr++;
    }
    strcpy(str, ptr);
}

void str_lower(char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        char c = tolower(str[i]);
        str[i] = c;
    }
}

int main() {
    char str1[] = "Hello World!";
    char str2[] = "This is a test string";
    char str3[1024];

    str_cpy(str3, STR_EMPTY);

    str_cat(str3, str1);
    str_cat(str3, str2);
    str_trim(str3);
    str_lower(str3);

    printf("%s\n", str3);

    return 0;
}