/*
	Name: Yigit Berkay Asli
	ID: 2315091
*/

#pragma warning(disable:4996) // remove security warnings on VS
#pragma warning(disable:6031) // remove return is ignored warnings on VS
#pragma warning(disable:6011) // remove dereference warnings on VS
#include <stdio.h>
#include <stdlib.h>

int* fillArray(int*);
struct listDef improvedInsertionSort(int[], int);
void printArray(int[], int);
int* insertionSort(int[], int);
int* merge2List(int[], int[], int, int, int*);

struct listDef {
	int* theList;
	int elementCount;
};

int main()
{
	int numOfInts;
	int* numArray = fillArray(&numOfInts);

	struct listDef sortedList = improvedInsertionSort(numArray, numOfInts);

	printArray(sortedList.theList, sortedList.elementCount);

	return 0;
}

int* fillArray(int* numOfInts)
{
	int* arrayToBeReturned;

	scanf("%d\n", numOfInts);

	arrayToBeReturned = (int*)malloc((*numOfInts) * sizeof(int));

	int i;
	for (i = 0; i < *numOfInts; i++)
		scanf("%d\n", &arrayToBeReturned[i]);

	return arrayToBeReturned;
}

struct listDef improvedInsertionSort(int numbers[], int numbersCount)
{
	int i;

	int min = numbers[0];
	int max = numbers[0];

	for (i = 1; i < numbersCount; i++)
	{
		if (numbers[i] > max)
			max = numbers[i];

		if (numbers[i] < min)
			min = numbers[i];
	}

	int range = max - min;
	if (range <= 10)
		range = 11;

	struct listDef list1;
	struct listDef list2;
	struct listDef list3;
	struct listDef list4;
	struct listDef list5;
	struct listDef list6;
	struct listDef list7;
	struct listDef list8;
	struct listDef list9;
	struct listDef list10;

	list1.elementCount = 0;
	list2.elementCount = 0;
	list3.elementCount = 0;
	list4.elementCount = 0;
	list5.elementCount = 0;
	list6.elementCount = 0;
	list7.elementCount = 0;
	list8.elementCount = 0;
	list9.elementCount = 0;
	list10.elementCount = 0;

	list1.theList = (int*)malloc((numbersCount) * sizeof(int));
	list2.theList = (int*)malloc((numbersCount) * sizeof(int));
	list3.theList = (int*)malloc((numbersCount) * sizeof(int));
	list4.theList = (int*)malloc((numbersCount) * sizeof(int));
	list5.theList = (int*)malloc((numbersCount) * sizeof(int));
	list6.theList = (int*)malloc((numbersCount) * sizeof(int));
	list7.theList = (int*)malloc((numbersCount) * sizeof(int));
	list8.theList = (int*)malloc((numbersCount) * sizeof(int));
	list9.theList = (int*)malloc((numbersCount) * sizeof(int));
	list10.theList = (int*)malloc((numbersCount) * sizeof(int));

	for (i = 0; i < numbersCount; i++)
	{
		if ((numbers[i] >= min) && (numbers[i] < min + (range / 10)))
		{
			list1.theList[list1.elementCount] = numbers[i];
			list1.elementCount++;
		}
		else if ((numbers[i] >= min + (range / 10)) && (numbers[i] < min + ((2 * range) / 10)))
		{
			list2.theList[list2.elementCount] = numbers[i];
			list2.elementCount++;
		}
		else if ((numbers[i] >= min + ((2 * range) / 10)) && (numbers[i] < min + ((3 * range) / 10)))
		{
			list3.theList[list3.elementCount] = numbers[i];
			list3.elementCount++;
		}
		else if ((numbers[i] >= min + ((3 * range) / 10)) && (numbers[i] < min + ((4 * range) / 10)))
		{
			list4.theList[list4.elementCount] = numbers[i];
			list4.elementCount++;
		}
		else if ((numbers[i] >= min + ((4 * range) / 10)) && (numbers[i] < min + ((5 * range) / 10)))
		{
			list5.theList[list5.elementCount] = numbers[i];
			list5.elementCount++;
		}
		else if ((numbers[i] >= min + ((5 * range) / 10)) && (numbers[i] < min + ((6 * range) / 10)))
		{
			list6.theList[list6.elementCount] = numbers[i];
			list6.elementCount++;
		}
		else if ((numbers[i] >= min + ((6 * range) / 10)) && (numbers[i] < min + ((7 * range) / 10)))
		{
			list7.theList[list7.elementCount] = numbers[i];
			list7.elementCount++;
		}
		else if ((numbers[i] >= min + ((7 * range) / 10)) && (numbers[i] < min + ((8 * range) / 10)))
		{
			list8.theList[list8.elementCount] = numbers[i];
			list8.elementCount++;
		}
		else if ((numbers[i] >= min + ((8 * range) / 10)) && (numbers[i] < min + ((9 * range) / 10)))
		{
			list9.theList[list9.elementCount] = numbers[i];
			list9.elementCount++;
		}
		else if ((numbers[i] >= min + ((9 * range) / 10)) && (numbers[i] <= max))
		{
			list10.theList[list10.elementCount] = numbers[i];
			list10.elementCount++;
		}
	}

