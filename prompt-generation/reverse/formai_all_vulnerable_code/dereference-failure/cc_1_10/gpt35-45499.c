//FormAI DATASET v1.0 Category: Text Summarizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check whether a character is a vowel or not
int is_vowel(char c)
{
    char vowels[] = "aeiouAEIOU";
    int i;
    for (i = 0; i < 10; i++)
    {
        if (c == vowels[i])
        {
            return 1; // True
        }
    }
    return 0; // False
}

// Function to generate a summary text
void generate_summary(char *text, int n)
{
    char *summary = (char *) malloc(n * sizeof(char)); // Allocate memory
    int len = strlen(text);
    int j = 0;
    int i;
    for (i = 0; i < len; i++)
    {
        if (text[i] != '\n') // Skip newlines
        {
            if (j == 0) // Always capitalize the first letter
            {
                summary[j] = toupper(text[i]);
                j++;
            }
            else if (is_vowel(text[i-1]) && !is_vowel(text[i])) // End of a sentence (vowel followed by consonant)
            {
                summary[j] = '.';
                j++;
                if (j < n)
                {
                    summary[j] = ' ';
                    j++;
                }
            }
            if (j < n)
            {
                summary[j] = text[i];
                j++;
            }
            else
            {
                break; // Limit summary to n characters
            }
        }
    }
    summary[j] = '\0'; // Null-terminate the string
    printf("Summary: %s\n", summary);
    free(summary); // Deallocate memory
}

int main()
{
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla malesuada, tellus non rutrum congue, quam magna bibendum mi, vel lacinia nisl augue eget nisl. Sed tincidunt sapien massa, non pulvinar odio facilisis eget. Vivamus elementum dignissim odio, id maximus nibh facilisis in. Donec maximus ante sit amet lobortis suscipit. Nam luctus nibh enim, ac pulvinar felis hendrerit vel. Duis eget dignissim augue. Sed sed odio vel felis rutrum mattis vel eget nisi. Quisque rutrum enim elit, ac condimentum metus aliquet in. Nulla facilisi. Nam ut sollicitudin justo.";

    printf("%s\n", text); // Print original text
    generate_summary(text, 50); // Generate summary with 50 characters

    return 0;
}