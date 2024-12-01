/*  Trong siêu thị người ta xếp hàng để thực hiện thanh toán. 
Mỗi giỏ hàng với các hàng hoá được coi như một node trong một 
 cấu trúc hàng đợi.  

1.Khai báo cấu trúc hàng đợi. Các thông tin chứa ở mỗi node sinh viên 
tự đưa vào để đảm bảo các nội dung sau được thực hiện 
2.Loại bỏ từng người ra khỏi hàng đợi sau khi người đó đã thực hiện
 thanh toán xong 
3.Tính tổng số tiền mà thu ngân thu được tại quầy trong một phiên 
làm việc  
4.Xác định số lượng một sản phẩm A đã được bán tại quầy thu ngân  */


#include<stdio.h>
#include <stdlib.h>
#define Max 100
typedef struct{
    int spA;
    int spB;
    int spC;
}sp;
typedef struct {
    char people[50];
    float money;
    sp product;
}customer;
typedef struct {
    customer items[Max];
    int front,rear;
}Queue;
//khởi tạo hàng đợi front ,rear ban đầu là -1
void initializeQueue(Queue *q){
    q->front=-1;
    q->rear=-1;
}
//Kiểm tra hàng đợi đầy
int isFull(Queue *q){
    if(q->rear==Max-1){
        return 1;
    }else return 0;
}
//Kiểm tra hàng đợi rỗng
int isEmpty(Queue *q){
    if(q->front==-1||q->front >q->rear)
    return 1;
    else
    return 0;
}
//Thêm 1 phân tử vào hàng đợi
void enqueue(Queue *q, customer s){
    if(isFull(q)){
        printf("Hàng đợi đầy !\n");
    }else{
        if(q->front==-1)
        q->front=0;
        q->rear++;
        q->items[q->rear]=s;
        printf("Đã thêm %s vào hàng đợi\n",s.people);
    }
}
//Xóa 1 phần tử khỏi hàng đợi
customer dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Hàng đợi đợi rỗng !\n");
        customer empty={"",0,0};
        return empty;
    }else{
        customer item = q->items[q->front];
        q->front++;
        if(q->front >q->rear){
            q->front = q->rear=-1;
        }
       printf("Đã xóa %s ra khỏi hàng đợi\n",item);
        return item;
    }
}
//hiển thị các phần tử hiện có trong phần tử hàng đợi
void display(Queue *q){
    int i;
    if(isEmpty(q)){
        printf("Hàng đợi rỗng!\n");

    }else {
        printf("Các phần tử trong hàng đợi:");
        for(i=q->front;i<=q->rear;i++)
            printf("Tên: %s ",q->items[i].people);
            printf("\n");
    }
}
//Hàm tính tổng tiền thu ngân thu được tại quầy
void income(Queue *q){
    float total=0;
    for(int i=q->front;i<=q->rear;i++){
        total=total+q->items[i].money;
        }
    printf("tổng số tiền thu ngân thu được là %f\n",total);
}
void total(Queue *q){
    int total=0;
    for(int i=q->front;i<=q->rear;i++){
        total=total+q->items[i].product.spA;
    }
    printf("Tổng số sản phẩm A là %d\n",total);
}
int main(){
    Queue q;
    initializeQueue(&q);
    customer s1={"A",100.000,1,2,3};
    customer s2={"B",150.000,4,5,3};
    customer s3={"C",50.000,3,4,5};
    
    enqueue(&q,s1);
    enqueue(&q,s2);
    enqueue(&q,s3);

    display(&q);
    income(&q);
    total(&q);
    printf(" %s thanh toán xong\n",dequeue(&q).people);
    printf(" %s thanh toán xong\n",dequeue(&q).people);
    printf(" %s thanh toán xong\n",dequeue(&q).people);
    return 0;
}