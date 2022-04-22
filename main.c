#include <stdio.h>
#include <stdlib.h>
#include "conversoes.h"

int main(int argc, char *argv[]) {

	int num;
	char str[7];
	char str1[] = "13450";
	char str2[] = "-1203";

	
	//Testes IntToStr

	num = 1905;
	IntToStr(num, (char*) str);
	printf("%d = %s\n", num, str);

	num = -8057;
	IntToStr(num, (char*) str);
	printf("%d = %s\n", num, str);

	
	//Testes StrToInt

	StrToInt((char*) str1, &num);
	printf("\n%s = %d\n", str1, num);

	StrToInt((char*) str2, &num);
	printf("%s = %d\n", str2, num);

	return 0;
}
