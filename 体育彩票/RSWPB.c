#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<Windows.h>


   int b[8];

void  RSWPB(int n) {            //机选 排序  去重   输出

	

	
	int i;
	int k;

	srand((unsigned)time(NULL));

		for (i = 1; i <= 7; i++)
		{

			b[i] = rand() % 35 + 1;

			if (b[i - 1] == b[i]) {
				b[i] = rand() % 35 + 1;
			}

		}



	



	int  j, t;                                   //排序
		for (j = 0; j < 7; j++) {
			for (i = 1; i < (7 - j); i++) {

				if (b[i + 1] < b[i]) {
					t = b[i];
					b[i] = b[i + 1];
					b[i + 1] = t;

				}
			}
		}

	



	printf("\n");

	//将重复的实现代替
	for (k = 1; k <= n; k++) {

		for (j = 0; j < 7; j++) {
			for (i = 1; i < (7 - j); i++) {

				if (b[i + 1] == b[i]) {

					b[i] = b[i] + 1;
					t = b[i];
					b[i] = b[i + 1];
					b[i + 1] = t;

				}
			}
		}
	}

	//输出    
	
	
		for (i = 1; i <= 7; i++) {


			printf(" %d\t", b[i]);

			Sleep(700);
		}printf("\n");

	


	printf("\n");

}