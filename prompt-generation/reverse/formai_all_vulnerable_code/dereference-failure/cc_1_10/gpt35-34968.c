//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Resume details structure
struct Resume_Details{
    char name[50];
    char email[50];
    char phone[15];
    char education[100];
    char skills[200];
    char experience[500];
}RD;

//function to check if email is valid
int isValidEmail(char* email){
    int i,at=0,dot=0;
    for(i=0;i<strlen(email);i++){
        if(email[i]=='@')
            at++;
        else if(email[i]=='.')
            dot++;
    }
    if(at==1 && dot>0)
        return 1;
    else
        return 0;
}

//function to parse the resume details
void parseResume(char* resume){
    char* delimiters = "\n\t ,.-";
    char* token;
    
    //name
    token = strtok(resume, delimiters);
    strcpy(RD.name,token);
    
    //email
    token = strtok(NULL, delimiters);
    if(isValidEmail(token))
        strcpy(RD.email,token);
    else{
        printf("Invalid email!\n");
        exit(1);
    }
    
    //phone
    token = strtok(NULL, delimiters);
    strcpy(RD.phone,token);
    
    //education
    token = strtok(NULL, delimiters);
    while(token!=NULL && strcmp(token,"Skills")!=0){
        strcat(RD.education,token);
        strcat(RD.education," ");
        token = strtok(NULL, delimiters);
    }
    
    //skills
    token = strtok(NULL, delimiters);
    while(token!=NULL && strcmp(token,"Experience")!=0){
        strcat(RD.skills,token);
        strcat(RD.skills," ");
        token = strtok(NULL, delimiters);
    }
    
    //experience
    token = strtok(NULL, delimiters);
    while(token!=NULL){
        strcat(RD.experience,token);
        strcat(RD.experience," ");
        token = strtok(NULL, delimiters);
    }
}

int main(){
    char resume_details[1000];
    printf("Enter the resume details:\n");
    fgets(resume_details,1000,stdin);
    
    parseResume(resume_details);
    
    printf("----------------------\n");
    printf("Resume Details:\n");
    printf("----------------------\n");
    printf("Name: %s\n",RD.name);
    printf("Email: %s\n",RD.email);
    printf("Phone: %s\n",RD.phone);
    printf("Education: %s\n",RD.education);
    printf("Skills: %s\n",RD.skills);
    printf("Experience: %s\n",RD.experience);
    
    return 0;
}