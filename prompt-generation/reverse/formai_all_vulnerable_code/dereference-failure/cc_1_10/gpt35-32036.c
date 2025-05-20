//FormAI DATASET v1.0 Category: Error handling ; Style: interoperable
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<string.h>

//utility function to check the value of errno and terminate the program if necessary.
void check_errno(char* message){
    if(errno!=0){
        perror(message);
        exit(EXIT_FAILURE);
    }
}

//utility function to perform necessary cleanup if necessary before terminating the program.
void cleanup(FILE* file){
    if(fclose(file)!=0){
        perror("File Close Error");
    }
}

//a struct representing a point in a 2D plane
typedef struct Point{
    int x;
    int y;
}Point;

//function to create a new Point instance.
Point* create_point(int x, int y){
    Point* point=(Point*)calloc(1,sizeof(Point));
    if(point==NULL){
        check_errno("Memory Allocation Error");
    }
    point->x=x;
    point->y=y;
    return point;
}

//function that reads Point data from a file stream.
Point* read_point(FILE* file){
    int x,y;
    size_t read=fscanf(file,"%d %d",&x,&y);
    if(read!=2){
        if(ferror(file)){
            perror("File Read Error");
        }
        else if(feof(file)){
            fprintf(stderr, "Unexpected End Of File\n");
        }
        cleanup(file);
        exit(EXIT_FAILURE);
    }
    return create_point(x,y);
}

//main function 
int main(){
    FILE* file=fopen("points.txt","r");
    check_errno("File Open Error");

    //an array to store points
    Point* points[5];
    size_t index=0;
    Point* point;
    while((point=read_point(file))!=NULL){
        points[index++]=point;
        if(index==5){
            break;
        }
    }
    check_errno("File Read Error");
    printf("Read %ld points from file\n",index);

    //print out all points from the array
    for(size_t i=0;i<index;i++){
        printf("Point %ld : x=%d, y=%d\n",i+1,points[i]->x,points[i]->y);
    }

    //clean up memory and close file stream
    for(size_t i=0;i<index;i++){
        free(points[i]);
    }
    cleanup(file);

    return 0;
}