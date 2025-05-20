//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the struct for the resume
struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char education[100];
    char experience[500];
};

int main() {
    char resume_text[1000];  // assume the resume text is less than 1000 characters
    printf("Please copy and paste your resume text:\n");
    fgets(resume_text, 1000, stdin);  // get the resume text from user input

    struct Resume my_resume;

    // parse the name from the resume text
    char* name_start = strstr(resume_text, "Name:") + 5;  // find the start of name field
    char* name_end = strstr(name_start, "\n") - 1;  // find the end of name field
    strncpy(my_resume.name, name_start, name_end - name_start + 1);  // extract name field
    my_resume.name[name_end - name_start + 1] = '\0';  // null-terminate the name field

    // parse the email from the resume text
    char* email_start = strstr(resume_text, "Email:") + 6;  // find the start of email field
    char* email_end = strstr(email_start, "\n") - 1;  // find the end of email field
    strncpy(my_resume.email, email_start, email_end - email_start + 1);  // extract email field
    my_resume.email[email_end - email_start + 1] = '\0';  // null-terminate the email field

    // parse the phone from the resume text
    char* phone_start = strstr(resume_text, "Phone:") + 6;  // find the start of phone field
    char* phone_end = strstr(phone_start, "\n") - 1;  // find the end of phone field
    strncpy(my_resume.phone, phone_start, phone_end - phone_start + 1);  // extract phone field
    my_resume.phone[phone_end - phone_start + 1] = '\0';  // null-terminate the phone field

    // parse the address from the resume text
    char* address_start = strstr(resume_text, "Address:") + 8;  // find the start of address field
    char* address_end = strstr(address_start, "\n") - 1;  // find the end of address field
    strncpy(my_resume.address, address_start, address_end - address_start + 1);  // extract address field
    my_resume.address[address_end - address_start + 1] = '\0';  // null-terminate the address field

    // parse the education from the resume text
    char* education_start = strstr(resume_text, "Education:") + 10;  // find the start of education field
    char* education_end = strstr(education_start, "\n") - 1;  // find the end of education field
    strncpy(my_resume.education, education_start, education_end - education_start + 1);  // extract education field
    my_resume.education[education_end - education_start + 1] = '\0';  // null-terminate the education field

    // parse the experience from the resume text
    char* experience_start = strstr(resume_text, "Experience:") + 11;  // find the start of experience field
    char* experience_end = strstr(experience_start, "\n") - 1;  // find the end of experience field
    strncpy(my_resume.experience, experience_start, experience_end - experience_start + 1);  // extract experience field
    my_resume.experience[experience_end - experience_start + 1] = '\0';  // null-terminate the experience field

    // print out the parsed resume
    printf("Name: %s\n", my_resume.name);
    printf("Email: %s\n", my_resume.email);
    printf("Phone: %s\n", my_resume.phone);
    printf("Address: %s\n", my_resume.address);
    printf("Education: %s\n", my_resume.education);
    printf("Experience: %s\n", my_resume.experience);

    return 0;
}