//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

#define MAX_LENGTH 15
#define NUM_UPPER_CASE 3
#define NUM_LOWER_CASE 3
#define NUM_DIGITS 3
#define NUM_SPECIAL_CHARS 3
#define NUM_TOTAL_CHARS (NUM_UPPER_CASE + NUM_LOWER_CASE + NUM_DIGITS + NUM_SPECIAL_CHARS)

void shuffle(char *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          char temp = array[j];
          array[j] = array[i];
          array[i] = temp;
        }
    }
}

int main()
{
    srand(time(NULL));

    char password[MAX_LENGTH+1];
    char upper_case_chars[NUM_UPPER_CASE+1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower_case_chars[NUM_LOWER_CASE+1] = "abcdefghijklmnopqrstuvwxyz";
    char digit_chars[NUM_DIGITS+1] = "1234567890";
    char special_chars[NUM_SPECIAL_CHARS+1] = "!@#$%^&*()_+";

    int pos = 0;
    for(int i = 0; i < NUM_UPPER_CASE; i++)
    {
        password[pos++] = upper_case_chars[rand() % strlen(upper_case_chars)];
    }
    for(int i = 0; i < NUM_LOWER_CASE; i++)
    {
        password[pos++] = lower_case_chars[rand() % strlen(lower_case_chars)];
    }
    for(int i = 0; i < NUM_DIGITS; i++)
    {
        password[pos++] = digit_chars[rand() % strlen(digit_chars)];
    }
    for(int i = 0; i < NUM_SPECIAL_CHARS; i++)
    {
        password[pos++] = special_chars[rand() % strlen(special_chars)];
    }

    while(pos < MAX_LENGTH)
    {
        int char_class = rand() % 4;

        switch(char_class)
        {
            case 0:
                password[pos++] = upper_case_chars[rand() % strlen(upper_case_chars)];
                break;

            case 1:
                password[pos++] = lower_case_chars[rand() % strlen(lower_case_chars)];
                break;

            case 2:
                password[pos++] = digit_chars[rand() % strlen(digit_chars)];
                break;

            case 3:
                password[pos++] = special_chars[rand() % strlen(special_chars)];
                break;
        }
    }

    shuffle(password, MAX_LENGTH);

    printf("Your secure password is: %s\n", password);

    return 0;
}