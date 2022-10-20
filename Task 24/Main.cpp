// проэкт создан с помощью персонального шаблона
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// вывод массва
template<typename T>
void show_arr(T arr[], const int len) {
	cout << '[';
	for (int i = 0; i < len; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
// заполнение массива
template<typename T>
void fill_arr(T arr[], const int len, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		arr[i] = begin + rand() % (begin - end);
}

// Задача 2

template<typename T>
void resize_arr(T*& arr, const int len, int newlen) {
	if (newlen <= 0)
		return;
	T* tmp = new T[len + newlen - len]{};
	for (int i = 0; i < len; i++)
		tmp[i] = arr[i];
	delete[]arr;
	arr = tmp;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// Задача 1

	cout << "Введите длины массивов: ";
	cin >> n >> m;
	int* A = new int[n];
	int* B = new int[m];
	fill_arr(A, n, 10, 50);
	fill_arr(B, m, 50, 100);
	cout << "Массив А:\n";
	show_arr(A, n);
	cout << "Массив B:\n";
	show_arr(B, m);
	int* C = new int[n + m];
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = n; i < n + m; i++)
		C[i] = B[i - n];
	cout << "Массив С состоящий из массивов А и В:";
	show_arr(C, n + m);
	delete[] A;
	delete[] B;

	// Задача 2

	cout << "введите длину массива: ";
	int size1;
	cin >> size1;
	int* arr1 = new int[size1];
	cout << "изначальный массив: ";
	fill_arr(arr1, size1, 0, 10);
	show_arr(arr1, size1);
	cout << "введите новую длину массива:\n";
	cin >> n;
	resize_arr(arr1, size1, n);
	cout << "итоговый массив:";
	show_arr(arr1, size1 + n - size1);

	return 0;
}