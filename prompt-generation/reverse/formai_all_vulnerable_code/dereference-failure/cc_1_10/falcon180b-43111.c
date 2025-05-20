//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 1000

//Structure for storing the CSV data
typedef struct{
   char **fields;
   int num_fields;
}CSVData;

//Function to split a string into words
char *split_string(char *str){
   int len = strlen(str);
   char *new_str = (char *)malloc(len*sizeof(char));
   int i = 0,j = 0;
   while(str[i]!= '\0'){
      if(str[i] == ','){
         new_str[j] = '\0';
         j++;
      }
      else{
         new_str[j] = tolower(str[i]);
         j++;
      }
      i++;
   }
   new_str[j] = '\0';
   return new_str;
}

//Function to read a CSV file
CSVData read_csv_file(FILE *fp){
   char line[MAX_SIZE];
   CSVData data;
   data.num_fields = 0;
   data.fields = (char **)malloc(MAX_SIZE*sizeof(char *));
   while(fgets(line,MAX_SIZE,fp)!= NULL){
      char *word = split_string(line);
      data.fields[data.num_fields] = word;
      data.num_fields++;
   }
   return data;
}

//Function to print a CSV data structure
void print_csv_data(CSVData data){
   int i;
   for(i = 0;i < data.num_fields;i++){
      printf("%s ",data.fields[i]);
   }
   printf("\n");
}

//Main function to read a CSV file and print its data
int main(){
   FILE *fp;
   fp = fopen("example.csv","r");
   if(fp == NULL){
      printf("Error: File not found\n");
      exit(0);
   }
   CSVData data = read_csv_file(fp);
   printf("CSV Data:\n");
   print_csv_data(data);
   return 0;
}