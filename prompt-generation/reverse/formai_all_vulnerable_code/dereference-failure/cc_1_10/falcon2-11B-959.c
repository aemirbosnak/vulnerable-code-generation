//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 100
#define MAX_E 1000

int gcd(int a, int b) {
  return (b == 0)? a : gcd(b, a % b);
}

int main(void) {
  int V, E, I, J, C, T, U, A, B, G;
  int *adj;
  int *colors;

  V = MAX_V;
  E = MAX_E;
  adj = (int *) malloc(V * sizeof(int));
  colors = (int *) malloc(V * sizeof(int));

  scanf("%d %d", &V, &E);

  for (I = 0; I < V; I++) {
    adj[I] = 0;
    colors[I] = 0;
  }

  for (I = 0; I < E; I++) {
    scanf("%d %d", &J, &U);
    adj[J]++;
    adj[U]++;
  }

  for (I = 0; I < V; I++) {
    if (adj[I] == 0) {
      scanf("%d", &G);
      colors[I] = G;
    }
  }

  for (I = 0; I < V; I++) {
    for (J = 0; J < V; J++) {
      if (adj[I] > 0 && adj[J] > 0) {
        C = gcd(colors[I], colors[J]);
        if (C!= 0) {
          colors[I] /= C;
          colors[J] /= C;
          adj[I] -= C;
          adj[J] -= C;
          if (colors[I] == 0) {
            colors[I] = 1;
          }
          if (colors[J] == 0) {
            colors[J] = 1;
          }
          if (colors[I] == colors[J]) {
            printf("Impossible\n");
            return 0;
          }
        }
      }
    }
  }

  for (I = 0; I < V; I++) {
    if (colors[I] == 0) {
      printf("Impossible\n");
      return 0;
    }
  }

  for (I = 0; I < V; I++) {
    printf("%d\n", colors[I]);
  }

  free(adj);
  free(colors);

  return 0;
}