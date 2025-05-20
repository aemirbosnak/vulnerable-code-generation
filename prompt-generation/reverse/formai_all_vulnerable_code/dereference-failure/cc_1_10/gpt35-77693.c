//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char resume[10000];  // Assuming maximum size of the resume is 10,000 characters
    printf("Enter the resume:\n");
    fgets(resume, sizeof(resume), stdin);  // Taking input of the resume from the user

    char name[100], email[100], phone[20], skills[1000], education[500];

    // Searching for the name of the candidate
    char *ptr1 = strstr(resume, "Name");
    if (ptr1 != NULL) {
        char *ptr2 = strchr(ptr1, ':');
        strncpy(name, ptr2 + 1, strchr(ptr2, '\n') - (ptr2 + 1));
    }

    // Searching for the email of the candidate
    char *ptr3 = strstr(resume, "Email");
    if (ptr3 != NULL) {
        char *ptr4 = strchr(ptr3, ':');
        strncpy(email, ptr4 + 1, strchr(ptr4, '\n') - (ptr4 + 1));
    }

    // Searching for the phone number of the candidate
    char *ptr5 = strstr(resume, "Phone");
    if (ptr5 != NULL) {
        char *ptr6 = strchr(ptr5, ':');
        strncpy(phone, ptr6 + 1, strchr(ptr6, '\n') - (ptr6 + 1));
    }

    // Searching for the skills of the candidate
    char *ptr7 = strstr(resume, "Skills");
    if (ptr7 != NULL) {
        char *ptr8 = strchr(ptr7, ':');
        strncpy(skills, ptr8 + 1, strchr(ptr8, '\n') - (ptr8 + 1));
    }

    // Searching for the education details of the candidate
    char *ptr9 = strstr(resume, "Education");
    if (ptr9 != NULL) {
        char *ptr10 = strchr(ptr9, ':');
        strncpy(education, ptr10 + 1, strchr(ptr10, '\n') - (ptr10 + 1));
    }

    // Printing the details of the candidate
    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Skills: %s\n", skills);
    printf("Education: %s\n", education);

    return 0;
}