#include<stdio.h>
#include<stdlib.h>
//Hàm in đa thức
void output(int a[],int n){
    for(int i=n;i>=0;i--){
        if(a[i]!=0){
            if(i!=n && a[i]>0){
                printf(" + ");
            }
            if(i==0){
                printf("%d",a[i]);
            }else if(i==1){
                printf("%dx",a[i]);
            }else{
                printf("%dx^%d",a[i],i);
            }
        }
    } 
    printf(" = 0");
    printf("\n");
}
//Hàm nhập đa thức:
void input(int a[],int n){
    for(int i=n;i>=0;i--){
        printf("Nhap hẹ so X^%d:i");
        scanf("%d",&a[i]);
    }
}
int main(){
    int n;
    printf("Nhap bac cua da thuc: ");
    scanf("%d",&n);
    int* a= (int*)malloc((n+1) * sizeof(int));//cấp phát bộ nhớ cho mảng a (n+1) phần tử
    input(a,n);
    printf("Đa thuc vua nhap: ");
    output(a,n);
    free(a);
    return 0;
}