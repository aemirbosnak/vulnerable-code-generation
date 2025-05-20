//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// These values should be kept in sync with the corresponding
// enum values in html_beautify.h
enum {
  HTML_BEAUTIFY_DEFAULT,
  HTML_BEAUTIFY_UNESCAPE,
  HTML_BEAUTIFY_PRESERVE_NEWLINES,
  HTML_BEAUTIFY_USE_BR,
  HTML_BEAUTIFY_DISABLE_COMMENTS,
  HTML_BEAUTIFY_DISABLE_TAGS,
  HTML_BEAUTIFY_DISABLE_IDS,
  HTML_BEAUTIFY_DISABLE_CLASSES,
  HTML_BEAUTIFY_DISABLE_STYLES,
};

typedef struct {
  int unescape;
  int preserve_newlines;
  int use_br;
  int disable_comments;
  int disable_tags;
  int disable_ids;
  int disable_classes;
  int disable_styles;
} html_beautify_options_t;

char *html_beautify(const char *html, html_beautify_options_t options) {
  // ...
}

int main(void) {
  const char *html = "<html><body><h1>Hello, world!</h1></body></html>";
  html_beautify_options_t options = {
    .unescape = 0,
    .preserve_newlines = 0,
    .use_br = 0,
    .disable_comments = 0,
    .disable_tags = 0,
    .disable_ids = 0,
    .disable_classes = 0,
    .disable_styles = 0,
  };

  char *beautified_html = html_beautify(html, options);
  printf("%s\n", beautified_html);

  free(beautified_html);
  return 0;
}