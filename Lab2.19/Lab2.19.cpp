#include <iostream>
#include <ctime>


using namespace std;

void quicksort(float*, int, int);

int main()
{
	srand(time(0));
	int col = 1, row = 1;
	cout << "Enter Columns and Rows of mass: ";
	cin >> col >> row;
	if ((col > 0) && (row > 0)) {
		float** mass = new float* [col];
		for (int i = 0; i < col; i++) {
			mass[i] = new float[row];
			for (int j = 0; j < row; j++) {
				mass[i][j] = rand()%9 + 1;
				cout << mass[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < col; i++) {
			quicksort(mass[i], 0, row - 1);
			for (int j = 0; j < row; j++) {
				cout << mass[i][j] << " ";
			}
			cout << endl;
		}
	}

	
}
void quicksort(float* mas, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2];
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l)
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