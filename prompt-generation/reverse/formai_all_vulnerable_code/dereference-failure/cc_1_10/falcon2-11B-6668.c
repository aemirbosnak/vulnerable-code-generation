//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
void beautify(char *html) {
    char *output = (char*)malloc(sizeof(char) * (strlen(html) + 1));
    int index = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int tab_count = 0;

    // Iterate through the input HTML code
    for (i = 0; i < strlen(html); i++) {
        // Check if the character is a tab character
        if (html[i] == '\t') {
            tab_count++;
        }

        // If the character is not a tab character and it is not the end of the line, add it to the output
        else if (html[i]!= '\n' && html[i]!= '\r' && tab_count <= 4) {
            output[index++] = html[i];
            tab_count = 0;
        }

        // If the character is not a tab character and it is the end of the line, add a tab character to the output
        else if (html[i]!= '\n' && html[i]!= '\r' && tab_count > 4) {
            for (j = 0; j < 4 - tab_count; j++) {
                output[index++] = '\t';
            }
            output[index++] = '\n';
            tab_count = 0;
        }

        // If the character is a tab character, add it to the output
        else if (html[i] == '\t') {
            output[index++] = '\t';
        }
    }

    // Add the closing HTML tag to the output
    output[index++] = '>';
    output[index] = '\0';

    // Print the beautified HTML code
    printf("%s\n", output);
}

int main() {
    char html[] = "<html>\n<head>\n<title>My Website</title>\n</head>\n<body>\n<h1>Welcome to my website!</h1>\n</body>\n</html>";
    beautify(html);
    return 0;
}