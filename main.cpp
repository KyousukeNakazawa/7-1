#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell {
	char str[8];
	struct cell* next;
} CELL;

void Create(CELL* endCell, const char* buf);
void index(CELL* endCell);

int main() {
	char str[8];

	CELL head;
	head.next = nullptr;

	while (1) {
		printf("D‚«‚È‚¨ŽõŽi‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
		scanf_s("%s", str, 8);

		Create(&head, str);

		index(&head);
	}

	return 0;
}

void Create(CELL* endCell, const char* buf) {
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));

	if (newCell) {
		strcpy_s(newCell->str, 8, buf);
		newCell->next = NULL;
	}

	while (endCell->next != NULL) {
		endCell = endCell->next;
	}

	endCell->next = newCell;
}

void index(CELL* endCell) {
	while (endCell->next != NULL) {
		endCell = endCell->next;
		printf("%s,", endCell->str);
	}
	printf("\n");
}