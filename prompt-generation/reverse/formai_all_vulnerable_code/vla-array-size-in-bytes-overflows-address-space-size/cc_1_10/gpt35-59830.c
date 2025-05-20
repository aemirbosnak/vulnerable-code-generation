//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surprised
#include <stdio.h>

int main() {
  printf("Surprise! I've written a C Clustering Algorithm Implementation!\n");
  printf("This program will take in a dataset of numbers and cluster them into groups.\n");

  int n;
  printf("Enter the number of data points in the dataset:\n");
  scanf("%d", &n);

  float data[n];
  float clusters[5]; // We'll cluster the data into 5 groups for simplicity's sake

  printf("Enter the data points in the dataset:\n");
  for (int i = 0; i < n; i++) {
    scanf("%f", &data[i]);
  }

  // Let's initialize the clusters as the first 5 data points in the dataset
  for (int i = 0; i < 5; i++) {
    clusters[i] = data[i];
  }

  // Now let's iterate through the remaining data points and assign them to the closest cluster
  for (int i = 5; i < n; i++) {
    int closest_cluster = 0;
    float closest_distance = fabs(data[i] - clusters[0]);

    for (int j = 1; j < 5; j++) {
      float distance = fabs(data[i] - clusters[j]);

      if (distance < closest_distance) {
        closest_cluster = j;
        closest_distance = distance;
      }
    }

    // Add the data point to the closest cluster
    clusters[closest_cluster] = (clusters[closest_cluster] + data[i]) / 2;
  }

  // Now let's print out the clusters
  printf("The clusters are:\n");
  for (int i = 0; i < 5; i++) {
    printf("%f ", clusters[i]);
  }
  printf("\n");

  return 0;
}