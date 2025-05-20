//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the longest common substring
int lcs(char *s1, char *s2)
{
    int m = strlen(s1);
    int n = strlen(s2);
    int lcs[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = 0;
        }
    }
    return lcs[m][n];
}

// Function to summarize the text
char *summarize(char *text, int k)
{
    // Tokenize the text
    char *tokens[100];
    int numTokens = 0;
    char *token = strtok(text, " ");
    while (token != NULL)
    {
        tokens[numTokens++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the similarity between each pair of tokens
    int similarity[numTokens][numTokens];
    for (int i = 0; i < numTokens; i++)
    {
        for (int j = i + 1; j < numTokens; j++)
        {
            similarity[i][j] = lcs(tokens[i], tokens[j]);
        }
    }

    // Find the k most similar pairs of tokens
    int mostSimilarPairs[k][2];
    for (int i = 0; i < k; i++)
    {
        int maxSimilarity = 0;
        int maxI = -1;
        int maxJ = -1;
        for (int j = 0; j < numTokens; j++)
        {
            for (int l = j + 1; l < numTokens; l++)
            {
                if (similarity[j][l] > maxSimilarity)
                {
                    maxSimilarity = similarity[j][l];
                    maxI = j;
                    maxJ = l;
                }
            }
        }
        mostSimilarPairs[i][0] = maxI;
        mostSimilarPairs[i][1] = maxJ;
        similarity[maxI][maxJ] = -1;
    }

    // Generate the summary
    char *summary = (char *)malloc(1000);
    summary[0] = '\0';
    for (int i = 0; i < k; i++)
    {
        strcat(summary, tokens[mostSimilarPairs[i][0]]);
        strcat(summary, " ");
        strcat(summary, tokens[mostSimilarPairs[i][1]]);
        strcat(summary, " ");
    }

    return summary;
}

int main()
{
    // Get the text from the user
    char text[1000];
    printf("Enter the text to be summarized: ");
    gets(text);

    // Get the number of sentences to include in the summary
    int k;
    printf("Enter the number of sentences to include in the summary: ");
    scanf("%d", &k);

    // Summarize the text
    char *summary = summarize(text, k);

    // Print the summary
    printf("Summary: %s\n", summary);

    return 0;
}