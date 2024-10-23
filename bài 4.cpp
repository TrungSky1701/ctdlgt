#include <iostream>
using namespace std;

typedef struct population {
	int year;
	int people;
}population;

population* init_data(int n) {
	population* DS = new population[n];
	for (int i = 0; i < n; i++) {
		cout << "Nhap nam " << i + 1 << ": ";
		cin >> DS[i].year;
		cout << "Nhap so luong: ";
		cin >> DS[i].people;
	}
	return DS;
}

void print_data(population* DS, int n) {
	cout << "-----------------------" << endl;
	cout << "Nam" << '\t' << "So luong nguoi sinh ra" << endl;
	for (int i = 0; i < n; i++) {
		cout << DS[i].year << "\t\t" << DS[i].people << endl;
	}
	cout << "-----------------------" << endl;
}

int count_same(population* DS, int n, int val) {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (DS[i].people == val) {
			c++;
		}
	}
	return c;
}

void print_same(population* DS, int n, int c, int val) {
	for (int i = 0; i < n; i++) {
		if (DS[i].people == val) {
			cout << DS[i].year << (c != 1 ? ", " : ".");
			c--;
		}
	}
	cout << endl;
}

void print_same_people(population* DS, int n) {
	for (int i = 0; i < n; i++) {
		int c = count_same(DS, n, DS[i].people);
		if (c > 1) {
			cout << "So nam co " << DS[i].people << " nguoi sinh ra la " << c << ": ";
			print_same(DS, n, c, DS[i].people);
		}
	}
}

void print_highest_and_lowest(population* DS, int n) {
	int min = DS[0].people;
	int max = min;
	for (int i = 1; i < n; i++) {
		if (DS[i].people < min) {
			min = DS[i].people;
		}
		if (DS[i].people > max) {
			max = DS[i].people;
		}
	}
	int c = count_same(DS, n, max);
	int d = count_same(DS, n, min);
	cout << "So nam co nguoi sinh nhieu nhat la " << c << ": ";
	print_same(DS, n, c, max);
	cout << "So nam co nguoi sinh it nhat la " << d << ": ";
	print_same(DS, n, d, min);
	
}

int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	population* DS = init_data(n);
	print_data(DS, n);
	print_same_people(DS, n);
	print_highest_and_lowest(DS, n);
	return 0;
}