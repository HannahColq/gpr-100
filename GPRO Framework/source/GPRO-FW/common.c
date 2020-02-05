#include "GPRO-FW/common.h"
#include <stdio.h>
#include <stdbool.h>

int getXInput() {
	int xInput;
	printf("Enter the horizontal row: ");
	scanf_s("%d", &xInput);
	return xInput;
}
int getYInput() {
	int yInput;
	printf("Enter the vertical column: ");
	scanf_s("%d", &yInput);
	return yInput;
}