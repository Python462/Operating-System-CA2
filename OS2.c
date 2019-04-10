#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include<conio.h>
#include<windows.h>

/*
Arrival Time:       Time at which the process arrives in the ready queue.
Completion Time:    Time at which process completes its execution.
Burst Time:         Time required by a process for CPU execution.
Turn Around Time:   Time Difference between completion time and arrival time.          
     Turn Around Time = Completion Time - Arrival Time

Waiting Time(W.T): Time Difference between turn around time and burst time.
     Waiting Time = Turn Around Time - Burst Time
*/


int n=0,option=-1;

void gotoxy(long x, long y) 
      {
           COORD pos = {x, y};
           SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
      }
/////////////////////////////////////
struct Process
{
	int P_ID,arrival_time,burst_time,left_burst_time,completion_time,waiting_time,turnaround_time,flag,round;
};
////////////////////
average(struct Process P[n])
{
	int i;
	float totWt=0,totTt=0,avgWt,avgTt;
	for(i=0;i<n;i++)
	{
		totWt+=P[i].waiting_time;
		totTt+=P[i].turnaround_time;
	}
	avgWt=totWt/n;
	avgTt=totTt/n;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
		gotoxy(71,2*n+12);	
		printf("%c     %.2f ",186,avgWt);
		gotoxy(86,2*n+12);	
		printf("%c    %.2f",186,avgTt);
}

