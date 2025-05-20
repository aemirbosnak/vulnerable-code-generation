//FormAI DATASET v1.0 Category: Graph representation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Graph Party!\n");

  printf("   o\n");
  printf("  /|\\                ,\n");
  printf("  //\\               ((\n");
  printf("  V  \\        /(\\/)\n");
  printf("       \\  //\\/  _/^\n");
  printf("        \\/^/   \\/\n");
  printf("           \\   / \n");

  printf("Here we graph everything but our emotions.\n");
  printf("Let's represent a graph using C code!\n");

  int vertices = 5, edges = 7;
  printf("We have %d vertices and %d edges.\n", vertices, edges);

  // creating the graph matrix
  int **graph = (int**)malloc(vertices * sizeof(int*));
  for(int i = 0; i < vertices; i++) {
    graph[i] = (int*)malloc(vertices * sizeof(int));
    for(int j = 0; j < vertices; j++) {
      graph[i][j] = 0;
    }
  }

  graph[0][1] = 1;
  graph[1][2] = 1;
  graph[2][3] = 1;
  graph[3][4] = 1;
  graph[4][0] = 1;
  graph[1][3] = 1;
  graph[3][1] = 1;

  printf("Our graph matrix looks like this:\n");
  for(int i = 0; i < vertices; i++) {
    for(int j = 0; j < vertices; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }

  printf("Wow, that's a lot of numbers. Let's make this graph look pretty!\n");

  printf("      _____\n");
  printf("     /     \\\n");
  printf("    /       \\\n");
  printf("   /         \\\n");
  printf("  /     2     \\\n");
  printf("  \\           /\n");
  printf("   \\  1   3  /\n");
  printf("    |       |\n");
  printf("  __|__4____|___\n");
  printf("  \\         /\n");
  printf("   \\  5   6  /\n");
  printf("    |       |\n");
  printf("    \\_______/\n");

  printf("Ah, so much better!\n");

  printf("Thanks for coming to the Graph Party! Don't forget to bring your graphing calculator next time!\n");

  // freeing memory
  for(int i = 0; i < vertices; i++) {
    free(graph[i]);
  }
  free(graph);

  return 0;
}