//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main(int argc, char **argv) {
    char *resume_filepath = argv[1];
    char *resume_contents;

    // Read the resume contents from file
    FILE *fp = fopen(resume_filepath, "r");

    if (fp) {
        fseek(fp, 0, SEEK_END);
        long filesize = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        resume_contents = (char *)malloc(filesize);

        fread(resume_contents, filesize, 1, fp);
        fclose(fp);
    } else {
        printf("Failed to open file\n");
        return 1;
    }

    // Define the regular expressions to extract data
    char *name_regex_str = "^\\s*([A-Za-z]+\\s*[A-Za-z]*)";
    char *email_regex_str = "[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}";
    char *phone_regex_str = "\\d{3}-\\d{3}-\\d{4}";
    char *education_regex_str = "(Ph.D.|MS|BS)[\\ ,\\-]*([A-Za-z][\\sA-Za-z]*)+";

    regex_t name_regex, email_regex, phone_regex, education_regex;
    regmatch_t name_match[2], email_match[1], phone_match[1], education_match[1];

    regcomp(&name_regex, name_regex_str, REG_EXTENDED | REG_NEWLINE);
    regcomp(&email_regex, email_regex_str, REG_EXTENDED | REG_NEWLINE);
    regcomp(&phone_regex, phone_regex_str, REG_EXTENDED | REG_NEWLINE);
    regcomp(&education_regex, education_regex_str, REG_EXTENDED | REG_NEWLINE);

    // Extract data using regular expressions
    char name[64];
    char email[64];
    char phone[64];
    char education[256];

    if (regexec(&name_regex, resume_contents, 2, name_match, 0) == 0) {
        strncpy(name, &resume_contents[name_match[1].rm_so], name_match[1].rm_eo - name_match[1].rm_so);
        name[name_match[1].rm_eo - name_match[1].rm_so] = '\0';
    }

    if (regexec(&email_regex, resume_contents, 1, email_match, 0) == 0) {
        strncpy(email, &resume_contents[email_match[0].rm_so], email_match[0].rm_eo - email_match[0].rm_so);
        email[email_match[0].rm_eo - email_match[0].rm_so] = '\0';
    }

    if (regexec(&phone_regex, resume_contents, 1, phone_match, 0) == 0) {
        strncpy(phone, &resume_contents[phone_match[0].rm_so], phone_match[0].rm_eo - phone_match[0].rm_so);
        phone[phone_match[0].rm_eo - phone_match[0].rm_so] = '\0';
    }

    if (regexec(&education_regex, resume_contents, 1, education_match, 0) == 0) {
        strncpy(education, &resume_contents[education_match[0].rm_so], education_match[0].rm_eo - education_match[0].rm_so);
        education[education_match[0].rm_eo - education_match[0].rm_so] = '\0';
    }

    // Print extracted data
    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Education: %s\n", education);

    // Clean up resources
    free(resume_contents);

    regfree(&name_regex);
    regfree(&email_regex);
    regfree(&phone_regex);
    regfree(&education_regex);

    return 0;
}