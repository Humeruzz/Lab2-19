#include <iostream>

using namespace std;

void quicksort(float*, int, int);

int main()
{
	int col = 1, row = 1;
	cout << "Enter Columns and Rows of mass: ";
	cin >> col >> row;
	float** mass = new float*[col];
	for (int i = 0; i < col; i++) {
		mass[i] = new float[row];
		for (int j = 0; j < row; j++) {
			mass[i][j] = rand()+1%((rand()/(rand()+1))+1);
		}
	}
	for (int i = 0; i < col; i++) {
		quicksort(mass[i], 0, row - 1);
		for (int j = 0; j < row; j++) {
			cout << mass[i][j] << " ";
		}
		cout << endl;
	}

	
}
void quicksort(float* mas, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; //вычисление опорного элемента
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l) //перестановка элементов
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksort(mas, first, l);
	if (f < last) quicksort(mas, f, last);
}