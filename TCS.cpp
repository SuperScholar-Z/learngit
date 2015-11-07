#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int x,y;
void gotoxy(int x,int y);

struct Node
{
    int x;
    int y;
    struct Node *pre;
    struct Node *next;
};

struct Food
{
    int x;
    int y;
    char c;
};

int main()
{
    int a[15][15]={0};
    int i,j,t,flag=0;
    char c='d',c1='d';
    struct Food food={5,8,'A'};
    int gameover=0;
    struct Node *head,*p,*rear,*pt;
    
    head=(struct Node *)malloc(sizeof(struct Node));
    head->x=5;
    head->y=8;
    head->pre=NULL;
    head->next=NULL;
    rear=head;

    srand((unsigned)time(NULL));
    
    printf("  ©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n");
    for(i=0;i<15;i++)
    {
        printf("©¦");
        for(j=0;j<15;j++)
        {
            printf("  ");
        }
        printf("©¦");
        putchar('\n');
    }
    printf("  ©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n");
    
    while(1)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    {
        if(food.x==head->x && food.y==head->y)
        {
            p=(struct Node *)malloc(sizeof(struct Node));
            pt=head;
            while(pt->next!=NULL)
                pt=pt->next ;
            p->pre= pt;
            pt->next = p;
            p->next=NULL;
            rear=p;

            food.x=rand()%15;
            food.y=rand()%15;
            food.c=65+rand()%26;

            flag=1;
            t=0;
            while(flag==1)
            {
                if(t>5)
                    break;

                flag=0;

                pt=head;
                while(pt!=NULL)
                {
                    if(food.x==pt->x && food.y==pt->y)
                    {
                        flag=1;
                        food.x=rand()%15;
                        food.y=rand()%15;
                        break;
                    }
                    pt=pt->next;
                }
                t++;
            }
            if(t>5)
            {
                if(c=='d' || c=='D')
                {
                    food.x=head->x+1;
                    food.y=head->y;
                    if(food.x>=15)
                        food.x-=15;
                }
                else if(c=='a' || c=='A')
                {
                    food.x=head->x-1;
                    food.y=head->y;
                    if(food.x<0)
                        food.x+=15;
                }
                else if(c=='w' || c=='W')
                {
                    food.x=head->x;
                    food.y=head->y+1;
                    if(food.y>=15)
                        food.y-=15;
                }
                else if(c=='s' || c=='S')
                {
                    food.x=head->x;
                    food.y=head->y-1;
                    if(food.y<0)
                        food.y+=15;
                }
            }
        }

        if(kbhit())
        {
            c1=getch();
            if(c1=='P' || c1=='p')
            {
            	gotoxy(9,9);
                system("pause");
            }
            
            if(c!='d' && c!='D' && (c1=='a' || c1=='A'))
                c=c1;
            else if(c!='a' && c!='A' && (c1=='d' || c1=='D'))
                c=c1;
            else if(c!='w' && c!='W' && (c1=='s' || c1=='S'))
                c=c1;
            else if(c!='s' && c!='S' && (c1=='w' || c1=='W'))
                c=c1;
        }

        pt=rear;
        while(pt!=head )
        {
            pt->x=pt->pre->x;
            pt->y=pt->pre->y;
            pt=pt->pre;
        }

        if(c=='d' || c=='D')
        {
            head->y+=1;
            if(head->y>=15)
                head->y-=15;
        }
        else if(c=='a' || c=='A')
        {
            head->y-=1;
            if(head->y<0)
                head->y+=15;
        }
        else if(c=='w' || c=='W')
        {
            head->x-=1;
            if(head->x<0)
                head->x+=15;
        }
        else if(c=='s' || c=='S')
        {
            head->x+=1;
            if(head->x>=15)
                head->x-=15;
        }

        pt=head->next;
        while(pt!=NULL)
        {
            if(head->x==pt->x && head->y==pt->y)
            {
                gameover=1;
                break;
            }
            pt=pt->next ;
        }
        if(gameover==1)
            break;
        
            for(i=1;i<16;i++)
        {
    	    gotoxy(i,2);
        	printf("                             ");
        }
        
        for(i=0;i<15;i++)
        {
            for(j=0;j<15;j++)
            {

                flag=0;
                pt=head;
                while(pt!=NULL)
                {
                    if(i==pt->x && j==pt->y)
                    {
                    	gotoxy(i+1,2*(j+1));
                        if(pt==head)
                            printf("¡ö");
                        else
                            printf("¡õ");
                        flag=1;
                        break;
                    }
                    pt=pt->next;
                }


                if(flag==0)
                {
                    if(i==food.x && j==food.y)
                    {
                    	gotoxy(i+1,2*(j+1));
                        putchar(food.c);
                        putchar(food.c);
                        continue;
                    }
                }
            }
        }

        
        _sleep(200);   
		    
    }

    if(gameover==1)
        puts("game over!\n");

    getch();
    
}

void gotoxy(int y,int x)
{
	CONSOLE_SCREEN_BUFFER_INFO   csbiInfo;
	HANDLE    hConsoleOut;
	hConsoleOut=GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
	csbiInfo.dwCursorPosition.X=x;
	csbiInfo.dwCursorPosition.Y=y;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
