//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
char *stk;int top;int siz;}stk;
struct queue{
char *que;int front,rear,siz;}que;
void strrev(char *str)
{int i,j;char temp;j=strlen(str)-1;for(i=0;i<j;i++,j--){temp=str[i];str[i]=str[j];str[j]=temp;}}
void initqueue(struct queue *q,int s)
{q->que=(char *)malloc(s*sizeof(char));q->siz=s;q->front=0;q->rear=0;}
void enq(struct queue *q,char t)
{if(q->rear==q->siz)printf("\nQueue Overflow");
else{q->que[q->rear]=t;q->rear++;}}
char deq(struct queue *q)
{
char t;if(q->front==q->rear)printf("\nQueue Underflow");
else{t=q->que[q->front];q->front++;return t;}}
void initstack(struct stack *s,int s1)
{s->stk=(char *)malloc(s1*sizeof(char));
s->siz=s1;s->top=0;}
void push(struct stack *s,char c)
{
if(s->top==s->siz)printf("\nStack Overflow");
else{s->stk[s->top]=c;s->top++;}}
char pop(struct stack *s)
{char t;if(s->top==0)printf("\nStack Underflow");
else{s->top--;t=s->stk[s->top];return t;}}
char *ntoken(char *s)
{
struct stack s1,s2;int i;initqueue(&que,500);
initstack(&s1,strlen(s));initstack(&s2,strlen(s));
for(i=strlen(s)-1;i>=0;i--)push(&s1,s[i]);
char c=' ';while(c!='='&&c!='!'&&c!='<'&&c!='>'&&c!='/'&&c!=' '){c=pop(&s1);push(&s2,c);}
char *pt=(char *)malloc(strlen(s)*sizeof(char));
i=0;c=pop(&s2);while(c!=' ')
{pt[i]=c;i++;c=pop(&s2);}
pt[i]='\0';strrev(pt);return pt;}
void ptoken(char *s)
{
struct stack s1;int i;initstack(&s1,strlen(s));
for(i=strlen(s)-1;i>=0;i--)push(&s1,s[i]);
char c=' ',p=' ';c=pop(&s1);while(c!=' '){enq(&que,c);c=pop(&s1);p=c;}
printf("%s",que.que);}
void pmt(char *t)
{
char *s;int i=0;while(1)
{s=ntoken(t);if(s==NULL)break;
printf("\n");if(strlen(s)==1)printf("%s",s);
else ptoken(s);i+=strlen(s);t+=strlen(s);}}
void main()
{char *str;str=(char *)malloc(200*sizeof(char));printf("\nEnter the string : ");gets(str);pmt(str);}