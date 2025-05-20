//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: shape shifting
#include <stdio.h>
#include <string.h>

typedef struct {
    char* first_name;
    char* last_name;
    char* email;
    char* phone;
    char* summary;
} Candidate;

Candidate* parse_resume(char* resume_text) {
    Candidate* candidate = malloc(sizeof(Candidate));

    // Find first and last name
    char* name_start = strstr(resume_text, "Name: ");
    char* name_end = strstr(resume_text, "\n");
    char* full_name = strndup(name_start + strlen("Name: "), name_end - (name_start + strlen("Name: ")));
    char* space = strrchr(full_name, ' ');
    
    candidate->first_name = strndup(full_name, space - full_name);
    candidate->last_name = strdup(space + 1);
    free(full_name);

    // Find email
    char* email_start = strstr(resume_text, "Email: ");
    char* email_end = strstr(email_start, "\n");
    candidate->email = strndup(email_start + strlen("Email: "), email_end - (email_start + strlen("Email: ")));

    // Find phone
    char* phone_start = strstr(resume_text, "Phone: ");
    char* phone_end = strstr(phone_start, "\n");
    candidate->phone = strndup(phone_start + strlen("Phone: "), phone_end - (phone_start + strlen("Phone: ")));

    // Find summary
    char* summary_start = strstr(resume_text, "Summary: ");
    char* summary_end = strstr(summary_start, "\n\n");
    candidate->summary = strndup(summary_start + strlen("Summary: "), summary_end - (summary_start + strlen("Summary: ")));

    return candidate;
}

int main() {
    char* resume_text = "Name: John Doe\nEmail: john.doe@example.com\nPhone: 123-456-7890\nSummary: Experienced software engineer with a focus on C programming.\n\nSkills: C, C++, Java, Python\nExperience: ...\nEducation: ...";
    Candidate* candidate = parse_resume(resume_text);
    
    printf("First Name: %s\n", candidate->first_name);
    printf("Last Name: %s\n", candidate->last_name);
    printf("Email: %s\n", candidate->email);
    printf("Phone: %s\n", candidate->phone);
    printf("Summary: %s\n", candidate->summary);
    
    return 0;
}