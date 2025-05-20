//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void parse_resume(char **resume)
{
    int i, j, count = 0;
    char **skills = (char **)malloc(MAX * sizeof(char *));
    char **education = (char **)malloc(MAX * sizeof(char *));

    for (i = 0; resume[i] != NULL; i++)
    {
        if (strcmp(resume[i], "Skills:") == 0)
        {
            skills[count] = strdup(resume[i + 1]);
            count++;
        }
        else if (strcmp(resume[i], "Education:") == 0)
        {
            education[count] = strdup(resume[i + 1]);
            count++;
        }
    }

    printf("Skills:\n");
    for (j = 0; skills[j] != NULL; j++)
    {
        printf("%s\n", skills[j]);
    }

    printf("Education:\n");
    for (j = 0; education[j] != NULL; j++)
    {
        printf("%s\n", education[j]);
    }

    free(skills);
    free(education);
}

int main()
{
    char **resume = (char **)malloc(MAX * sizeof(char *));
    resume[0] = "John Doe";
    resume[1] = "123 Main St";
    resume[2] = "New York, NY 10001";
    resume[3] = "Skills:";
    resume[4] = "Java";
    resume[5] = "C++";
    resume[6] = "Python";
    resume[7] = "Education:";
    resume[8] = "Bachelor's degree in Computer Science";
    resume[9] = "Master's degree in Software Engineering";

    parse_resume(resume);

    free(resume);

    return 0;
}