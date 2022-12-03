#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
Node templet;
Node* ptr_templet;
static Node* GLobal_Head=NULL;
int Global_count=0;
int count=0;
void Create_list(Node* Data){
    GLobal_Head=(Node*)malloc(sizeof(Node));
    if(GLobal_Head==NULL){
        puts("Memory not allocated");
    }
    else{
        puts("Memory allocated");
        GLobal_Head->Grade=Data->Grade;
        GLobal_Head->ID=Data->ID;
        GLobal_Head->Year=Data->Year;
        strcpy(GLobal_Head->Course_code,Data->Course_code);
        strcpy(GLobal_Head->name,Data->name);
        puts("the data is saved");
        GLobal_Head->next=NULL;
    }
}
void SDB_AddEntry(Node* data1){
    Node * temp=GLobal_Head;
    if(GLobal_Head==NULL){
        Create_list(data1);
    }
    else {
        //capture last node 
        while(temp->next!= NULL){
            temp=temp->next;
        }
        // allocate new node and fill data
        Node* new=(Node*)malloc(sizeof(Node));
        //assgin new data
        new->Grade=data1->Grade;
        new->ID=data1->ID;
        new->Year=data1->Year;
        strcpy(new->Course_code,data1->Course_code);
        strcpy(new->name,data1->name);
        puts("the data is saved");
        new->next=NULL;
        //link new node with the old nodes
        temp->next=new;
        //update count
        Global_count++;
    }
}
void SDB_DeleteEntry(int pos)
{
    Node* deleted_node;
    Node*temp=GLobal_Head;
    int count=0;
    if(pos==0){
        GLobal_Head=temp->next;
        free(temp);
        puts("Head node deleted");
    }
    else if(pos<=Global_count){
        if(GLobal_Head!=NULL){
            while((temp->next)!=NULL){
                if(count==(pos-1)){
                    break;
                }
                temp=temp->next;
                ++count;
            }
            deleted_node=temp->next;
            temp->next=temp->next->next;
            deleted_node->next=NULL;
            free(deleted_node);
            Global_count--;
            puts("Node deleted");
            
        }
    }
    else{
        puts("postion given is not in the list");
    }
}
void display_list(){
    Node* temp;
    int i=0;
    temp=GLobal_Head;
    if (GLobal_Head!=NULL)
    {
        puts("*********************** Linked list elements ***********************");
        while(temp!=NULL){
            
            printf("[%d]",i+1);
            printf("  Name : %s  \n",temp->name);
            printf("  grade %d \n",temp->Grade);
            printf("  ID %d \n",temp->ID);
            printf("  year %d \n",temp->Year);
            printf("  Course code :%s  \n",temp->Course_code);
            puts("**********************************************************************************");
            puts("");
            temp=temp->next;
            ++i;
        }
    }
    else{
        puts("no list to display");
    }
    
}
void SDB_GetIdList()
{
     Node* temp;
    int i=0;
    temp=GLobal_Head;
    if (GLobal_Head!=NULL)
    {
        puts("*********************** ID ***********************");
        while(temp!=NULL){
            
            printf("[%d]",i+1);
            printf("  ID %d \n",temp->ID);
            puts("**********************************************************************************");
            puts("");
            temp=temp->next;
            ++i;
        }
    }
    else{
        puts("no list to display");
    }

}
void SDB_IsIdExist(int ID)
 {
     Node* temp;
    int i=0;
    temp=GLobal_Head;
    char check =0;
    if (GLobal_Head!=NULL)
    {
        while(temp!=NULL){
            if(ID == temp->ID){
                printf("the ID exist in database \n");
                check=1;
                break;
            }
            temp=temp->next;
            ++i;
        }
        if(check== 0){
        puts("ID Doesn't exist in Database");
        }
    }  
}
void SDB_ReadEntry(int ID){    
    Node* temp;
    int i=0;
    temp=GLobal_Head;
    char check =0;
    if (GLobal_Head!=NULL)
    {
        while(temp!=NULL){
            if(ID == temp->ID){
                printf("  Name : %s  \n",temp->name);
                printf("  grade %d \n",temp->Grade);
                printf("  ID %d \n",temp->ID);
                printf("  year %d \n",temp->Year);
                printf("  Course code :%s  \n",temp->Course_code);
            puts("**********************************************************************************");
            puts("");
                check=1;
                break;
            }
            temp=temp->next;
            ++i;
        }
        if(check== 0){
        puts("ID Doesn't exist in Database");
        }
    }  }

 
int SDB_GetUsedSize(){
    return Global_count;
}
int menu(void){
    int data=0;
    printf("enter a choice \n");
    printf("1. to push data \n 2. to pop data \n 3.display linked list \n 4. Get Used size \n 5.print ID for students \n 6.check ID \n 7.Read Entry \n 8.exit \n");
    int choice=0;
    scanf("%d",&choice);
    switch (choice)
    {
    case  1:
        printf("enter data \n");
        printf("enter name : \n");
        // used  %[^\n]s to take string from the user with spaces between each word
        fflush(stdin);
        while(!(scanf("%[^\n]s",templet.name))){
            fflush(stdin);
            printf("enter valid name \n");
        }
        fflush(stdin);
        puts("name saved");
        puts("enter id");
        while(!(scanf("%d",&templet.ID))){
            fflush(stdin);
            printf("enter valid ID \n");
        }
        fflush(stdin);
        puts("ID saved");
        puts("enter year");
        while(!(scanf("%d",&templet.Year))){
            fflush(stdin);
            printf("enter valid year \n");
        }
        fflush(stdin);
        puts("year saved");
        puts("enter course code");
        while(!(scanf("%[^\n]s",&templet.Course_code))){
            fflush(stdin);
            printf("enter valid course code \n");
        }
        fflush(stdin);
        puts("Course code saved");
        puts("enter grade");
        while(!(scanf("%d",&templet.Grade))){
            fflush(stdin);
            printf("enter valid grade \n");
        }
        ptr_templet=&templet;
        SDB_AddEntry(ptr_templet);
        break;
        case 2:
        printf("enter Node you want to delete ( to delete Head press 0)");
        int n=0;
        while(!(scanf("%d",&n))){
            fflush(stdin);
            puts("Enter valid input");
        }
            SDB_DeleteEntry(n);
            break;
        case 3:
            display_list();
            break;

        case 4: 
           printf("enteris used :%d   \n",SDB_GetUsedSize());
           break;
        case 5:
           SDB_GetIdList();
           break;
        case 6:
            printf("enter ID : ");
            int IN_ID=0;
            while(!(scanf("%d",&IN_ID))){
                fflush(stdin);
                puts("Enter valid input");
            }
                SDB_IsIdExist(IN_ID);
                break;
        case 7:
            printf("enter ID : ");
            int IN_Entry=0;
            while(!(scanf("%d",&IN_Entry))){
                fflush(stdin);
                puts("Enter valid input");
            }
                SDB_ReadEntry(IN_Entry);
                break;

        case 8:
            return 0;
        default:
            fflush(stdin);
            puts("enter valid input");
            break;
        };
    return 1;
}