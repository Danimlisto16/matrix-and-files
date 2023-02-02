#include <iostream>
#include <fstream>

using namespace std;

// declaracion de funciones
void loadMatrix(string fileName, int mat[][2])
{

	int n, m, value;
	ifstream myfile;

	myfile.open(fileName.c_str());
	myfile >> n >> m;

	mat[n][m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			myfile >> value;
			// cout << value<< " ";
			mat[i][j] = value;
		}
		cout << endl;
	}

	myfile.close();
}

void plusMatrix(int m1[][2], int m2[][2], int m3[][2], int n, int m)
{

	m3[n][m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			m3[i][j] = m1[i][j] + m2[i][j];
}

void display(int mult[][2], int rowFirst, int columnSecond)
{
	int i, j;

	cout << "Output Matrix:" << endl;
	for (i = 0; i < rowFirst; ++i)
	{
		for (j = 0; j < columnSecond; ++j)
		{
			cout << mult[i][j] << " ";
			if (j == columnSecond - 1)
				cout << endl
					 << endl;
		}
	}
}

void writeFile(int mat[][2], int n, int m)
{
	ofstream MyFile("matrixRes.txt");

	// Write to the file
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			MyFile << mat[i][j];
			MyFile << "\t";
		}
		MyFile << "\n";
	}

	// Close the file
	MyFile.close();
}

int main()
{

	int firstMatrix[2][2],
		secondMatrix[2][2],
		resMatrx[2][2];

	loadMatrix("m1.txt", firstMatrix);
	display(firstMatrix, 2, 2);

	loadMatrix("m2.txt", secondMatrix);
	display(secondMatrix, 2, 2);

	plusMatrix(firstMatrix, secondMatrix, resMatrx, 2, 2);
	display(resMatrx, 2, 2);

	writeFile(resMatrx, 2, 2);

	return 0;
}
