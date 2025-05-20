//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct declarations */
typedef struct {
    char *name;
    char *email;
    char *phone;
} Contact;

typedef struct {
    char *name;
    int experience_years;
    char *education;
    char *skills;
    Contact contact_info;
} Resume;

/* Function declarations */
void print_resume_info(Resume *resume);
void parse_resume_data(char *data, Resume *new_resume);

/* Main function */
int main() {
    char *resume_data = "Name: John Smith\nExperience: 5 years\nEducation: Bachelor's degree in Computer Science\nSkills: C++, Java, Python\nContact:\n\tName: John Smith\n\tEmail: johnsmith@email.com\n\tPhone: 123-456-7890";
    Resume new_resume;
    parse_resume_data(resume_data, &new_resume);
    print_resume_info(&new_resume);
    return 0;
}

/* Function to parse resume data */
void parse_resume_data(char *data, Resume *new_resume) {
    /* Name */
    char *name_start = strstr(data, "Name: ");
    char *name_end = strstr(name_start, "\n");
    size_t name_length = name_end - name_start - strlen("Name: ");
    new_resume->name = malloc(name_length + 1);
    strncpy(new_resume->name, name_start + strlen("Name: "), name_length);
    new_resume->name[name_length] = '\0';

    /* Experience */
    char *exp_start = strstr(data, "Experience: ");
    char *exp_end = strstr(exp_start, " years");
    size_t exp_length = exp_end - exp_start - strlen("Experience: ");
    char *exp_str = malloc(exp_length + 1);
    strncpy(exp_str, exp_start + strlen("Experience: "), exp_length);
    exp_str[exp_length] = '\0';
    new_resume->experience_years = atoi(exp_str);
    free(exp_str);

    /* Education */
    char *edu_start = strstr(data, "Education: ");
    char *edu_end = strstr(edu_start, "\n");
    size_t edu_length = edu_end - edu_start - strlen("Education: ");
    new_resume->education = malloc(edu_length + 1);
    strncpy(new_resume->education, edu_start + strlen("Education: "), edu_length);
    new_resume->education[edu_length] = '\0';

    /* Skills */
    char *skills_start = strstr(data, "Skills: ");
    char *skills_end = strstr(skills_start, "\n");
    size_t skills_length = skills_end - skills_start - strlen("Skills: ");
    new_resume->skills = malloc(skills_length + 1);
    strncpy(new_resume->skills, skills_start + strlen("Skills: "), skills_length);
    new_resume->skills[skills_length] = '\0';

    /* Contact */
    Contact contact_info;
    char *contact_start = strstr(data, "Contact:\n");
    char *contact_name_start = strstr(contact_start, "\tName: ");
    char *contact_name_end = strstr(contact_name_start, "\n");
    size_t contact_name_length = contact_name_end - contact_name_start - strlen("\tName: ");
    contact_info.name = malloc(contact_name_length + 1);
    strncpy(contact_info.name, contact_name_start + strlen("\tName: "), contact_name_length);
    contact_info.name[contact_name_length] = '\0';

    char *contact_email_start = strstr(contact_name_end, "\tEmail: ");
    char *contact_email_end = strstr(contact_email_start, "\n");
    size_t contact_email_length = contact_email_end - contact_email_start - strlen("\tEmail: ");
    contact_info.email = malloc(contact_email_length + 1);
    strncpy(contact_info.email, contact_email_start + strlen("\tEmail: "), contact_email_length);
    contact_info.email[contact_email_length] = '\0';

    char *contact_phone_start = strstr(contact_email_end, "\tPhone: ");
    char *contact_phone_end = strstr(contact_phone_start, "\n");
    size_t contact_phone_length = contact_phone_end - contact_phone_start - strlen("\tPhone: ");
    contact_info.phone = malloc(contact_phone_length + 1);
    strncpy(contact_info.phone, contact_phone_start + strlen("\tPhone: "), contact_phone_length);
    contact_info.phone[contact_phone_length] = '\0';

    new_resume->contact_info = contact_info;
}

/* Function to print resume info */
void print_resume_info(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Experience: %d years\n", resume->experience_years);
    printf("Education: %s\n", resume->education);
    printf("Skills: %s\n", resume->skills);
    printf("Contact:\n\tName: %s\n\tEmail: %s\n\tPhone: %s\n", resume->contact_info.name, resume->contact_info.email, resume->contact_info.phone);
}