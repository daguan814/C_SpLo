#include<stdio.h>
 
void setprice() {

	extern int b[8];

	int i;
	
	printf("请输入您需要设定的中奖号码：");
	for (i = 1; i <= 7; i++) {
		scanf_s("%d", &b[i]);
	}
}

void setbuy() {
	extern int a[11][8];

	int i;

	printf("请输入您需要购买的号码：");
	for (i = 1; i <= 7; i++) {
		scanf_s("%d", &a[1][i]);
	}
}