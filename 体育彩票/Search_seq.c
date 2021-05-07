
//顺序查找
//用中奖号码和我购买的做比对

#include<stdio.h>
#include<Windows.h>
   
void Search_seq(char c) {
    extern int a[11][8];
    extern int k;
    extern int b[8];


   int count_1 = 0;
   int i, j, h;          //i 机选号码的
   int zhong = 0, price;      //每组的中奖号码个数
   int sum1= 0 ,sum2 =0,sum3=0;     //总中奖号码数   总共查找次数


    if (c == 'r') {                               //     添加自己输入号码入口     ##  未完成 
       
        for (i=1; i < k; i++) {           //   机选号码组
         
            for (h=1; h <= 7;h++) {           //开奖号码
        
                 for (j=1; j <= 7; j++) {            //购买的号码组
                    //  printf("%d  ",b[h]);
                    zhong++;
                    if (b[h] == a[i][j]) {
                        count_1 += 1;
                        printf("恭喜！！  *%d*  找到中奖号码：%d\n",i, b[h]);
                        break;
                    }
                }
            }
            printf("第%d组机选号码中奖的号码有%d个，查找的次数是：%d\n", i, count_1, zhong);
            switch (count_1) {
            case 3:
                price = 5;
                printf("您获得了安慰奖，奖金5元\n\n");
                printf("****************************\n\n");
                    break;
                case 4:
                    printf("您获得了三等奖，奖金20元\n\n");
                    printf("****************************\n\n");
                    price = 20;  break;
                case 5 :
                    printf("您获得了二等奖，奖金100元\n\n");
                    printf("****************************\n\n");
                    price = 100;  break;
                case 6:
                    printf("您获得了一等奖，奖金 一千 元\n\n");
                    printf("****************************\n\n");
                    price = 1000;  break;
                case 7:
                    printf("您获得了特等奖，奖金 一万 元\n\n");
                    printf("****************************\n\n");
                    price = 10000;  break;
                default :
                    price = 0; break;

            }
            sum3 = sum3 + price;
            sum1 = sum1 + count_1;
            sum2 = sum2 + zhong;
            count_1 = 0; 
            zhong = 0;
            Sleep(300);
        }
            
        
    }
       
    printf("总共获奖的号码总数是%d,总共查找次数是：%d次\n\n\n",sum1,sum2);
    printf("本次购买彩票您的中奖总金额为：%d元\n", sum3);
    printf("您本次用来购买彩票的金额为：%d元\n\n", 2 * (k - 1));

}




