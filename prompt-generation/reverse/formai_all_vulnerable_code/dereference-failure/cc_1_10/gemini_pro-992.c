//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Linker is a grumpy old lady who doesn't know how to accept arguments from command line
// So we're gonna use our own linker, the ol' fashioned way!
int main(int argc, const char *argv[]) {
  int i;
  char *args[argc + 1];
  for (i = 0; i < argc; i++) {
    args[i] = (char *)malloc(sizeof(argv[i]));
    strcpy(args[i], argv[i]);
  }
  args[argc] = NULL;

  // Welcome to the wild, wild West!
  int numVertices, numEdges;
  printf("Howdy, partner! How many varmints we talkin' 'bout? (Vertices): ");
  scanf("%d", &numVertices);
  printf("And how many dusty trails we got between 'em? (Edges): ");
  scanf("%d", &numEdges);

  // Allocate enough space for all the cowboys and their horses
  int **graph = malloc(sizeof(int *) * numVertices);
  for (i = 0; i < numVertices; i++) {
    graph[i] = malloc(sizeof(int) * numVertices);
  }

  // Lets fill up this ghost town with some saloons, banks and sheriffs' offices!
  int j, k, weight;
  for (i = 0; i < numEdges; i++) {
    printf("Tell me about the %dth trail, buckaroo!\n", i + 1);
    printf("From which saloon? (Vertex 1): ");
    scanf("%d", &j);
    printf("To which bank? (Vertex 2): ");
    scanf("%d", &k);
    printf("How many pesos does it cost to get there?: ");
    scanf("%d", &weight);
    graph[j][k] = weight;
    graph[k][j] = weight; // Our trails are two-way, no one-horse towns here!
  }

  // Time to print out our map of this spaghetti western!
  printf("\nGet ready for a wild ride, folks!\n");
  printf("----------------------------------------------\n");
  for (i = 0; i < numVertices; i++) {
    printf("%d | ", i);
    for (j = 0; j < numVertices; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
  printf("----------------------------------------------\n");

  // Cleanup time! Let's put those horses back in the stables
  for (i = 0; i < numVertices; i++) {
    free(graph[i]);
  }
  free(graph);

  // Pack up your six-shooters, folks! We're outta here!
  for (i = 0; i < argc; i++) {
    free(args[i]);
  }
  return 0;
}