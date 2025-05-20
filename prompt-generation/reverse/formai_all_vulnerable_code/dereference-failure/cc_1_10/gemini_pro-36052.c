//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

char *html_tags[] = {"html", "head", "body", "p", "h1", "h2", "h3", "h4", "h5", "h6", "ul", "ol", "li", "a", "img", "div", "span", "table", "tr", "td", "th", "form", "input", "button", "select", "option", "textarea"};

int is_html_tag(char *str) {
  for (int i = 0; i < sizeof(html_tags) / sizeof(char *); i++) {
    if (strcmp(str, html_tags[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

void beautify_html(char *html) {
  int depth = 0;
  char *line = strtok(html, "\n");
  while (line) {
    for (int i = 0; i < depth; i++) {
      printf("  ");
    }
    if (is_html_tag(line)) {
      printf("<%s>", line);
      depth++;
    } else if (strncmp(line, "</", 2) == 0) {
      depth--;
      printf("%s>", line);
    } else {
      printf("%s", line);
    }
    printf("\n");
    line = strtok(NULL, "\n");
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <html>\n", argv[0]);
    return 1;
  }

  char *html = malloc(MAX_LINE_LEN * 100);
  if (!html) {
    fprintf(stderr, "Error: malloc failed\n");
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (!fp) {
    fprintf(stderr, "Error: fopen failed\n");
    return 1;
  }

  while (fgets(html, MAX_LINE_LEN * 100, fp)) {
    beautify_html(html);
  }

  fclose(fp);
  free(html);

  return 0;
}