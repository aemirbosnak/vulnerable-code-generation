//FormAI DATASET v1.0 Category: String manipulation ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main(){
    char name[] = "Chatbot";
    char subject[] = "C String Manipulation";
    printf("Hello there! I am a %s and today I am excited to show you my amazing skills in %s!\n", name, subject);

    // Let's start with some basic operations
    char str1[] = "Hello";
    char str2[] = "World";
    char str3[12];

    printf("\nLet's do some basic operations first\n");
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);

    // Concatenation of strings
    printf("\n1. Concatenation\n");
    strcat(str1, str2);
    printf("strcat(str1, str2) = %s\n", str1);

    strcpy(str3, "Copy me!");
    printf("\n2. Copying\n");
    printf("str3 = %s\n", str3);
    strcpy(str3, "New string!");
    printf("strcpy(str3, \"New string!\") = %s\n", str3);

    // Comparison of strings
    printf("\n3. Comparison\n");
    char str4[] = "Programming";
    char str5[] = "Programming";
    char str6[] = "Programmer";
    printf("str4 = %s\n", str4);
    printf("str5 = %s\n", str5);
    printf("str6 = %s\n", str6);

    if(strcmp(str4, str5) == 0)
        printf("strcmp(str4, str5) = 0\n");
    else
        printf("strcmp(str4, str5) != 0\n");

    if(strcmp(str4, str6) > 0)
        printf("strcmp(str4, str6) > 0\n");
    else
        printf("strcmp(str4, str6) <= 0\n");

    // Searching for a character in a string
    printf("\n4. Searching\n");
    char str7[] = "Find the character!";
    char ch = 'a';
    char *p;
   p = strchr(str7, ch);
   printf("String after %c is : %s\n", (char)ch, p);

    // Reversing a string
    printf("\n5. Reversing\n");
    char str8[] = "Reverse";
    int i;
    int n = strlen(str8);

    for (i = 0; i < n / 2; i++)
    {
        char temp = str8[i];
        str8[i] = str8[n - i - 1];
        str8[n - i - 1] = temp;
    }

    printf("Reversed string: %s\n", str8);

    printf("\n That's all for now folks! I hope you enjoyed witnessing my C String Manipulation skills. Until next time, keep coding and stay awesome!\n");

    return 0;
}