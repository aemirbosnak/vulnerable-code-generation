//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* firstName;
    char* lastName;
    char* emailAddress;
    char* phoneNumber;
} Applicant;

void freeApplicant(Applicant* a) {
    free(a->firstName);
    free(a->lastName);
    free(a->emailAddress);
    free(a->phoneNumber);
    free(a);
}

Applicant* parseResume(char* resumeText) {
    Applicant* newApplicant = malloc(sizeof(Applicant));

    int firstNameSize = 0;
    while(resumeText[firstNameSize] != ' ') firstNameSize++;
    newApplicant->firstName = malloc(sizeof(char) * (firstNameSize + 1));
    strncpy(newApplicant->firstName, resumeText, firstNameSize);
    newApplicant->firstName[firstNameSize] = '\0';

    int lastNameStart = firstNameSize + 1;
    int lastNameSize = 0;
    while(resumeText[lastNameStart + lastNameSize] != ' ') lastNameSize++;
    newApplicant->lastName = malloc(sizeof(char) * (lastNameSize + 1));
    strncpy(newApplicant->lastName, resumeText + lastNameStart, lastNameSize);
    newApplicant->lastName[lastNameSize] = '\0';

    int emailStart = lastNameStart + lastNameSize + 1;
    int emailSize = 0;
    while(resumeText[emailStart + emailSize] != ' ') emailSize++;
    newApplicant->emailAddress = malloc(sizeof(char) * (emailSize + 1));
    strncpy(newApplicant->emailAddress, resumeText + emailStart, emailSize);
    newApplicant->emailAddress[emailSize] = '\0';

    int phoneStart = emailStart + emailSize + 1;
    int phoneSize = 0;
    while(resumeText[phoneStart + phoneSize] != '\n' && resumeText[phoneStart + phoneSize] != '\0') phoneSize++;
    newApplicant->phoneNumber = malloc(sizeof(char) * (phoneSize + 1));
    strncpy(newApplicant->phoneNumber, resumeText + phoneStart, phoneSize);
    newApplicant->phoneNumber[phoneSize] = '\0';

    return newApplicant;
}

int main() {
    char* resumeText = "John Doe johndoe@gmail.com 555-1234";
    Applicant* john = parseResume(resumeText);

    printf("First Name: %s\n", john->firstName);
    printf("Last Name: %s\n", john->lastName);
    printf("Email Address: %s\n", john->emailAddress);
    printf("Phone Number: %s\n", john->phoneNumber);

    freeApplicant(john);
    return 0;
}