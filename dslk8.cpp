#include<stdio.h>
#include<stdlib.h>
//Định nghĩa cấu trúc Node
struct Node {
    int a;
    int exp;
    struct Node* next;
};
//Hàm tạo node mới
struct Node* createNode(int a,int exp){
    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode->a =a;
    newNode->exp=exp;
    newNode->next =NULL;
    return newNode;
}
//Hàm chèn node mới vào đầu danh sách
void insert(struct Node** head,int a,int exp){
    struct Node* newNode = createNode(a,exp);
    newNode->next =*head;
    *head=newNode;
}
//Hàm nhập đa thức
void input(struct Node**head){
    int n,a,exp;
    printf("nhập bậc: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Nhap he so va so mu cho hạng tử %d ",i+1);
        scanf("%d %d",&a,&exp);
        insert(head,a,exp);
    }
}
void output(struct Node* head){
    struct Node* temp=head;
    while(temp!= NULL){
        if(temp->a >0 && temp!= head){
            printf(" + ");
        }

        if(temp->exp ==0){
            printf("%d",temp->a);
        }
        else if(temp->exp==1){
            printf("%dx",temp->a);
        }
        else {
            printf("%dx^%d",temp->a,temp->exp);
        }
        temp=temp->next;
    }
    printf(" = 0");
    printf("\n");
}
int main(){
    struct Node*head=NULL;
    input(&head);
    printf("Da thuc vua nhap: ");
    output(head);
    //giait phóng bộ nhớ
    struct Node* temp;
    while(head != NULL){
        temp=head;
        head=temp->next;
        free(temp);
    }
    return 0;
}