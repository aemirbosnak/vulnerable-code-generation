//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Resume {
    char name[50];
    char email[50];
    char phone[15];
    char skills[500];
    char experience[1000];
    char education[500];
};


void extractName(struct Resume *resume, const char *text);
void extractEmail(struct Resume *resume, const char *text);
void extractPhone(struct Resume *resume, const char *text);
void extractSkills(struct Resume *resume, const char *text);
void extractExperience(struct Resume *resume, const char *text);
void extractEducation(struct Resume *resume, const char *text);


int main()
{
    const char *resumeText =
        "John Doe\n"
        "johndoe@gmail.com\n"
        "555-555-5555\n"
        "Skills: C++, Java, Python\n"
        "Experience: Worked on a C++ project for two years.\n"
        "Education: B.S. in Computer Science from XYZ University\n";

    struct Resume *resume = malloc(sizeof(struct Resume));
    if (resume == NULL) {
        printf("Error: failed to allocate memory for resume\n");
        return 1;
    }

    extractName(resume, resumeText);
    extractEmail(resume, resumeText);
    extractPhone(resume, resumeText);
    extractSkills(resume, resumeText);
    extractExperience(resume, resumeText);
    extractEducation(resume, resumeText);

    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);

    free(resume);

    return 0;
}


void extractName(struct Resume *resume, const char *text)
{
    const char *end = strchr(text, '\n');
    if (end == NULL) {
        printf("Error: failed to extract name from resume\n");
        exit(1);
    }
    int length = end - text;
    if (length >= sizeof(resume->name)) {
        printf("Error: name is too long\n");
        exit(1);
    }
    strncpy(resume->name, text, length);
    resume->name[length] = '\0';
}

void extractEmail(struct Resume *resume, const char *text)
{
    const char *start = strchr(text, '\n') + 1;
    const char *end = strchr(start, '\n');
    if (end == NULL) {
        printf("Error: failed to extract email from resume\n");
        exit(1);
    }
    int length = end - start;
    if (length >= sizeof(resume->email)) {
        printf("Error: email is too long\n");
        exit(1);
    }
    strncpy(resume->email, start, length);
    resume->email[length] = '\0';
}

void extractPhone(struct Resume *resume, const char *text)
{
    const char *start = strchr(text, '\n') + 1;
    const char *end = strchr(start, '\n');
    end = strchr(end + 1, '\n') + 1;
    if (end == NULL) {
        printf("Error: failed to extract phone from resume\n");
        exit(1);
    }
    int length = end - start;
    if (length >= sizeof(resume->phone)) {
        printf("Error: phone is too long\n");
        exit(1);
    }
    strncpy(resume->phone, start, length);
    resume->phone[length] = '\0';
}

void extractSkills(struct Resume *resume, const char *text)
{
    const char *start = strstr(text, "Skills:");
    if (start == NULL) {
        printf("Error: failed to extract skills from resume\n");
        exit(1);
    }
    start += strlen("Skills:");
    const char *end = strchr(start, '\n');
    if (end == NULL) {
        printf("Error: failed to extract skills from resume\n");
        exit(1);
    }
    int length = end - start;
    if (length >= sizeof(resume->skills)) {
        printf("Error: skills are too long\n");
        exit(1);
    }
    strncpy(resume->skills, start, length);
    resume->skills[length] = '\0';
}

void extractExperience(struct Resume *resume, const char *text)
{
    const char *start = strstr(text, "Experience:");
    if (start == NULL) {
        printf("Error: failed to extract experience from resume\n");
        exit(1);
    }
    start += strlen("Experience:");
    const char *end = strchr(start, '\n');
    if (end == NULL) {
        printf("Error: failed to extract experience from resume\n");
        exit(1);
    }
    int length = end - start;
    if (length >= sizeof(resume->experience)) {
        printf("Error: experience is too long\n");
        exit(1);
    }
    strncpy(resume->experience, start, length);
    resume->experience[length] = '\0';
}

void extractEducation(struct Resume *resume, const char *text)
{
    const char *start = strstr(text, "Education:");
    if (start == NULL) {
        printf("Error: failed to extract education from resume\n");
        exit(1);
    }
    start += strlen("Education:");
    const char *end = strchr(start, '\n');
    if (end == NULL) {
        printf("Error: failed to extract education from resume\n");
        exit(1);
    }
    int length = end - start;
    if (length >= sizeof(resume->education)) {
        printf("Error: education is too long\n");
        exit(1);
    }
    strncpy(resume->education, start, length);
    resume->education[length] = '\0';
}