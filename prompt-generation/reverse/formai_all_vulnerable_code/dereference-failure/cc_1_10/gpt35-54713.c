//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_RESUME_LENGTH 10000

typedef struct {
    char* name;
    char* email;
    char* phone;
    char* experience;
    char* education;
    int num_skills;
    char* skills[10];
} Resume;

int parseResume(char* resumeText, Resume* resume);
int extractContactInfo(char* resumeText, Resume* resume);
int extractExperience(char* resumeText, Resume* resume);
int extractEducation(char* resumeText, Resume* resume);
int extractSkills(char* resumeText, Resume* resume);

int main(int argc, char* argv[]) {
    char* resumeText = (char*) malloc(MAX_RESUME_LENGTH);
    Resume resume;

    // read the resume text from file or user input
    printf("Enter resume text:\n");
    fgets(resumeText, MAX_RESUME_LENGTH, stdin);

    // parse the resume
    if (parseResume(resumeText, &resume) != 0) {
        printf("Error parsing resume\n");
        return 1;
    }

    // print the parsed resume
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);
    printf("Skills: ");
    for (int i = 0; i < resume.num_skills; i++) {
        printf("%s, ", resume.skills[i]);
    }
    printf("\n");

    return 0;
}

// Parses the resume text and extracts relevant information into the given Resume struct
int parseResume(char* resumeText, Resume* resume) {
    // Extract contact info
    if (extractContactInfo(resumeText, resume) != 0) {
        return 1;
    }

    // Extract experience
    if (extractExperience(resumeText, resume) != 0) {
        return 1;
    }

    // Extract education
    if (extractEducation(resumeText, resume) != 0) {
        return 1;
    }

    // Extract skills
    if (extractSkills(resumeText, resume) != 0) {
        return 1;
    }

    return 0;
}

// Extracts contact information from the resume text and fills out the given Resume struct
int extractContactInfo(char* resumeText, Resume* resume) {
    char buffer[MAX_BUFFER_SIZE];
    char* start = NULL;
    char* end = NULL;

    // Extract name
    start = resumeText;
    end = strstr(start, "\n");
    if (end == NULL) {
        return 1;
    }
    *end = '\0';
    resume->name = strdup(start);
    resumeText = end + 1;

    // Extract email
    start = strstr(resumeText, "@");
    if (start == NULL) {
        return 1;
    }
    end = start;
    while (start > resumeText && *start != ' ') {
        start--;
    }
    if (*start == ' ') {
        start++;
    }
    strncpy(buffer, start, end-start+1);
    buffer[end-start+1] = '\0';
    resume->email = strdup(buffer);
    start = end + 1;

    // Extract phone number
    start = strstr(resumeText, "(");
    if (start == NULL) {
        return 1;
    }
    end = start;
    while (*end != ')') {
        end++;
    }
    strncpy(buffer, start, end-start+1);
    buffer[end-start+1] = '\0';
    resume->phone = strdup(buffer);

    return 0;
}

// Extracts experience from the resume text and fills out the given Resume struct
int extractExperience(char* resumeText, Resume* resume) {
    char buffer[MAX_BUFFER_SIZE];
    char* start = NULL;
    char* end = NULL;

    // Find "Experience" section
    start = strstr(resumeText, "Experience");
    if (start == NULL) {
        return 1;
    }

    // Find end of "Experience" section
    end = strstr(start+1, "\n\n");
    if (end == NULL) {
        end = resumeText + strlen(resumeText);
    }

    // Extract experience text
    strncpy(buffer, start, end-start);
    buffer[end-start] = '\0';
    resume->experience = strdup(buffer);

    return 0;
}

// Extracts education from the resume text and fills out the given Resume struct
int extractEducation(char* resumeText, Resume* resume) {
    char buffer[MAX_BUFFER_SIZE];
    char* start = NULL;
    char* end = NULL;

    // Find "Education" section
    start = strstr(resumeText, "Education");
    if (start == NULL) {
        return 1;
    }

    // Find end of "Education" section
    end = strstr(start+1, "\n\n");
    if (end == NULL) {
        end = resumeText + strlen(resumeText);
    }

    // Extract education text
    strncpy(buffer, start, end-start);
    buffer[end-start] = '\0';
    resume->education = strdup(buffer);

    return 0;
}

// Extracts skills from the resume text and fills out the given Resume struct
int extractSkills(char* resumeText, Resume* resume) {
    char buffer[MAX_BUFFER_SIZE];
    char* start = NULL;
    char* end = NULL;

    resume->num_skills = 0;

    // Find "Skills" section
    start = strstr(resumeText, "Skills");
    if (start == NULL) {
        return 1;
    }

    // Find end of "Skills" section
    end = strstr(start+1, "\n\n");
    if (end == NULL) {
        end = resumeText + strlen(resumeText);
    }

    // Extract skills text
    strncpy(buffer, start, end-start);
    buffer[end-start] = '\0';

    // Extract individual skills
    start = buffer;
    end = strstr(start, ",");
    while (end != NULL) {
        *end = '\0';
        resume->skills[resume->num_skills++] = strdup(start);
        start = end + 1;
        end = strstr(start, ",");
    }
    resume->skills[resume->num_skills++] = strdup(start);

    return 0;
}