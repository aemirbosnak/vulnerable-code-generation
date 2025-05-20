//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char jsonString[] = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
    char *name, *city;
    int age;
    //Parsing begins
    for(int i=0; i<strlen(jsonString); i++){
        //Finding name key
        if(jsonString[i] == '\"' && jsonString[i+1] == 'n' && jsonString[i+2] == 'a' && jsonString[i+3] == 'm' && jsonString[i+4] == 'e'){
            i+=6; //move i to the value
            int j=i;
            while(jsonString[j] != '\"'){
                j++;
            }
            int len = j-i;
            name = (char*) malloc((len+1)*sizeof(char)); //allocate space for name string
            for(int k=0; k<len; k++){
                name[k] = jsonString[i+k];
            }
            name[len] = '\0'; //terminate name string with null character
        }
        //Finding age key
        else if(jsonString[i] == '\"' && jsonString[i+1] == 'a' && jsonString[i+2] == 'g' && jsonString[i+3] == 'e'){
            i+=5; //move i to the value
            int j=i;
            while(jsonString[j] != ','){
                j++;
            }
            int len = j-i;
            char ageStr[len+1];
            for(int k=0; k<len; k++){
                ageStr[k] = jsonString[i+k];
            }
            ageStr[len] = '\0'; //terminate age string with null character
            age = atoi(ageStr); //convert age string to integer
        }
        //Finding city key
        else if(jsonString[i] == '\"' && jsonString[i+1] == 'c' && jsonString[i+2] == 'i' && jsonString[i+3] == 't' && jsonString[i+4] == 'y'){
            i+=6; //move i to the value
            int j=i;
            while(jsonString[j] != '\"'){
                j++;
            }
            int len = j-i;
            city = (char*) malloc((len+1)*sizeof(char)); //allocate space for city string
            for(int k=0; k<len; k++){
                city[k] = jsonString[i+k];
            }
            city[len] = '\0'; //terminate city string with null character
        }
    }
    //Printing the results
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("City: %s\n", city);
    //Freeing the allocated memory
    free(name);
    free(city);
    return 0;
}