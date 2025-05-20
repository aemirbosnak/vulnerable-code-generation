//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate and return a random upper case letter
char randomUpper()
{
    return (char)(rand()%26 + 'A');
}

// Function to generate and return a random lower case letter
char randomLower()
{
    return (char)(rand()%26 + 'a');
}

// Function to generate and return a random digit
char randomDigit()
{
    return (char)(rand()%10 + '0');
}

// Function to generate and return a random special character
char randomSpecialChar()
{
    char specialChar[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '[', ']', '{', '}', '|', ';', ':',
                          ',', '.', '<', '>', '/', '?', '\\'};

    return specialChar[rand()%30];
}

// Function to generate and return a C secure password of length n
char* generatePassword(int n)
{
    char* password = (char*)malloc(n*sizeof(char));

    password[0] = randomUpper();
    password[1] = randomLower();
    password[2] = randomDigit();
    password[3] = randomSpecialChar();

    srand(time(0)); // Seeding the RNG with current time

    for(int i=4; i<n; i++)
    {
        int r = rand()%4;

        if(r==0)
            password[i] = randomUpper();
        else if(r==1)
            password[i] = randomLower();
        else if(r==2)
            password[i] = randomDigit();
        else
            password[i] = randomSpecialChar();
    }

    return password;
}

// Driver function
int main()
{
    int n;

    printf("Enter password length: ");
    scanf("%d", &n);

    char* password = generatePassword(n);

    printf("\n\nGenerated password: %s\n\n", password);

    free(password);

    return 0;
}