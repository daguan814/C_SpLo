#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<Windows.h>


   int b[8];

void  RSWPB(int n) {            //��ѡ ����  ȥ��   ���

	

	
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



	



	int  j, t;                                   //����
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

	//���ظ���ʵ�ִ���
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

	//���    
	
	
		for (i = 1; i <= 7; i++) {


			printf(" %d\t", b[i]);

			Sleep(700);
		}printf("\n");

	


	printf("\n");

}