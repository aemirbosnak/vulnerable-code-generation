//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 15
#define MAX_NAME_LEN 10
#define MAX_LINE_LEN 100

struct node {
  char name[MAX_NAME_LEN];
  int edge_cnt;
  int edges[MAX_NODES];
};

struct node nodes[MAX_NODES];

int node_cnt;

int get_node_index(char *name) {
  int i;
  for (i = 0; i < node_cnt; i++) {
    if (strcmp(nodes[i].name, name) == 0) {
      return i;
    }
  }
  strcpy(nodes[node_cnt].name, name);
  nodes[node_cnt].edge_cnt = 0;
  return node_cnt++;
}

void add_edge(char *a, char *b) {
  int i, j;
  i = get_node_index(a);
  j = get_node_index(b);
  nodes[i].edges[nodes[i].edge_cnt++] = j;
  nodes[j].edges[nodes[j].edge_cnt++] = i;
}

void print_node_list() {
  int i, j;
  for (i = 0; i < node_cnt; i++) {
    printf("%s: ", nodes[i].name);
    for (j = 0; j < nodes[i].edge_cnt; j++) {
      printf("%s ", nodes[nodes[i].edges[j]].name);
    }
    printf("\n");
  }
}

int main() {
  char line[MAX_LINE_LEN];
  while (fgets(line, MAX_LINE_LEN, stdin)) {
    char *a, *b;
    a = strtok(line, " \n");
    b = strtok(NULL, " \n");
    add_edge(a, b);
  }
  print_node_list();
  return 0;
}