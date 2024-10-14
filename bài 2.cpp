#include <iostream>
#include <cmath>
using namespace std;

bool SoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool SoNguyenTo4k3(int n) {
    return SoNguyenTo(n) && (n % 4 == 3);
}

int* TaoMangBlum(int N, int& count) {
    count = 0; 
    int* blumNumbers = new int[N]; 
    for (int p = 2; p < N; p++) {
        if (SoNguyenTo4k3(p)) {
            for (int q = p; q < N; q++) {
                if (SoNguyenTo4k3(q)) {
                    int blumNumber = p * q;
                    if (blumNumber < N) {
                        blumNumbers[count++] = blumNumber; 
                    }
                }
            }
        }
    }

    return blumNumbers; 
}

void TongLaBlum(int* blumNumbers, int blumCount, int N) {
    for (int i = 0; i < blumCount; i++) {
        for (int j = i + 1; j < blumCount; j++) {
            int sum = blumNumbers[i] + blumNumbers[j];
            for (int k = 0; k < blumCount; k++) {
                if (blumNumbers[k] == sum && sum < N) {
                    std::cout << "Cap so Blum: (" << blumNumbers[i] << ", " << blumNumbers[j] << ") co tong la " << sum << "\n";
                    break;
                }
            }
        }
    }
}

bool LaSoBlum(int M, int* blumNumbers, int blumCount) {
    for (int i = 0; i < blumCount; i++) {
        if (blumNumbers[i] == M) {
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    int blumCount = 0;
    int* blumNumbers = TaoMangBlum(N, blumCount);

    cout << "Cac so Blum nho hon " << N << " la: ";
    for (int i = 0; i < blumCount; i++) {
        std::cout << blumNumbers[i] << " ";
    }
    cout << "\n";
    TongLaBlum(blumNumbers, blumCount, N);
    int M;
    cin >> M;
    if (LaSoBlum(M, blumNumbers, blumCount)) cout << M << " la mot so Blum.\n";
    else cout << M << " khong phai la so Blum.\n";  
    delete[] blumNumbers;
    return 0;
}