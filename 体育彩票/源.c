//题目十四、体育彩票的模拟生成和兑奖
//基本要求：
//模拟36选7的中国体育彩票。从1～36中随机取出7个数作为一张彩票的号码，随机生成若干张彩票，
//采用顺序和折半两种不同的查找算法和指定的中奖号码进行比较，输出每种查找算法的比较次数和中奖情况。

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<Windows.h>
#include"agent.h"



int  main() {
        
	
	

	while (1) {
		int select;

			printf("********************************\n");
			printf("*                              *\n");
			printf("*     欢迎购买中国体育彩票     *\n");
			printf("*       1.机选购买彩票         *\n");
			printf("*       2.生成中奖号码         *\n");
			printf("*       3.顺序查找             *\n");
			printf("*       4.折半查找             *\n");
			printf("*       5.设定中奖号码         *\n");
			printf("*       6.购买彩票号码         *\n");
			printf("*       0.退出                 *\n");
			printf("*                              *\n");
			printf("********************************\n\n");

			printf("请选择:");

			scanf_s("%d", &select);
		switch (select) {
		case 1:
			printf("请输入您要购买的彩票份数(最多9份)：");
			int f; scanf_s("%d", &f);
			while (f >= 10 || f <= 0) {
				printf("输入超过界定值，请重新输入：");
				int f; scanf_s("%d", &f);

			}
			RSWPA(f);
			break;

		case 2:
			Sleep(1000);
			RSWPB(1);
			break;

		case 3:
			Search_seq('r');
			break;
		case 4:
	
			Search_bin('r');
			break;
		case 5:
			setprice();
			printf("\n");
			break;
		case 6:
			setbuy();
			break;
		case 0: return 0 ;
			break;
		default: printf("请输入0----3之间的数\n");
		}
	
	}
	
	
}




