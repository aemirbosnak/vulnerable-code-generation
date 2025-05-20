//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Function to parse XML file
void parseXML(char *filename);

// Function to check for opening tags
bool checkOpenTag(char *tag);

// Function to check for closing tags
bool checkCloseTag(char *tag);

int main()
{
    // Input file name
    char filename[] = "example.xml";

    // Call the function to parse the XML file
    parseXML(filename);

    return 0;
}

// Function to parse XML file
void parseXML(char *filename)
{
    // Open the input file for reading
    FILE *fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    // Initialize variables
    char current_char;
    char current_tag[50];
    char value[50];
    int index = -1;
    bool inside_tag = false;
    bool inside_value = false;

    // Read the file character by character
    while ((current_char = fgetc(fp)) != EOF)
    {
        // If current character is '<', it indicates the start of a new tag
        if (current_char == '<')
        {
            // Set inside_tag flag to true and reset current_tag and value
            inside_tag = true;
            memset(current_tag, 0, sizeof(current_tag));
            memset(value, 0, sizeof(value));
            index = -1;
        }

        // If current character is '>', it indicates the end of a tag
        else if (current_char == '>')
        {
            // Check if inside a tag or inside a value
            if (inside_tag)
            {
                // Check if it is an opening tag or a closing tag
                if (checkOpenTag(current_tag))
                {
                    printf("Found opening tag: %s\n", current_tag);
                }
                else if (checkCloseTag(current_tag))
                {
                    printf("Found closing tag: %s\n", current_tag);
                }

                // Reset inside_tag flag
                inside_tag = false;
            }
            else if (inside_value)
            {
                printf("Value: %s\n", value);

                // Reset inside_value flag
                inside_value = false;
            }
        }

        // If current character is a space or newline, ignore it
        else if (isspace(current_char))
        {
            continue;
        }

        // If inside a tag, add character to current_tag
        else if (inside_tag)
        {
            current_tag[++index] = current_char;
        }

        // If inside a value, add character to value
        else if (inside_value)
        {
            value[++index] = current_char;
        }

        // If none of the above, we are inside a value
        else
        {
            inside_value = true;
            value[++index] = current_char;
        }
    }

    // Close the input file
    fclose(fp);
}

// Function to check for opening tags
bool checkOpenTag(char *tag)
{
    // Check if first character is not a slash and last character is a '>'
    if (tag[0] != '/' && tag[strlen(tag) - 1] == '>')
    {
        return true;
    }

    return false;
}

// Function to check for closing tags
bool checkCloseTag(char *tag)
{
    // Check if first character is a slash and last character is a '>'
    if (tag[0] == '/' && tag[strlen(tag) - 1] == '>')
    {
        return true;
    }

    return false;
}