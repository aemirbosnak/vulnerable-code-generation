//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#define N 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_LENGTH 100

typedef struct{
    char **row;
    int num_fields;
    int num_rows;
}CSV;

CSV *csv_open(const char *filename){
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    CSV *csv;
    int i,j;
    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("Error opening file %s\n",filename);
        exit(1);
    }
    csv=(CSV*)malloc(sizeof(CSV));
    csv->row=(char**)malloc(N*sizeof(char*));
    csv->num_fields=0;
    csv->num_rows=0;
    while(fgets(line,MAX_LINE_LENGTH,fp)!=NULL){
        if(csv->num_rows>=N){
            printf("Error: too many rows\n");
            exit(1);
        }
        i=0;
        j=0;
        token=strtok(line,",");
        while(token!=NULL){
            if(j>=MAX_FIELD_LENGTH){
                printf("Error: field too long\n");
                exit(1);
            }
            csv->row[i]=token;
            i++;
            j+=strlen(token)+1;
            token=strtok(NULL,",");
        }
        csv->num_fields=i;
        csv->num_rows++;
    }
    fclose(fp);
    return csv;
}

void csv_print(CSV *csv){
    int i,j;
    for(i=0;i<csv->num_rows;i++){
        for(j=0;j<csv->num_fields;j++){
            printf("%s ",csv->row[i*csv->num_fields+j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv){
    int i;
    for(i=0;i<csv->num_rows;i++){
        free(csv->row[i*csv->num_fields]);
    }
    free(csv->row);
    free(csv);
}

int main(){
    CSV *csv;
    csv=csv_open("data.csv");
    csv_print(csv);
    csv_close(csv);
    return 0;
}