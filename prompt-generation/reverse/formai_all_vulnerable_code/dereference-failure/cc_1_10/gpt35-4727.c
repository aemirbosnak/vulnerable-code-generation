//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function to calculate the minimum of three values
int minimum(int a,int b,int c){
    return a<b ? (a<c ? a : c) : (b<c ? b : c);
}

// Function to calculate the Levenshtein distance
int levenshtein_distance(char *s1, char *s2){
    int len1=strlen(s1);
    int len2=strlen(s2);
    
    // allocate memory for 2D array
    int **dist = (int **)malloc((len1 + 1) * sizeof(int *));
    for(int i=0;i<=(len1+1);i++)
        dist[i] = (int *)malloc((len2 + 1) * sizeof(int));
    
    // initialising the first row and first column
    for (int i = 0; i <= len1; i++) 
        dist[i][0] = i;
    for (int j = 0; j <= len2; j++) 
        dist[0][j] = j;
  
    // calculating the Levenshtein distance
    for (int i = 1; i <= len1; i++){
        for (int j = 1; j <= len2; j++){
            if (s1[i-1] == s2[j-1]){
                dist[i][j] = dist[i-1][j-1];
            }
            else{
                dist[i][j] = 1 + minimum(dist[i][j-1],dist[i-1][j],dist[i-1][j-1]);
            }
        }
    }
    
    // storing the Levenshtein distance
    int result=dist[len1][len2];
  
    // cleanup the memory
    for(int i=0;i<=(len1+1);i++){
        free(dist[i]);
    }
    free(dist);
  
    return result;
}

//main function
int main(){
    char s1[100],s2[100];
  
    //taking input of two strings
    printf("Enter string1:\n");
    scanf("%s",s1);
    printf("Enter string2:\n");
    scanf("%s",s2);
    
    //calculate distance
    int distance = levenshtein_distance(s1,s2);
    
    printf("Levenshtein Distance between %s and %s is %d\n",s1,s2,distance);
    return 0;
}