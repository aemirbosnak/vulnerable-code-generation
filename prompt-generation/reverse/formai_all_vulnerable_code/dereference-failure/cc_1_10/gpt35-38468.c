//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000

struct employee{
    int id;
    char name[MAX_CHARS];
    char role[MAX_CHARS];
    float salary;
};

void parseXML(char* xmlFilePath, struct employee* empInfo);
char* getValue(char* xmlData, char* tag);

int main(){
    char* xmlFilePath = "employee_info.xml";
    struct employee* empInfo = malloc(sizeof(struct employee));
    parseXML(xmlFilePath, empInfo);

    printf("Employee Details:\n");
    printf("ID: %d\n", empInfo->id);
    printf("Name: %s\n", empInfo->name);
    printf("Role: %s\n", empInfo->role);
    printf("Salary: $%.2f\n", empInfo->salary);

    free(empInfo);
    return 0;
}

void parseXML(char* xmlFilePath, struct employee* empInfo){
    FILE* xmlFile = fopen(xmlFilePath, "r");
    if(xmlFile == NULL){
        printf("Error opening XML file. Exiting...\n");
        exit(1);
    }

    char line[MAX_CHARS], *tagValue;
    while(fgets(line, MAX_CHARS, xmlFile)){
        // parse the employee ID
        if(strstr(line, "<id>")){
            tagValue = getValue(line, "<id>");
            empInfo->id = atoi(tagValue);
            free(tagValue);
        }
        // parse the employee name
        else if(strstr(line, "<name>")){
            tagValue = getValue(line, "<name>");
            strncpy(empInfo->name, tagValue, MAX_CHARS);
            free(tagValue);
        }
        // parse the employee role
        else if(strstr(line, "<role>")){
            tagValue = getValue(line, "<role>");
            strncpy(empInfo->role, tagValue, MAX_CHARS);
            free(tagValue);
        }
        // parse the employee salary
        else if(strstr(line, "<salary>")){
            tagValue = getValue(line, "<salary>");
            empInfo->salary = atof(tagValue);
            free(tagValue);
        }
    }

    fclose(xmlFile);
}

char* getValue(char* xmlData, char* tag){
    char *valueStart = strstr(xmlData, tag) + strlen(tag);
    char *valueEnd = strstr(valueStart, "<");
    int length = valueEnd - valueStart;
    char *value = malloc(length + 1);
    strncpy(value, valueStart, length);
    value[length] = '\0';
    return value;
}