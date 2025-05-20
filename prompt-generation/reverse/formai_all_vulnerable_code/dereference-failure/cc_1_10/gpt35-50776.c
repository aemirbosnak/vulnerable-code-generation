//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

char *generate_password();

int main()
{
    printf("Generating a secure password...\n");
    char *password = generate_password();
    printf("The generated password is: %s\n", password);
    free(password);

    return 0;
}

char *generate_password()
{
    char *password = (char *)malloc(sizeof(char) * (MAX_PASSWORD_LENGTH + 1));
    int password_length = rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1) + MIN_PASSWORD_LENGTH;
    const char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char numbers[] = "0123456789";
    const char special_characters[] = "!@#$%^&*()-_=+[]{};:,.<>?";

    srand(time(NULL));
    int char_type_count = 4;
    int password_char_count = 0;

    while (password_char_count != password_length)
    {
        int random_char_type = rand() % char_type_count;

        switch (random_char_type)
        {
        case 0:
            password[password_char_count] = lowercase_letters[rand() % strlen(lowercase_letters)];
            password_char_count++;
            break;
        case 1:
            password[password_char_count] = uppercase_letters[rand() % strlen(uppercase_letters)];
            password_char_count++;
            break;
        case 2:
            password[password_char_count] = numbers[rand() % strlen(numbers)];
            password_char_count++;
            break;
        case 3:
            password[password_char_count] = special_characters[rand() % strlen(special_characters)];
            password_char_count++;
            break;
        }
    }

    // Null terminate password string
    password[password_length] = '\0';

    return password;
}