/*Cài đặt cây biểu thức cho biểu thức trên lớp ngày 3/12/2024,
  Biểu thức có dạng :a*5-(b*c^(1/2))/d+(h-v)*e^(1/2)
 và in ra biểu thức theo các cách biểu diễn Trung tố, hậu tố, 
 và tiền tố.
Định nghĩa và khai báo các hàm sau:
Cài đặt thuộc tính cho 1 node trên cây 
Cài đặt hàm khởi tạo cây (không được bỏ qua hàm kiểm tra rỗng)
Cài đặt hàm nhập phần tử (bổ sung) vào cây 
In các phần tử trên cây theo 3 giải thuật duyệt*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
//Định nghĩa cấu trúc Node
typedef struct Node{
    char data[10];
    struct Node* left;
    struct Node* right;
} Node;
//Hàm tạo Node mới
Node* createNode(char *data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){//!newNode trả về true nếu newNode NULL hay if(newNode==NULL)
        printf("Bộ nhớ không đủ để cấp phát\n");
        exit(1);//Hàm trong stdlib.h dùng để kết thức chương trình ngay lập tức
    }
    strcpy(newNode->data, data); // Sao chép chuỗi vào node
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//Hàm kiểm tra cây rỗng
bool isEmpty(Node* root){
     return root==NULL;
}
//Hàm khởi tạo cây
Node * initTree(){
    return NULL;//cây ban đầu rỗng
}

//Hàm kiểm tra toán tử
bool isOperator(char *c){
    return (*c=='+'||*c=='-'||*c=='*'||*c=='/'||*c=='^');
}
//Hàm xây dựng cây biểu thức từ biểu thức hậu tố
Node *buildExpressionTree(char* postfix[],int length){
    Node *stack[100];
    int top=-1;
    for(int i=0;i<length;i++){
        Node * newNode=createNode(postfix[i]);
        if(!isOperator(postfix[i])){
            stack[++top]=newNode;
        }else{
            newNode->right=stack[top--];
            newNode->left=stack[top--];
            stack[++top]=newNode;
        }
    }
    return stack[top];
}

//Duyệt và in phần tử
//cách 1:trung tố
void inOrder(Node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%s ",root->data);
        inOrder(root->right);//
    }
}
//Cachs2: tiền tố
void preOrder(Node *root){
    if(root!=NULL){
        printf("%s ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
//Cách 3:Hậu tố
void postOrder(Node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%s ",root->data);
    }
}
int main(){
    //Biểu thwucs a*5 - (b*c^(1/2))/d + (h-v)*e^(1/2) sang hậu tố:
    // a5* bc12^*d/- hv-e12^*+
   char* postfix[] = {"a", "5", "*", "b", "c", "1", "2", "^", "*", "d", "/", "-", "h", "v", "-", "e", "1", "2", "^", "*", "+"};
    int length = sizeof(postfix) / sizeof(postfix[0]);

    Node* root = buildExpressionTree(postfix, length);

    printf("Biểu diễn Trung tố (In-order): ");
    inOrder(root);
    printf("\n");

    printf("Biểu diễn Hậu tố (Post-order): ");
    postOrder(root);
    printf("\n");

    printf("Biểu diễn Tiền tố (Pre-order): ");
    preOrder(root);
    printf("\n");

    return 0;
}
