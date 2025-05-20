//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: lively
#include <stdio.h>
#include <math.h>

int main() {
  int n;
  printf("Enter the number of points: ");
  scanf("%d", &n);
  
  // populate the points array
  int points[n][2];
  printf("Enter the coordinates of each point (x, y):\n");
  for (int i = 0; i < n; i++) {
    printf("Point %d: ", i+1);
    scanf("%d %d", &points[i][0], &points[i][1]);
  }
  
  // find the convex hull
  int upper_hull[n], lower_hull[n], count_upper = 0, count_lower = 0;
  
  // sort the points by x-coordinate
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      if (points[i][0] > points[j][0]) {
        // swap
        int temp_x = points[i][0];
        int temp_y = points[i][1];
        points[i][0] = points[j][0];
        points[i][1] = points[j][1];
        points[j][0] = temp_x;
        points[j][1] = temp_y;
      }
    }
  }
  
  // find the upper hull
  for (int i = 0; i < n; i++) {
    while (count_upper >= 2 &&
           ((points[upper_hull[count_upper-1]][1] - points[upper_hull[count_upper-2]][1]) *
            (points[i][0] - points[upper_hull[count_upper-2]][0])) -
           ((points[i][1] - points[upper_hull[count_upper-2]][1]) *
            (points[upper_hull[count_upper-1]][0] - points[upper_hull[count_upper-2]][0])) <= 0) {
      count_upper--;
    }
    upper_hull[count_upper++] = i;
  }
  
  // find the lower hull
  for (int i = n-1; i >= 0; i--) {
    while (count_lower >= 2 &&
           ((points[lower_hull[count_lower-1]][1] - points[lower_hull[count_lower-2]][1]) *
            (points[i][0] - points[lower_hull[count_lower-2]][0])) -
           ((points[i][1] - points[lower_hull[count_lower-2]][1]) *
            (points[lower_hull[count_lower-1]][0] - points[lower_hull[count_lower-2]][0])) <= 0) {
      count_lower--;
    }
    lower_hull[count_lower++] = i;
  }
  
  // print the convex hull
  printf("The convex hull is:\n");
  for (int i = 0; i < count_upper-1; i++) {
    printf("(%d, %d) ", points[upper_hull[i]][0], points[upper_hull[i]][1]);
  }
  for (int i = 0; i < count_lower-1; i++) {
    printf("(%d, %d) ", points[lower_hull[i]][0], points[lower_hull[i]][1]);
  }
  printf("\n");
  
  return 0;
}