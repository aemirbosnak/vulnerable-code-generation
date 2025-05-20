//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a line from the ebook file
char* read_line(FILE* ebook) {
    char* line = NULL;
    char ch;
    size_t len = 0;
    while ((ch = fgetc(ebook))!= EOF) {
        if (ch == '\n') {
            len = ftell(ebook) - 1;
            break;
        }
        len++;
    }
    line = (char*)malloc((len + 1) * sizeof(char));
    fseek(ebook, -len, SEEK_END);
    fread(line, len, 1, ebook);
    line[len] = '\0';
    return line;
}

// Function to print a line from the ebook file
void print_line(FILE* ebook) {
    char* line = read_line(ebook);
    printf("%s\n", line);
    free(line);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <ebook-file>\n", argv[0]);
        return 1;
    }

    FILE* ebook = fopen(argv[1], "r");
    if (!ebook) {
        fprintf(stderr, "Error opening ebook file\n");
        return 1;
    }

    while (1) {
        print_line(ebook);
        char c = getchar();
        if (c == 'q') {
            break;
        }
    }

    fclose(ebook);
    return 0;
}