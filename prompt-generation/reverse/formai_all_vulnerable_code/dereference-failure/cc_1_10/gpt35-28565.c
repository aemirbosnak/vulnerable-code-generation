//FormAI DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

struct graph {
   int num_vertices;
   int **matrix;
};

struct thread_data {
   int thread_id;
   struct graph g;
};

void *printGraph(void *threadarg) {
   struct thread_data *my_data;
   int i, j;

   my_data = (struct thread_data *) threadarg;

   for (i = 0; i < my_data->g.num_vertices; i++) {
      for (j = i + 1; j < my_data->g.num_vertices; j++) {
         if (my_data->g.matrix[i][j] == 1) {
            printf("Thread %ld: Edge between vertex %d and vertex %d\n", my_data->thread_id, i, j);
         }
      }
   }

   pthread_exit(NULL);
}

int main (int argc, char *argv[]) {
   int i, j;
   pthread_t threads[NUM_THREADS];
   struct thread_data thread_data_array[NUM_THREADS];
   struct graph g;

   //initialize graph
   g.num_vertices = 6;
   g.matrix = (int **) malloc(g.num_vertices*sizeof(int *));
   for (i = 0; i < g.num_vertices; i++) {
      g.matrix[i] = (int *) malloc(g.num_vertices*sizeof(int));
      for (j = 0; j < g.num_vertices; j++) {
         g.matrix[i][j] = 0;
      }
   }
   g.matrix[0][1] = 1;
   g.matrix[0][2] = 1;
   g.matrix[1][3] = 1;
   g.matrix[2][4] = 1;
   g.matrix[3][5] = 1;
   g.matrix[4][5] = 1;

   //create threads
   for (i = 0; i < NUM_THREADS; i++) {
      thread_data_array[i].thread_id = i;
      thread_data_array[i].g = g;
      pthread_create(&threads[i], NULL, printGraph, (void *) &thread_data_array[i]);
   }

   //wait for threads to finish
   for (i = 0; i < NUM_THREADS; i++) {
      pthread_join(threads[i], NULL);
   }

   //free memory
   for (i = 0; i < g.num_vertices; i++) {
      free(g.matrix[i]);
   }
   free(g.matrix);

   pthread_exit(NULL);
}