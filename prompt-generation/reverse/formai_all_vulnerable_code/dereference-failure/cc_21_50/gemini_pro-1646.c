//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include <stdio.h>
#define C(a) ((a)>255?255:(a)<0?0:(a))

void draw(int w, int h, int *t){
    static int c=9, n=11;
    static int t2[9][11]=
    {
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},
        {-1,-1,-1,-1,-2,-2,-1,-1,-1,-1,-1,},
        {-1,-1,-1,-1,-2,-2,-1,-1,-1,-1,-1,},
        {-1,-1,-1,-1,-3,-3,-1,-1,-1,-1,-1,},
        {-1,-1,-1,-1,-3,-3,-1,-1,-1,-1,-1,},
        {-1,-1,-1,-1,-3,-3,-1,-1,-1,-1,-1,},
    };
    static int x[4]={-1, 0, 0, 1}, y[4]={0, -1, 1, 0};
    int i, j, d, r, r2, p=0, q, m=23, z=0;
    for(j=0; j<h; j++)for(i=0; i<w; i++)
        if(p=t[i+w*j])
        {
            d=t2[(p>>2)&7][p&3];
            for(q=0; q<4; q++){
                if(p==3){
                    r=3;
                    r2=3;
                }
                else{
                    r=(4+d+q)&7;
                    r2=(4+p+q)&7;
                }
                if((i+x[q]<0) || (i+x[q]>=w) || (j+y[q]<0) || (j+y[q]>=h)) if(p==1)m=0;
                else if(p==2)z=0;
                else continue;
                else if(t[(i+x[q])+w*(j+y[q])]%2==0){
                    r=0;
                    r2=0;
                }
                else if(t[(i+x[q])+w*(j+y[q])]==-2){
                    r2=8;
                    m=0;
                    z=0;
                }
            }
            if(m)t[i+w*j]=100*r+10*r2+m+10*t[i+w*j]%10;
            else if(z)t[i+w*j]=100*r+10*r2+z+10*t[i+w*j]%10;
            else t[i+w*j]=100*r+10*r2;
        }
    for(j=0; j<h; j++)for(i=0; i<w; i++){
        p=t[i+w*j];
        if(p){
            r=(p/100)%10;
            r2=(p/10)%10;
            m=p%10;
            z=p/10;
            if(m){
                if(r>5 && r2>=5)t[i+w*j]=0;
                else if(r>5 && r2<5)t[i+w*j]=9+(r2%2);
                else if(r<5 && r2==5)t[i+w*j]=27+(r%2);
                else if(r<5 && r2<5)t[i+w*j]=36+(r%2)+(r2%2);
            }
            else if(z){
                if(r>5 && r2>=5)t[i+w*j]=8;
                else if(r>5 && r2<5)t[i+w*j]=17+(r2%2);
                else if(r<5 && r2==5)t[i+w*j]=35+(r%2);
                else if(r<5 && r2<5)t[i+w*j]=44+(r%2)+(r2%2);
            }
            else{
                if(r>5 && r2>=5)t[i+w*j]=9;
                else if(r>5 && r2<5)t[i+w*j]=18+(r2%2);
                else if(r<5 && r2==5)t[i+w*j]=26+(r%2);
                else if(r<5 && r2<5)t[i+w*j]=35+(r%2)+(r2%2);
            }
            if(m){
                if(r==4)t[i+w*j]+=1;
                if(r2==4)t[i+w*j]+=3;
                if(r==5)t[i+w*j]+=12;
                if(r2==5)t[i+w*j]+=3;
            }
            else if(z){
                if(r==4)t[i+w*j]+=2;
                if(r2==4)t[i+w*j]+=3;
                if(r==5)t[i+w*j]+=14;
                if(r2==5)t[i+w*j]+=3;
            }
            else{
                if(r==4)t[i+w*j]+=2;
                if(r2==4)t[i+w*j]+=3;
            }
        }
    }
}

int main(void){
    static int *t, *t2, w=40, h=18;
    int i, j;
    for(t=t2=(int*)calloc(w*h,sizeof(int));;++t,--h)
        for(i=0;i<w;++i,*t=(i<w/2)*(*t%3+1))
        {
            if(!(*t%2)){
                for(j=0;j<6;++j,*t+=!(*t%3)?2*(*t%3):1);
                *t+=(*t%3?1:0)+((i+(*t%3))%3?2:1);
            }
            *t/=(t2==t?2:1);
        }
    for(i=0;i<w*h;i+=w){
        for(j=0;j<w;++j)printf("%c%c",
            " .?XO@"[C(t[i+j]%10)]," .?XO@"[C(t[i+j]/10%10)]);
        putchar('\n');
    }
    return 0;
}