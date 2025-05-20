//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100
#define INFINITY 999999

typedef struct cluster_node {
    int id;
    float x;
    float y;
    int cid;
} cluster_node;

int n;
cluster_node items[MAX];

float distance(cluster_node a, cluster_node b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int find_min_distance_cluster(cluster_node c[], int len, int k, float *min_dis) {
    int i, j;
    *min_dis = INFINITY;
    int idx1, idx2;
    for(i=0;i<len;i++) {
        for(j=i+1;j<len;j++) {
            float dis = distance(c[i], c[j]);
            if(dis < *min_dis) {
                idx1 = c[i].id;
                idx2 = c[j].id;
                *min_dis = dis;
            }
        }
    }
    int found = 0;
    for(i=0;i<n;i++) {
        if(items[i].id == idx1 || items[i].id == idx2) {
            c[found++]= items[i];
        }
    }
    return found;
}

void print_clusters(cluster_node c[], int k, float distance) {
    int i;
    printf("Cluster Details\n");
    for(i=0;i<k;i++) {
        printf("Cluster : %d\n", i+1);
        printf("Items: ");
        int j;
        for(j=0;j<n;j++) {
            if(items[j].cid == c[i].id) {
                printf("%d ", items[j].id);
            }
        }
        printf("\n");
        printf("Centroid: (%.2f, %.2f)\n\n", c[i].x, c[i].y);
    }
    printf("Total Distance: %f", distance);
}

float perform_clustering(cluster_node c[], int k) {
    int done = 0;
    int len = n;
    float total_distance = 0;
    while(!done) {
        float min_dis = INFINITY;
        int count = find_min_distance_cluster(c, len, k, &min_dis);
        if(count == k) {
            done = 1;
        }
        total_distance += min_dis;
        len = count;
    }
    return total_distance;
}

int main() {
    printf("Enter the number of items:\n");
    scanf("%d", &n);
    int i;
    for(i=0;i<n;i++) {
        printf("Enter item %d:\n", i+1);
        items[i].id = i+1;
        printf("Enter x:\n");
        scanf("%f", &items[i].x);
        printf("Enter y:\n");
        scanf("%f", &items[i].y);
        items[i].cid = i+1;
    }
    int k;
    printf("Enter the number of clusters:\n");
    scanf("%d", &k);

    cluster_node *c = (cluster_node *) malloc(k*sizeof(cluster_node));
    int j;
    for(i=0;i<k;i++) {
        printf("Enter the initial x,y values of cluster %d:\n", i+1);
        scanf("%f %f", &c[i].x, &c[i].y);
        c[i].id = i+1;
    }

    float distance = perform_clustering(c, k);
    print_clusters(c, k, distance);
    return 0;
}