#include <stdio.h>

	struct newStruct{
		int myNum;
		char myLetter;
	};

int main(){

	struct newStruct s1;

	s1.myNum = 22;
	s1.myLetter = 'c';

	printf("%d%c",s1.myNum,s1.myLetter);

	return 0;
}
