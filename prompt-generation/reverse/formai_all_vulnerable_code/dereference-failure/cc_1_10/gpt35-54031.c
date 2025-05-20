//FormAI DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 2000

// function to remove leading and trailing spaces from a string
char *trim(char *str)
{
    if (!str) return NULL;
    char *end = str + strlen(str) - 1;
    // remove leading spaces
    while (*str == ' ') str++;
    // remove trailing spaces
    while (*end == ' ' && end > str) end--;
    *(end+1) = '\0';
    return str;
}

// function to beautify HTML code
char *beautify_html(char *html, int indent_size)
{
    char *res = malloc(MAXLENGTH * sizeof(char)); // allocate memory for the result
    char *indent = malloc(indent_size * sizeof(char)); // allocate memory for the indentation
    memset(indent, ' ', indent_size); // fill the indentation with spaces
    int i, j, k, l = 0, len = strlen(html);
    for (i = 0; i < len; i++) {
        // if it's not a '<', add it to result
        if (html[i] != '<') {
            res[l++] = html[i];
            if (html[i] == '>' && i < len - 1 && html[i+1] != '<') res[l++] = '\n';
            continue;
        }
        // if it's a '<', check if it's an open tag or a close tag
        j = i + 1; k = 0;
        while (html[j] != '>' && html[j] != ' ') {
            k++; j++;
        }
        char tag[k+1]; tag[k] = '\0';
        memcpy(tag, &html[i+1], k);
        tag[k] = '\0';
        i = j;
        // if it's a close tag, decrease indentation and add tag to result
        if (tag[0] == '/') {
            indent_size -= 4; // decrease indentation by 4 spaces
            if (l > 0 && res[l-1] == '\n') l--; // remove extra newline character
            memcpy(res + l, indent, indent_size);
            l += indent_size;
            memcpy(res + l, &html[i-strlen(tag)-1], strlen(tag)+2);
            l += strlen(tag)+2;
            if (html[i+1] != '<') res[l++] = '\n';
        } else { // if it's an open tag, increase indentation and add tag to result
            if (html[i-1] != '\n') res[l++] = '\n'; // add newline character before the open tag
            memcpy(res + l, indent, indent_size);
            l += indent_size;
            memcpy(res + l, &html[i-1], strlen(tag)+2);
            if (html[i+1] != '<') res[l++] = '\n';
            indent_size += 4; // increase indentation by 4 spaces
        }
    }
    res[l] = '\0'; // add null terminator to result
    free(indent); // free memory allocated for the indentation
    return res;
}

int main()
{
    char html[MAXLENGTH], *beauty;
    int indent_size;
    printf("Enter the HTML code to beautify: ");
    fgets(html, MAXLENGTH, stdin); // get the HTML code from the user
    // remove leading and trailing spaces
    char *trimmed = trim(html);
    printf("Enter the indentation size (2 to 8): ");
    scanf("%d", &indent_size); // get the indentation size from the user
    indent_size = (indent_size < 2 || indent_size > 8) ? 4 : indent_size; // use default value of 4 if the user inputs an invalid value
    beauty = beautify_html(trimmed, indent_size); // beautify the HTML code
    printf("Beautified HTML:\n%s\n", beauty); // print the beautified HTML code
    free(beauty); // free memory allocated for the result
    return 0;
}