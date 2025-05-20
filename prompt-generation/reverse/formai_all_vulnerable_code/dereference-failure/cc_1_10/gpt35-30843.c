//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAX_NODES 20
#define MAX_DEVICES 20

typedef struct device{
    char type[10];
    int nodeA;
    int nodeB;
    float value;
}device;

int nodeCount = 0;
int deviceCount = 0;
int nodeTable[MAX_NODES+1][MAX_DEVICES+1];

void addNode(int nodeNumber){
    int i;
    for(i=0; i<=nodeCount; i++){
        if(nodeTable[i][0]==nodeNumber){ return; }
    }
    nodeTable[nodeCount][0] = nodeNumber;
    nodeCount++;
}

int nodeNumber(char* nodeName){
    int i, n=0;
    char c;
    for(i=1; i<strlen(nodeName); i++){
        c = nodeName[i];
        n = n*10 + (c - '0');
    }
    return n;
}

int getNode(char* nodeName){
    int n = nodeNumber(nodeName);
    int i;
    for(i=0; i<nodeCount; i++){
        if(nodeTable[i][0]==n){
            return i+1;
        }
    }
    return -1;
}

void addDevice(char* deviceName){
    char *deviceType, *nA, *nB, *val;
    deviceType = strtok(deviceName,"(");
    nA = strtok(NULL," ,");
    nB = strtok(NULL," ,");
    val = strtok(NULL," )");
    if(strcmp(deviceType,"R")==0 || strcmp(deviceType,"C")==0 || strcmp(deviceType,"L")==0){
        addNode(nodeNumber(nA));
        addNode(nodeNumber(nB));
        device d;
        strcpy(d.type, deviceType);
        d.nodeA = getNode(nA);
        d.nodeB = getNode(nB);
        d.value = atof(val);
        if(d.nodeA > d.nodeB){
            int temp = d.nodeA;
            d.nodeA = d.nodeB;
            d.nodeB = temp;
        }
        nodeTable[d.nodeA-1][++nodeTable[d.nodeA-1][0]] = deviceCount;
        nodeTable[d.nodeB-1][++nodeTable[d.nodeB-1][0]] = deviceCount;
        deviceCount++;
    }
}

void printNodeTable(){
    int i,j;
    printf("\n\nNODE TABLE\n\n");
    for(i=0; i<nodeCount; i++){
        for(j=0; j<=nodeTable[i][0]; j++){
            printf("%d ", nodeTable[i][j]);
        }
        printf("\n");
    }
}

int main(){
    char line[80], *token;
    device devices[MAX_DEVICES];
    while(1){
        fgets(line,80,stdin);
        token = strtok(line," ");
        if(strcmp(token,".end")==0){ break; }
        if(token[0]=='R' || token[0]=='L' || token[0]=='C'){
            addDevice(token);
        }
    }
    printNodeTable();
    return 0;
}