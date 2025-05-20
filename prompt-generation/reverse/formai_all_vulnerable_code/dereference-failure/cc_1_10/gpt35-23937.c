//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LEN 10000 // maximum length of the resume file
#define MAX_STRING_LEN 100 // maximum length of a string

// function to read the contents of a file into a string
char* read_file(char* filename) {
    FILE* fp;
    char* buffer;
    long file_len;
    
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }
    
    fseek(fp, 0L, SEEK_END);
    file_len = ftell(fp);
    rewind(fp);
    
    buffer = (char*) malloc(file_len * sizeof(char));
    if (buffer == NULL) {
        printf("Error allocating memory for file %s\n", filename);
        return NULL;
    }
    
    fread(buffer, sizeof(char), file_len, fp);
    fclose(fp);
    
    return buffer;
}

// function to parse contact information from a resume string
void parse_contact(char* resume_str, char* name, char* email, char* phone) {
    char* ptr;
    
    // parse name
    ptr = strstr(resume_str, "Name:");
    if (ptr == NULL) {
        printf("Error: Could not find name in resume\n");
        return;
    }
    ptr += strlen("Name:");
    while (*ptr == ' ') ptr++;
    sscanf(ptr, "%s", name);
    
    // parse email
    ptr = strstr(resume_str, "Email:");
    if (ptr == NULL) {
        printf("Error: Could not find email in resume\n");
        return;
    }
    ptr += strlen("Email:");
    while (*ptr == ' ') ptr++;
    sscanf(ptr, "%s", email);
    
    // parse phone
    ptr = strstr(resume_str, "Phone:");
    if (ptr == NULL) {
        printf("Error: Could not find phone in resume\n");
        return;
    }
    ptr += strlen("Phone:");
    while (*ptr == ' ') ptr++;
    sscanf(ptr, "%s", phone);
}

// function to parse education information from a resume string
void parse_education(char* resume_str, char* degree, char* major, char* university, char* gpa) {
    char* ptr;
    
    // parse degree
    ptr = strstr(resume_str, "Degree:");
    if (ptr == NULL) {
        printf("Error: Could not find degree in resume\n");
        return;
    }
    ptr += strlen("Degree:");
    while (*ptr == ' ') ptr++;
    sscanf(ptr, "%s", degree);
    
    // parse major
    ptr = strstr(resume_str, "Major:");
    if (ptr == NULL) {
        printf("Error: Could not find major in resume\n");
        return;
    }
    ptr += strlen("Major:");
    while (*ptr == ' ') ptr++;
    sscanf(ptr, "%s", major);
    
    // parse university
    ptr = strstr(resume_str, "University:");
    if (ptr == NULL) {
        printf("Error: Could not find university in resume\n");
        return;
    }
    ptr += strlen("University:");
    while (*ptr == ' ') ptr++;
    sscanf(ptr, "%s", university);
    
    // parse GPA
    ptr = strstr(resume_str, "GPA:");
    if (ptr == NULL) {
        printf("Error: Could not find GPA in resume\n");
        return;
    }
    ptr += strlen("GPA:");
    while (*ptr == ' ') ptr++;
    sscanf(ptr, "%s", gpa);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 0;
    }
    
    char* resume_str = read_file(argv[1]);
    if (resume_str == NULL) {
        return 0;
    }
    
    char name[MAX_STRING_LEN];
    char email[MAX_STRING_LEN];
    char phone[MAX_STRING_LEN];
    char degree[MAX_STRING_LEN];
    char major[MAX_STRING_LEN];
    char university[MAX_STRING_LEN];
    char gpa[MAX_STRING_LEN];
    
    parse_contact(resume_str, name, email, phone);
    parse_education(resume_str, degree, major, university, gpa);
    
    printf("CONTACT INFORMATION:\n");
    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    
    printf("\nEDUCATION INFORMATION:\n");
    printf("Degree: %s\n", degree);
    printf("Major: %s\n", major);
    printf("University: %s\n", university);
    printf("GPA: %s\n", gpa);
    
    free(resume_str);
    
    return 0;
}