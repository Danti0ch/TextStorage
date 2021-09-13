#include <stdio.h>
#include "onegin.h"
#include "unit_testing.h"

int main(){
	int arr[2] = {0, 1};
	printf("%d\n%d", &(arr[0]), &(arr[1]));
	return 0;
}