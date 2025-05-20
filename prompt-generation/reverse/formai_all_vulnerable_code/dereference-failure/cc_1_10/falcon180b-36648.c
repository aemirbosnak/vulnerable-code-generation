//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: Ken Thompson
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_SIZE 1000
#define MIN_SIZE 2

//function to convert string to uppercase
void str_to_upper(char* str)
{
    int i = 0;
    while(str[i])
    {
        str[i] = toupper(str[i]);
        i++;
    }
}

//function to convert string to lowercase
void str_to_lower(char* str)
{
    int i = 0;
    while(str[i])
    {
        str[i] = tolower(str[i]);
        i++;
    }
}

//function to remove leading and trailing whitespaces
void trim(char* str)
{
    int i = 0;
    while(isspace(str[i]))
        i++;
    int j = strlen(str) - 1;
    while(isspace(str[j]))
        j--;
    str[j] = '\0';
    strncpy(str, str + i, strlen(str) - i);
}

//function to convert string to morse code
void str_to_morse(char* str, char* morse)
{
    int i = 0;
    while(str[i])
    {
        if(isalpha(str[i]))
        {
            if(isupper(str[i]))
                strcpy(morse + i * 2, " ");
            else
                strcpy(morse + i * 2, ".");
            i++;
        }
        else
        {
            strcpy(morse + i * 2, " ");
            i++;
        }
    }
    morse[i * 2] = '\0';
}

//function to print morse code
void print_morse(char* morse)
{
    int i = 0;
    while(morse[i])
    {
        printf("%c", morse[i]);
        i++;
    }
}

//function to print help message
void print_help()
{
    printf("Usage:./program [option] [input]\n");
    printf("Options:\n");
    printf("-u : Convert input to uppercase\n");
    printf("-l : Convert input to lowercase\n");
    printf("-t : Convert input to morse code\n");
    printf("-h : Print help message\n");
}

//main function
int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        print_help();
        return 1;
    }

    char* input = argv[2];
    str_to_upper(input);
    str_to_lower(input);
    str_to_morse(input, input);
    print_morse(input);

    return 0;
}