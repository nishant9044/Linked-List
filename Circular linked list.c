#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next,*prev; 
}*head,*end;
void create(int n){
	struct node *newnode,*temp;
	int i,data;
	head=(struct node*)malloc(sizeof(struct node));
	printf("Enter data for 1 node\t");
	scanf("%d",&data);
	head->data=data;
	head->next=NULL;
	head->prev=NULL;
	end=head;
	temp=head;
	temp=end;
	for(i=2;i<=n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data for %d node\t",i);
		scanf("%d",&data);
		newnode->data=data;
		newnode->next=head;
		newnode->prev=temp;
		head->prev=newnode;
		temp->next=newnode;
		temp=temp->next;
		end=temp;
	}printf("\nAll nodes are inserted successfully.");
}
void insert_beg(int data_beg){
	struct node *temp,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	temp=head;
	newnode->data=data_beg;
	newnode->prev=end;
	newnode->next=end->next;
	end->next=newnode;
	temp->prev=newnode;
	head=newnode;
}
void insert_end(int data_end){
	struct node *temp,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	temp=end;
	newnode->data=data_end;
	newnode->next=temp->next;
	head->prev=newnode;	
	newnode->prev=temp;
	temp->next=newnode;	
	end=newnode;
	printf("\nEnd data is:\t",end->data);
}
void display(){
	struct node *temp;
	temp=head;
	if(temp==NULL){
		printf("List is Empty.");
	}
	else{
		while(temp->next!=head)
		{
			printf("%d\t",temp->data);	
			temp=temp->next;
		}
	}
	printf("%d\t",temp->data);
}
void insert_after(int pos){
	struct node *temp,*newnode;
	int i,data;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data for node:\t");
	scanf("%d",&data);
	temp=head;
	for(i=2;i<=pos;i++){
		temp=temp->next;
	}
	newnode->data=data;
	newnode->prev=temp;
	newnode->next=temp->next;
	temp->next->prev=newnode;
	temp->next=newnode;
	printf("\nHead data is:%d\t",head->data);
}
int main(){
	int n,data_beg,data_end,pos;
	printf("Hpw many nodes you want to Insert\t");
	scanf("%d",&n);
	create(n);
	printf("\nEnter data for insert at beginning:\t");
	scanf("%d",&data_beg);
	insert_beg(data_beg);
	printf("Enter data for insert at end:\t");
	scanf("%d",&data_end);
	insert_end(data_end);
	printf("\nElements in list is/are:\t");
	display();
	printf("\nAfter which postion you want to insert:\t");
	scanf("%d",&pos);
	insert_after(pos);
	printf("\nElements in list is/are:\t");
	display();
	return 0;
}