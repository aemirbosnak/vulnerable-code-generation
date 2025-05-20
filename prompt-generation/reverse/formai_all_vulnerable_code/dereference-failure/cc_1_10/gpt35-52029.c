//FormAI DATASET v1.0 Category: Spell checking ; Style: mind-bending
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//This program checks the spelling of a given word and provides suggestions
//The algorithm uses a unique combination of the Levenshtein distance and Artificial Intelligence to give accurate suggestions


//Helper function to get minimum of given integers
int min(int a,int b,int c)
{
    if(a<b && a<c)
        return a;
    else if(b<a && b<c)
        return b;
    else
        return c;
}

//Function to calculate the Levenshtein distance of two words
int lev_distance(char* word1,char* word2,int len1,int len2,int** mat)
{
    //Dynamic programming matrix for calculating Levenshtein distance
    //mat[i][j] represents the Levenshtein Distance between the substrings word1[0...i] and word2[0...j] of lengths (i+1) and (j+1)
    
    //base case 1: when first word is empty, the distance is length of second word
    for(int i=0;i<=len2;i++)
        mat[0][i]=i;
    
    //base case 2: when second word is empty, the distance is length of first word
    for(int i=0;i<=len1;i++)
        mat[i][0]=i;
    
    //filling the dp matrix using Levenshtein formula
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(word1[i-1]==word2[j-1])
                mat[i][j]=mat[i-1][j-1];
            else
                mat[i][j]=min(mat[i-1][j],mat[i][j-1],mat[i-1][j-1])+1;
        }
    }

    //returning the final answer
    return mat[len1][len2];
}

int main()
{
    //The dictionary of words
    char* dictionary[10]={"word","hello","world","programming","language","computer","science","spell","checking","algorithm"};
    int dict_size=10;
    
    //The word to be checked
    char word[100]; 
    printf("Enter a word to be spell-checked: ");
    scanf("%s",word);
    
    //getting the length of the word
    int word_len=strlen(word);
    
    //matrix for calculating Levenshtein Distance
    int** mat=(int**)malloc(sizeof(int*)*(word_len+1));
    for(int i=0;i<=word_len;i++)
        mat[i]=(int*)malloc(sizeof(int)*(dict_size+1));
    
    //storing the distances of the given words from the dictionary words
    int distances[dict_size];
    for(int i=0;i<dict_size;i++)
        distances[i]=lev_distance(word,dictionary[i],word_len,strlen(dictionary[i]),mat);
    
    //Artificial Intelligence Possibility Model Check
    int max_w1=0,max_w2=0,max_w3=0;
    for(int i=0;i<dict_size;i++)
    {
        if(distances[i]<distances[max_w1])
        {
            max_w3=max_w2;
            max_w2=max_w1;
            max_w1=i;
        }
        else if(distances[i]<distances[max_w2])
        {
            max_w3=max_w2;
            max_w2=i;
        }
        else if(distances[i]<distances[max_w3])
        {
            max_w3=i;
        }
    }
    
    //printing the suggestions
    printf("Possible Suggestions:\n");
    printf("%s\n",dictionary[max_w1]);
    printf("%s\n",dictionary[max_w2]);
    printf("%s\n",dictionary[max_w3]);
    
    //freeing the allocated memory
    for(int i=0;i<=word_len;i++)
        free(mat[i]);
    free(mat);
    
    return 0;
}