#include<stdio.h>
#include<stdlib.h>
//Định nghĩa cấu trúc Node
struct Node {
    int a;
    struct Node* next;
};
//Hàm tạo node mới
struct Node* createNode(int a){
    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode->a =a;
    newNode->next =NULL;
    return newNode;
}//chèn vào cuối danh sách
void insertAtEnd(struct Node** head, int a) {
    struct Node* newNode = createNode(a);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//Hàm nhập đa thức
void input(struct Node**head,int n){
    int a;
    
    for(int i=n;i>=0;i--){
        printf("Nhap he so x^%d ",i);
        scanf("%d",&a);
        insertAtEnd(head,a);
    }
}
void output(struct Node* head,int n){
    struct Node* temp=head;
    while(temp!= NULL){
        for(int i=n;i>=0;i--){
        if(temp->a >0 && temp!= head&& i!=n){
            printf(" + ");
        }

        if(i ==0){
            printf("%d",temp->a);
        }
        else if(i==1){
            printf("%dx",temp->a);
        }
        else {
            printf("%dx^%d",temp->a,i);
        }
        temp=temp->next;
    }
    }
    printf(" = 0");
    printf("\n");
}
int main(){
    int n;
    struct Node*head=NULL;
     printf("nhập bậc: ");
    scanf("%d",&n);
    input(&head,n);
    printf("Da thuc vua nhap: ");
    output(head,n);
    //giait phóng bộ nhớ
    struct Node* temp;
    while(head != NULL){
        temp=head;
        head=temp->next;
        free(temp);
    }
    return 0;
}