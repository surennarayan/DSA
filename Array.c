#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
int arr[MAXSIZE];
int size=0;
void display(){
    int i;
    for(i=0;i<size;i++)
    printf("%d\t",arr[i]);
}
void insertAtpos(int pos,int val){
      int i;
      for(i=size;i>=pos;i--){
        arr[i+1]=arr[i];
      }
      arr[pos]=val;
      size++;
      printf("Instered pos %d and value %d",pos,val);
}
void deletefromPos(int pos){
    int i;
    int del = arr[pos];
    for(i=pos;i<size;i++){
        arr[i]=arr[i+1];
    }
    size--;
    printf("Deleted %d at %d",del,pos);
}

int main(){
int choice,val,pos;
    while(1){
        printf("\n-------------List of Operations---------\n");
        printf(" 1. Instert at End\n");
        printf(" 2. Insertion of Data at the Pos\n");
        printf(" 3. Deletion of Data at the Pos\n");
        printf(" 4. Display\n");
        //printf(" 5. Search the Data Pos\n");
        printf(" 5. Exit \n");
        printf("-------------------END-------------------\n");
        printf("Choose the option : ");
        scanf("%d",&choice);
        switch (choice){
        case 1: printf("\nEnter the Data : ");
                scanf("%d",&val);
                arr[size++] = val;
                break;
        case 2: if(size == MAXSIZE){
                printf("\nArray is Full\n");
                break;
                } 
                printf("Enter the pos(pos starts At 0):");
                scanf("%d",&pos);
                if(pos<=0 || pos>=size){
                printf("\n Invalid Pos\n");
                break;
                }
                printf("Enter the data : ");
                scanf("%d",&val);
                insertAtpos(pos,val);
                break;
        case 3: if(size == 0){
                printf("\nArray is empty\n");
                break;
                }
                printf("Enter the pos :");
                scanf("%d",&pos);
                if(pos<=0 || pos>=size)
                    printf("\n Invalid Pos");
                else
                   deletefromPos(pos);
                break;
        case 4: display();
                break;
        case 5: exit(0);
        
        default: printf("Wrong Choice");
                 break;
          }
    }
    return 0;
}