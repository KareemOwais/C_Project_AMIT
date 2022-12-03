#ifndef DATA_H
#define DATA_H
#include<stdio.h>
typedef struct main{
    char name[50];
    int ID;
    int Year;
    int Grade;
    char Course_code[50];
    struct main* next;
}Node;
int SDB_GetUsedSize();
void display_list();
void SDB_AddEntry(Node* data1);
void SDB_DeleteEntry(int pos);    
void Create_list(Node* Data);
void SDB_GetIdList();
void SDB_IsIdExist(int ID);
void SDB_ReadEntry(int ID);
int menu(void);

#endif     /* Data.h*/