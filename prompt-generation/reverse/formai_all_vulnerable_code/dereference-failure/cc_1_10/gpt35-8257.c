//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random integer within a range
int rand_range(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// function to generate a random uppercase letter
char rand_upper()
{
    return (char)rand_range(65, 90);
}

// function to generate a random lowercase letter
char rand_lower()
{
    return (char)rand_range(97, 122);
}

// function to generate a random digit
char rand_digit()
{
    return (char)rand_range(48, 57);
}

// function to generate a random symbol
char rand_symbol()
{
    char symbols[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '='};
    return symbols[rand_range(0, 13)];
}

// function to generate a secure random password
char* gen_password(int length)
{
    char* password = malloc(length + 1); // allocate memory for password
    int types = 4; // number of character types needed in password
    int num_each_type = length / types; // number of characters of each type needed
    int extra_chars = length % types; // number of extra characters to add to password
    
    srand(time(NULL)); // seed the random number generator
    
    // generate characters of each type
    int i = 0;
    for (; i < num_each_type; i++)
    {
        password[i] = rand_upper();
        password[i + num_each_type] = rand_lower();
        password[i + 2 * num_each_type] = rand_digit();
        password[i + 3 * num_each_type] = rand_symbol();
    }
    
    // add any extra characters needed
    for (i = 0; i < extra_chars; i++)
    {
        if (i == 0)
        {
            password[length - 1] = rand_upper();
        }
        else if (i == 1)
        {
            password[length - 2] = rand_lower();
        }
        else if (i == 2)
        {
            password[length - 3] = rand_digit();
        }
        else
        {
            password[length - 4] = rand_symbol();
        }
    }
    
    password[length] = '\0'; // add null terminator to password
    
    return password;
}

int main()
{
    int length = 12; // length of password
    char* password = gen_password(length);
    printf("Generated password: %s\n", password);
    free(password); // free malloc'd memory
    return 0;
}