//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

void printArt(char* text);

int main()
{
    char myText[1000];
    printf("Enter your romantic text: ");
    fgets(myText, 1000, stdin);
    printArt(myText);
    return 0;
}

void printArt(char* text)
{
    int i, j, k, l, n=0, m=0, x=0, y=0;
    while (text[m]!='\0')
        m++;
    if (text[m-1] == '\n')
        text[m-1] = '\0';
    while (text[n]!='\0')
        n++;
    x = (80 - n) / 2;
    y = x;
    for(i=0; i<5; i++)
    {
        for(j=0; j<80; j++)
            printf("*");
        printf("\n");
    }
    for(i=0; i<10; i++)
    {
        printf("*");
        for(j=0; j<78; j++)
            printf(" ");
        printf("*\n");
    }
    for(i=0; i<5; i++)
    {
        printf("*");
        for(k=0; k<x; k++)
            printf(" ");
        printf("%s", text);
        for(l=0; l<y; l++)
            printf(" ");
        printf("*\n");
    }
    for(i=0; i<10; i++)
    {
        printf("*");
        for(j=0; j<78; j++)
            printf(" ");
        printf("*\n");
    }
    for(i=0; i<5; i++)
    {
        for(j=0; j<80; j++)
            printf("*");
        printf("\n");
    }
}