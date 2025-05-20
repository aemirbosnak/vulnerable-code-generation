//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

typedef struct {
    char *str;
    int len;
} string;

string *new_string(const char *str) {
    string *s = malloc(sizeof(string));
    s->str = strdup(str);
    s->len = strlen(s->str);
    return s;
}

void free_string(string *s) {
    free(s->str);
    free(s);
}

string *compress(string *s) {
    string *t = new_string("");
    int i, j, k;
    for (i = 0; i < s->len; i++) {
        for (j = i + 1; j < s->len; j++) {
            if (s->str[j] != s->str[i]) {
                break;
            }
        }
        k = j - i;
        if (k > 1) {
            char buf[32];
            sprintf(buf, "%d%c", k, s->str[i]);
            strcat(t->str, buf);
        } else {
            strcat(t->str, s->str + i);
        }
        i = j - 1;
    }
    return t;
}

string *decompress(string *s) {
    string *t = new_string("");
    int i, j, k;
    for (i = 0; i < s->len; i++) {
        if (s->str[i] >= '0' && s->str[i] <= '9') {
            j = i + 1;
            while (s->str[j] >= '0' && s->str[j] <= '9') {
                j++;
            }
            k = atoi(s->str + i);
            while (k--) {
                strcat(t->str, s->str + j);
            }
            i = j - 1;
        } else {
            strcat(t->str, s->str + i);
        }
    }
    return t;
}

int main() {
    string *s = new_string("aabbbccaadddeee");
    string *t = compress(s);
    printf("Compressed: %s\n", t->str);
    printf("Decompressed: %s\n", decompress(t)->str);
    free_string(s);
    free_string(t);
    return 0;
}