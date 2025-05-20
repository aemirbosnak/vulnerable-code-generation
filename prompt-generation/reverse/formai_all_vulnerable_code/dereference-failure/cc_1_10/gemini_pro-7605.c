//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define HREF_SIZE 1024

typedef struct {
  char *href;
  char *text;
} Link;

typedef struct {
  size_t link_count;
  Link *links;
} Node;

typedef struct {
  size_t node_count;
  Node *nodes;
} Page;

Node *visit(char *url) {
  Node *node = malloc(sizeof(Node));
  node->link_count = 0;
  node->links = NULL;
  FILE *f = fopen(url, "r");
  if (!f) {
    perror("couldn't open file");
    exit(1);
  }
  char buf[HREF_SIZE];
  while (fscanf(f, "%s", buf) != EOF) {
    if (!strncmp(buf, "href=", 5)) {
      char *href = malloc(HREF_SIZE);
      strcpy(href, buf + 5);
      char *text = malloc(HREF_SIZE);
      fscanf(f, "%s", text);
      Link *link = malloc(sizeof(Link));
      link->href = href;
      link->text = text;
      node->links = realloc(node->links, sizeof(Link) * (node->link_count + 1));
      node->links[node->link_count++] = *link;
    }
  }
  fclose(f);
  return node;
}

Page *crawl(char *url) {
  Page *page = malloc(sizeof(Page));
  page->node_count = 0;
  page->nodes = NULL;
  page->nodes = realloc(page->nodes, sizeof(Node) * (page->node_count + 1));
  page->nodes[page->node_count++] = *visit(url);
  for (size_t i = 0; i < page->nodes[0].link_count; i++) {
    Link *link = &page->nodes[0].links[i];
    page->nodes = realloc(page->nodes, sizeof(Node) * (page->node_count + 1));
    page->nodes[page->node_count++] = *visit(link->href);
  }
  return page;
}

void print_page(Page *page) {
  for (size_t i = 0; i < page->node_count; i++) {
    Node *node = &page->nodes[i];
    printf("NODE %zu:\n", i);
    for (size_t j = 0; j < node->link_count; j++) {
      Link *link = &node->links[j];
      printf("  LINK %zu:\n", j);
      printf("    href: %s\n", link->href);
      printf("    text: %s\n", link->text);
    }
  }
}

void free_page(Page *page) {
  for (size_t i = 0; i < page->node_count; i++) {
    Node *node = &page->nodes[i];
    for (size_t j = 0; j < node->link_count; j++) {
      Link *link = &node->links[j];
      free(link->href);
      free(link->text);
    }
    free(node->links);
  }
  free(page->nodes);
  free(page);
}

int main() {
  Page *page = crawl("index.html");
  print_page(page);
  free_page(page);
  return 0;
}