//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

// Function to analyze sentiment of a sentence
int analyzeSentiment(char* sentence) {
    char* token = strtok(sentence, " ");
    int count = 0;
    
    while (token!= NULL) {
        if (strcmp(token, "positive") == 0) {
            count++;
        } else if (strcmp(token, "negative") == 0) {
            count--;
        }
        token = strtok(NULL, " ");
    }
    
    return count;
}

// Function to get the sentiment score of a file
int getSentimentScore(const char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    char* buffer = NULL;
    ssize_t bytesRead = read(fd, buffer, 100);
    if (bytesRead == -1) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }
    
    int score = 0;
    for (int i = 0; i < bytesRead; i++) {
        char* token = strtok(buffer + i, "\n");
        if (token!= NULL) {
            score += analyzeSentiment(token);
        }
    }
    
    free(buffer);
    close(fd);
    
    return score;
}

// Main function
int main() {
    const char* filename = "input.txt";
    int sentimentScore = getSentimentScore(filename);
    
    printf("Sentiment score: %d\n", sentimentScore);
    
    return 0;
}