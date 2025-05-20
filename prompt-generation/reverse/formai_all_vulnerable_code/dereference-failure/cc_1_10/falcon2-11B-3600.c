//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read email data from file and convert it to lowercase
char* readEmail(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* buf = malloc((size+1)*sizeof(char));
    fread(buf, size, 1, fp);
    fclose(fp);

    char* result = strdup(buf);
    for (int i=0; i<strlen(result); i++) {
        result[i] = tolower(result[i]);
    }

    return result;
}

// Function to split email data into words
void splitEmail(char* email, char** words) {
    char* word = strtok(email, " ");
    int count = 0;

    while (word!= NULL) {
        words[count] = word;
        count++;
        word = strtok(NULL, " ");
    }
}

// Function to find the frequency of each word in the email data
void countWordFrequency(char* email, int length, int* freq) {
    char* word = strtok(email, " ");
    int count = 0;

    while (word!= NULL) {
        if (strlen(word) > 0) {
            freq[count]++;
        }
        word = strtok(NULL, " ");
        count++;
    }
}

// Function to count the number of words in each email
int countWordsInEmail(char* email, int length) {
    char* word = strtok(email, " ");
    int count = 0;

    while (word!= NULL) {
        if (strlen(word) > 0) {
            count++;
        }
        word = strtok(NULL, " ");
    }

    return count;
}

// Function to compare the frequency of each word in each email and determine if it is spam or not
int isSpam(int* freq1, int length1, int* freq2, int length2) {
    int count = 0;

    for (int i=0; i<length1; i++) {
        if (freq1[i] > freq2[i]) {
            count++;
        }
    }

    return count;
}

// Main function
int main() {
    char** emails = malloc(1000*sizeof(char*));
    int numEmails = 0;

    // Read email data from file
    char* email1 = readEmail("email1.txt");
    char* email2 = readEmail("email2.txt");

    // Split email data into words
    splitEmail(email1, emails);
    splitEmail(email2, emails);

    // Count word frequency
    countWordFrequency(email1, strlen(email1), emails[0]);
    countWordFrequency(email2, strlen(email2), emails[1]);

    // Count number of words in each email
    int wordCount1 = countWordsInEmail(email1, strlen(email1));
    int wordCount2 = countWordsInEmail(email2, strlen(email2));

    // Compare frequency of each word and determine if it is spam or not
    int result = isSpam(emails[0], wordCount1, emails[1], wordCount2);

    // Print results
    printf("Email 1: %s\n", email1);
    printf("Email 2: %s\n", email2);
    printf("Number of words in Email 1: %d\n", wordCount1);
    printf("Number of words in Email 2: %d\n", wordCount2);
    printf("Is Email 1 spam? %s\n", result? "Yes" : "No");

    free(emails);
    free(email1);
    free(email2);

    return 0;
}