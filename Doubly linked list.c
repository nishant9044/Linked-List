#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *prev,*next;
}*head,*end;
void create(int n)
{
    int data,i;
    struct node *temp,*newnode;
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter data for node 1\t");
    scanf("%d",&data);
    if(head==NULL){
        printf("Memory not allocated.");
    }
    else{
        head->data=data;
        head->next=NULL;
        head->prev=NULL;
        temp=head;
        end=head;
        for(i=2;i<=n;i++)
        {
            printf("Enter data for node %d\t",i);
            scanf("%d",&data);
            newnode=(struct node*)malloc(sizeof(struct node));
            if(newnode==NULL){
                printf("Memory not allocated.");
            }
            else
            {
                newnode->data=data;
                newnode->next=NULL;
                newnode->prev=temp;
                temp->next=newnode;
                temp=temp->next;
                end=temp;
            }
        }
        printf("All nodes are inserted successfully.\n");
    }
}
void insert_beg(int data_beg){
    struct node*temp,*newnode;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));  
    if(newnode==NULL){
        printf("Memory not allocated.");
    }
    else{
        newnode->data=data_beg;
        newnode->next=temp;
        newnode->prev=NULL;
        head=newnode;
    }
}
void insert_end(int data_end){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));  
    if(newnode==NULL){
        printf("Memory not allocated.");
    }
    else{
        newnode->data=data_end;
        newnode->next=NULL;
        newnode->prev=end;
        end->next=newnode;
        end=end->next;
    }
}
void insert_after(int m){
    int data,i;
    struct node *newnode,*temp;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));  
    printf("Enter data for %d node\t",m);
    scanf("%d",&data);
    if(newnode==NULL){
        printf("Memory not allocated.");
    }
    else{
        for(i=2;i<=m;i++){
            temp=temp->next;
        }
        newnode->data=data;
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
    }
}
void insert_before(int b){
    int data,i;
    struct node *newnode,*temp;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));  
    printf("Enter data for %d node\t",b);
    scanf("%d",&data);
    if(newnode==NULL){
        printf("Memory not allocated.");
    }
    else{
        for(i=2;i<=b;i++){
            temp=temp->next;
        }
        newnode->data=data;
        newnode->next=temp;
        newnode->prev=temp->prev;
        temp->prev->next=newnode;
        temp->prev=newnode;
    }
}
void del_beg(){
    struct node *temp;
    temp=head;
    if(temp==NULL){
        printf("List is Empty.");
    }
    else{
        head=head->next;
        head->prev=NULL;
        printf("\nDeleted data is %d\t",temp->data);
        free(temp);
    }
}
void del_end(){
    struct node *temp;
    temp=end;
    if(temp==NULL){
         printf("List is Empty.");
    }
    else{
        end=end->prev;
        end->next=NULL;
        printf("\nDeleted data is %d\t",temp->data);
        free(temp);
    }
}
void del_mid(int pos){
    int i;
    struct node *temp;
    temp=head;
    if(temp==NULL){
         printf("List is Empty.");
    }
    else{
        for(i=2;i<=pos;i++){
           temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp=head;
    if(temp==NULL){
        printf("\nList is empty.");
    }
    else
    {
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    int n,data_beg,data_end,m,pos,b;
    printf("\nEnter number of nodes you want to insert\t");
    scanf("%d",&n);
    create(n);
    printf("Elements in the List is/are:\t");
    display();
    printf("\nEnter the data which is inserted at beginning\t");
    scanf("%d",&data_beg);
    insert_beg(data_beg);
    printf("Elements in the List is/are:\t");
    display();
    printf("\nEnter the data which is inserted at end\t");
    scanf("%d",&data_end);
    insert_end(data_end);
    printf("Elements in the List is/are:\t");
    display();
    printf("\nAfter which position you want to insert data:\t");
    scanf("%d",&m);
    insert_after(m);
    printf("Elements in the List is/are:\t");
    display();
    printf("\nBefore which position you want to insert data:\t");
    scanf("%d",&b);
    insert_before(b);
    printf("Elements in the List is/are:\t");
    display();
    del_beg();
    printf("\nAfter deleting element from beginning the List is:\t");
    display();
    del_end();
    printf("\nAfter deleting element from end the List is:\t");
    display();
    printf("\nWhich node you want to delete\t");
    scanf("%d",&pos);
    del_mid(pos);
    printf("\nAfter deleting %d node from list, the List is:\t",pos);
    display();
    return 0;
}