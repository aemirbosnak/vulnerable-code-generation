//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

// Function to count the number of words in a string
int countWords(char *str)
{
    int count = 0;
    char *word = strtok(str, " ");
    while (word!= NULL)
    {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to count the frequency of words in a string
void countWordFrequency(char *str, int *freq)
{
    char *word = strtok(str, " ");
    while (word!= NULL)
    {
        int i;
        for (i = 0; i < 26; i++)
        {
            if (isalpha(word[0]) && tolower(word[0]) == i + 'a')
            {
                freq[i]++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }
}

// Function to print the word frequency
void printWordFrequency(int freq[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%c: %d\n", i + 'a', freq[i]);
    }
}

// Function to read the log file
void readLogFile(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: File not found.\n");
        exit(1);
    }
    char line[1000];
    while (fgets(line, sizeof(line), fp)!= NULL)
    {
        // Count the number of words in the line
        int count = countWords(line);
        // Count the frequency of words in the line
        int freq[26] = { 0 };
        countWordFrequency(line, freq);
        // Print the word frequency
        printf("Word frequency for line %d:\n", count);
        printWordFrequency(freq, 26);
        printf("\n");
    }
    fclose(fp);
}

// Function to read all the log files in a directory
void readAllLogFiles(char *dirname)
{
    DIR *dp;
    struct dirent *dir;
    dp = opendir(dirname);
    if (dp == NULL)
    {
        printf("Error: Directory not found.\n");
        exit(1);
    }
    while ((dir = readdir(dp))!= NULL)
    {
        char filename[100];
        strcpy(filename, dirname);
        strcat(filename, "/");
        strcat(filename, dir->d_name);
        // Check if the file is a log file
        if (strstr(filename, ".log")!= NULL)
        {
            printf("Reading log file: %s\n", filename);
            readLogFile(filename);
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Error: Directory not specified.\n");
        exit(1);
    }
    char dirname[100];
    strcpy(dirname, argv[1]);
    readAllLogFiles(dirname);
    return 0;
}