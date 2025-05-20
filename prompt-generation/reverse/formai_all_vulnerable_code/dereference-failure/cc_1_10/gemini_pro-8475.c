//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// Function to beautify HTML code
void beautifyHTML(char *html) {
    int level = 0;
    char *output = malloc(strlen(html) * 2);
    char *p = output;
    
    for (char *i = html; *i; i++) {
        switch (*i) {
            case '<':
                // Start of a tag
                *p++ = *i;
                if (*(i + 1) == '/') {
                    // End tag
                    level--;
                    *p++ = *(i + 1);
                    *p++ = *(i + 2);
                    i += 2;
                } else {
                    // Start tag
                    level++;
                    *p++ = *i;
                    *p++ = *(i + 1);
                    i++;
                    while (*i != '>') {
                        *p++ = *i++;
                    }
                }
                *p++ = '\n';
                for (int j = 0; j < level; j++) {
                    *p++ = '\t';
                }
                break;
            case '>':
                // End of a tag
                *p++ = *i;
                *p++ = '\n';
                break;
            default:
                // Text
                *p++ = *i;
                break;
        }
    }
    
    *p = '\0';
    strcpy(html, output);
    free(output);
}

int main() {
    char html[] = "<html>\n<head>\n<title>Example</title>\n</head>\n<body>\n<h1>Hello, world!</h1>\n</body>\n</html>";
    
    beautifyHTML(html);
    
    printf("%s", html);
    
    return 0;
}