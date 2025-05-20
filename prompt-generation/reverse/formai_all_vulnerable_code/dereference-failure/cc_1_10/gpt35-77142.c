//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

typedef struct Resume {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char address[MAX_LENGTH];
    char education[MAX_LENGTH];
    char experience[MAX_LENGTH];
} Resume;

Resume* parse_resume(char* txt) {
    Resume* res = (Resume*) malloc(sizeof(Resume));
    int pos_name = 0, pos_email = 0, pos_phone = 0, pos_address = 0, pos_education = 0, pos_experience = 0;
    int len = strlen(txt);
    char buffer[MAX_LENGTH];
    for (int i = 0; i < len; i++) {
        if (txt[i] == '\n') {
            if (strncmp(txt + i + 1, "Name:", 5) == 0) {
                res->name[pos_name] = '\0';
                pos_name = 0;
            } else if (strncmp(txt + i + 1, "Email:", 6) == 0) {
                res->email[pos_email] = '\0';
                pos_email = 0;
            } else if (strncmp(txt + i + 1, "Phone:", 6) == 0) {
                res->phone[pos_phone] = '\0';
                pos_phone = 0;
            } else if (strncmp(txt + i + 1, "Address:", 8) == 0) {
                res->address[pos_address] = '\0';
                pos_address = 0;
            } else if (strncmp(txt + i + 1, "Education:", 10) == 0) {
                res->education[pos_education] = '\0';
                pos_education = 0;
            } else if (strncmp(txt + i + 1, "Experience:", 11) == 0) {
                res->experience[pos_experience] = '\0';
                pos_experience = 0;
            }
        } else {
            if (pos_name < MAX_LENGTH - 1) {
                res->name[pos_name++] = txt[i];
            }
            if (pos_email < MAX_LENGTH - 1) {
                res->email[pos_email++] = txt[i];
            }
            if (pos_phone < MAX_LENGTH - 1) {
                res->phone[pos_phone++] = txt[i];
            }
            if (pos_address < MAX_LENGTH - 1) {
                res->address[pos_address++] = txt[i];
            }
            if (pos_education < MAX_LENGTH - 1) {
                res->education[pos_education++] = txt[i];
            }
            if (pos_experience < MAX_LENGTH - 1) {
                res->experience[pos_experience++] = txt[i];
            }
        }
    }
    return res;
}

int main() {
    char* txt = "Name: John Smith \nEmail: johnsmith@example.com \nPhone: 555-555-5555\nAddress: 123 Main Street\nEducation: B.S. in Computer Science\nExperience: 3 years as a software engineer\n";
    Resume* res = parse_resume(txt);
    printf("Name: %s \nEmail: %s \nPhone: %s \nAddress: %s \nEducation: %s \nExperience: %s\n", res->name, res->email, res->phone, res->address, res->education, res->experience);
    free(res);
    return 0;
}