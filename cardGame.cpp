//버전 2
/*
카드게임 응용
1. 컴퓨터가 카드를 2장 뽑아서 보여준다.
2. 플레이어는 카드를 보고 베팅한다.
3. 플레이어는 카드를 한 장 뽑는다.
4. 플레이어의 카드가 컴퓨터의 카드 2장 사이에 존재한다면, 
   플레이어는 한 번의 게임을 승리하여 베팅 점수의 2배를 얻는다.
   플레이어의 카드가 2장 사이에 존재하지 않는 경우,
   플레이어는 한번의 게임을 패배하여 베팅 점수만큼 잃는다.
5. 플레이어는 일정 점수를 획득하면 게임을 최종 승리하며, 0점 이하인 경우 게임을 최종 패배한다.
6. 게임을 종료한다.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
void swab(int* ptr, int* ptr2);

int main()
{   
    // 주석 처리된 변수는 player1 player2 카드 합 대소비교 문제
    //int player1_Arr[2] = {0,};
    //int player2_Arr[2] = {0,};
    //int player1_Sum =0,player2_Sum=0;
    //int player1_mark = 0, player2_mark = 0;
    //int numberResult = 0, markResult = 0;
    //int winNumber1 = 0, winNumber2 =0;
    //int winMark1 = 0, winMark2 = 0;
    int number1 = 0,number2 = 0;
    int whoWin = 0;
    int r;
    int cardDeck[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int cardMarkDeck[4] = {1,2,3,4};
    int p1_cardNumber1=0,p1_cardNumber2=0,p1_mark1=0,p1_mark2=0;
    int p2_cardNumber1=0,p2_cardNumber2=0,p2_mark1=0,p2_mark2=0;
    char numberDeck[13][3] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    char markDeck[4][7] = {"♣︎","♥︎","♦︎","♠︎"};
    int bet = 0, playerPoint = 10000, setPoint = 20000, finalPoint = 0;
    char check = '0';

    while(1)
    {
        srand(time(NULL));

        // 플레이어 2명 각각 카드 2번뽑고 숫자 더하는 부분
        for(int i = 0; i<2;i++)
        {
            if(i==0) // 컴퓨터 카드 번호 뽑는곳(random 2개)
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

                // >> player1 player2 카드 합 대소비교 문제
                //player1_Sum = p1_cardNumber1+p1_cardNumber2;
                // >> player1 player2 카드 합 대소비교 문제

                r=0;//루프 변수 r 초기화
            }//if
            else if(i==1)
            { // player 카드번호
                
                while(r < 300)
                {
                    number1 = rand()%13;

                    // >> player1 player2 카드 합 대소비교 문제
                    // number2 = rand()%13;
                    // if(number1==number2)
                    // {
                    //     continue;
                    // }
                    // >> player1 player2 카드 합 대소비교 문제
                    
                    p2_cardNumber1=cardDeck[number1];

                    // >> player1 player2 카드 합 대소비교 문제
                    //p2_cardNumber2=cardDeck[number2];
                    // >> player1 player2 카드 합 대소비교 문제

                    r++;
                }//while

                // >> player1 player2 카드 합 대소비교 문제
                //player2_Sum = p2_cardNumber1+p2_cardNumber2;
                // >> player1 player2 카드 합 대소비교 문제

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

                // >> player1 player2 카드 합 대소비교 문제
                // if(p1_mark1 > p1_mark2)
                // {
                //     player1_mark = p1_mark1;
                // }
                // else{
                //     player1_mark = p1_mark2;
                // }
                // >> player1 player2 카드 합 대소비교 문제

                r=0;//루프 변수 r 초기화
            }//if
            else if(i==1)
            { //플레이어 2번의 마크
                while(r < 300)
                {
                    number1 = rand()%4;

                    // >> player1 player2 카드 합 대소비교 문제
                    // number2 = rand()%4;
                    // if(number1==number2)
                    // {
                    //     continue;
                    // }
                    // >> player1 player2 카드 합 대소비교 문제

                    p2_mark1 = cardMarkDeck[number1];

                    // >> player1 player2 카드 합 대소비교 문제
                    //p2_mark2 = cardMarkDeck[number2];
                    // >> player1 player2 카드 합 대소비교 문제

                    r++;
                }//while

                // >> player1 player2 카드 합 대소비교 문제
                // if(p2_mark1 > p2_mark2)
                // {
                //     player2_mark = p2_mark1;
                // }
                // else{
                //     player2_mark = p2_mark2;
                // }
                // >> player1 player2 카드 합 대소비교 문제

                r=0;
            }//elseif

            // >> player1 player2 카드 합 대소비교 문제
            // if(player1_mark == player2_mark)
            // {
            //     i--;
            // }
            // >> player1 player2 카드 합 대소비교 문제


        }//for
        //카드 문양 섞는 부분

        // 큰 숫자를 카진 카드가 뒤로 오도록
        if(p1_cardNumber1 > p1_cardNumber2)
        {
            swab(&p1_cardNumber1,&p1_cardNumber2);
            swab(&p1_mark1,&p1_mark2);
        }


        // 결과 계산
        if((p1_cardNumber1 < p2_cardNumber1) && (p1_cardNumber2 > p2_cardNumber1))
        {
            whoWin = 1; //player승리시 1
        }
        else 
        {
            whoWin = 2; //컴퓨터 승리시 2
        }

        
        // >> player1 player2 카드 합 대소비교 문제
        // if(player1_Sum > player2_Sum)
        // {
        //     numberResult = player1_Sum;
        //     winMark1 = p1_mark1;
        //     winMark2 = p1_mark2;
        //     winNumber1 = p1_cardNumber1;
        //     winNumber2 = p1_cardNumber2;
        //     whoWin = 1;
        // }
        // else if(player1_Sum < player2_Sum)
        // {
        //     numberResult = player2_Sum;
        //     winMark1 = p2_mark1;
        //     winMark2 = p2_mark2;
        //     winNumber1 = p2_cardNumber1;
        //     winNumber2 = p2_cardNumber2;
        //     whoWin = 2;
        // }
        // else if(player1_Sum == player2_Sum)
        // {
        //     if(player1_mark > player2_mark)
        //     {
        //         numberResult = player1_Sum;
        //         winMark1 = p1_mark1;
        //         winMark2 = p1_mark2;
        //         winNumber1 = p1_cardNumber1;
        //         winNumber2 = p1_cardNumber2;
        //         markResult = player1_mark;
        //         whoWin = 1;
        //     }
        //     else if(player1_mark < player2_mark)
        //     {
        //         markResult = player2_mark;
        //         numberResult = player2_Sum;
        //         winMark1 = p2_mark1;
        //         winMark2 = p2_mark2;
        //         winNumber1 = p2_cardNumber1;
        //         winNumber2 = p2_cardNumber2;
        //         whoWin = 2;
        //     }
        // }
        // >> player1 player2 카드 합 대소비교 문제

        //결과 계산

        //출력
        printf(" 컴퓨터가 카드를 두번 뽑습니다.\n");
        printf(" ⌈⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⌉    ⌈⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⌉\n");
        printf(" ⎮ %2s %2s        ⎮    ⎮ %2s %2s        ⎮\n",markDeck[p1_mark1-1],numberDeck[p1_cardNumber1-1],markDeck[p1_mark2-1],numberDeck[p1_cardNumber2-1]);
        printf(" ⎮             ⎮    ⎮             ⎮\n");
        printf(" ⎮             ⎮    ⎮             ⎮\n");
        printf(" ⎮             ⎮    ⎮             ⎮\n");
        printf(" ⎮             ⎮    ⎮             ⎮\n");
        printf(" ⎮        %2s %2s ⎮    ⎮       %2s %2s  ⎮\n",markDeck[p1_mark1-1],numberDeck[p1_cardNumber1-1],markDeck[p1_mark2-1],numberDeck[p1_cardNumber2-1]);
        printf(" ⌊⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⌋    ⌊⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⌋\n");
        printf("\n");

        printf("범위 안에 있다고 생각하면 Y \n");
        printf("범위 밖에 있다고 생각하면 N \n");
        cin >> check;

        printf("얼마를 베팅하시겠습니까?\n");
        cin >> bet;

        printf(" 플레이어가 카드를 뽑습니다.\n");
        printf(" ⌈⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⌉\n");
        printf(" ⎮ %2s %2s        ⎮\n",markDeck[p2_mark1-1],numberDeck[p2_cardNumber1-1]);
        printf(" ⎮             ⎮\n");
        printf(" ⎮             ⎮\n");
        printf(" ⎮             ⎮\n");
        printf(" ⎮             ⎮\n");
        printf(" ⎮       %2s %2s  ⎮\n",markDeck[p2_mark1-1],numberDeck[p2_cardNumber1-1]);
        printf(" ⌊⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⌋\n");
        printf("\n");

        if(whoWin == 1 && (check == 'Y'|| check =='y'))
        {
            playerPoint += bet*2;
            printf("정답입니다. 플레이어 WIN\n");
            printf("베팅점수의 두배 포인트를 얻습니다.\n");
        }
        else if(whoWin ==2 && (check == 'N'||check =='n'))
        {
            playerPoint += bet*2;
            printf("정답입니다. 플레이어 WIN\n");
            printf("베팅점수의 두배 포인트를 얻습니다.\n");
        }
        else
        {
            playerPoint -= bet;
            printf("오답입니다. 컴퓨터 WIN\n");
            printf("베팅점수만큼 포인트를 잃습니다.\n");
        }

        printf("당신의 현재 포인트는 %d 입니다.\n",playerPoint);

        if(playerPoint >= setPoint)
        {
            finalPoint = 1;
            break;
        }
        else if(playerPoint <= 0)
        {
            finalPoint = 2;
            break;
        }

        // printf("[%s/%s] [%s/%s] [합:%d] [%s/%s] [%s/%s] [합:%d]\n\n",numberDeck[p1_cardNumber1-1],markDeck[p1_mark1-1],numberDeck[p1_cardNumber2-1],markDeck[p1_mark2-1],player1_Sum,numberDeck[p2_cardNumber1-1],markDeck[p2_mark1-1],numberDeck[p2_cardNumber2-1],markDeck[p2_mark2-1],player2_Sum);


        //,numberDeck[winNumber1],markDeck[winMark1],numberDeck[winNumber2],markDeck[winMark2]
    
    }
    system("clear");

    if(finalPoint ==1)
    {
        printf("포인트가 20000점 이상입니다. 축하합니다. 최종적으로 게임에 승리하셨습니다 \n");
    }
    else if(finalPoint == 2)
    {
        printf("포인트가 0점 이하입니다. 패배하셨습니다 \n");
    }
    
}

void swab(int* ptr, int* ptr2)
{
    int temp = 0;
    temp = *ptr;
    *ptr = *ptr2;
    *ptr2 = temp;
}



////////버전 1/////////
/*
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
    int number1 = 0,number2 = 0;
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
*/