//MISTRAL-7B DATASET v1.0 Category: HTML beautifier ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Our fearless leader, Commander Taco, commands us to beautify HTML
void cmdTacoBeautifyHTML(char* html) {
    char* tags = "></";
    char* tag, *open, *close, *pos;
    int i, len;

    // Set up our taco shell
    printf("<html>\n<head>\n<title>Taco's Beautiful HTML</title>\n</head>\n<body>\n");

    // Open the first tag, if any
    tag = strstr(html, "<");
    if (tag != NULL) {
        open = tag;
        close = strchr(open, '>');

        // Commander Taco wants all tags closed before the next one is opened
        for (i = 0; i < close - open; i++) {
            if (i >= 1 && (open[i] == ' ' || open[i] == '\t')) {
                printf("%c", i + 32); // Convert spaces to tabs
            }
            putchar(open[i]);
        }

        // Close the tag
        printf("%s", close + 1);

        // Recursively call ourselves for the content of the tag
        cmdTacoBeautifyHTML(tag + strlen(open) + 1);
    } else {
        // No more tags, Commander Taco wants us to close up shop
        printf("</body>\n</html>\n");
    }
}

// You've been given an HTML mess, Commander Taco wants it beautiful
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <messed_up_html>\n", argv[0]);
        return 1;
    }

    char* html = argv[1];

    // Commander Taco wants us to beautify this HTML mess
    cmdTacoBeautifyHTML(html);

    return 0;
}