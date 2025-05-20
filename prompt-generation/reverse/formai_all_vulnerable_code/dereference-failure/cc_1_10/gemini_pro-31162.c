//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    int len;
} string;

string get_text(void) {
    string s;
    char buf[1024];
    printf("Enter text: ");
    while (fgets(buf, sizeof(buf), stdin)) {
        s.text = realloc(s.text, s.len + strlen(buf) + 1);
        strcpy(s.text + s.len, buf);
        s.len += strlen(buf);
    }
    return s;
}

string summarize(string text) {
    string summary;
    char *words[1024];
    int i, j, k, n;

    n = 0;
    for (i = 0; i < text.len; i++) {
        if (text.text[i] == ' ' || text.text[i] == '\n' || text.text[i] == '\t') {
            words[n++] = text.text + i;
            text.text[i] = '\0';
        }
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                for (k = j; k < n; k++) {
                    words[k] = words[k + 1];
                }
                n--;
                j--;
            }
        }
    }

    summary.text = malloc(n * 16 + 1);
    summary.len = 0;
    for (i = 0; i < n; i++) {
        summary.len += sprintf(summary.text + summary.len, "%s ", words[i]);
    }
    return summary;
}

void print_summary(string summary) {
    printf("Summary: %s\n", summary.text);
    free(summary.text);
}

int main(void) {
    string text, summary;
    text = get_text();
    summary = summarize(text);
    print_summary(summary);
    free(text.text);
    return 0;
}