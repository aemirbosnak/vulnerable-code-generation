//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include<stdio.h>

struct Point{
    int x,y;
};

int direction(struct Point a, struct Point b, struct Point c){
    //Determines the direction of the vector bc with respect to the vector ab
    //Returns +1 if clockwise, -1 if anti-clockwise, and 0 if they are collinear
    int area = (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x);
    if(area < 0) return -1;
    else if(area > 0) return +1;
    else return 0;
}

int main(){
    int n,i;
    scanf("%d",&n);

    struct Point poly[n+1];
    int hull[n+1], top=2;

    for(i=0;i<n;i++)
        scanf("%d%d",&poly[i].x,&poly[i].y);

    //Finding the leftmost point
    int l=0;
    for(i=1;i<n;i++){
        if(poly[i].x < poly[l].x)
            l=i;
    }

    hull[0] = l;

    //Finding the point on hull farthest from the base
    int h=0;
    do{
        h = (h+1)%n;
        for(i=0;i<n;i++){
            if(direction(poly[hull[top-2]], poly[hull[top-1]], poly[i]) == -1)
                break;
        }
        hull[top++] = i;

    }while(i != l);

    //Printing the convex hull
    for(i=0;i<top;i++){
        printf("(%d,%d)\n", poly[hull[i]].x, poly[hull[i]].y);
    }

    return 0;
}