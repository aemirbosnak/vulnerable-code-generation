//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
// In a realm where pixels dance and clusters whisper secrets

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A canvas woven with threads of data
typedef struct Pixel {
  double x, y;  // Coordinates in a surrealist dimension
} Pixel;

// A celestial body of clustered pixels
typedef struct Cluster {
  int size;  // The mass of the cluster
  Pixel* pixels;  // The pixels that form the constellation
} Cluster;

// An algorithm that transcends the boundaries of reason
void surrealCluster(Pixel* pixels, int n, Cluster** clusters, int* k) {
  // Paint the canvas with a cosmic brush
  for (int i = 0; i < n; i++) {
    // Each pixel, a shimmering star in the tapestry
    pixels[i].x = ((double)rand()) / RAND_MAX * 100;
    pixels[i].y = ((double)rand()) / RAND_MAX * 100;
  }

  // Summon a constellation of clusters
  *clusters = malloc(*k * sizeof(Cluster));

  // Each cluster, a vortex of swirling pixels
  for (int i = 0; i < *k; i++) {
    (*clusters)[i].size = 0;
    (*clusters)[i].pixels = malloc(n * sizeof(Pixel));
  }

  // The celestial dance begins
  for (int i = 0; i < n; i++) {
    double minDist = INFINITY;
    int closestCluster = -1;

    // The pixel searches for its celestial home
    for (int j = 0; j < *k; j++) {
      double dist = sqrt(pow(pixels[i].x - (*clusters)[j].pixels[0].x, 2) + pow(pixels[i].y - (*clusters)[j].pixels[0].y, 2));
      if (dist < minDist) {
        minDist = dist;
        closestCluster = j;
      }
    }
    // The pixel finds solace in its rightful cluster
    memcpy(&(*clusters)[closestCluster].pixels[(*clusters)[closestCluster].size++], &pixels[i], sizeof(Pixel));
  }

  // The cosmic tapestry is complete
  printf("The surreal clusters have emerged:\n");
  for (int i = 0; i < *k; i++) {
    printf("Cluster %d:\n", i + 1);
    for (int j = 0; j < (*clusters)[i].size; j++) {
      printf("(%lf, %lf)\n", (*clusters)[i].pixels[j].x, (*clusters)[i].pixels[j].y);
    }
  }
}

int main() {
  // The number of stars in the surreal sky
  int n = 100;

  // The number of celestial clusters
  int k = 5;

  // The canvas that holds the cosmic tapestry
  Pixel* pixels = malloc(n * sizeof(Pixel));

  // A celestial council of clusters
  Cluster* clusters;

  // Invoke the surreal clustering algorithm
  surrealCluster(pixels, n, &clusters, &k);

  return 0;
}