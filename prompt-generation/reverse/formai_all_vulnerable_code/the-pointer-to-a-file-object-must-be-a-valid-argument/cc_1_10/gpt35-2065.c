//FormAI DATASET v1.0 Category: Database simulation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_REC 100
#define MAX_ATTR 100
char data[MAX_REC][MAX_ATTR][100];
int rec_cnt=0,attr_cnt=0;
char attrs[MAX_ATTR][100];
int get_attr_index(char*attr)
{
    int i;
    for(i=0;i<attr_cnt;i++)
    {
        if(strcmp(attrs[i],attr)==0)
        {
            return i;
        }
    }
    strcpy(attrs[i],attr);
    attr_cnt++;
    return i;
}
int read_csv(char*filename)
{
    FILE*fp=fopen(filename,"r");
    char line[1000],* token;
    fgets(line,sizeof(line),fp);
    token = strtok(line, ",");
    while (token != NULL)
    {
        strcpy(attrs[attr_cnt],token);
        token = strtok(NULL, ",");
        attr_cnt++;
    }
    while (fgets(line, sizeof(line), fp)) 
    {         
        token = strtok(line, ",");
        int j=0;
        while (token != NULL)
        {
            strcpy(data[rec_cnt][j++],token);
            token = strtok(NULL, ",");
        }
        rec_cnt++;
    }
    fclose(fp);
    return 1;
}
void insert_record()
{
    int i;
    for(i=0;i<attr_cnt;i++)
    {
        printf("Enter %s: ",attrs[i]);
        scanf("%s",data[rec_cnt][i]);
    }
    rec_cnt++;
}
void show_records()
{
    int i,j;
    printf("Total records: %d\n",rec_cnt);
    for(i=0;i<attr_cnt;i++)
    {
        printf("%s\t",attrs[i]);
    }
    printf("\n");
    for(i=0;i<rec_cnt;i++)
    {
        for(j=0;j<attr_cnt;j++)
        {
            printf("%s\t",data[i][j]);
        }
        printf("\n");
    }
}
void search_records()
{
    int i,j;
    char attr[100],val[100];
    printf("Enter attribute name : ");
    scanf("%s",attr);
    printf("Enter attribute value : ");
    scanf("%s",val);
    int index=get_attr_index(attr);
    printf("Total records: %d\n",rec_cnt);
    for(i=0;i<attr_cnt;i++)
    {
        printf("%s\t",attrs[i]);
    }
    printf("\n");
    for(i=0;i<rec_cnt;i++)
    {
        if(strcmp(data[i][index],val)==0)
        {
            for(j=0;j<attr_cnt;j++)
            {
                printf("%s\t",data[i][j]);
            }
            printf("\n");
        }
    }
}
int main()
{
    int choice;
    char filename[]="data.csv";
    read_csv(filename);
    while(1)
    {
        printf("1. Insert Record\n");
        printf("2. Show Records\n");
        printf("3. Search Record\n");
        printf("4. Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert_record();
                break;
            case 2:
                show_records();
                break;
            case 3:
                search_records();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}