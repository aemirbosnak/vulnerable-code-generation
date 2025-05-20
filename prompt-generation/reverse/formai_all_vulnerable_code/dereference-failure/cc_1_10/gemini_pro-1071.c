//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our faithful companion, the magnifying glass
typedef struct {
    char *html;
    int length;
} MagnifyingGlass;

// Initialize the magnifying glass with a string of HTML
MagnifyingGlass *initMagnifyingGlass(char *html) {
    MagnifyingGlass *glass = malloc(sizeof(MagnifyingGlass));
    glass->html = html;
    glass->length = strlen(html);
    return glass;
}

// Free the magnifying glass and its contents
void freeMagnifyingGlass(MagnifyingGlass *glass) {
    free(glass->html);
    free(glass);
}

// Inspect a single character
char inspectCharacter(MagnifyingGlass *glass, int index) {
    if (index < 0 || index >= glass->length) {
        return '\0';
    }
    return glass->html[index];
}

// Beautify the HTML, one character at a time
char *beautifyHTML(MagnifyingGlass *glass) {
    char *beautified = malloc(glass->length * 2);
    int beautifiedIndex = 0;

    // Watson, let us enhance the HTML
    for (int i = 0; i < glass->length; i++) {
        char c = inspectCharacter(glass, i);
        switch (c) {
            case '<':
                // It's a tag, Watson!
                beautified[beautifiedIndex++] = c;
                while (c != '>') {
                    c = inspectCharacter(glass, ++i);
                    beautified[beautifiedIndex++] = c;
                }
                beautified[beautifiedIndex++] = '\n';
                break;
            case '\n':
                // A new line, eh?
                beautified[beautifiedIndex++] = c;
                beautified[beautifiedIndex++] = '\t';
                break;
            default:
                // Just a regular character
                beautified[beautifiedIndex++] = c;
                break;
        }
    }

    return beautified;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Elementary, my dear Watson! You must provide the HTML to beautify.\n");
        return 1;
    }

    // Obtain the HTML from Watson's notes
    MagnifyingGlass *glass = initMagnifyingGlass(argv[1]);

    // Engage the beautifier, Watson!
    char *beautified = beautifyHTML(glass);

    // Inspect the results, Watson
    printf("The beautified HTML, Watson:\n%s", beautified);

    // Dispose of the magnifying glass
    freeMagnifyingGlass(glass);
    free(beautified);

    return 0;
}