	list1.theList = insertionSort(list1.theList, list1.elementCount);
	list2.theList = insertionSort(list2.theList, list2.elementCount);
	list3.theList = insertionSort(list3.theList, list3.elementCount);
	list4.theList = insertionSort(list4.theList, list4.elementCount);
	list5.theList = insertionSort(list5.theList, list5.elementCount);
	list6.theList = insertionSort(list6.theList, list6.elementCount);
	list7.theList = insertionSort(list7.theList, list7.elementCount);
	list8.theList = insertionSort(list8.theList, list8.elementCount);
	list9.theList = insertionSort(list9.theList, list9.elementCount);
	list10.theList = insertionSort(list10.theList, list10.elementCount);

	struct listDef subList1;
	struct listDef subList2;
	struct listDef subList3;
	struct listDef subList4;
	struct listDef subList5;

	subList1.theList = merge2List(list1.theList, list2.theList, list1.elementCount, list2.elementCount, &subList1.elementCount);
	subList2.theList = merge2List(list3.theList, list4.theList, list3.elementCount, list4.elementCount, &subList2.elementCount);
	subList3.theList = merge2List(list5.theList, list6.theList, list5.elementCount, list6.elementCount, &subList3.elementCount);
	subList4.theList = merge2List(list7.theList, list8.theList, list7.elementCount, list8.elementCount, &subList4.elementCount);
	subList5.theList = merge2List(list9.theList, list10.theList, list9.elementCount, list10.elementCount, &subList5.elementCount);

	struct listDef subSubList1;
	struct listDef subSubList2;

	subSubList1.theList = merge2List(subList1.theList, subList2.theList, subList1.elementCount, subList2.elementCount, &subSubList1.elementCount);
	subSubList2.theList = merge2List(subList3.theList, subList4.theList, subList3.elementCount, subList4.elementCount, &subSubList2.elementCount);

	struct listDef subSubList3;

	subSubList3.theList = merge2List(subSubList1.theList, subSubList2.theList, subSubList1.elementCount, subSubList2.elementCount, &subSubList3.elementCount);

	struct listDef sortedList;

	sortedList.theList = merge2List(subList5.theList, subSubList3.theList, subList5.elementCount, subSubList3.elementCount, &sortedList.elementCount);

	return sortedList;
}

void printArray(int numbers[], int numbersCount)
{
	int i;
	for (i = 0; i < numbersCount; i++)
		printf("%d\n", numbers[i]);
}

int* insertionSort(int numbers[], int numbersCount)
{
	int i, j, temp;
	int n = numbersCount;
	for (i = 1; i <= n - 1; i++)
	{
		j = i;
		while (j > 0 && numbers[j - 1] > numbers[j])
		{
			temp = numbers[j];
			numbers[j] = numbers[j - 1];
			numbers[j - 1] = temp;
			j--;
		}
	}

	return numbers;
}

int* merge2List(int list1[], int list2[], int list1Count, int list2Count, int* newListCount)
{
	int* theListToBeReturned = (int*)malloc((list1Count + list2Count) * sizeof(int));

	int list1Cursor = 0, list2Cursor = 0, theListCursor = 0;
	while (list1Count != list1Cursor && list2Count != list2Cursor)
	{
		if (list1[list1Cursor] < list2[list2Cursor])
		{
			theListToBeReturned[theListCursor] = list1[list1Cursor];
			list1Cursor++;
		}
		else
		{
			theListToBeReturned[theListCursor] = list2[list2Cursor];
			list2Cursor++;
		}
		theListCursor++;
	}

	while (list1Count != list1Cursor)
	{
		theListToBeReturned[theListCursor] = list1[list1Cursor];
		list1Cursor++;
		theListCursor++;
	}

	while (list2Count != list2Cursor)
	{
		theListToBeReturned[theListCursor] = list2[list2Cursor];
		list2Cursor++;
		theListCursor++;
	}

	*newListCount = theListCursor;

	return theListToBeReturned;
}