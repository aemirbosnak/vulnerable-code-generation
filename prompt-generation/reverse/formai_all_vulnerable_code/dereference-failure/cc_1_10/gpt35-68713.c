//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define DISTANCE_BUFFER_SIZE 1000000

char *str1, *str2;
int len1, len2;
int dist_buff_ptr;
int distance_buffer[DISTANCE_BUFFER_SIZE];

int get_distance(int i, int j) {
    int index = i*len2 + j;
    if(distance_buffer[index] != -1) {
        return distance_buffer[index];
    }
    if(i == 0) {
        distance_buffer[index] = j;
    }
    else if(j == 0) {
        distance_buffer[index] = i;
    }
    else if(str1[i-1] == str2[j-1]) {
        distance_buffer[index] = get_distance(i-1, j-1);
    }
    else {
        int dist1 = get_distance(i-1, j) + 1;
        int dist2 = get_distance(i, j-1) + 1;
        int dist3 = get_distance(i-1, j-1) + 1;
        int min = (dist1 < dist2) ? dist1 : dist2;
        min = (min < dist3) ? min : dist3;
        distance_buffer[index] = min;
    }
    return distance_buffer[index];
}

int main() {

    str1 = (char *)malloc(MAX_LEN * sizeof(char));
    str2 = (char *)malloc(MAX_LEN * sizeof(char));

    printf("Enter the first string: ");
    fgets(str1, MAX_LEN, stdin);
    str1[strcspn(str1, "\n")] = 0; // remove \n character
    printf("Enter the second string: ");
    fgets(str2, MAX_LEN, stdin);
    str2[strcspn(str2, "\n")] = 0; // remove \n character

    len1 = strlen(str1);
    len2 = strlen(str2);

    // Initialize distance buffer to -1
    for(int i=0; i<len1+1; i++) {
        for(int j=0; j<len2+1; j++) {
            distance_buffer[i*len2 + j] = -1;
        }
    }

    int distance = get_distance(len1, len2);

    printf("Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);

    free(str1);
    free(str2);

    return 0;
}