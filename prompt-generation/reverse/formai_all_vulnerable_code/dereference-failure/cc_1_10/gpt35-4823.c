//FormAI DATASET v1.0 Category: Log analysis ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to count occurrences of a substring in a given string
int countSubstr(char *str, char *subStr)
{
    int count = 0;

    // Get the length of the substring
    int subStrLen = strlen(subStr);

    // Loop through the string
    while (*str)
    {
        // If the substring is found
        if (strncmp(str, subStr, subStrLen) == 0)
        {
            // Increment the count of occurrences
            count++;
        }

        // Move to the next character in the string
        str++;
    }

    // Return the count of occurrences
    return count;
}

// Function to calculate the entropy of a message using the Shannon entropy formula
double shannonEntropy(char *message)
{
    // Calculate the length of the message
    int len = strlen(message);

    // Variable to store the entropy
    double entropy = 0.0;

    // Loop through all possible values of a byte (0-255)
    for (int i = 0; i < 256; i++)
    {
        // Variable to store the frequency of the byte
        int freq = 0;

        // Loop through all characters in the message
        for (int j = 0; j < len; j++)
        {
            // If the character matches the byte value
            if (message[j] == i)
            {
                // Increment the frequency
                freq++;
            }
        }

        // If the frequency is non-zero
        if (freq > 0)
        {
            // Convert the frequency to a probability
            double prob = (double)freq / (double)len;

            // Add to the entropy
            entropy -= prob * log2(prob);
        }
    }

    // Return the calculated entropy
    return entropy;
}

int main()
{
    // Read the logfile
    FILE *logFile = fopen("logfile.txt", "r");

    // If the file cannot be opened
    if (logFile == NULL)
    {
        // Display an error message
        printf("Error: Could not open logfile.txt. Exiting...\n");

        // Exit with an error status
        exit(1);
    }

    // Allocate memory to store the contents of the file
    char *fileContent = (char *)malloc(100000 * sizeof(char));

    // Read the contents of the file into the allocated memory
    fread(fileContent, sizeof(char), 100000, logFile);

    // Close the file
    fclose(logFile);

    // Count the number of occurrences of the string "error" in the logfile
    int errorCount = countSubstr(fileContent, "error");

    // Count the number of occurrences of the string "warning" in the logfile
    int warningCount = countSubstr(fileContent, "warning");

    // Calculate the entropy of the file
    double entropy = shannonEntropy(fileContent);

    // Display the results
    printf("The logfile contains %d errors and %d warnings.\n", errorCount, warningCount);
    printf("The Shannon entropy of the logfile is %.2lf bits per byte.\n", entropy);

    // Free the memory allocated for the file content
    free(fileContent);

    // Return with success status
    return 0;
}