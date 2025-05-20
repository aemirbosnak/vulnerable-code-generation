//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>

int main()
{
    char statement[100];
    int i=0,happy=0,sad=0,neutral=0,len=0;

    printf("Enter a statement:\n");
    gets(statement);

    len=strlen(statement);

    for(i=0;i<len;i++)
    {
        if(statement[i]==':') //if the statement contains a smiley
        {
            if(statement[i+1]=='-') //the smiley is sad
            {
                if(statement[i+2]==')')
                {
                    sad++;
                }
            }
            
            if(statement[i+1]=='-') //the smiley is happy
            {
                if(statement[i+2]=='(')
                {
                    happy++;
                }
            }
        }

        if(statement[i]=='(') //if the statement contains a bracket
        {
            if(statement[i+1]=='N'&&statement[i+2]=='e'&&statement[i+3]=='u'&&statement[i+4]=='t'&&statement[i+5]=='r'&&statement[i+6]=='a'&&statement[i+7]=='l'&&statement[i+8]==')')
            //the statement is neutral
            {
                neutral++;
            }   
        }
    }

    if(happy>sad&&happy>neutral) //if the number of happy smileys are more than sad and neutral smileys
    {
        printf("The statement is happy\n");
    }
    if(sad>happy&&sad>neutral) //if the number of sad smileys are more than happy and neutral smileys
    {
        printf("The statement is sad\n");
    }
    if(neutral>sad&&neutral>happy) //if the statement is neutral
    {
        printf("The statement is neutral\n");
    }
    return 0;
}