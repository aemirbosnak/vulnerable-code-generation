//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: recursive
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

char *password;
int length;

int main()
{
    printf("Enter the length of the password: ");
    scanf("%d",&length);
    password = (char*)malloc(length*sizeof(char));
    printf("Enter the password: ");
    scanf("%s",password);
    printf("Password strength: %d\n",password_strength(password));
    return 0;
}

int password_strength(char *str)
{
    int count_uppercase=0,count_lowercase=0,count_digits=0,count_special_chars=0;
    int strength=0;
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(isupper(str[i]))
        {
            count_uppercase++;
        }
        else if(islower(str[i]))
        {
            count_lowercase++;
        }
        else if(isdigit(str[i]))
        {
            count_digits++;
        }
        else
        {
            count_special_chars++;
        }
    }
    if(count_uppercase>0)
    {
        strength+=3;
    }
    if(count_lowercase>0)
    {
        strength+=3;
    }
    if(count_digits>0)
    {
        strength+=2;
    }
    if(count_special_chars>0)
    {
        strength+=1;
    }
    if(strength<10)
    {
        return 0;
    }
    else
    {
        return strength;
    }
}