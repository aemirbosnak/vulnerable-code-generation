//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to calculate the mean of an array of data
double calcMean(double data[], int n) {
    double sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

// Function to calculate the standard deviation of an array of data
double calcSD(double data[], int n, double mean) {
    double sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += pow(data[i] - mean, 2);
    }
    return sqrt(sum / n);
}

int main()
{
    // Define a sample data set of text reviews and associated sentiment values
    char *reviews[] = {"This was a great experience", "I'd never use this product again", 
                       "The service was terrible", "I love this place", 
                       "The food was excellent", "The staff were not helpful",
                       "I would highly recommend this hotel", "I was very disappointed with my stay",
                       "The movie was amazing", "I wouldn't waste my time watching it again"};
    int sentiment[] = {1, -1, -1, 1, 1, -1, 1, -1, 1, -1};

    // Calculate the total number of reviews
    int n = sizeof(reviews) / sizeof(reviews[0]);

    // Calculate the mean sentiment
    double mean = calcMean(sentiment, n);
    
    // Calculate the standard deviation of sentiment
    double sd = calcSD(sentiment, n, mean);

    // Print out the mean and standard deviation of sentiment
    printf("Mean sentiment: %f\n", mean);
    printf("Standard deviation: %f\n", sd);

    // Loop through each review and calculate its z-score
    int i;
    double zscore;
    for (i = 0; i < n; i++) {
        zscore = (sentiment[i] - mean) / sd;
        printf("Review: %s\nSentiment: %d\nZ-score: %f\n\n", reviews[i], sentiment[i], zscore);
    }

    return 0;
}