/*This program contains functions to manipulate strings, namely- stringlength and stringNCompare
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int stringlength(const char* arr, int SIZE);
int stringNCompare(const char* arr1, const char* arr2, int SIZE);

int main()
{
	const int SIZE = 30;
	char input1[SIZE];
	char input2[SIZE];

	cout << "Please enter string1: ";
	cin.getline(input1, SIZE);
	cout << "Please enter string2: ";
	cin.getline(input2, SIZE);
	
	char goAgain;
	int choice;
	
	do
	{
		cout << " Please make a selection: " << endl;
		cout << " 1. stringlength \n";
		cout << " 2. stringNCompare \n";
		//cout << " 3. exit\n";
		cin >> choice;
		
			if (choice == 1)
			{
				cout << " the length of string1 is : " << stringlength(input1, SIZE) << endl;
				cout << " the length of string2 is : " << stringlength(input2, SIZE) << endl;
			}
			else if (choice == 2)
			{
				int x;
				int num;
				cout << " How many letters would you like to compare ?";
				cin >> num;
				x = stringNCompare(input1, input2, num);

				if (x == 0)
					cout << " \nThe two strings are identical! \n";
				else if (x == -1)
					cout << "String1 is smaller than string 2! \n";
				else if (x == 1)
					cout << " String1 is larger than string 2! \n";
			}

			else
			{
				cout << " This is an invalid selection. Please select again. \n";	
			}

		cout << " Would you like to choose again? Y for yes or N for no:";
		cin >> goAgain;

	} while (toupper(goAgain) == 'Y');

	system("pause");
	return 0;
}

int stringlength(const char* arr, int SIZE)
{
	int count = 0;
	while (*arr != '\0' && count < SIZE)
	{
		cout << "\n" << *arr << " " << count << endl;
		arr++;
		count++;
	}
	return count;
	//count = 0;
}

int stringNCompare(const char* arr1, const char* arr2, int num)
{
	int count = 0;									//Loop counter

												//Check to see if both strings are empty.
	if (*(arr1 + count) == '\0')
		cout << "\n String 1  is empty. \n";
	if (*(arr2 + count) == '\0')
		cout << "\n String 2 is empty. \n";

	//Compare the two strings based on their ASCII values.
	while (*(arr1 + count) != '\0' && *(arr2 + count) != '\0' && count < num)
	{
		if (*(arr1 + count) == *(arr2 + count))
		{
			cout << count << num << *(arr1 + count) << *(arr2 + count) << endl;
			count++;	
		}
		else if (*(arr1 + count) < *(arr2 + count))
		{
			return -1;
			break;
		}
		else if (*(arr1 + count) > *(arr2 + count))
		{
			return 1;
			break;
		}	
		
	}
	return 0;
}