// otrezki.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <iterator>
using namespace std;
void print_map(std::string_view comment, const std::map<int, int>& m)
{
	std::cout << comment;
	for (const auto& [key, value] : m) {
		std::cout << key << " = " << value << "; ";
	}
	std::cout << "\n";
}
int main()
{
	map<int, int> squiz;
	
	double Ua, Ub, numerator_a, numerator_b, denominator;
	
	const int n = 3;
	const int m = 4;
	
	int otrezki[n][m];
	std::cout << "Vvedite kkordinati otrezkov" << endl;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			std::cin >> otrezki[i][j];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			std::cout << otrezki[i][j] << ' ';
		std::cout << std::endl;
	}


	

	for (int i = 0; i < n - 1; ++i) {
	
		for (int k = i + 1; k < n ; ++k) {
			int count = 0;
			


			int x1 = otrezki[i][0];
			int y1 = otrezki[i][1];
			int x2 = otrezki[i][2];
			int y2 = otrezki[i][3];
			int x3 = otrezki[k][0];
			int y3 = otrezki[k][1];
			int x4 = otrezki[k][2];
			int y4 = otrezki[k][3];
			denominator = (y4 - y3) * (x1 - x2) - (x4 - x3) * (y1 - y2);

			if (denominator == 0)// Определитель
			{
				if ((x1 * y2 - x2 * y1) * (x4 - x3) - (x3 * y4 - x4 * y3) * (x2 - x1) == 0 && (x1 * y2 - x2 * y1) * (y4 - y3) - (x3 * y4 - x4 * y3) * (y2 - y1) == 0)
				{
					cout << "OTREZKI PERESEKAUTSA" << endl;
					++count;
					int val1 = squiz[i + 1];
					int val2 = squiz[k + 1];
					squiz[i + 1] = val1 + count;
					squiz[k + 1] = val2 + count;
				}
				else cout << "OTREZKI NE PERESEKAUTSA"<<endl;
			}
			else {
				numerator_a = (x4 - x2) * (y4 - y3) - (x4 - x3) * (y4 - y2);
				numerator_b = (x1 - x2) * (y4 - y2) - (x4 - x2) * (y1 - y2);
				Ua = numerator_a / denominator;
				Ub = numerator_b / denominator;
				if (Ua >= 0 && Ua <= 1 && Ub >= 0 && Ub <= 1) {
					cout << "OTREZKI PERESEKAUTSA" << endl;
					++count;
					int val1 = squiz[i+1];
					int val2 = squiz[k + 1];
						squiz[i + 1] = val1+count;
					squiz[k + 1] = val2+count;

				}
				else {
					cout << "OTREZKI NE PERESEKAUTSA" << endl;
				}
				//cout << (Ua >= 0 && Ua <= 1 && Ub >= 0 && Ub <= 1 ? "OTREZKI PERESEKAUTSA" : "OTREZKI NE PERESEKAUTSA");
			}
		}
	}
	print_map("MAP : ", squiz);
	}


	

	
	
	



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
