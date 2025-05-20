//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 1000

typedef struct {
    char *url;
    int depth;
} Link;

void print_links(Link *links, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s (depth %d)\n", links[i].url, links[i].depth);
    }
}

void scrape_page(char *url, int depth, Link **links, int *n_links) {
    char *html = malloc(1000000); // Allocate 1MB for HTML content
    FILE *fp = fopen(url, "r");
    if (fp == NULL) {
        printf("Error: Could not open %s\n", url);
        return;
    }
    fread(html, 1, 1000000, fp); // Read up to 1MB of HTML content
    fclose(fp);

    char *pos = strstr(html, "<a href=");
    while (pos!= NULL) {
        pos += 9; // Skip "<a href="
        char *end = strchr(pos, '"');
        if (end == NULL) {
            printf("Warning: Invalid link found in %s\n", url);
            return;
        }
        *end = '\0';
        char *link = malloc(end - pos + 1);
        strncpy(link, pos, end - pos);
        link[end - pos] = '\0';
        Link l = {link, depth + 1};
        if (*n_links >= MAX_DEPTH) {
            printf("Warning: Maximum depth of %d reached\n", MAX_DEPTH);
            return;
        }
        (*links)[*n_links] = l;
        (*n_links)++;
        pos = strstr(pos, "<a href=");
    }
    free(html);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }
    char *url = argv[1];
    Link *links = malloc(MAX_DEPTH * sizeof(Link));
    int n_links = 0;
    scrape_page(url, 0, links, &n_links);
    print_links(links, n_links);
    free(links);
    return 0;
}