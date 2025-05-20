//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Romeo and Juliet
// Romeo and Juliet Clustering Algorithm Implementation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cluster Cluster;
struct Cluster {
    int id;
    char name[20];
    int x;
    int y;
    Cluster *next;
};

int distance(Cluster *a, Cluster *b){
    return ((a->x - b->x) * (a->x - b->x)) + ((a->y - b->y) * (a->y - b->y));
}

Cluster *create_cluster(int id, char name[20], int x, int y){
    Cluster *cluster = (Cluster*) malloc(sizeof(Cluster));
    cluster->id = id;
    strcpy(cluster->name, name);
    cluster->x = x;
    cluster->y = y;
    cluster->next = NULL;
    return cluster;
}

void append_cluster(Cluster **head, Cluster *new_cluster){
    if (*head == NULL){
        *head = new_cluster;
        return;
    }
    Cluster *temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_cluster;
}

Cluster *find_closest_cluster(Cluster *clusters, int num_clusters, Cluster *current_cluster){
    Cluster *closest_cluster = NULL;
    int min_distance = 9999999;
    for (int i = 0; i < num_clusters; i++){
        Cluster *cluster = &clusters[i];
        if (cluster->id != current_cluster->id){
            int dist = distance(cluster, current_cluster);
            if (dist < min_distance){
                min_distance = dist;
                closest_cluster = cluster;
            }
        }
    }
    return closest_cluster;
}

void print_clusters(Cluster *clusters){
    Cluster *temp = clusters;
    while (temp != NULL){
        printf("Cluster %d '%s' at (%d, %d)\n", temp->id, temp->name, temp->x, temp->y);
        temp = temp->next;
    }
}

int main(){
    // Initialize clusters
    Cluster *clusters = NULL;
    append_cluster(&clusters, create_cluster(1, "Romeo", 3, 7));
    append_cluster(&clusters, create_cluster(2, "Juliet", 8, 4));
    append_cluster(&clusters, create_cluster(3, "Tybalt", 4, 2));
    append_cluster(&clusters, create_cluster(4, "Mercutio", 9, 6));
    append_cluster(&clusters, create_cluster(5, "Benvolio", 5, 8));
    append_cluster(&clusters, create_cluster(6, "Capulet", 2, 3));
    append_cluster(&clusters, create_cluster(7, "Montague", 7, 9));

    int num_clusters = 7;

    // Run clustering algorithm
    while (num_clusters > 1){
        Cluster *closest_cluster = NULL;
        int min_distance = 9999999;
        Cluster *curr_cluster = clusters;
        while (curr_cluster != NULL){
            Cluster *closest = find_closest_cluster(clusters, num_clusters, curr_cluster);
            if (distance(curr_cluster, closest) < min_distance){
                min_distance = distance(curr_cluster, closest);
                closest_cluster = curr_cluster;
            }
            curr_cluster = curr_cluster->next;
        }
        Cluster *second_closest = find_closest_cluster(clusters, num_clusters, closest_cluster);
        printf("Methinks '%s' and '%s' are star-crossed clusters, and thus shall be merged...\n", closest_cluster->name, second_closest->name);
        closest_cluster->x = (closest_cluster->x + second_closest->x) / 2;
        closest_cluster->y = (closest_cluster->y + second_closest->y) / 2;
        strcat(closest_cluster->name, second_closest->name);
        closest_cluster->next = second_closest->next;
        free(second_closest);
        num_clusters--;
        printf("The new cluster is formed: '%s'\n", closest_cluster->name);
        print_clusters(clusters);
    }

    return 0;
}