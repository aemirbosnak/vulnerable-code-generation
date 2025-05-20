//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: protected
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 100

void protected_strcpy(char *dest, const char *src) {
    size_t src_len = strlen(src);
    if (dest == NULL || src_len > MAX_STR_LEN) {
        return;
    }
    memcpy(dest, src, src_len);
}

void protected_strcat(char *dest, const char *src) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);
    if (dest == NULL || src_len > MAX_STR_LEN) {
        return;
    }
    memcpy(dest + dest_len, src, src_len);
    dest_len += src_len;
}

void protected_strtok(char *str, const char *delim) {
    size_t len = strlen(str);
    size_t i = 0;
    for (; i < len; ) {
        if (strchr(delim, str[i]) != NULL) {
            break;
        }
        i++;
    }
    if (i == len) {
        return;
    }
    memmove(str, str + i, len - i);
    str[len - i] = '\0';
}

int main() {
    char str1[] = "Hello, world!";
    char str2[] = "How are you?";
    char str3[50];

    protected_strcpy(str3, str1);
    protected_strcat(str3, " ");
    protected_strcat(str3, str2);

    protected_strtok(str3, " ");
    printf("%s\n", str3);

    return 0;
}