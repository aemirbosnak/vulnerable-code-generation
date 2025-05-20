//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove special characters from a string
void removeSpecialChars(char* str) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        while (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] == ' '))) {
            for (j = i; str[j] != '\0'; j++) {
                str[j] = str[j + 1];
            }
            str[j] = '\0';
        }
    }
}

// Function to extract name from resume
void extractName(char* resume) {
    char* name = (char*) malloc(sizeof(char) * 50);
    int i, j = 0;
    for (i = 0; resume[i] != '\0'; i++) {
        if (resume[i] == 'N' && resume[i + 1] == 'a' && resume[i + 2] == 'm' && resume[i + 3] == 'e' && resume[i + 4] == ':') {
            i += 6; // skip space after Name:
            while (resume[i] != '\n') {
                name[j++] = resume[i++];
            }
            name[j] = '\0';
            break;
        }
    }
    if (strlen(name) > 0) {
        printf("Name: %s\n", name);
    }
    else {
        printf("Name not found!\n");
    }
    free(name);
}

// Function to extract email from resume
void extractEmail(char* resume) {
    char* email = (char*) malloc(sizeof(char) * 50);
    int i, j = 0;
    for (i = 0; resume[i] != '\0'; i++) {
        if (resume[i] == 'E' && resume[i + 1] == 'm' && resume[i + 2] == 'a' && resume[i + 3] == 'i' && resume[i + 4] == 'l' && resume[i + 5] == ':') {
            i += 7; // skip space after Email:
            while (resume[i] != '\n') {
                email[j++] = resume[i++];
            }
            email[j] = '\0';
            break;
        }
    }
    if (strlen(email) > 0) {
        printf("Email: %s\n", email);
    }
    else {
        printf("Email not found!\n");
    }
    free(email);
}

// Function to extract phone number from resume
void extractPhone(char* resume) {
    char* phone = (char*) malloc(sizeof(char) * 15);
    int i, j = 0;
    for (i = 0; resume[i] != '\0'; i++) {
        if (resume[i] == 'P' && resume[i + 1] == 'h' && resume[i + 2] == 'o' && resume[i + 3] == 'n' && resume[i + 4] == 'e' && resume[i + 5] == ':') {
            i += 7; // skip space after Phone:
            while (resume[i] != '\n') {
                phone[j++] = resume[i++];
            }
            phone[j] = '\0';
            break;
        }
    }
    if (strlen(phone) > 0) {
        printf("Phone: %s\n", phone);
    }
    else {
        printf("Phone not found!\n");
    }
    free(phone);
}

int main() {
    char* resume = "Name: John Doe\nEmail: john.doe@email.com\nPhone: 123-456-7890\n";
    printf("%s", resume);
    removeSpecialChars(resume);
    extractName(resume);
    extractEmail(resume);
    extractPhone(resume);
    return 0;
}