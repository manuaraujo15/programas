#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n=0,x;
	printf("informe um número inteiro\n");
	scanf("%d\n",&n);
	for(x=1;x<=10;x++){
		printf("%dX%d=%d\n",n,x,n*x);
	}
}