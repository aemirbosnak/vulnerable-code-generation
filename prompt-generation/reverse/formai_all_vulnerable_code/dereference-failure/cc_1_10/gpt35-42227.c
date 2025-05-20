//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT 1000
#define MAX_OUTPUT 100

typedef struct Resume
{
    char name[20];
    char email[50];
    char phone[20];
    char education[50];
    char experience[50];
} Resume;

void parseResume(char *input, Resume *output);

int main()
{
    char input[MAX_INPUT];
    Resume output[MAX_OUTPUT];

    printf("Enter resume information: ");
    fgets(input, MAX_INPUT, stdin);

    parseResume(input, output);

    printf("\nResume parsed successfully!\n");
    for(int i=0; i<MAX_OUTPUT; i++)
    {
        if(output[i].name[0] == '\0')
            break;
        printf("\nName: %s\n", output[i].name);
        printf("Email: %s\n", output[i].email);
        printf("Phone: %s\n", output[i].phone);
        printf("Education: %s\n", output[i].education);
        printf("Experience: %s\n", output[i].experience);
    }

    return 0;
}

void parseResume(char *input, Resume *output)
{
    int i=0, j=0, k=0, l=0, m=0;
    char temp[20];

    while(input[i] != '\0')
    {
        if(input[i] == '\n')
            input[i] = ' ';
        if(input[i] == ':')
        {
            temp[j] = '\0';
            j = 0;
            i++;
            switch(temp[0])
            {
                case 'N':
                    strcpy(output[k].name, &input[i]);
                    break;
                case 'E':
                    strcpy(output[k].email, &input[i]);
                    break;
                case 'P':
                    strcpy(output[k].phone, &input[i]);
                    break;
                case 'S':
                    strcpy(output[k].education, &input[i]);
                    break;
                case 'X':
                    strcpy(output[k].experience, &input[i]);
                    break;
            }
        }
        else
        {
            temp[j++] = input[i];
        }

        if(input[i] == ',')
        {
            output[k].name[l-1] = '\0';
            output[k].experience[m-1] = '\0';
            k++;
            l = 0;
            m = 0;
        }
        else if(input[i] == ' ')
        {
            if(temp[0] == 'N')
                l = j;
            if(temp[0] == 'X')
                m = j;
        }

        i++;
    }

    output[k].name[l-1] = '\0';
    output[k].experience[m-1] = '\0';
}