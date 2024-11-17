#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void zamijeni(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int* GenerateArray(int len, int arrayType)
{
	int* arr = new int[len];
	if (arrayType == 0)
	{
		srand(static_cast<unsigned>(time(0)));

		
		for (int i = 0; i < len; i++)
		{
			arr[i] = rand() % len + 1;
		}
	}
	else if (arrayType == 1)
	{
		for (int i = 0; i < len; i++)
		{
			arr[i] = i + 1;
		}
	}
	else if (arrayType == 2)
	{
		for (int i = len; i >= 0; i--)
		{
			arr[i] = len - i;
		}
	}
	
	return arr;
}
void printArray(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int* CloneArray(int* arr, int len)
{
	int* clone = new int[len];
	for (int i = 0; i < len; i++)
	{
		clone[i] = arr[i];
	}
	return clone;
}
class sortTest {
public:
	int brojIteracija;
	int brojZamjena;
	void Info() 
	{
		
		cout << "\033[1;35m";
		cout << "Broj iteracija: " << brojIteracija << " Broj zamjena: " << brojZamjena << endl;		
		cout << "Efikasnost algoritma: " << brojIteracija + brojZamjena * 2 << endl;
		cout << "\033[0m";
	}
	sortTest()
	{
		brojIteracija = 0;
		brojZamjena = 0;
	}
};

void SelectionSort(int* arr, int len) 
{
	sortTest selectionTest;
	int i, j, minIndex, temp;
	for (int i = 0; i < len; i++)
	{
		selectionTest.brojIteracija++;
		minIndex = i;
		for (j = i + 1; j < len; j++)
		{
			selectionTest.brojIteracija++;
			if (arr[j] < arr[minIndex])			
				minIndex = j;		
		}
						
		
		if (minIndex != i)
		{
			temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
			selectionTest.brojZamjena++;
		}
	}
	selectionTest.Info();
}
void BubbleSort(int* arr, int len) {
	sortTest bubbleTest;
	bool promjena = true;
	int j = 0;
	while (promjena) {
		promjena = false;		
		j++;
		bubbleTest.brojIteracija++;
		for (int i = 0; i < len - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				zamijeni(&arr[i], &arr[i + 1]);				
				bubbleTest.brojZamjena++;
				promjena = true;
			}

		}
	}
	bubbleTest.Info();
}
void InsertionSort(int* arr, int len) {
	sortTest insertionTest;
	for (int i = 0; i < len; i++)
	{
		insertionTest.brojIteracija++;
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j]) 
		{
			zamijeni(&arr[j], &arr[j - 1]);			
			insertionTest.brojIteracija++;
			insertionTest.brojZamjena++;

			j--;
		}
	}
	insertionTest.Info();
}
void main()
{
   int len = 15;
   int* array = GenerateArray(len, 0);
   int* array2 = CloneArray(array, len);
   int* array3 = CloneArray(array, len);
   int* worstCase1 = GenerateArray(len, 2);
   int* worstCase2 = CloneArray(worstCase1, len);
   int* worstCase3 = CloneArray(worstCase1, len);
   int* bestCase1 = GenerateArray(len, 1);
   int* bestCase2 = CloneArray(bestCase1, len);
   int* bestCase3 = CloneArray(bestCase1, len);
 

   
   
   cout << "\033[1;33m";
   cout << "Testiranje prosjecnog slucaja: " << endl;   
   cout << "\033[0m";

   cout << "Testiranje bubble sorta: " << endl;
   printArray(array, len);
   
   BubbleSort(array, len);
   cout << "Sortirani niz: " <<endl;
   printArray(array, len);
   cout << endl;
 
   cout << "Testiranje selection sorta: " << endl;
   printArray(array2, len);
   SelectionSort(array2, len);
   cout << "Sortirani niz: " << endl;
   printArray(array2, len);
   cout << endl;

   cout << "Testiranje insertion sorta: " << endl;
   printArray(array3, len);
   InsertionSort(array3, len);
   cout << "Sortirani niz: " << endl;
   printArray(array3, len);
   cout << endl;
   cout << "***************************************************************" << endl;
   
   cout << "\033[1;31m";
   cout << "Testiranje najgoreg slucaja: " << endl;
   cout << "\033[0m";
   
   cout << "Bubblesort: " << endl;
   printArray(worstCase1, len);
   BubbleSort(worstCase1, len);
   cout << "Sortirani niz: " << endl;
   printArray(worstCase1, len);


   cout << "Selectionsort:" << endl;
   printArray(worstCase2, len);
   SelectionSort(worstCase2, len);
   cout << "Sortirani niz: " << endl;
   printArray(worstCase2, len);

   cout << "Insertionsort:" << endl;
   printArray(worstCase3, len);
   InsertionSort(worstCase3, len);
   cout << "Sortirani niz: " << endl;
   printArray(worstCase3, len);

   cout << "***************************************************************" << endl;
   
   cout << "\033[1;32m";
   cout << "Testiranje najboljeg slucaja: " << endl;
   cout << "\033[0m";

   cout << "Bubblesort" << endl;
   printArray(bestCase1, len);
   BubbleSort(bestCase1, len);
   cout << "Sortirani niz: " << endl;
   printArray(bestCase1, len);

   cout << "Selectionsort" << endl;
   printArray(bestCase2, len);
   SelectionSort(bestCase2, len);
   cout << "Sortirani niz: " << endl;
   printArray(bestCase2, len);

   cout << "Insertionsort" << endl;
   printArray(bestCase3, len);
   InsertionSort(bestCase3, len);
   cout << "Sortirani niz: " << endl;
   printArray(bestCase3, len);
   


   
  
}
