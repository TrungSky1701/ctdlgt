#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Định nghĩa cấu trúc Node
struct Node{
    char word[50];
    struct Node* next;
};
//Hàm tạo node mới
struct Node* createNode(const char* word){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    newNode->next =NULL;
    return newNode;
}
//hàm chèn node mới vào cuối danh sách liên kết
void insertAtEnd(struct Node** head,const char *word){
    struct Node* newNode = createNode(word);
    if(*head ==NULL){
        *head = newNode;
    }else{
        struct Node* tmp = *head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}
//Hàm in danh sách các từ
void print(struct Node* head){
    struct Node* tmp = head;
    while (tmp != NULL){
        printf("%s ",tmp->word);
        tmp =tmp->next;
    }
    printf("\n");
}
// Hàm giải phóng bộ nhớ đã cấp phát
void freeList(struct Node* head){
    struct Node* tmp;
    while(head != NULL){
        tmp=head;
        head= head->next;
        free(tmp);
    }
}
//Xác đình từ xuất hiện nhiều nhất trong câu:
void findMostFrequentWord(struct Node* head) { 
   struct Node* cur = head;
   struct Node* index = head;
   int coust = 1;
   int max = 1;
   while(cur != NULL){
    index = cur->next;
    while(index != NULL){
        if(strcasecmp(cur->word,index->word)==0){
            coust++;
        }
        if(coust>max){
            max = coust;
        }
      index=index->next;
    } 
    if(max>1){
    printf("từ' %s 'xuất hiện %d lần\n",cur->word,max);}
    coust=1;
    max=1;
    cur = cur->next;
   }
}
//một bỏ một từ láy trong từ láy
void freeLay(struct Node* head){
    struct Node* cur= head;
    struct Node* index=head;
    
    while(cur!=NULL){
         index=cur->next;
        
         while(index!= NULL){
           
            if(strcasecmp(index->word,cur->word)==0){
                cur->next=index->next;
                free(index);
                index=cur->next;
                
      
            }else{
                index=index->next;
            }
        }
    cur=cur->next;
    }
}
 int countNodes(struct Node* head) {
     int count = 0;
      struct Node* temp = head; 
      while (temp != NULL) { 
        count++; temp = temp->next; 
        } 
        return count; 
        }

   


int main(){
    struct Node*head=NULL;
    //THêm  các từ vào danh sách lk
    insertAtEnd(&head,"Tớ");
    insertAtEnd(&head,"ăn");
    insertAtEnd(&head,"là");
    insertAtEnd(&head,"là");
    //in 
    printf("Câu đã viết:");
    print(head);
  
    findMostFrequentWord(head); 
   
    freeLay(head);
    printf("danh sách sau khi xóa là:");
    print(head);
    int nodeCount = countNodes(head); 
    printf("Số lượng node trong danh sách: %d\n", nodeCount);
    freeList(head);
    return 0;
}