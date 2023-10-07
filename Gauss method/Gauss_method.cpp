#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int correctInput() { //this function determines whether the entered
	int n;			 //number is the correct dimension of the matrix
	double temp;
	bool ind = false;

	while (!ind) {
		cout << "Enter the dimension of the matrix: ";

		cin >> temp;
		n = temp;

		if (!cin) {
			cout << "The entered number is not an integer." << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (temp - static_cast<double>(n) == 0.0) ind = true;
		else {
			cout << "The entered number is not an integer." << endl;
		}
	}

	return n;
}

string methodOfInput(){ //this function determines how the user wants to enter the matrix 
	string answer;
	bool ind = false;

	while (!ind) {

		cout << "Would you like to enter the matrix manually or from a file?" << endl << "Write \"file\" or \"manually\"" << endl;
		cout << "Or type \"f\" for file and \"m\" for manually." << endl;

		cin >> answer;
		transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c) { return tolower(c); });
		
		if (answer == "file" || answer == "f") {
			ind = true;
			answer = "f";
		}
		else if (answer == "m" || answer == "manually") {
			ind = true;
			answer = "m";
		}
		else {
			cout << "You must enter \"file\" or \"manually\". Try again." << endl;
		}
	}

	return answer;
}

void creatingMatrix(string str, vector<vector<double>>& matrix, vector<double>& b) { //this function creates matrix
	if (str == "f") {
		fstream in("input.txt");

		cout << "Your matrix: " << endl;

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size(); j++) {
				in >> matrix[i][j];
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}

		cout << "Your vector of the right part: " << endl;

		for (int i = 0; i < b.size(); i++) {
			in >> b[i];
			cout << b[i] << endl;
		}
	}
	else {
		cout << "Your matrix: " << endl;

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size(); j++) {
				cin >> matrix[i][j];
			}
		}
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size(); j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}

		cout << "Your vector of the right part: " << endl;

		for (int i = 0; i < b.size(); i++) {
			cin >> b[i];
		}
		for (int i = 0; i < b.size(); i++) {
			cout << b[i];
		}
	}
}

void GaussMethod(int n, vector<vector<double>>& matrix, vector<double>& b, vector<double>& x) {
	for (int i = 0; i < n; i++) {			//this function performs finding a solution
		double mainElement = matrix[i][i];  //to a system of equations by the Gauss method
											//with the selection of the main element
		if (mainElement == 0) {				// as the first element in the row
			cout << "Main element equals to 0." << endl;
			return;
		}

		for (int j = i; j < n; j++) {
			matrix[i][j] /= mainElement;
		}
		b[i] /= mainElement;

		for (int k = i + 1; k < n; k++) {
			double factor = matrix[k][i];
			for (int j = i; j < n; j++) {
				matrix[k][j] -= factor * matrix[i][j];
			}
			b[k] -= factor * b[i];
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		x[i] = b[i];
		for (int j = i + 1; j < n; j++) {
			x[i] -= matrix[i][j] * x[j];
		}
	}

	cout << "Answer: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "x[" << i + 1 << "] = " << x[i] << endl;
	}
}

int main() {
	int n = correctInput();

	string method = methodOfInput();
	
	vector<vector<double>> matrix(n, vector<double>(n));
	vector<double> b(n);
	vector<double> x(n);

	creatingMatrix(method, matrix, b);
	GaussMethod(n, matrix, b, x);

	return 0;
}