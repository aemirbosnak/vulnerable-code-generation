//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <string.h>

struct Resume
{
    char name[50];
    char email[50];
    char phone[15];
    char jobtitle[50];
    char skills[200];
};

void parseResume(char* resumeText, struct Resume* resume)
{
    char* token;
    char* rest = resumeText;
    int count = 1;
    
    while ((token = strtok_r(rest, ",\n", &rest)))
    {
        switch(count)
        {
            case 1:
                strcpy(resume->name, token);
                break;
            case 2:
                strcpy(resume->email, token);
                break;
            case 3:
                strcpy(resume->phone, token);
                break;
            case 4:
                strcpy(resume->jobtitle, token);
                break;
            case 5:
                strcpy(resume->skills, token);
                break;
            default:
                break;
        }
        count++;
    }
}

int main()
{
    char resumeText[] = "John Smith,johnsmith@email.com,555-555-5555,Software Engineer,C++,Python";
    struct Resume resume;
    
    parseResume(resumeText, &resume);
    
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Job Title: %s\n", resume.jobtitle);
    printf("Skills: %s\n", resume.skills);
    
    return 0;
}