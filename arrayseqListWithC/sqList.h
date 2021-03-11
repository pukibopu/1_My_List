
#include<stdio.h>

#define MAX 100
#define OK 0
#define ERROR -1

typedef int ElemType; 
typedef int Status;

typedef struct
{
    ElemType*elem;
    int Lenth;

}SqList;

//初始化一个空的顺序表
Status InitList(SqList&L)
{
    L.elem =new ElemType[MAX];
    if(!L.elem) return ERROR;
    L.Lenth=0;
    return OK;
}