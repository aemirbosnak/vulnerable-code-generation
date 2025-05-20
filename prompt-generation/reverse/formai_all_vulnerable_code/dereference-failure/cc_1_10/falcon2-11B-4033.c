//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//function to check if a string contains only alphabets
int isAlphabet(char str[])
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(!isalpha(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

//function to check if a string is valid
int isValid(char *name, char *password)
{
    int len,i;
    char *temp;
    if(name==NULL || password==NULL)
    {
        printf("Name and Password cannot be NULL\n");
        return 0;
    }
    len=strlen(name);
    for(i=0;i<len;i++)
    {
        if(!isalpha(name[i]))
        {
            printf("Name should contain only alphabets\n");
            return 0;
        }
    }
    temp=strdup(password);
    if(!isAlphabet(temp))
    {
        printf("Password should contain only alphabets\n");
        return 0;
    }
    if(strcmp(name,password)!=0)
    {
        printf("Name and Password should be same\n");
        return 0;
    }
    free(temp);
    return 1;
}

int main()
{
    char name[100];
    char password[100];
    printf("Enter your Name: ");
    fgets(name, sizeof(name), stdin);
    if(strlen(name)==0)
    {
        printf("Invalid Name\n");
        return 0;
    }
    printf("Enter your Password: ");
    fgets(password, sizeof(password), stdin);
    if(strlen(password)==0)
    {
        printf("Invalid Password\n");
        return 0;
    }
    if(isValid(name, password))
    {
        printf("Valid\n");
    }
    return 0;
}