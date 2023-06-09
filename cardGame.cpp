//플레이어와 컴퓨터가 각각 카드를 2장씩 뽑는다. 
//두 카드의 합이 더 큰 쪽이 승리, 작은쪽이 패배 
//동일한 숫자가 나올경우 문양(스페이드_다이아_하트_클로버 순서)

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{   
    while(1)
    {
    int number1 = 0,number2 = 0;;
    int player1_Arr[2] = {0,};
    int player2_Arr[2] = {0,};
    int player1_Sum =0,player2_Sum=0;
    int player1_mark = 0, player2_mark = 0;
    int numberResult = 0, markResult = 0, whoWin = 0;
    int r;
    int cardDeck[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int cardMarkDeck[4] = {1,2,3,4};
    int p1_cardNumber1=0,p1_cardNumber2=0,p1_mark1=0,p1_mark2=0;
    int p2_cardNumber1=0,p2_cardNumber2=0,p2_mark1=0,p2_mark2=0;
    char numberDeck[13][3] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    char markDeck[4][7] = {"♣︎","♥︎","♦︎","♠︎"};
    int winNumber1 = 0, winNumber2 =0;
    int winMark1 = 0, winMark2 = 0;
    char a = '0';

    
    srand(time(NULL));

    // 플레이어 2명 각각 카드 2번뽑고 숫자 더하는 부분
    for(int i = 0; i<2;i++)
    {
        if(i==0) // player1 번 카드번호
        {
            while(r < 300)
            {
                number1 = rand()%13;
                number2 = rand()%13;
                if(number1==number2)
                {
                    continue;
                }
                p1_cardNumber1=cardDeck[number1];
                p1_cardNumber2=cardDeck[number2];
                r++;
            }//while
            player1_Sum = p1_cardNumber1+p1_cardNumber2;
            r=0;//루프 변수 r 초기화
        }//if
        else if(i==1){ // player2번 카드번호
            while(r < 300)
            {
                number1 = rand()%13;
                number2 = rand()%13;
                if(number1==number2)
                {
                    continue;
                }
                p2_cardNumber1=cardDeck[number1];
                p2_cardNumber2=cardDeck[number2];
                r++;
            }//while
            player2_Sum = p2_cardNumber1+p2_cardNumber2;
            r=0;
        }//elseif
    }//for
    // 플레이어 2명 각각 카드 2번뽑고 숫자 더하는 부분
    
    //카드 문양 섞는 부분
    for(int i = 0; i<2;i++)
    {
        if(i==0) // 플레이어 1번의 마크
        {
            while(r < 300)
            {
                number1 = rand()%4;
                number2 = rand()%4;
                if(number1==number2)
                {
                    continue;
                }
                p1_mark1 = cardMarkDeck[number1];
                p1_mark2 = cardMarkDeck[number2];
                r++;
            }//while
            if(p1_mark1 > p1_mark2)
            {
                player1_mark = p1_mark1;
            }
            else{
                player1_mark = p1_mark2;
            }
            r=0;//루프 변수 r 초기화
        }//if
        else if(i==1){ //플레이어 2번의 마크
            while(r < 300)
            {
                number1 = rand()%4;
                number2 = rand()%4;
                if(number1==number2)
                {
                    continue;
                }
                p2_mark1 = cardMarkDeck[number1];
                p2_mark2 = cardMarkDeck[number2];
                r++;
            }//while
            if(p2_mark1 > p2_mark2)
            {
                player2_mark = p2_mark1;
            }
            else{
                player2_mark = p2_mark2;
            }
            r=0;
        }//elseif

        if(player1_mark == player2_mark)
        {
            i--;
        }
    }//for
    //카드 문양 섞는 부분


    

    // 결과 계산
    if(player1_Sum > player2_Sum)
    {
        numberResult = player1_Sum;
        winMark1 = p1_mark1;
        winMark2 = p1_mark2;
        winNumber1 = p1_cardNumber1;
        winNumber2 = p1_cardNumber2;
        whoWin = 1;
    }
    else if(player1_Sum < player2_Sum)
    {
        numberResult = player2_Sum;
        winMark1 = p2_mark1;
        winMark2 = p2_mark2;
        winNumber1 = p2_cardNumber1;
        winNumber2 = p2_cardNumber2;
        whoWin = 2;
    }
    else if(player1_Sum == player2_Sum)
    {
        if(player1_mark > player2_mark)
        {
            numberResult = player1_Sum;
            winMark1 = p1_mark1;
            winMark2 = p1_mark2;
            winNumber1 = p1_cardNumber1;
            winNumber2 = p1_cardNumber2;
            markResult = player1_mark;
            whoWin = 1;
        }
        else if(player1_mark < player2_mark)
        {
            markResult = player2_mark;
            numberResult = player2_Sum;
            winMark1 = p2_mark1;
            winMark2 = p2_mark2;
            winNumber1 = p2_cardNumber1;
            winNumber2 = p2_cardNumber2;
            whoWin = 2;
        }
    }
    //결과 계산

    //출력
    printf(" 플레이어 %d번이 이겼습니다.\n",whoWin);
    printf(" ⌈⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⌉    ⌈⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⌉\n");
    printf(" ⎮ %2s %2s        ⎮    ⎮ %2s %2s        ⎮\n",markDeck[winMark1-1],numberDeck[winNumber1-1],markDeck[winMark2-1],numberDeck[winNumber2-1]);
    printf(" ⎮             ⎮    ⎮             ⎮\n");
    printf(" ⎮             ⎮    ⎮             ⎮\n");
    printf(" ⎮             ⎮    ⎮             ⎮\n");
    printf(" ⎮             ⎮    ⎮             ⎮\n");
    printf(" ⎮        %2s %2s ⎮    ⎮       %2s %2s  ⎮\n",markDeck[winMark1-1],numberDeck[winNumber1-1],markDeck[winMark2-1],numberDeck[winNumber2-1]);
    printf(" ⌊⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⌋    ⌊⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⌋\n");
    printf("\n");

    printf("   [플레이어1]          [플레이어2]\n");
    printf("[%s/%s] [%s/%s] [합:%d] [%s/%s] [%s/%s] [합:%d]\n\n",numberDeck[p1_cardNumber1-1],markDeck[p1_mark1-1],numberDeck[p1_cardNumber2-1],markDeck[p1_mark2-1],player1_Sum,numberDeck[p2_cardNumber1-1],markDeck[p2_mark1-1],numberDeck[p2_cardNumber2-1],markDeck[p2_mark2-1],player2_Sum);


    //,numberDeck[winNumber1],markDeck[winMark1],numberDeck[winNumber2],markDeck[winMark2]
    cin >> a;
    }
}