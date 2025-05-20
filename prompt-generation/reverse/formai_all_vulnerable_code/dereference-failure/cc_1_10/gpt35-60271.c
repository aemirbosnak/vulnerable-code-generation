//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c){
    int min = a;
    if(b < min){
        min = b;
    }
    if(c < min){
        min = c;
    }
    return min;
}

// Function to calculate Levenshtein distance between two words
int levenshtein_distance(char* word1, char* word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int cost;

    // Create a 2D array to store the distances
    int** distance = (int**)malloc((len1 + 1) * sizeof(int*));
    for(int i = 0; i <= len1; i++){
        distance[i] = (int*)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix
    for(int i = 0; i <= len1; i++){
        distance[i][0] = i;
    }
    for(int j = 0; j <= len2; j++){
        distance[0][j] = j;
    }

    // Iterate through the matrix and calculate the distances
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            cost = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1, distance[i][j - 1] + 1, distance[i - 1][j - 1] + cost);
        }
    }

    // Save the final distance and free the memory used by the matrix
    int final_distance = distance[len1][len2];
    for(int i = 0; i <= len1; i++){
        free(distance[i]);
    }
    free(distance);

    return final_distance;
}

int main(){
    // Test the Levenshtein distance calculator with some example words
    char* word1 = "kitten";
    char* word2 = "sitting";
    int distance = levenshtein_distance(word1, word2);

    printf("The Levenshtein distance between %s and %s is %d.", word1, word2, distance);

    return 0;
}