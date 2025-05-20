//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the content of a file
char *get_file_content(const char *filename)
{
    FILE *fp;
    char *content = NULL;
    size_t size = 0;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    content = (char*)malloc(size + 1);
    if (content == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    if (fread(content, 1, size, fp)!= size) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }

    content[size] = '\0';
    fclose(fp);

    return content;
}

// Function to beautify the HTML
void beautify_html(char *html)
{
    int i, j;
    char *buffer = NULL;
    char *start, *end, *tag, *line = NULL;

    // Split the HTML into lines
    line = strtok_r(html, "\n", &buffer);
    while (line!= NULL) {
        if (line[0] == '<' && line[1] == '/') {
            i = 2;
            while (line[i]!= '>') {
                i++;
            }
            line += i - 2;

            // Split the tag into start and end tags
            start = strtok_r(line, "/", &buffer);
            end = strtok_r(NULL, "/", &buffer);

            // Print the start tag
            printf("<!DOCTYPE html>\n");
            printf("<%s>\n", start);

            // Print the content
            printf("<p>\n");
            while (line!= NULL) {
                printf("%s", line);
                line = strtok_r(NULL, "\n", &buffer);
            }
            printf("</p>\n");

            // Print the end tag
            printf("</%s>\n", end);
        }
        else {
            printf("%s", line);
            line = strtok_r(NULL, "\n", &buffer);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *html = get_file_content(argv[1]);
    if (html == NULL) {
        fprintf(stderr, "Error reading file\n");
        exit(EXIT_FAILURE);
    }

    beautify_html(html);
    free(html);

    return 0;
}