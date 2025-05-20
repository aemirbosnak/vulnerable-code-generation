//FormAI DATASET v1.0 Category: HTML beautifier ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    FILE *fp2;
    char ch;
    int tabCount = 0;

    // Open the HTML file to be formatted
    fp = fopen("index.html", "r");

    // Create a new file to output the formatted HTML to
    fp2 = fopen("formatted.html", "w");

    // If file cannot be opened, print an error message and exit
    if (fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    // Read each character in the file
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '<') {
            // If an opening tag is found, add a tab and print the tag
            fputc(ch, fp2);
            tabCount++;
            fputc('\n', fp2);
            for (int i = 0; i < tabCount; i++) {
                fputc('\t', fp2);
            }
        } else if (ch == '>') {
            // If a closing tag is found, print a newline and decrement the tab count
            fputc(ch, fp2);
            fputc('\n', fp2);
            tabCount--;
            for (int i = 0; i < tabCount; i++) {
                fputc('\t', fp2);
            }
        } else {
            // Otherwise, just print the character
            fputc(ch, fp2);
        }
    }

    printf("HTML formatted successfully!");

    // Close the files
    fclose(fp);
    fclose(fp2);
    return 0;
}