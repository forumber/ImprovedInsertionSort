/*
	Name: Yigit Berkay Asli
	ID: 2315091
*/

#pragma warning(disable:4996) // remove security warnings on VS
#pragma warning(disable:6031) // remove return is ignored warnings on VS
#pragma warning(disable:6011) // remove dereference warnings on VS
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct listDef {
	int* theList;
	unsigned int elementCount;
};

int checkFile(char[]);
int* fillArray(unsigned int*, char[]);
struct listDef improvedInsertionSort(int[], unsigned int);
void printArray(int[], unsigned int);
void writeArray(int[], unsigned int, char[]);
void* insertionSort(struct listDef*);
int* merge2List(int[], int[], unsigned int, unsigned int, unsigned int*);

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("usage: improvedinsertionsort <input file name> <output file name>");
		exit(1);
	}

	if (checkFile(argv[1]))
	{
		printf("The input file could not be opened, is empty or is not exist");
		exit(1);
	}

	unsigned int numOfInts;
	int* numArray = fillArray(&numOfInts, argv[1]);

	printf("\n");
	struct listDef sortedList = improvedInsertionSort(numArray, numOfInts);
	printf("\n");

	writeArray(sortedList.theList, sortedList.elementCount, argv[2]);

	return 0;
}

int checkFile(char fileName[])
{
	FILE* txt = fopen(fileName, "r");

	if (txt == NULL) // file is not present
		return 1;

	char firstLine;
	fscanf(txt, "%c", &firstLine);

	if (firstLine == 0) // file is empty
	{
		fclose(txt);
		return 1;
	}

	fclose(txt);

	return 0;
}

int* fillArray(unsigned int* numOfInts, char inputFileName[])
{
	printf("Opening %s\n", inputFileName);

	FILE* txt = fopen(inputFileName, "r");

	int* arrayToBeReturned;

	fscanf(txt, "%u\n", numOfInts);

	arrayToBeReturned = (int*)malloc((*numOfInts) * sizeof(int));

	printf("Reading and storing %u number to memory\n", *numOfInts);

	unsigned int i;
	for (i = 0; i < *numOfInts; i++)
		fscanf(txt, "%d\n", &arrayToBeReturned[i]);

	fclose(txt);

	printf("Reading operation has been completed\n");
	return arrayToBeReturned;
}

struct listDef improvedInsertionSort(int numbers[], unsigned int numbersCount)
{
	printf("Begin of improvedInsertionSort\n");
	printf("Creating and filling 10 list\n");
	unsigned int i;

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

	pthread_t threads[10];

	printf("Begin of regular insertion sort to 10 list\n\n");
	// Creating and starting threads
	pthread_create(&threads[0], NULL, insertionSort, (void*)&list1);
	pthread_create(&threads[1], NULL, insertionSort, (void*)&list2);
	pthread_create(&threads[2], NULL, insertionSort, (void*)&list3);
	pthread_create(&threads[3], NULL, insertionSort, (void*)&list4);
	pthread_create(&threads[4], NULL, insertionSort, (void*)&list5);
	pthread_create(&threads[5], NULL, insertionSort, (void*)&list6);
	pthread_create(&threads[6], NULL, insertionSort, (void*)&list7);
	pthread_create(&threads[7], NULL, insertionSort, (void*)&list8);
	pthread_create(&threads[8], NULL, insertionSort, (void*)&list9);
	pthread_create(&threads[9], NULL, insertionSort, (void*)&list10);

	// Waiting for threads to complete
	for (i = 0; i < 10; i++)
		pthread_join(threads[i], NULL);

	printf("\nRegular insertion sort to 10 list has been completed\n");

	printf("Begin of merging 10 list into 5 sublist\n\n");
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
	printf("\nMerging 10 list into 5 sublist has been completed\n");

	printf("Begin of merging 5 list into 3 sublist\n\n");
	struct listDef subSubList1;
	struct listDef subSubList2;

	subSubList1.theList = merge2List(subList1.theList, subList2.theList, subList1.elementCount, subList2.elementCount, &subSubList1.elementCount);
	subSubList2.theList = merge2List(subList3.theList, subList4.theList, subList3.elementCount, subList4.elementCount, &subSubList2.elementCount);

	struct listDef subSubList3;

	subSubList3.theList = merge2List(subSubList1.theList, subSubList2.theList, subSubList1.elementCount, subSubList2.elementCount, &subSubList3.elementCount);
	printf("\nMerging 5 list into 3 sublist has been completed\n");

	printf("Begin of last merge operation\n\n");
	struct listDef sortedList;

	sortedList.theList = merge2List(subList5.theList, subSubList3.theList, subList5.elementCount, subSubList3.elementCount, &sortedList.elementCount);
	printf("\nLast merge operation has been completed\n\n");

	printf("End of improvedInsertionSort\n");
	return sortedList;
}

void printArray(int numbers[], unsigned int numbersCount)
{
	unsigned int i;
	for (i = 0; i < numbersCount; i++)
		printf("%d\n", numbers[i]);
}

void writeArray(int numbers[], unsigned int numbersCount, char outputFileName[])
{
	printf("Writing %u numbers to %s\n", numbersCount, outputFileName);
	FILE* txt = fopen(outputFileName, "w");

	unsigned int i;
	for (i = 0; i < numbersCount; i++)
		fprintf(txt, "%d\n", numbers[i]);

	fclose(txt);

	printf("Writing operation has been completed\n");
}

void* insertionSort(void *args)
{
	struct listDef* list = (struct listDef*) args;

	printf("insertionSort: sorting %u numbers...\n", list->elementCount);
	unsigned int i, j;
	int temp;
	unsigned int n = list->elementCount;
	for (i = 1; i <= n - 1; i++)
	{
		j = i;
		while (j > 0 && list->theList[j - 1] > list->theList[j])
		{
			temp = list->theList[j];
			list->theList[j] = list->theList[j - 1];
			list->theList[j - 1] = temp;
			j--;
		}
	}
}

int* merge2List(int list1[], int list2[], unsigned int list1Count, unsigned int list2Count, unsigned int* newListCount)
{
	printf("merge2List: merging list that contains %u numbers and list that contains %u numbers...\n", list1Count, list2Count);

	int* theListToBeReturned = (int*)malloc((list1Count + list2Count) * sizeof(int));

	unsigned int list1Cursor = 0, list2Cursor = 0, theListCursor = 0;
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