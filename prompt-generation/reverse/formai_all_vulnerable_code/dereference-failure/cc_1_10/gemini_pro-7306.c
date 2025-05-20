//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros for ANSI color codes
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Function to tokenize a string into an array of strings
char **tokenize(char *str, const char *delim)
{
    // Allocate memory for the array of strings
    char **tokens = malloc(sizeof(char *) * 100);
    if (tokens == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Get the first token
    char *token = strtok(str, delim);

    // Loop through the rest of the tokens
    int i = 0;
    while (token != NULL)
    {
        // Store the token in the array
        tokens[i] = token;
        i++;

        // Get the next token
        token = strtok(NULL, delim);
    }

    // Add a NULL pointer to the end of the array
    tokens[i] = NULL;

    // Return the array of strings
    return tokens;
}

// Function to print an array of strings
void print_array(char **array)
{
    // Loop through the array
    for (int i = 0; array[i] != NULL; i++)
    {
        // Print the string
        printf("%s\n", array[i]);
    }
}

// Function to count the number of lines in a file
int count_lines(FILE *fp)
{
    // Initialize the line count
    int line_count = 0;

    // Loop through the file
    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        // Increment the line count when a newline character is encountered
        if (ch == '\n')
        {
            line_count++;
        }
    }

    // Return the line count
    return line_count;
}

// Function to read a file into a string
char *read_file(const char *filename)
{
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Get the number of lines in the file
    int line_count = count_lines(fp);

    // Allocate memory for the string
    char *str = malloc(sizeof(char) * (line_count + 1));
    if (str == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Read the file into the string
    rewind(fp);
    int i = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        str[i] = ch;
        i++;
    }

    // Add a null terminator to the string
    str[i] = '\0';

    // Close the file
    fclose(fp);

    // Return the string
    return str;
}

// Function to write a string to a file
void write_file(const char *filename, char *str)
{
    // Open the file
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Write the string to the file
    fprintf(fp, "%s", str);

    // Close the file
    fclose(fp);
}

// Function to print the usage of the program
void usage()
{
    printf("Usage: textproc <filename> <command>\n");
    printf("Commands:\n");
    printf("  tokenize <delim>\n");
    printf("  print\n");
    printf("  count-lines\n");
    printf("  read\n");
    printf("  write\n");
}

// Main function
int main(int argc, char *argv[])
{
    // Check the number of arguments
    if (argc != 3)
    {
        usage();
        exit(EXIT_FAILURE);
    }

    // Get the filename and command
    char *filename = argv[1];
    char *command = argv[2];

    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Process the command
    if (strcmp(command, "tokenize") == 0)
    {
        // Get the delimiter
        char *delim = strtok(NULL, " ");
        if (delim == NULL)
        {
            usage();
            exit(EXIT_FAILURE);
        }

        // Tokenize the file
        char *str = read_file(filename);
        char **tokens = tokenize(str, delim);

        // Print the tokens
        print_array(tokens);

        // Free the memory allocated for the tokens
        free(tokens);
        free(str);
    }
    else if (strcmp(command, "print") == 0)
    {
        // Read the file into a string
        char *str = read_file(filename);

        // Print the string
        printf("%s", str);

        // Free the memory allocated for the string
        free(str);
    }
    else if (strcmp(command, "count-lines") == 0)
    {
        // Count the number of lines in the file
        int line_count = count_lines(fp);

        // Print the line count
        printf("%d\n", line_count);
    }
    else if (strcmp(command, "read") == 0)
    {
        // Read the file into a string
        char *str = read_file(filename);

        // Print the string
        printf("%s", str);

        // Free the memory allocated for the string
        free(str);
    }
    else if (strcmp(command, "write") == 0)
    {
        // Read the file into a string
        char *str = read_file(filename);

        // Get the new contents of the file
        char *new_contents = strtok(NULL, " ");
        if (new_contents == NULL)
        {
            usage();
            exit(EXIT_FAILURE);
        }

        // Write the new contents to the file
        write_file(filename, new_contents);

        // Free the memory allocated for the string
        free(str);
    }
    else
    {
        usage();
        exit(EXIT_FAILURE);
    }

    // Close the file
    fclose(fp);

    return EXIT_SUCCESS;
}