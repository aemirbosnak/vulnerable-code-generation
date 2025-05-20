//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HTML_SIZE 1000000 // Maximum size of HTML code to be beautified

void beautifyHTML(char* html) {
    int i, j, k;
    int count = 0;
    char* newHTML = (char*) malloc(MAX_HTML_SIZE * sizeof(char));
    newHTML[0] = '\0';

    for (i = 0; i < strlen(html); i++) {
        if (html[i] == '<') {
            count++;
        }
        else if (html[i] == '>') {
            count--;
        }

        if (count == 0) {
            j = i;
            while (j < strlen(html) && html[j]!= '<') {
                newHTML[k++] = html[j++];
            }
            newHTML[k++] = '<';
            k = 0;
            j++;
        }

        if (count > 0) {
            newHTML[k++] = '<';
        }
        if (count < 0) {
            newHTML[k++] = '>';
        }
    }

    newHTML[k] = '\0';

    printf("Beautified HTML:\n%s\n", newHTML);

    free(newHTML);
}

int main() {
    char html[] = "<html><head><title>My Website</title></head><body><h1>Welcome to My Website!</h1><p>This is my first website.</p></body></html>";

    beautifyHTML(html);

    return 0;
}