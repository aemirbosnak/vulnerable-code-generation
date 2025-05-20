//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *text;
  int len;
} HtmlElement;

typedef struct {
  HtmlElement **elements;
  int num_elements;
} HtmlDocument;

void print_html_document(HtmlDocument *doc) {
  for (int i = 0; i < doc->num_elements; i++) {
    printf("%s", doc->elements[i]->text);
  }
}

void free_html_document(HtmlDocument *doc) {
  for (int i = 0; i < doc->num_elements; i++) {
    free(doc->elements[i]->text);
    free(doc->elements[i]);
  }
  free(doc->elements);
  free(doc);
}

HtmlDocument *beautify_html(char *html) {
  HtmlDocument *doc = malloc(sizeof(HtmlDocument));
  doc->num_elements = 0;
  doc->elements = NULL;
  
  char *start = html;
  char *end = strchr(html, '>');
  while (end != NULL) {
    int len = end - start + 1;
    char *text = malloc(len);
    strncpy(text, start, len);
    text[len - 1] = '\0';
    
    HtmlElement *element = malloc(sizeof(HtmlElement));
    element->text = text;
    element->len = len;
    
    doc->elements = realloc(doc->elements, (doc->num_elements + 1) * sizeof(HtmlElement *));
    doc->elements[doc->num_elements++] = element;
    
    start = end + 1;
    end = strchr(start, '>');
  }
  
  return doc;
}

int main() {
  char *html = "<html><head><title>A Majestic Tapestry</title></head><body><h1>Behold, the Beauty of Imagination</h1><p>Code, like a whimsical dance, weaves its magic on the screen.</p></body></html>";
  HtmlDocument *doc = beautify_html(html);
  print_html_document(doc);
  free_html_document(doc);
  
  return 0;
}