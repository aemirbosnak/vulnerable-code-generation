//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//structure for JSON data
struct json_data{
    char* key;
    char* value;
};

//function to remove leading and trailing whitespaces
void trim(char* str){
    int i,j;
    for(i=0;i<strlen(str);i++){
        if(str[i]!=' '){
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

//function to parse JSON data
int parse_json(char* json, struct json_data* data){
    char* key = NULL;
    char* value = NULL;
    char* temp = strtok(json,": ");
    int i = 0;
    while(temp!= NULL){
        if(i%2 == 0){
            key = strdup(temp);
            trim(key);
        }
        else{
            value = strdup(temp);
            trim(value);
            data[i/2].key = key;
            data[i/2].value = value;
        }
        i++;
        temp = strtok(NULL,": ");
    }
    return i/2;
}

//function to print JSON data
void print_json(struct json_data* data, int size){
    int i;
    for(i=0;i<size;i++){
        printf("Key: %s\tValue: %s\n",data[i].key,data[i].value);
    }
}

//main function
int main(){
    char* json = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    struct json_data data[10];
    int size = parse_json(json,data);
    print_json(data,size);
    return 0;
}