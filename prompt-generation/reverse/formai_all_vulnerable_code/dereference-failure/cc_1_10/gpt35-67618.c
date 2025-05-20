//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to hold JSON object data 
struct JSON_object{
    char *key;
    char *value;
}json[10];

//Function to print JSON object 
void print_JSON(int num_objects){
    printf("{\n");
    for(int i=0;i<num_objects;i++){
        if(i<num_objects-1){
            printf("\t\"%s\" : \"%s\",\n",json[i].key,json[i].value);
        }
        else{
            printf("\t\"%s\" : \"%s\"\n",json[i].key,json[i].value);
        }
    }
    printf("}\n");
}

//Function to parse the JSON string 
void parse_JSON(char *str){
    int num_objects=0;
    char *token,*key,*value;
    token=strtok(str,"{},:\"");
    while(token!=NULL){
        if(strcmp(token,"{")!=0&&strcmp(token,"}")!=0&&strcmp(token,",")!=0){
            if(num_objects%2==0){
                key=token;
            }
            else{
                value=token;
                json[num_objects/2].key=key;
                json[num_objects/2].value=value;
            }
            num_objects++;
        }
        token=strtok(NULL,"{},:\"");
    }
    printf("Parsed JSON object is :\n");
    print_JSON(num_objects/2);
}

int main(){
    char *json_str="{\"Name\":\"John\",\"Age\":\"35\",\"City\":\"New York\"}";
    parse_JSON(json_str);
    return 0;
}