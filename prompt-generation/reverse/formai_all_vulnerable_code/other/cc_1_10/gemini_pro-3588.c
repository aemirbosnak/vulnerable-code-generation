//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define MAX_STR_LEN INT_MAX

char *paranoid_strstr(const char *haystack, const char *needle)
{
    size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);

    if (needle_len > haystack_len)
    {
        return NULL;
    }

    for (size_t i = 0; i <= haystack_len - needle_len; i++)
    {
        if (memcmp(haystack + i, needle, needle_len) == 0)
        {
            return (char *)(haystack + i);
        }
    }

    return NULL;
}

char *paranoid_strcpy(char *dest, const char *src)
{
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);

    if (src_len > dest_len)
    {
        return NULL;
    }

    memcpy(dest, src, src_len);
    dest[src_len] = '\0';

    return dest;
}

char *paranoid_strcat(char *dest, const char *src)
{
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);
    size_t total_len = dest_len + src_len;

    if (total_len > MAX_STR_LEN)
    {
        return NULL;
    }

    memcpy(dest + dest_len, src, src_len);
    dest[total_len] = '\0';

    return dest;
}

int main()
{
    char haystack[] = "Hello, paranoid world!";
    char needle[] = "world";

    char *found = paranoid_strstr(haystack, needle);
    assert(found != NULL);
    printf("Found needle at: %s\n", found);

    char dest[256] = "Hello, ";
    char *copied = paranoid_strcpy(dest, haystack);
    assert(copied != NULL);
    printf("Copied string: %s\n", dest);

    char *concatenated = paranoid_strcat(dest, needle);
    assert(concatenated != NULL);
    printf("Concatenated string: %s\n", dest);

    return 0;
}