//FormAI DATASET v1.0 Category: Syntax parsing ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{    //structure to store parsed data
    char type[50];
    char name[50];
    int line_number;
};
int count=0;
struct node arr[100];   //array of structures to store parsed data

void parse_function(char str[], int line){  //function to parse the function definition
    char *type,*name;
    int i,j,len=0;
    type=(char*)malloc(50*sizeof(char));
    name=(char*)malloc(50*sizeof(char));
    for(i=0; str[i]!='('; i++){   //parsing the function name
        name[i]=str[i];
    }
    name[i]='\0';
    i++;
    for(j=i; str[j]!=')'; j++){   //parsing the function arguments
        len++;
    }
    if(len==0){   //if no arguments are passed
        strcpy(type,"void");
    }else{
        for(i=j-len-1; str[i]!=' '; i--){  //parsing the data type of argument
            type[i-j+len+1]=str[i];
        }
    }
    type[i-j+len+1]='\0';
    strcpy(arr[count].type,type);   //storing the parsed data in a structure
    strcpy(arr[count].name,name);
    arr[count].line_number=line;
    count++;
}

void parse_global(char str[], int line){   //function to parse the global declaration
    char *type,*name;
    int i,len=0;
    type=(char*)malloc(50*sizeof(char));
    name=(char*)malloc(50*sizeof(char));
    for(i=0; str[i]!=' '; i++){   //parsing the data type
        type[i]=str[i];
    }
    type[i]='\0';
    i++;
    for(; str[i]!=';'; i++){   //parsing the variable name
        name[len]=str[i];
        len++;
    }
    name[len]='\0';
    strcpy(arr[count].type,type);   //storing the parsed data in a structure
    strcpy(arr[count].name,name);
    arr[count].line_number=line;
    count++;
}

void parse_file(char file_name[]){  //function to parse the entire file
    FILE *fp;
    fp=fopen(file_name,"r");
    char str[200];
    int i,line=1;
    while(fgets(str,200,fp)!=NULL){  //reading the file line by line
        for(i=0; str[i]!='\n'; i++){  //ignoring the new-line character
        }
        str[i]='\0';
        char *type=strstr(str,"(");
        if(type!=NULL){  //checking for function definition
            parse_function(str,line);
        }else{
            type=strstr(str,";");
            if(type!=NULL){  //checking for global declaration
                parse_global(str,line);
            }
        }
        line++;
    }
    fclose(fp);
}

void print_data(){   //function to print the parsed data
    int i;
    printf("Type\tName\tLine\n");
    for(i=0; i<count; i++){
        printf("%s\t%s\t%d\n",arr[i].type,arr[i].name,arr[i].line_number);
    }
}

int main(){
    char file_name[50];
    printf("Enter file name: ");
    scanf("%s",file_name);
    parse_file(file_name);   //calling the parsing function
    print_data();   //calling the function to print the parsed data
    return 0;
}