//FormAI DATASET v1.0 Category: HTML beautifier ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()  
{  
    char htmlCode[1000];
    char *input;
    FILE *fp;
    fp = fopen("input.txt","r+");
    if(fp == NULL)
    {
        printf("Error opening file");
        return 0;
    }
    while(fgets(input,sizeof(input),fp))
    {
        strcat(htmlCode,input);
    }
    fclose(fp);
    
    // HTML beautifier code starts from here
    int indent_level = 0, i = 0;
    char indent_str[10] = "    ";
    char prettyCode[10000] = "";
    int len = strlen(htmlCode);

    for(i = 0; i < len; i++)
    {
        char current_char = htmlCode[i];
        char next_char = htmlCode[i+1];
        if(current_char == '<')
        {
            if(next_char == '/') 
            {
                indent_level--;
            }
            int j;
            for(j = 0; j < indent_level; j++)
            {
                strcat(prettyCode, indent_str);
            }
            indent_level++;
        }
        else if(current_char == '>')
        {
            if(next_char != '<')
            {
                strcat(prettyCode, ">\n");
            }
            else
            {
                strcat(prettyCode, ">");
            }
        }
        else
        {
            strncat(prettyCode, &current_char, 1);
        }
    }
    // HTML beautifier code ends here

    fp = fopen("output.txt","w+");
    if(fp == NULL)
    {
        printf("Error opening file");
        return 0;
    }
    fprintf(fp, "%s", prettyCode);
    fclose(fp);
    return 0;  
}