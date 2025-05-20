//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautifyHTML(char* htmlFile) {
    char* buffer = NULL;
    long length;
    FILE* fp = fopen(htmlFile, "rb");

    if (fp) {
        fseek(fp, 0, SEEK_END);
        length = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        buffer = malloc(length);
        if (buffer) {
            fread(buffer, 1, length, fp);
        }
        fclose(fp);
    }

    if (buffer) {
        int indent_level = 0;
        int i = 0;
        char c;
        for (i = 0; i < length; i++) {
            c = buffer[i];
            if (c == '<') {
                if (buffer[i + 1] == '/') {
                    indent_level--;
                }
                for (int j = 0; j < indent_level; j++) {
                    putchar(' ');
                    putchar(' ');
                }
                putchar(c);
                indent_level++;
                putchar('\n');
            } else if (c == '>') {
                putchar(c);
                putchar('\n');
                indent_level--;
            } else {
                putchar(c);
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s file.html\n", argv[0]);
        return 1;
    }
    beautifyHTML(argv[1]);
    return 0;
}