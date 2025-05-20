//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 255
#define MAX_FIELDS 100
#define MAX_EDUCATION_LINES 10
#define MAX_EXPERIENCE_LINES 50

struct resume {
    char* name;
    char* email;
    char* phone;
    char* address;
    char* education[MAX_EDUCATION_LINES];
    int education_count;
    char* experience[MAX_EXPERIENCE_LINES];
    int experience_count;
};

struct education {
    char* degree;
    char* major;
    char* school;
    char* start_date;
    char* end_date;
};

struct experience {
    char* company;
    char* title;
    char* start_date;
    char* end_date;
    char* location;
    char* description;
};

void tokenize_line(char* line, char** fields, int max_fields) {
    int field_count = 0;
    char* token = strtok(line, ",");
    while (token != NULL && field_count < max_fields) {
        fields[field_count] = token;
        token = strtok(NULL, ",");
        field_count++;
    }
}

void parse_education_line(char* line, struct education* e) {
    char* fields[MAX_FIELDS];
    int field_count = 0;
    char* token = strtok(line, ",");
    while (token != NULL && field_count < MAX_FIELDS) {
        fields[field_count] = token;
        token = strtok(NULL, ",");
        field_count++;
    }
    if (field_count == 5) {
        e->degree = strdup(fields[0]);
        e->major = strdup(fields[1]);
        e->school = strdup(fields[2]);
        e->start_date = strdup(fields[3]);
        e->end_date = strdup(fields[4]);
    }
}

void parse_experience_line(char* line, struct experience* exp) {
    char* fields[MAX_FIELDS];
    int field_count = 0;
    char* token = strtok(line, ",");
    while (token != NULL && field_count < MAX_FIELDS) {
        fields[field_count] = token;
        token = strtok(NULL, ",");
        field_count++;
    }
    if (field_count >= 5) {
        exp->company = strdup(fields[0]);
        exp->title = strdup(fields[1]);
        exp->start_date = strdup(fields[2]);
        exp->end_date = strdup(fields[3]);
        exp->location = strdup(fields[4]);
        if (field_count > 5) {
            int i;
            exp->description = strdup(fields[5]);
            for (i = 6; i < field_count; i++) {
                strcat(exp->description, ",");
                strcat(exp->description, fields[i]);
            }
        } else {
            exp->description = "";
        }
    }
}

struct resume* parse_resume(char* filename) {
    FILE* file;
    char line[MAX_LINE_LENGTH];
    char* fields[MAX_FIELDS];
    struct resume* r = malloc(sizeof(struct resume));
    r->education_count = 0;
    r->experience_count = 0;
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File %s not found\n", filename);
        return NULL;
    }
    
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (line[0] == '\n') {
            continue;
        }
        if (strstr(line, "Name:")) {
            strtok(line, " ");
            r->name = strdup(strtok(NULL, "\n"));
        } else if (strstr(line, "Email:")) {
            strtok(line, " ");
            r->email = strdup(strtok(NULL, "\n"));
        } else if (strstr(line, "Phone:")) {
            strtok(line, " ");
            r->phone = strdup(strtok(NULL, "\n"));
        } else if (strstr(line, "Address:")) {
            strtok(line, " ");
            r->address = strdup(strtok(NULL, "\n"));
        } else if (strstr(line, "Education:")) {
            char education_line[MAX_LINE_LENGTH];
            do {
                fgets(education_line, MAX_LINE_LENGTH, file);
                if (education_line[0] != '\n') {
                    r->education[r->education_count] = strdup(education_line);
                    r->education_count++;
                } 
            } while (fgets(education_line, MAX_LINE_LENGTH, file) != NULL && education_line[0] != '\n');
        } else if (strstr(line, "Experience:")) {
            char experience_line[MAX_LINE_LENGTH];
            do {
                fgets(experience_line, MAX_LINE_LENGTH, file);
                if (experience_line[0] != '\n') {
                    r->experience[r->experience_count] = strdup(experience_line);
                    r->experience_count++;
                } 
            } while (fgets(experience_line, MAX_LINE_LENGTH, file) != NULL && experience_line[0] != '\n');
        }
    }
    return r;
}

int main() {
    struct resume* r = parse_resume("resume.txt");
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Address: %s\n", r->address);
    
    printf("Education:\n");
    int i;
    for (i = 0; i < r->education_count; i++) {
        struct education e;
        parse_education_line(r->education[i], &e);
        printf("\t%s %s, %s\n\t%s - %s\n", 
               e.degree, e.major, e.school, e.start_date, e.end_date);
    }
    
    printf("Experience:\n");
    for (i = 0; i < r->experience_count; i++) {
        struct experience exp;
        parse_experience_line(r->experience[i], &exp);
        printf("\t%s - %s\n\t%s %s, %s\n\t%s\n", 
               exp.company, exp.title, exp.location, exp.start_date, exp.end_date, exp.description);
    }
    return 0;
}