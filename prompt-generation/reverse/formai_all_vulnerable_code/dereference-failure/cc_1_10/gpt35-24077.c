//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function Declarations
void generate_password(int length, char* password);

int main()
{
    int length;
    printf("Enter the length of password you wish to generate: ");
    scanf("%d", &length);

    char password[length+1]; // +1 for null termination
    generate_password(length, password);

    printf("Your secure password is: %s\n", password);

    return 0;
}

void generate_password(int length, char* password)
{
    int lowercase_count = 0;
    int uppercase_count = 0;
    int digit_count = 0;
    int special_count = 0;

    srand(time(NULL)); // Seed for random number generator based on current system time

    for(int i=0; i<length; i++)
    {
        int random_num = rand()%4; // Generate random number between 0 and 3

        if(random_num == 0)
        {
            // Generate lowercase alphabet character between 'a' and 'z'
            password[i] = (char)(rand()%26 + 97);
            lowercase_count++;
        }
        else if(random_num == 1)
        {
            // Generate uppercase alphabet character between 'A' and 'Z'
            password[i] = (char)(rand()%26 + 65);
            uppercase_count++;
        }
        else if(random_num == 2)
        {
            // Generate digit character between '0' and '9'
            password[i] = (char)(rand()%10 + 48);
            digit_count++;
        }
        else
        {
            // Generate special character from the set { !,@,#,$,%,^,&,*,(,) }
            password[i] = (char)(rand()%10 + 33);
            special_count++;
        }
    }

    // Ensure there is at least one of each character type in password
    if(lowercase_count == 0)
    {
        int random_index = rand()%length;
        password[random_index] = (char)(rand()%26 + 97);
        lowercase_count = 1;
    }
    if(uppercase_count == 0)
    {
        int random_index = rand()%length;
        password[random_index] = (char)(rand()%26 + 65);
        uppercase_count = 1;
    }
    if(digit_count == 0)
    {
        int random_index = rand()%length;
        password[random_index] = (char)(rand()%10 + 48);
        digit_count = 1;
    }
    if(special_count == 0)
    {
        int random_index = rand()%length;
        password[random_index] = (char)(rand()%10 + 33);
        special_count = 1;
    }

    password[length] = '\0'; // End the string with null character
}