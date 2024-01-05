#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double a[][N]){
	for (int i = 0; i < N; i++)
	{
		cout << "Row " << i+1 << ": ";
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}
}

void findLocalMax(const double a[][N], bool b[][N]){
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == 0 || j == 0 || i == N-1 || j == N-1)
			{
				b[i][j] = 0;
			}
		}
	}
	for (int e = 0; e < N; e++)
	{
		for (int q = 0; q < N; q++)
		{
			if (e == 0 || q == 0 || e == N-1 || q == N-1)
			{
				continue;
			}
			bool up,down,left,right,result;
			up = a[e][q]>= a[e-1][q];
			down = a[e][q]>= a[e+1][q];
			left = a[e][q]>= a[e][q-1];
			right = a[e][q]>= a[e][q+1];
			result = up&down&left&right;
			if (result == true)
			{
				b[e][q]= 1;
			}else{
				b[e][q]= 0;
			}
			
		}
		
	}
	
	
}

void showMatrix(const bool a[][N]){
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	
}
