//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Romeo and Juliet
#include <stdio.h> 

/*
  Rosaline's Clustering Algorithm Implementation
*/

int main() 
{ 
    int num_points, num_clusters; 
    printf("O Romeo, give me thy number of points: "); 
    scanf("%d", &num_points); 
    printf("Fair Juliet, give me thy number of clusters: "); 
    scanf("%d", &num_clusters);

    int points[num_points], clusters[num_clusters]; 
    int i, j, k; 
    printf("O Romeo, give me thy points: \n"); 
    for(i=0; i<num_points; i++)
        scanf("%d", &points[i]); 

    int sum = 0, avg = 0; 
    printf("O Romeo, let's cluster the points: \n"); 

    for(i=0; i<num_clusters-1; i++)
    {
        printf("O Romeo, let's cluster #%d: \n", i+1); 
        for(j=0; j<=num_points/num_clusters; j++)
        {
            clusters[i] = points[j];
            printf("Thy point %d to cluster %d\n", points[j], i+1); 
            sum += points[j];
        }
        avg = sum/(j-1);
        printf("O Romeo, the average of cluster #%d is %d: \n", i+1, avg);
        sum = 0;
    }

    printf("O Romeo, let's cluster #%d: \n", i+1); 
    for(k=j-1; k<num_points; k++)
    {
        clusters[i] = points[k];
        printf("Thy point %d to cluster %d\n", points[k], i+1); 
        sum += points[k];
    }
    avg = sum/(k-j+1); 
    printf("O Romeo, the average of cluster #%d is %d: \n", i+1, avg);

    printf("Farewell Romeo! Our clustering algorithm has come to an end."); 
    return 0; 
}