//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<ctype.h>

int check_file(char *filename);

int main(int argc, char **argv)
{
    char *path;
    if(argc != 2)
    {
        printf("Usage %s <Folder Path>\n",argv[0]);
        return 1;
    }
    path=argv[1];
    DIR *dir;
    struct dirent *ent;

    if((dir=opendir(path)) != NULL)
    {
        while((ent=readdir(dir)) != NULL)
        {
            if(strcmp(ent->d_name,".") && strcmp(ent->d_name,".."))
            {
                char filename[BUFSIZ];
                strcpy(filename,path);
                strcat(filename,"/");
                strcat(filename,ent->d_name);
                if(check_file(ent->d_name))
                {
                    printf("File %s contains virus\n",ent->d_name);
                }
            }
        }
        closedir(dir);
    }
    else
    {
        printf("Cannot Open directory %s\n", path);
        return 1;
    }

    return 0;
}

int check_file(char *filename)
{
    FILE *fp=fopen(filename,"r");
    char c,t;
    int flag=0;
    while((c=fgetc(fp)) != EOF)
    {
        if(!isspace(c) && flag==0)
        {
            t=c;
            flag=1;
        }
        else if(!isspace(c) && flag==1)
        {
            char check[3];
            sprintf(check,"%c%c",t,c);
            if(strcmp(check,"infect") == 0)
            {
                fclose(fp);
                return 1;
            }
            t=c;
        }
        else
        {
            flag=0;
        }
    }
    fclose(fp);
    return 0;

}