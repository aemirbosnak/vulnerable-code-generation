//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RESUME_SIZE 1000
#define MAX_TOKEN_SIZE 50

//Structure to hold extracted information from resume
struct Resume{
    char name[50];
    char email[50];
    char phone[15];
    char education[50];
    char skills[100];
};

//Function to extract name from resume
void extractName(char* resume, char* name){
    int i = 0, j = 0;
    while(resume[i] != '\n'){
        if(resume[i] == ' '){
            i++;
            continue;
        }
        name[j++] = resume[i++];
    }
    name[j] = '\0';
}

//Function to extract email from resume
void extractEmail(char* resume, char* email){
    int i = 0, j = 0;
    while(resume[i] != '\0'){
        if(resume[i] == '@'){
            while(resume[i] != '\n'){
                email[j++] = resume[i++];
            }
            email[j] = '\0';
            break;
        }
        i++;
    }
}

//Function to extract phone number from resume
void extractPhone(char* resume, char* phone){
    int i = 0, j = 0;
    while(resume[i] != '\0'){
        if(resume[i] >= '0' && resume[i] <= '9'){
            while(resume[i] != '\n'){
                phone[j++] = resume[i++];
            }
            phone[j] = '\0';
            break;
        }
        i++;
    }
}

//Function to extract education details from resume
void extractEducation(char* resume, char* education){
    char* token;
    int i = 0;
    while(resume[i] != '\0'){
        if(resume[i] == 'E' && resume[i+1] == 'd' && resume[i+2] == 'u'){
            //Skipping the word 'Education'
            i += 10;
            //Extracting the actual education details
            token = strtok(&resume[i], "\n");
            strcpy(education, token);
            break;
        }
        i++;
    }
}

//Function to extract skills from resume
void extractSkills(char* resume, char* skills){
    char* token;
    int i = 0;
    while(resume[i] != '\0'){
        if(resume[i] == 'S' && resume[i+1] == 'k' && resume[i+2] == 'i' && resume[i+3] == 'l' && resume[i+4] == 'l' && resume[i+5] == 's'){
            //Skipping the word 'Skills'
            i += 7;
            //Extracting the actual skills
            token = strtok(&resume[i], "\n");
            strcpy(skills, token);
            break;
        }
        i++;
    }
}

//Function to parse resume and extract information
void parseResume(char* resume, struct Resume* r){
    char name[MAX_TOKEN_SIZE], email[MAX_TOKEN_SIZE], phone[MAX_TOKEN_SIZE], education[MAX_TOKEN_SIZE], skills[MAX_TOKEN_SIZE];
    extractName(resume, name);
    extractEmail(resume, email);    
    extractPhone(resume, phone);
    extractEducation(resume, education);
    extractSkills(resume, skills);
    strcpy(r->name, name);
    strcpy(r->email, email);
    strcpy(r->phone, phone);
    strcpy(r->education, education);
    strcpy(r->skills, skills);
}

int main(){
    char resume[MAX_RESUME_SIZE];
    struct Resume r;
    printf("Enter your resume:\n");
    fgets(resume, MAX_RESUME_SIZE, stdin);
    parseResume(resume, &r);
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Education: %s\n", r.education);
    printf("Skills: %s\n", r.skills);
    return 0;
}