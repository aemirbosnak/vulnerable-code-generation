//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_resume(char *resume)
{
    // Allocate memory for parsed data
    char **parsed_data = malloc(10 * sizeof(char *));
    parsed_data[0] = malloc(100 * sizeof(char));
    parsed_data[1] = malloc(50 * sizeof(char));
    parsed_data[2] = malloc(20 * sizeof(char));
    parsed_data[3] = malloc(30 * sizeof(char));
    parsed_data[4] = malloc(40 * sizeof(char));
    parsed_data[5] = malloc(60 * sizeof(char));
    parsed_data[6] = malloc(80 * sizeof(char));
    parsed_data[7] = malloc(10 * sizeof(char));
    parsed_data[8] = malloc(20 * sizeof(char));
    parsed_data[9] = malloc(30 * sizeof(char));

    // Extract personal information
    char *name = strstr(resume, "Name:");
    char *address = strstr(resume, "Address:");
    char *phone = strstr(resume, "Phone:");
    char *email = strstr(resume, "Email:");

    // Extract professional summary
    char *summary = strstr(resume, "Summary:");
    char *summary_text = summary ? strstr(summary, ":") + 1 : NULL;

    // Extract skills
    char *skills = strstr(resume, "Skills:");
    char *skills_text = skills ? strstr(skills, ":") + 1 : NULL;

    // Extract experience
    char *experience = strstr(resume, "Experience:");
    char *experience_text = experience ? strstr(experience, ":") + 1 : NULL;

    // Extract education
    char *education = strstr(resume, "Education:");
    char *education_text = education ? strstr(education, ":") + 1 : NULL;

    // Print parsed data
    printf("Name: %s\n", name);
    printf("Address: %s\n", address);
    printf("Phone: %s\n", phone);
    printf("Email: %s\n", email);
    printf("Summary:\n%s\n", summary_text);
    printf("Skills:\n%s\n", skills_text);
    printf("Experience:\n%s\n", experience_text);
    printf("Education:\n%s\n", education_text);

    // Free allocated memory
    for (int i = 0; i < 10; i++)
    {
        free(parsed_data[i]);
    }
    free(parsed_data);
}

int main()
{
    // Read resume text from file
    char resume[1000];
    FILE *fp = fopen("resume.txt", "r");
    fread(resume, 1000, 1, fp);
    fclose(fp);

    // Parse resume
    parse_resume(resume);

    return 0;
}