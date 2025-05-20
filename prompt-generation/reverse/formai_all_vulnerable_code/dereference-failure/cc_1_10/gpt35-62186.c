//FormAI DATASET v1.0 Category: String manipulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int stringLength(char* string);
void stringCopy(char* source, char* destination);
void stringConcat(char* str1, char* str2);
void reverseString(char* string);

int main()
{
    int choice;

    char* string = malloc(sizeof(char) * MAX_STRING_LENGTH);
    char* tempString = malloc(sizeof(char) * MAX_STRING_LENGTH);

    printf("Enter a string: ");
    fgets(string, MAX_STRING_LENGTH, stdin);
    printf("\n");

    do {
        printf("Menu\n");
        printf("1. Reverse the string\n");
        printf("2. Copy the string\n");
        printf("3. Concatenate the string with another string\n");
        printf("4. Exit the program\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reverseString(string);
                printf("Your reversed string is: %s\n", string);
                break;
            case 2:
                stringCopy(string, tempString);
                printf("Your copied string is: %s\n", tempString);
                break;
            case 3:
                printf("Enter a string to concatenate: ");
                getchar();
                fgets(tempString, MAX_STRING_LENGTH, stdin);
                stringConcat(string, tempString);
                printf("Your concatenated string is: %s\n", string);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (1);

    free(string);
    free(tempString);

    return 0;
}

int stringLength(char* string)
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }

    return length;
}

void stringCopy(char* source, char* destination)
{
    int i = 0;
    while (source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0'; // add null terminator to the end of the copied string
}

void stringConcat(char* str1, char* str2)
{
    int length1 = stringLength(str1);
    int length2 = stringLength(str2);

    for (int i = 0; i < length2; i++)
    {
        str1[length1 + i] = str2[i];
    }
}

void reverseString(char* string)
{
    int length = stringLength(string);
    char temp;
    for (int i = 0; i < length / 2; i++)
    {
        temp = string[i];
        string[i] = string[length - 1 - i];
        string[length - 1 - i] = temp;
    }
}