#include<stdio.h>
#include<Windows.h>


void Search_bin(char c) {
    extern int a[11][8];
    extern int k;
    extern int b[8];

    int count_2 = 0;
    int i, h, j,price;          //i (组)h（奖号的个）机选号码的 j(买的号码)
    int zhong = 0;         //每组的中奖号码个数 

    int sum1 = 0, sum2 = 0,sum3=0;   //总中奖号码数   总共查找次数


    if (c == 'r') {                               //     添加自己输入号码入口     ##  未完成 

        for (i = 1; i < k; i++) {           //   机选号码组

            for (h = 1; h <= 7; h++) {           //开奖号码
                j = 7;

                if (b[h] == a[i][1] || b[h] == a[i][j / 2+1]||b[h]==a[i][j]) {    //先看看是不是在开头，中间或者开头
                    printf("找到获奖号码%d\n", b[h]);
                    zhong++;
                    count_2++;
                    
                }
                count_2++;


                if (b[h] < a[i][j / 2 + 1]) {                  //小于中间节点
                    if (b[h] == a[i][j / 2]) {
                        count_2++;
                        printf("找到获奖号码%d\n", b[h]);
                        zhong++;
                       
                    }
                    else {
                        count_2 += 2;
                        j= j/2-1;
                        if (b[h] == a[i][j]) {
                            printf("找到获奖号码%d\n", b[h]);
                        
                            zhong++;
                            
                        };
                    }
                }

                if (b[h] > a[i][j / 2 + 1]) {                  //大于中间节点
                    if (b[h] == a[i][j / 2 + 2]) {
                        count_2++;
                        printf("找到获奖号码%d\n", b[h]);
                        zhong++;
                    }
                    else {
                        count_2 += 2;
                        j= j/2+3;
                        if (b[h] == a[i][j]) {
                            printf("找到获奖号码%d\n", b[h]);
                            zhong++;
                                     //不去写break 原因：用奖号和买的做对比会导致后面的被忽略
                        }
                    }
                }



                
            } 
                printf("第*%d*组机选号码中奖的号码有%d个，查找的次数是：%d\n", i, zhong, count_2);
                switch (zhong) {
            case 3:
                price = 5;
                printf("您获得了安慰奖，奖金5元\n\n");
                    printf("****************************\n\n");
                break;
            case 4:
                printf("您获得了三等奖，奖金20元\n\n");
                printf("****************************\n\n");
                price = 20;  break;
            case 5:
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
            default:
                price = 0; break;

            }
              sum3 = sum3 + price;
                sum2 = sum2 + count_2;
                sum1 = sum1 + zhong;
                count_2 = 0;
                zhong = 0;
                Sleep(300);

        }

        printf("总共获奖的号码总数是%d,总共查找次数是：%d次\n", sum1, sum2);
        printf("本次购买彩票您的中奖总金额为：%d元\n\n", sum3);
        printf("您本次用来购买彩票的金额为：%d元\n\n\n", 2 * (k-1));
    }
}