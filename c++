#include <iostream>
#include<string>
#define RED 0
#define WHITE 1
#define BLUE 2
#define SIZE 9  

using namespace std;

void sortColors(int colors[], int size) {
    int temp;
  for(int i=0;i<size-1;i++){
      for(int j=i+1;j<size;j++){
          if(colors[i]>colors[j]){
              temp = colors[i];
              colors[i]=colors[j];
              colors[j]=temp;
          }
      }
  }
}
string colorToString(int color) {
    switch (color) {
        case 0: return "đỏ";
        case 1: return "trắng";
        case 2: return "xanh";
        default: return "không xác định";
    }
}
int main() {
    int colors[SIZE] = {BLUE, RED, BLUE, RED, RED, WHITE, RED, BLUE, WHITE};
    
    cout << "Input: ";
    for (int i = 0; i < SIZE; i++) {
        cout <<colorToString( colors[i]) << " ";
    }
    cout << endl;

    sortColors(colors, SIZE);

    cout << "Output: ";
    for (int i = 0; i < SIZE; i++) {
        cout << colorToString( colors[i]) << " ";
    }

    return 0;
}


