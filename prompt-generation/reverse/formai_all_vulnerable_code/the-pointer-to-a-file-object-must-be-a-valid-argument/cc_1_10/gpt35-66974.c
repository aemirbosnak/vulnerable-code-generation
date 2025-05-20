//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
   char* tag;
   char* attribute;
   char* value;
   struct Node* next; 
};

void parseXML(char* filename){
   char buffer[1000];
   FILE *fp = fopen(filename,"r");
   struct Node *head=NULL;
   while(fgets(buffer,1000,fp)!=NULL){

      if(strlen(buffer)!=1){       
         if(buffer[1]=='/'){
            head=head->next;
         }
         else{
            struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

            int start=0;
            int end=0;
            for(int i=1;i<strlen(buffer);i++){
               if(buffer[i]=='>'){
                  end=i;
                  break;          
               }
            }

            newNode->tag=(char*)malloc(sizeof(char)*end);
            strncpy(newNode->tag,buffer+1,end-1);
            newNode->tag[end-1]='\0';
            char* searchspace=strstr(buffer," ");
            if(searchspace!=NULL){
               int startattribute=0;
               int endattribute=searchspace-buffer-1;
               newNode->attribute=(char*)malloc(sizeof(char)*endattribute+1);
               strncpy(newNode->attribute,buffer+1,endattribute);
               newNode->attribute[endattribute]='\0';
               char* searchequal=strstr(buffer,"=");
               if(searchequal!=NULL){
                  int startvalue=searchequal-buffer+1; 
                  newNode->value=(char*)malloc(sizeof(char)*strlen(buffer)-startvalue-3);
                  strncpy(newNode->value,buffer+startvalue+1,strlen(buffer)-startvalue-3);
                  newNode->value[strlen(buffer)-startvalue-3]='\0';
               }
               else{
                  newNode->value="null";
               }
            }
            else{
               newNode->attribute="null";
               newNode->value="null";
            }
            newNode->next=NULL;
            if(head==NULL){
               head=newNode;
            }
            else{
               struct Node *temp=head;
               while(temp->next!=NULL){
                  temp=temp->next;
               }
               temp->next=newNode;
            }
         }
      } 
   }
   printf("Parsing Completed\n");
   fclose(fp);
}

int main(){
   char* filename="example.xml";
   parseXML(filename);  
   return 0;
}