//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<limits.h>

#define PI 3.14159265358979323846
#define R 6371.01
#define MAX 100

typedef struct{
    double lat;
    double lon;
}point;

typedef struct{
    int id;
    point location;
    int time;
    int speed;
    int direction;
}vehicle;

void init(vehicle v[],int n){
    int i;
    for(i=0;i<n;i++){
        v[i].id=i+1;
        v[i].location.lat=rand()%180+(-90);
        v[i].location.lon=rand()%360;
        v[i].time=0;
        v[i].speed=rand()%100+10;
        v[i].direction=rand()%360;
    }
}

void move(vehicle v[],int n,int time){
    int i;
    for(i=0;i<n;i++){
        v[i].time+=time;
        v[i].location.lat+=(v[i].speed/R)*cos(v[i].direction*PI/180)*time;
        v[i].location.lon+=(v[i].speed/R)*sin(v[i].direction*PI/180)*time;
        if(v[i].location.lat<-90) v[i].location.lat+=180;
        if(v[i].location.lat>90) v[i].location.lat-=180;
        if(v[i].location.lon<-180) v[i].location.lon+=360;
        if(v[i].location.lon>180) v[i].location.lon-=360;
    }
}

int main(){
    int n,m;
    printf("Enter the number of vehicles: ");
    scanf("%d",&n);
    printf("Enter the simulation time(in seconds): ");
    scanf("%d",&m);
    vehicle v[n];
    init(v,n);
    int i,j;
    for(i=0;i<m;i++){
        move(v,n,1);
        for(j=0;j<n;j++){
            printf("%d: (%lf,%lf) Speed: %d Direction: %d\n",v[j].id,v[j].location.lat,v[j].location.lon,v[j].speed,v[j].direction);
        }
        printf("\n");
    }
    return 0;
}