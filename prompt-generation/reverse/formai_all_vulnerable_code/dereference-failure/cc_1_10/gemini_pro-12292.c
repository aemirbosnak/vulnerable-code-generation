//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *start;
    char *end;
} Range;

Range ranges[1000];
int nRanges = 0;

void findRanges(char *html) {
    int inAngle = 0;
    char *start = html;
    for (char *c = html; *c != '\0'; c++) {
        if (*c == '<') {
            if (!inAngle) {
                ranges[nRanges].start = c;
                nRanges++;
                inAngle = 1;
            }
        } else if (*c == '>') {
            ranges[nRanges - 1].end = c;
            inAngle = 0;
        }
    }
}

void beautify(char *html) {
    int indentLevel = 0;
    char *beautified = malloc(strlen(html) * 2);
    char *out = beautified;
    for (char *c = html; *c != '\0'; c++) {
        if (*c == '<') {
            *out++ = *c;
            *out++ = '\n';
            for (int i = 0; i < indentLevel; i++) {
                *out++ = ' ';
            }
        } else if (*c == '>') {
            if (*(c - 1) != '/') {
                indentLevel++;
            } else {
                indentLevel--;
            }
            *out++ = *c;
            *out++ = '\n';
        } else {
            *out++ = *c;
        }
    }
    *out = '\0';
    printf("%s", beautified);
    free(beautified);
}

int main() {
    char html[] = "<html><body><h1>Neo-C HTML Beautifier</h1><p>This is a sample paragraph.</p></body></html>";
    findRanges(html);
    beautify(html);
    return 0;
}