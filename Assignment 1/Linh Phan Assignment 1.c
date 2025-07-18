//Linh Phan - COP3502 - Assignment 1

#include <stdio.h>

//to storing the book data
typedef struct {
	char bookName[101];
	char authorName[101];
	int year;
} bookInfo;

int main() {
//to see how many books there are
	int bookNumber;
	bookInfo myArray[50];

//ask user to input how many books they want to document
	printf("Enter the number of books: ");
	scanf("%d", &bookNumber);
	while ((getchar()) != '\n');

//for loop to get each book's details
	for(int i = 0; i < bookNumber; i++) {
		printf("Enter details for book %d:\n", i + 1);
		printf("Title: ");
		fgets(myArray[i].bookName,100,stdin);
		printf("Author: ");
		fgets(myArray[i].authorName,100,stdin);
		printf("Year: ");
		scanf(" %d", &myArray[i].year);
		while ((getchar()) != '\n');
	}

//to sort through the list using bubble sort
	for (int j = 0; j < bookNumber; j++) {
		for (int i = 0; i < bookNumber - j - 1; i++) {
			if (myArray[i].year > myArray[i + 1].year) {
				bookInfo temp = myArray[i];
				myArray[i] = myArray[i + 1];
				myArray[i + 1] = temp;
			}
		}
	}
	
	printf("Library Inventory (Sorted by Year of Publication):\n");

//to print everything
	for(int i = 0; i < bookNumber; i++) {
		printf("%d. Title: %s \tAuthor: %s \tYear: %d\n", i + 1,
		       myArray[i].bookName, myArray[i].authorName, myArray[i].year);
	}
	
	return 0;
}
