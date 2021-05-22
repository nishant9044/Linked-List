#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head;
void create(int n)
{
    int data,i;
    struct node *newnode,*temp;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Memory not allocated.");
    }
    else{
        printf("Enter data in node 1:\t");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;
         }
        for(i=2;i<=n;i++)
        {   
            newnode=(struct node*)malloc(sizeof(struct node));
            if(newnode==NULL)
            {
                printf("Memory is not allocated.\n");
            }
            else{
                printf("Enter data for node %d\t",i);
                scanf("%d",&data);
                newnode->data=data;
                newnode->next=NULL;
                temp->next=newnode;
                temp=temp->next;
            }
        }printf("\nNode inserted successfully.\n");
}

void display()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("List is Empty.");
    }
    else{
    while(temp!=NULL)
    {
        printf(" %d\t",temp->data);
        temp=temp->next;
    }
    }
}
void mid(int pos,int data)
{
    int i;
    struct node *temp,*newnode;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
            if(newnode==NULL)
            {
                printf("Memory is not allocated.\n");
            }
            else{
                newnode->data=data;
                newnode->next=NULL;
                for(i=1;i<pos-1;i++)
                {
                    temp=temp->next;
                }
                newnode->next=temp->next;
                temp->next=newnode;
                temp=temp->next;
                printf("\nNode inserted Successfully.");
            }
}
void beg(int data_beg){
    struct node *newnode,*temp;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("\nMemory not allocated.");
    }
    else{
        newnode->data=data_beg;
        newnode->next=temp;
        head=newnode;
        printf("\nNode inserted Successfully.\n");
    }
}
void end(int data_end){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("\nMemory not allocated.");
    }
    else{
        newnode->data=data_end;
        newnode->next=NULL;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        printf("\nNode inserted Successfully.\n");
    }
}
void del_beg(){
    struct node *temp;
    temp=head;
    printf("\nDeleted data will be %d",temp->data);
    head=head->next;
    free(temp);
}
void del_end(){
    struct node *temp,*pretemp;
    temp=head;
    pretemp=head;
    while(temp->next!=NULL){
        pretemp=temp;
        temp=temp->next;
    }
    pretemp->next=NULL;
    printf("\nDeleted node is %d",temp->data);
    free(temp);
}
void del_mid(int l){
    int i;
    struct node *pretemp,*temp;
    temp=head;
    pretemp=head;
    for(i=2;i<=l;i++){
        pretemp=temp;
        temp=temp->next;
    }
    pretemp->next=temp->next;
    printf("\nDeleted node is %d",temp->data);
    free(temp);
}
int main(){
    int n,data,pos,data_beg,data_end,l;
    printf("How many you want to Insert\t");
    scanf("%d",&n);
    create(n);
    printf("\nElements in list are\t");
    display();
    printf("\nAt which position and data you want to insert:\t");
    scanf("%d%d",&pos,&data);
    mid(pos,data);
    printf("\nEnter data for beginning.\t");
    scanf("%d",&data_beg);
    beg(data_beg);
    printf("\nElements in list are\t");
    display();
    printf("\nEnter data for ending.\t");
    scanf("%d",&data_end);
    end(data_end);
    printf("\nElements in list are\t");
    display();
    del_beg();
    del_end();
    printf("\nElements in list are\t");
    display();
    printf("\nWhich postion you want to delete\t");
    scanf("%d",&l);
    del_mid(l);
    printf("\nElements in list are\t");
    display();
    return 0;
}