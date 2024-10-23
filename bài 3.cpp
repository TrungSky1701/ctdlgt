#include<stdio.h>
void nhap(int a[],int n){
    printf("Nhap:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void xuat(int a[],int n){
    printf("\nOutput:\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
void tron(int a[],int b[],int c[]){
    int i=0,k=0;
    int j=0;
    int n=10;
    while((i<5)&&(j<5)){
        if(a[i]<=b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            c[k]=b[j];
            j++;
            k++;
        }
    }

}
void xuat1(int c[],int m){
    for(int i=0;i<m;i++){
        printf("%d",c[i]);
    }
}
int main(){
    int a[5];
    int b[5];
    int c[9];
    nhap(a,5);
    nhap(b,5);
    xuat(a,5);
    xuat(b,5);
    tron(a,b,c);
    xuat1(c,10);
    return 0;
}
