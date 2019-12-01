/*
	Name: Yigit Berkay Asli
	ID: 2315091
*/

#pragma warning(disable:4996) // remove security warnings on VS
#pragma warning(disable:6031) // remove return is ignored warnings on VS
#pragma warning(disable:6011) // remove dereference warnings on VS
#pragma warning(disable:4018) // remove operator signed-unsigned mismatch warnings on VS
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

struct listDef {
	int* theList;
	unsigned int elementCount;
};

int checkFile(char[]);
int* fillArray(unsigned int*, char[]);
struct listDef improvedInsertionSort(int[], unsigned int);
void printArray(int[], unsigned int);
void writeArray(int[], unsigned int, char[]);
void* insertionSort(void*);
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
	clock_t t = clock(); // start time

	printf("Creating and filling 10 list\n");
	unsigned int i, j;

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

	struct listDef lists[10];

	for (i = 0; i < 10; i++)
		lists[i].elementCount = 0;

	for (i = 0; i < 10; i++)
		lists[i].theList = (int*)malloc((numbersCount) * sizeof(int));

	for (i = 0; i < numbersCount; i++)
	{
		if ((numbers[i] >= min) && (numbers[i] < min + (range / 10)))
		{
			lists[0].theList[lists[0].elementCount] = numbers[i];
			lists[0].elementCount++;
		}

		for (j = 1; j < 9; j++)
		{
			if ((numbers[i] >= min + ((j * range) / 10)) && (numbers[i] < min + (((j + 1) * range) / 10)))
			{
				lists[j].theList[lists[j].elementCount] = numbers[i];
				lists[j].elementCount++;
				break;
			}
		}
		
		if ((numbers[i] >= min + ((9 * range) / 10)) && (numbers[i] <= max))
		{
			lists[9].theList[lists[9].elementCount] = numbers[i];
			lists[9].elementCount++;
		}
	}

	pthread_t threads[10];

	printf("Begin regular insertion sort to 10 list\n\n");
	// Creating and starting threads

	for (i = 0; i < 10; i++)
		pthread_create(&threads[i], NULL, insertionSort, (void*)&lists[i]);

	// Waiting for threads to complete
	for (i = 0; i < 10; i++)
		pthread_join(threads[i], NULL);

	printf("\nRegular insertion sort to 10 list has been completed\n");

	printf("Begin merging 10 list into 5 sublist\n\n");
	struct listDef subLists[5];

	for (i = 0, j = 0; i < 5; i++, j = j + 2)
		subLists[i].theList = merge2List(lists[j].theList, lists[j + 1].theList, lists[j].elementCount, lists[j + 1].elementCount, &subLists[i].elementCount);

	printf("\nMerging 10 list into 5 sublist has been completed\n");

	printf("Begin merging 5 list into 3 sublist\n\n");
	struct listDef subSubLists[3];

	for (i = 0, j = 0; i < 2; i++, j = j + 2)
		subSubLists[i].theList = merge2List(subLists[j].theList, subLists[j + 1].theList, subLists[j].elementCount, subLists[j + 1].elementCount, &subSubLists[i].elementCount);

	subSubLists[2].theList = merge2List(subSubLists[0].theList, subSubLists[1].theList, subSubLists[0].elementCount, subSubLists[1].elementCount, &subSubLists[2].elementCount);

	printf("\nMerging 5 list into 3 sublist has been completed\n");
	printf("Begin last merge operation\n\n");
	struct listDef sortedList;

	sortedList.theList = merge2List(subLists[4].theList, subSubLists[2].theList, subLists[4].elementCount, subSubLists[2].elementCount, &sortedList.elementCount);
	printf("\nLast merge operation has been completed\n\n");

	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
	printf("The improvedInsertionSort function took %lf seconds to execute\n", time_taken);
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