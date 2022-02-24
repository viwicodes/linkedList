#include <stdio.h>
#include <malloc.h>
struct node{
int data;
struct node *next;
}*temp,*head=NULL,*p;
void insertAtfirst();
void insertAtEnd();
void deleteAtFront();
void deleteAtEnd();
void display();
int main(){
  int choice;
  do{
    scanf("%d",&choice);
    switch(choice){
      case 1:{
        int x;
        scanf("%d",&x);
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=x;
        insertAtfirst();
        break;
      }
      case 2:{
        display();
        break;
      }
      case 3:{
        int x;
        scanf("%d",&x);
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=x;
        insertAtEnd();
        break;
      }
      case 4:{
        deleteAtFront();
        break;
      }
      case 5:{
        deleteAtEnd();
        break;
      }
      default:
        printf("Type again\n");
    }
  }while(choice!=6);
}
void insertAtfirst(){
  if(head==NULL){
    head=temp;
    head->next=head;
  }
  else{
    temp->next=head;
    p=head;
    while(p->next!=head){
      p=p->next;
    }
    head=temp;
    p->next=head;
  }
}
void display(){
  if(head==NULL){
    printf("Empty node\n");
  }
  else{
    p=head;
    while(p->next!=head){
      printf("%d ",p->data);
      p=p->next;
    }
    printf("%d \n",p->data);
  }
}
void insertAtEnd(){
  if(head==NULL){
    head=temp;
    temp->next=head;
  }
  else{
    p=head;
    while(p->next!=head){
      p=p->next;
    }
    temp->next=head;
    p->next=temp;
  }
}
void deleteAtFront(){
  if(head==NULL){
    printf("Empty node\n");
  }
  else{
    if (head->next==head){
      head=NULL;
    }
    else{
    p=head;
    while(p->next!=head){
      p=p->next;
    }
    p->next=head->next;
    head=head->next;
  }
  }
}
void deleteAtEnd(){
  if(head==NULL){
    printf("Empty node\n");
  }
  else{
    if(head->next==head){
      head=NULL;
    }
    else{
    p=head;
    while(p->next->next!=head){
      p=p->next;
    }
    p->next=head;
    }
  }
}
