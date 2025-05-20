//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *text;
    size_t len;
} Text;

Text *
text_new(const char *str) {
    Text *t = malloc(sizeof(Text));
    t->len = strlen(str);
    t->text = malloc(t->len + 1);
    strcpy(t->text, str);
    return t;
}

void
text_free(Text *t) {
    free(t->text);
    free(t);
}

int
main(void) {
    Text *t = text_new("The quick brown fox jumps over the lazy dog");
    char buf[1024];
    size_t i, n, t0, t1;

    printf("Type the following text as fast as you can:\n\n%s\n\n", t->text);
    t0 = time(NULL);
    fgets(buf, sizeof(buf), stdin);
    t1 = time(NULL);

    n = 0;
    for (i = 0; i < t->len; i++) {
        if (t->text[i] == buf[i]) {
            n++;
        }
    }

    printf("You typed %zu characters correctly in %zu seconds.\n", n, t1 - t0);
    if (n == t->len) {
        printf("Congratulations! You are a typing ninja!\n");
    } else {
        printf("Better luck next time!\n");
    }

    text_free(t);

    return 0;
}