//FormAI DATASET v1.0 Category: HTML beautifier ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* beautifyHTML(char* htmlCode) {
    int i, j, len;
    char* res = (char*) malloc(sizeof(char) * strlen(htmlCode));
    int resIndex = 0;

    for(i = 0; i < strlen(htmlCode); i++) {
        if(htmlCode[i] == '<') {
            res[resIndex++] = '\n';
            res[resIndex++] = htmlCode[i];
            res[resIndex++] = ' ';

            for(j = i + 1; j < strlen(htmlCode) && htmlCode[j] != '>' && htmlCode[j] != ' '; j++) {
                res[resIndex++] = htmlCode[j];
            }

            if(htmlCode[j] == '>') {
                res[resIndex++] = '>';
                res[resIndex++] = '\n';
            } else {
                res[resIndex++] = ' ';
            }

            i = j;
        } else if(htmlCode[i] == '>') {
            res[resIndex++] = '>';
            res[resIndex++] = '\n';
        } else {
            res[resIndex++] = htmlCode[i];
        }
    }

    res[resIndex] = '\0';

    return res;
}

int main() {
    char htmlCode[10000];

    printf("Enter HTML code: ");
    fgets(htmlCode, 10000, stdin);

    char* beautifiedHTMLCode = beautifyHTML(htmlCode);

    printf("\n\n------------------------------------\n");
    printf("Beautified HTML code: \n\n%s\n", beautifiedHTMLCode);
    printf("------------------------------------\n");

    free(beautifiedHTMLCode);

    return 0;
}