/////////////////////////////////////////////////////////////////////////////////////
loading()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	int i,a=100000*0.5,b=100000*0.25,c=100000*0.125,u;
	gotoxy(50,3);
	printf("LOADING");
	for(i=0;i<30;i++)
	{
	    if(i<10)
	    u=a;
	    else if(i<20)
	    u=b;
	    else
	    u=c;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i%13+1 );
		gotoxy(40+i,4);
		printf("%c",220);
		gotoxy(40+i,2);
		printf("%c",186);
		gotoxy(40+i,2);
		printf("|");
		usleep(u);
		gotoxy(40+i,2);
		printf("/");
		usleep(u);
		gotoxy(40+i,2);
		printf("%c",250);
		usleep(u);
		int count=0;
		gotoxy(40+i,2);
		printf("\\");
		usleep(u);
		
		gotoxy(40+i,2);
		if(count<5)
		printf("%c",176);
		if(count>=5<10)
		printf("%c",177);
		else
		printf("%c",177);
		count++;
	}
}
///////////////////////////////////////////////////////////////////////////////////////
homepage()
{
	
	system("cls");
	
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | BACKGROUND_GREEN |BACKGROUND_RED|BACKGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY  );
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED );
	int i;
	printf("\n\n\n");
	printf("\t    ****************************************************************************************\n");
	printf("\t   |\t\t                    LOVELY PROFESSIONAL UNIVERSITY                          |\n");
	printf("\t   |\t\t           Department Of Computer Science And Engineering                   |\n");
	printf("\t   |\t\t                                                                            |\n");
	printf("\t   |\t\t                       A MINI PROJECT ON                                    |\n");
	printf("\t   |\t\t                                                                            |\n");
	printf("\t   |\t\t                        Operating System                                    |\n");
	printf("\t   |\t\t                                                                            |\n");
	printf("\t   |\t\t        BY:                                         GUIDE:                  |\n");
	printf("\t   |\t\t     -------------                                -----------               |\n");
	printf("\t   |\t\t   VIKRANT CHAUDHARY                         Mrs        |\n");
	printf("\t   |\t\t   Reg No.-> 11703065                                                       |\n");
	printf("\t   |\t\t   Roll NO.->44                                                             |\n");
    printf("\t    ****************************************************************************************\n\n");
	
	for(i=0;i<13;i++)
	{
		gotoxy(11,i+3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i );
		printf("%c",204);
		printf("%c",185);
		gotoxy(100,i+3);
		
		printf("%c",204);
		printf("%c",185);
	}
	int k;
	for(i=0;i<92;i++)
	{
		if(i>9)
		k=i%10;
		else
        k=i;
		gotoxy(10+i,3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),k);
		printf("*");
		gotoxy(10+i,16);
		printf("*");
	
	}
}
//////////////////////////////////////////////////////////////////////////
gant_chart(int gant[n],int r[n],int strt)
{
	int i,j=1;
	
	    gotoxy(53,2*n+14);
		printf("Gant Chart");
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
		gotoxy(43,2*n+17);
		printf("%d",strt);
	for(i=0;gant[i]!=99 && i<n ;i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i+1);
		j+=7;
		gotoxy(37+j,2*n+15);
		printf("P%d",gant[i]);
		gotoxy(35+j,2*n+16);
		printf("%c%c%c%c%c%c",219,219,219,219,219,219);
		gotoxy(40+j,2*n+17);
		printf("%d",r[i]);
		
	}
}
////////////////////////////////////////////////////
void frame()
{
	
	int i;
	
	for(i=0;i<91;i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4 );
		gotoxy(11+i,3);
		printf("%c",205);
		gotoxy(11+i,6);
		printf("%c",247);
		gotoxy(11+i,2*n+7);
		printf("%c",247);
		if(i<30)
		{
		gotoxy(71+i,2*n+8);
		printf("%c",205);
		gotoxy(71,2*n+9);
		printf("%c   Average    %c",186,186);
		gotoxy(71,2*n+10);	
		printf("%c     W.T      %c",186,186);
		gotoxy(89,2*n+9);
		printf("Average    %c",186,186);
		gotoxy(89,2*n+10);	
		printf("  T.T      %c",186,186);
		gotoxy(71+i,2*n+11);
		printf("%c",247);
		gotoxy(71+i,2*n+13);
		printf("%c",247);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
		gotoxy(71,2*n+12);	
		printf("%c       -      %c",186,186);
		gotoxy(89,2*n+12);	
		printf("    -      %c",186);
		
	    }
	}
	////////////////
	gotoxy(15,4);
    printf("Process    %c",186);
    gotoxy(15,5);
    printf("  ID       %c",186);
    gotoxy(30,4);
    printf("Arrival    %c",186);
    gotoxy(30,5);
    printf(" time      %c",186);
    gotoxy(45,4);
    printf("Burst      %c",186);
    gotoxy(45,5);
    printf("time       %c",186);
    gotoxy(60,4);
    printf("Completion %c",186);
    gotoxy(60,5);
    printf("   time    %c",186);
    gotoxy(75,4);
    printf("Waiting    %c",186);
    gotoxy(75,5);
    printf(" time      %c",186);
    gotoxy(89,4);
    printf("TurnAround %c",186);
    gotoxy(89,5);
    printf("   time    %c",186);
	////////////////
    for(i=0;i<n*2+4;i++)
	{
		gotoxy(11,i+4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
		//printf("%c",186);
		printf("%c",179);
		printf("%c",177);
		
		gotoxy(100,i+4);
		printf("%c",177);
		printf("%c",179);
		//printf("||");
	}
}
/////////////////////////////////////////////////////////////////////////////
void display(struct Process P[n])
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
	int i,l=0,b=0;
	for(i=0;i<n;i++)
    {
    l+=2;
	  //gotoxy(12,5+i);
	gotoxy(15,6+l);
	if(P[i].P_ID==-5)
    printf("   %c       %c",250,186);
    else
    {
    printf("           %c",186);
    gotoxy(15,6+l);
    printf("   P%d",P[i].P_ID);
    }
    
    gotoxy(30,6+l);
    if(P[i].arrival_time==-5)
    printf("   %c       %c",250,186);
    else{
    printf("           %c",186);
    gotoxy(30,6+l);
    printf("   %d",P[i].arrival_time);
    }
    gotoxy(45,6+l);
    if(P[i].burst_time==-5)
    printf("   %c       %c",250,186);
    else{
    printf("           %c",186);
    gotoxy(45,6+l);
    printf("   %d",P[i].burst_time);
    //printf("   %d",P[i].left_burst_time);
    }
    gotoxy(60,6+l);
    if(P[i].completion_time==-5)
    printf("   %c       %c",250,186);
    else{
    printf("           %c",186);
    gotoxy(60,6+l);
    printf("   %d",P[i].completion_time);
    }
    gotoxy(75,6+l);
    if(P[i].waiting_time==-5)
    printf("   %c       %c",250,186);
    else{
    printf("           %c",186);
    gotoxy(75,6+l);
    printf("   %d",P[i].waiting_time);
    }
    gotoxy(89,6+l);
    if(P[i].turnaround_time==-5)
    printf("   %c       ",250);
    else{
    printf("           %c",186);
    gotoxy(89,6+l);
    printf("   %d",P[i].turnaround_time);
    }
    int j;
    for(j=0;j<87;j++)
    {
    gotoxy(13+j,6+l+1);
    if(j%15==13)
    printf("%c",206);
    else
    printf("%c",205);
	}
	}
	frame();
	
}
///////////////////////////////////////////////////////////////////////////////
int main()
{
	//homepage();
	//getch();
	//system("cls");
	//loading();
	system("cls");
	int i,j,l=0,burst_count=0;
	for(i=0;i<50;i++)
	{
	gotoxy(30+i,5);
	printf("%c",177);
    }
	gotoxy(30,6);
	printf("Enter The number of Process to enter");
	gotoxy(30,7);
	scanf("%d",&n);
	system("cls");
	int gant[n],r[n];
    struct Process P[n];
   ///////initallizing the struct
    for(i=0;i<n;i++)
    {
    	P[i].arrival_time=-5,P[i].burst_time=-5,P[i].completion_time=-5,P[i].P_ID=-5;
    	P[i].turnaround_time=-5,P[i].waiting_time=-5;
		gant[i]=99,P[i].round=1;
	}
    for(i=0;i<n;i++)
    {
    	l+=2;
    	display(P);
    	gotoxy(33,2*n+10);
    	printf("Enter arrival time for process %d\n",i+1);
    	P[i].P_ID=i+1;
    	P[i].flag=0;
    	gotoxy(33,6+l);
	    scanf("%d",&P[i].arrival_time);
	    
	    gotoxy(33,2*n+10);
	    printf("Enter burst time for process %d\n",i+1);
	    gotoxy(48,6+l);
	    scanf("%d",&P[i].burst_time);
	    
	    burst_count+=P[i].burst_time;
	    P[i].left_burst_time=P[i].burst_time;
	}
	
	//for sorting according to arrival time
	for(j=0;j<n-1;j++)
	{
		for(i=0;i<n-j-1;i++)
		{
			if(P[i].arrival_time>P[i+1].arrival_time)
			{	
			struct Process t=P[i];
			P[i]=P[i+1];
			P[i+1]=t;
         	}
	    }
	}
	/////////////////////////////////////////////////
	system("cls");
	
	///////////////////////////////////////////////////
	int time_t=P[0].arrival_time,count_n=0,temp_i=0,prev_temp_i=-3,temp_opt=-1,v=0,temp_round=1,t=n,s=0,r_quanta;
    do
	{
		if(t==0 && (n-s)!=0)
		{
			t=n-s;//remaining process
			
			//printf("ttt %d  %d   %d",t,n,s);//delete
			temp_round++;
			getch();
		}
		
		int max=0;
		temp_opt=max;
		
		for(i=0;P[i].arrival_time<=time_t && i<n;i++)
		{
			
			////////////////////////////
			else if(temp_round==1)
			{
				printf("round 1");
				getch();
				r_quanta=6;////////////
	        	if(P[i].burst_time>=temp_opt &&P[i].flag==0)
	        	{
	        		if(P[i].left_burst_time<=6)
	        		{
	        			temp_opt=P[i].burst_time;
	        			P[i].flag=555;
	        	        temp_i=i;
					}
					
					else
					{
						temp_opt=6;
						temp_opt-=P[i].burst_time;
	        	        temp_i=i;
					}
					
	        	temp_opt=P[i].burst_time;
	        	temp_i=i;
	        	s++;
	        	t--;
	            }
	        }
	        
	        ////////////////////////
	        ////////////////////////////
			else if(temp_round==2)
			{
				printf("round 2");
				getch();
				r_quanta=10;
	        	if(P[i].burst_time>=temp_opt &&P[i].flag==0)
	        	{
	        	temp_opt=P[i].burst_time;
	        	temp_i=i;
	        	s++;
	        	t--;
	            }
	        }
	         ////////////////////////  
			////////////////////////////
			if(temp_round==3)
			{
	        	if(P[i].burst_time>=temp_opt &&P[i].flag==0)
	        	{
	        	temp_opt=P[i].burst_time;
	        	temp_i=i;
	            }
	        }
	         ////////////////////////   
        }
        if(prev_temp_i==temp_i)
        {
           time_t+=1;
		}
		else
		{
        printf("\n");
        P[temp_i].completion_time=time_t+temp_opt;
        P[temp_i].turnaround_time=P[temp_i].completion_time-P[temp_i].arrival_time;
        P[temp_i].waiting_time=P[temp_i].turnaround_time-P[temp_i].burst_time;
        gant[v]=P[temp_i].P_ID;
        r[v]=P[temp_i].completion_time;
        v++;
        display(P);
        gant_chart(gant,r,P[0].arrival_time);
        
        getch();
        P[temp_i].flag=555;
        time_t+=temp_opt;
        burst_count-=temp_opt;
        }
        prev_temp_i=temp_i;
        
        if(burst_count==0)
        average(P);
        
	}while(burst_count>0);
	gotoxy(30,n*2+18);
}