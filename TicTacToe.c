#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void board(char [],int);

int with_friend(char [],int,int, int);

int winning_with_friend(char [],int);

void smart_computer(char [],int,int);

void evil_computer(char [],int,int);

int winning_with_computer(char [],int);

int main()
{
	int w,r,p, player, marking, choice;
	char var,ttt[9]={'1','2','3','4','5','6','7','8','9'};
	
	printf("\t\t:----- Welcome To TicTacToe -----:");
	printf("\n\n1: Play With A Friend");
	printf("\n2: Play With Smart Computer");
	printf("\n3: Play With Evil Computer");
	printf("\n4: Exit");
	
	printf("\n\nChoose Any Option From The Above Menu: ");
	scanf("%d",&choice);   
	switch(choice)
	{
		case 1:		//case 1
			board(ttt,9);
				
			while(1)
			{
				for(player=1;player<=2;player++)
				{
					if(player==1)
					{
						printf("\nYour Turn, Enter Marking Place: ");
						scanf("%d",&marking);
					}
					else
					{
						printf("\nOpponent's Turn, Enter Marking Place: ");
						scanf("%d",&marking);
					}
					
					p=with_friend(ttt,9,player,marking);
			
					if(p==1)
					{
						player-=1;
						continue;
					}
						
					w=winning_with_friend(ttt,9);
					if(w==1)
					{
						if(player==1)
						{
							printf("\nCongrats, You Won The Match!");
							
							break;
						}
						else
						{
							printf("\nYour Opponent Won The Match!");
							
							break;
						}
					}
						
					else if(w==0)
					{
						printf("\nMatch Draw!");
						
						break;
					}
					else
						continue;
				}
				if(w==1 || w==0)
					break;
			}
			
			printf("\n\n\nEnter 'M' or 'm' to return to the Main Menu... ");
			printf("\n\n\nOr Press Enter Key To Exit the game... ");
			fflush(stdin);
			scanf("%c",&var);
			if(var=='M' ||var=='m')
			{
				system("cls");
				main();
			}
			else
			{
				system("cls");
				printf("See You Soon, GoodBye! :)");
				exit(0);
			}	
			
			break;
	
		case 2:		//case 2
			board(ttt,9);
			
			while(1)
			{	
				printf("\nYour Turn, Enter Marking Place: ");
				scanf("%d",&marking);
				
				smart_computer(ttt,9,marking);
					
				w=winning_with_computer(ttt,9);	
				if(w==1)
				{
					printf("\nCongrats, You Won The Match!");
					break;
				}
				else if(w==2)
				{
					printf("\nSmart Computer Won The Match!");
					break;
				}	
				else if(w==0)
				{
					printf("\nMatch Draw!");					
					break;
				}
				else
					continue;
			}
			
			printf("\n\n\nEnter 'M' or 'm' to return to the Main Menu... ");
			printf("\n\n\nOr Press Enter Key To Exit the game... ");
			fflush(stdin);
			scanf("%c",&var);
			if(var=='M' ||var=='m')
			{
				system("cls");
				main();
			}
			else
			{
				system("cls");
				printf("See You Soon, GoodBye! :)");
				exit(0);
			}
			
			break;
	
		case 3:		//case 3
			board(ttt,9);
			
			while(1)
			{	
				printf("\nYour Turn, Enter Marking Place: ");
				scanf("%d",&marking);
				
				evil_computer(ttt,9,marking);
					
				w=winning_with_computer(ttt,9);	
				if(w==1)
				{
					printf("\nCongrats, You Won The Match!");
					break;
				}
				else if(w==2)
				{
					printf("\nEvil Computer Won The Match!");
					break;
				}	
				else if(w==0)
				{
					printf("\nMatch Draw!");					
					break;
				}
				else
					continue;
			}
			
			printf("\n\n\nEnter 'M' or 'm' to return to the Main Menu... ");
			printf("\n\n\nOr Press Enter Key To Exit the game... ");
			fflush(stdin);
			scanf("%c",&var);
			if(var=='M' ||var=='m')
			{
				system("cls");
				main();
			}
			else
			{
				system("cls");
				printf("See You Soon, GoodBye! :)");
				exit(0);
			}
			
			break;
			
		case 4:		//case 4
			system("cls");
			printf("See You Soon, GoodBye! :)");
			exit(0);
			
		default:	//default
			printf("\n\nInvalid option, Please Choose a Valid Option From The Menu!\n\nPress Any Key To Continue...");
			getch();
			system("cls");
			main();
	}
		
	getch();								
}

//To Print The TicTacToe Board
void board(char ttt[],int size)	
{
	system("cls");
	printf("\t\t:----- TicTacToe -----:");
	printf("\n\n");
	printf("You -> X");
	printf("\nOpponent -> O");
	printf("\n\n\n");
	printf("\n------------------\n");
	
	int i;
	
	for(i=0;i<size;i++)
	{
		if(i==3 || i==6)	
			printf("\n------------------\n");
		printf("  %c  |",ttt[i]);
		
		if(i==8)
			printf("\n------------------\n");
	}
}

//Game Starts With Friend
int with_friend(char ttt[],int size,int player, int marking)
{
	system("cls");
	printf("\t\t:----- TicTacToe -----:");
	printf("\n\n");
	printf("You -> X");
	printf("\nOpponent -> O");
	printf("\n\n\n");
	printf("\n------------------\n");
	
	int j;
	
	if(player==1)	//For Player 1
	{
		if(ttt[marking-1]!='X' && ttt[marking-1]!='O')
			ttt[marking-1]='X';
		else
		{
			int i;
			for(i=0;i<size;i++)
			{
				if(i==3 || i==6)	
					printf("\n------------------\n");
				printf("  %c  |",ttt[i]);
				
				if(i==8)
					printf("\n------------------\n");
			}
			j=i;
			printf("\nPlace Already Occupied, Please Try Again!\n");
			return 1;
		}
	}
	
	else	//For Player 2
	{
		if(ttt[marking-1]!='X' && ttt[marking-1]!='O')
			ttt[marking-1]='O';
		else
		{
			int i;
			for(i=0;i<size;i++)
			{
				if(i==3 || i==6)	
					printf("\n------------------\n");
				printf("  %c  |",ttt[i]);
				
				if(i==8)
					printf("\n------------------\n");
			}
			j=i;
			printf("\nPlace Already Occupied, Please Try Again!\n");
			return 1;
		}		
	}
	
	if(j!=size)
	{
		for(j=0;j<size;j++)
		{
			if(j==3 || j==6)	
				printf("\n------------------\n");
			printf("  %c  |",ttt[j]);
			
			if(j==8)
				printf("\n------------------\n");
		}
	}				
}

//Lets See If I Won The Match with my friend
int winning_with_friend(char ttt[],int size)
{
	if(ttt[0]==ttt[1] && ttt[1]==ttt[2])
		return 1;
		
	else if(ttt[3]==ttt[4] && ttt[4]==ttt[5])
		return 1;
		
	else if(ttt[6]==ttt[7] && ttt[7]==ttt[8])
		return 1;
		
	else if(ttt[0]==ttt[3] && ttt[3]==ttt[6])
		return 1;
		
	else if(ttt[1]==ttt[4] && ttt[4]==ttt[7])
		return 1;
		
	else if(ttt[2]==ttt[5] && ttt[5]==ttt[8])
		return 1;
		
	else if(ttt[0]==ttt[4] && ttt[4]==ttt[8])
		return 1;
		
	else if(ttt[2]==ttt[4] && ttt[4]==ttt[6])
		return 1;
		
	else if(ttt[0]!='1' && ttt[1]!='2' && ttt[2]!='3' && ttt[3]!='4' && ttt[4]!='5' 
		&& ttt[5]!='6' && ttt[6]!='7' && ttt[7]!='8' && ttt[8]!='9') 
		return 0;
		
	else
		return -1;
}

//Game Starts With Smart Computer
void smart_computer(char ttt[],int size,int marking)
{
	system("cls");
	printf("\t\t:----- TicTacToe -----:");
	printf("\n\n");
	printf("You -> X");
	printf("\nOpponent -> O");
	printf("\n\n\n");
	printf("\n------------------\n");
	
	int i;
	
	if(ttt[marking-1]!='X' && ttt[marking-1]!='O')
	{
		ttt[marking-1] = 'X';
		

		if(ttt[0]=='X' && ttt[1]=='X')
			if(ttt[2]!='X' && ttt[2]!='O')
				ttt[2]='O';
			else
				goto a;
			
			
		else a: if(ttt[0]=='X' && ttt[2]=='X')
			if(ttt[1]!='X' && ttt[1]!='O')
				ttt[1]='O';
			else
				goto b;
				
			
		else b:  if(ttt[1]=='X' && ttt[2]=='X')
			if(ttt[0]!='X' && ttt[0]!='O')
				ttt[0]='O';
			else
				goto c;

			
		else c:  if(ttt[0]=='X' && ttt[3]=='X')
			if(ttt[6]!='X' && ttt[6]!='O')
				ttt[6]='O';
			else
				goto d;

			
		else d:  if(ttt[0]=='X' && ttt[6]=='X')
			if(ttt[3]!='X' && ttt[3]!='O')
				ttt[3]='O';
			else
				goto e;

		
		else e:  if(ttt[3]=='X' && ttt[6]=='X')
			if(ttt[0]!='X' && ttt[0]!='O')
				ttt[0]='O';
			else
				goto f;

							
		else f:  if(ttt[0]=='X' && ttt[4]=='X')
			if(ttt[8]!='X' && ttt[8]!='O')
				ttt[8]='O';
			else
				goto g;

		
		else g:  if(ttt[0]=='X' && ttt[8]=='X')
			if(ttt[4]!='X' && ttt[4]!='O')
				ttt[4]='O';
			else
				goto h;
			
		else h:  if(ttt[4]=='X' && ttt[8]=='X')
			if(ttt[0]!='X' && ttt[0]!='O')
				ttt[0]='O';
			else
				goto i;
		
		else i:  if(ttt[1]=='X' && ttt[4]=='X')
			if(ttt[7]!='X' && ttt[7]!='O')
				ttt[7]='O';
			else
				goto j;
				
		else j:  if(ttt[1]=='X' && ttt[7]=='X')
			if(ttt[4]!='X' && ttt[4]!='O')
				ttt[4]='O';
			else
				goto k;

		
		else k:  if(ttt[4]=='X' && ttt[7]=='X')
			if(ttt[1]!='X' && ttt[1]!='O')
				ttt[1]='O';	
			else
				goto l;

												
		else l:  if(ttt[2]=='X' && ttt[5]=='X')
			if(ttt[8]!='X' && ttt[8]!='O')
				ttt[8]='O';	
			else
				goto m;
				
		
		else m:  if(ttt[2]=='X' && ttt[8]=='X')
			if(ttt[5]!='X' && ttt[5]!='O')
				ttt[5]='O';	
			else
				goto n;

		
		else n:  if(ttt[5]=='X' && ttt[8]=='X')
			if(ttt[2]!='X' && ttt[2]!='O')
				ttt[2]='O';	
			else
				goto o;

		
		else o:  if(ttt[2]=='X' && ttt[4]=='X')
			if(ttt[6]!='X' && ttt[6]!='O')
				ttt[6]='O';	
			else
				goto p;

		
		else p:  if(ttt[2]=='X' && ttt[6]=='X')
			if(ttt[4]!='X' && ttt[4]!='O')
				ttt[4]='O';	
			else
				goto q;

		
		else q:  if(ttt[4]=='X' && ttt[6]=='X')
			if(ttt[2]!='X' && ttt[2]!='O')
				ttt[2]='O';	
			else
				goto r;

		
		else r:  if(ttt[3]=='X' && ttt[4]=='X')
			if(ttt[5]!='X' && ttt[5]!='O')
				ttt[5]='O';	
			else
				goto s;
				
		
		else s:  if(ttt[3]=='X' && ttt[5]=='X')
			if(ttt[4]!='X' && ttt[4]!='O')
				ttt[4]='O';	
			else
				goto t;

		
		else t:  if(ttt[4]=='X' && ttt[5]=='X')
			if(ttt[3]!='X' && ttt[3]!='O')
				ttt[3]='O';	
			else
				goto u;
				
		
		else u:  if(ttt[6]=='X' && ttt[7]=='X')
			if(ttt[8]!='X' && ttt[8]!='O')
				ttt[8]='O';	
			else
				goto v;
				
		
		else v:  if(ttt[6]=='X' && ttt[8]=='X')
			if(ttt[7]!='X' && ttt[7]!='O')
				ttt[7]='O';	
			else
				goto w;

		
		else w:  if(ttt[7]=='X' && ttt[8]=='X')
			if(ttt[6]!='X' && ttt[6]!='O')
				ttt[6]='O';	
			else
				goto x;
				
		
		else x:
			for(i=0;i<size;i++)
			{
				if(ttt[i]!='X' && ttt[i]!='O')
				{
					ttt[i] = 'O';
					break;
				}
			}
	}
	
	else
	{
		for(i=0;i<size;i++)
		{
			if(i==3 || i==6)
				printf("\n------------------\n");
			printf("  %c  |",ttt[i]);
			
			if(i==8)
				printf("\n------------------\n");
		}
		printf("\nPlace Already Occupied, Please Try Again!\n");
	}	
		
	if(i!=size)
	{
		for(i=0;i<size;i++)
		{
			if(i==3 || i==6)
				printf("\n------------------\n");
			printf("  %c  |",ttt[i]);
			
			if(i==8)
				printf("\n------------------\n");
		}	
	}								
}

//Game Starts With Evil Computer
void evil_computer(char ttt[],int size,int marking)
{
	system("cls");
	printf("\t\t:----- TicTacToe -----:");
	printf("\n\n");
	printf("You -> X");
	printf("\nOpponent -> O");
	printf("\n\n\n");
	printf("\n------------------\n");
	
	int i,count=0;
	
	if(ttt[marking-1]!='X' && ttt[marking-1]!='O')
	{
			ttt[marking-1] = 'X';
		
			if(ttt[0]=='X' && ttt[1]=='X')
				if(ttt[2]!='X' && ttt[2]!='O')
				{
					ttt[2]='O';
					count++;
				}
				
			if(ttt[0]=='X' && ttt[2]=='X')
				if(ttt[1]!='X' && ttt[1]!='O')
				{
					ttt[1]='O';
					count++;
				}
				
			if(ttt[1]=='X' && ttt[2]=='X')
				if(ttt[0]!='X' && ttt[0]!='O')
				{
					ttt[0]='O';
					count++;
				}
				
			if(ttt[0]=='X' && ttt[3]=='X')
				if(ttt[6]!='X' && ttt[6]!='O')
				{
					ttt[6]='O';
					count++;
				}
				
			if(ttt[0]=='X' && ttt[6]=='X')
				if(ttt[3]!='X' && ttt[3]!='O')
				{
					ttt[3]='O';
					count++;
				}
				
			if(ttt[3]=='X' && ttt[6]=='X')
				if(ttt[0]!='X' && ttt[0]!='O')
				{
					ttt[0]='O';
					count++;
				}
							
			if(ttt[0]=='X' && ttt[4]=='X')
				if(ttt[8]!='X' && ttt[8]!='O')
				{
					ttt[8]='O';
					count++;
				}
				
			if(ttt[0]=='X' && ttt[8]=='X')
				if(ttt[4]!='X' && ttt[4]!='O')
				{
					ttt[4]='O';
					count++;
				}
				
			if(ttt[4]=='X' && ttt[8]=='X')
				if(ttt[0]!='X' && ttt[0]!='O')
				{
					ttt[0]='O';
					count++;
				}
				
			if(ttt[1]=='X' && ttt[4]=='X')
				if(ttt[7]!='X' && ttt[7]!='O')
				{
					ttt[7]='O';
					count++;
				}
				
			if(ttt[1]=='X' && ttt[7]=='X')
				if(ttt[4]!='X' && ttt[4]!='O')
				{
					ttt[4]='O';
					count++;
				}
				
			if(ttt[4]=='X' && ttt[7]=='X')
				if(ttt[1]!='X' && ttt[1]!='O')
				{
					ttt[1]='O';
					count++;
				}	
											
			if(ttt[2]=='X' && ttt[5]=='X')
				if(ttt[8]!='X' && ttt[8]!='O')
				{
					ttt[8]='O';
					count++;
				}	
			
			if(ttt[2]=='X' && ttt[8]=='X')
				if(ttt[5]!='X' && ttt[5]!='O')
				{
					ttt[5]='O';
					count++;
				}	
			
			if(ttt[5]=='X' && ttt[8]=='X')
				if(ttt[2]!='X' && ttt[2]!='O')
				{
					ttt[2]='O';
					count++;
				}	
			
			if(ttt[2]=='X' && ttt[4]=='X')
				if(ttt[6]!='X' && ttt[6]!='O')
				{
					ttt[6]='O';
					count++;
				}	
			
			if(ttt[2]=='X' && ttt[6]=='X')
				if(ttt[4]!='X' && ttt[4]!='O')
				{
					ttt[4]='O';
					count++;
				}	
				
			if(ttt[4]=='X' && ttt[6]=='X')
				if(ttt[2]!='X' && ttt[2]!='O')
				{
					ttt[2]='O';
					count++;
				}	
				
			if(ttt[3]=='X' && ttt[4]=='X')
				if(ttt[5]!='X' && ttt[5]!='O')
				{
					ttt[5]='O';
					count++;
				}	
			
			if(ttt[3]=='X' && ttt[5]=='X')
				if(ttt[4]!='X' && ttt[4]!='O')
				{
					ttt[4]='O';
					count++;
				}	
			
			if(ttt[4]=='X' && ttt[5]=='X')
				if(ttt[3]!='X' && ttt[3]!='O')
				{
					ttt[3]='O';
					count++;
				}	
				
			if(ttt[6]=='X' && ttt[7]=='X')
				if(ttt[8]!='X' && ttt[8]!='O')
				{
					ttt[8]='O';
					count++;	
				}	
			
			if(ttt[6]=='X' && ttt[8]=='X')
				if(ttt[7]!='X' && ttt[7]!='O')
				{
					ttt[7]='O';
					count++;
				}	
			
			if(ttt[7]=='X' && ttt[8]=='X')
				if(ttt[6]!='X' && ttt[6]!='O')
				{
					ttt[6]='O';
					count++;	
				}
				
			if(count==0)
			{
				for(i=0;i<size;i++)
				{
					if(ttt[i]!='X' && ttt[i]!='O')
					{
						ttt[i] = 'O';
						break;
					}
				}
			}
	}
	
	else
	{
		for(i=0;i<size;i++)
		{
			if(i==3 || i==6)
				printf("\n------------------\n");
			printf("  %c  |",ttt[i]);
			
			if(i==8)
				printf("\n------------------\n");
		}
		printf("\nPlace Already Occupied, Please Try Again!\n");
	}	
		
	if(i!=size)
	{
		for(i=0;i<size;i++)
		{
			if(i==3 || i==6)
				printf("\n------------------\n");
			printf("  %c  |",ttt[i]);
			
			if(i==8)
				printf("\n------------------\n");
		}	
	}								
}

//Lets See if i Won The Match with computer
int winning_with_computer(char ttt[],int size)
{
	if(ttt[0]=='X'&&ttt[1]=='X'   &&   ttt[1]=='X'&&ttt[2]=='X')
		return 1;
	else if(ttt[0]=='O'&&ttt[1]=='O'   &&   ttt[1]=='O'&&ttt[2]=='O')
		return 2;
		
	else if(ttt[3]=='X'&&ttt[4]=='X'  &&   ttt[4]=='X'&&ttt[5]=='X')
		return 1;
	else if(ttt[3]=='O'&&ttt[4]=='O'  &&   ttt[4]=='O'&&ttt[5]=='O')
		return 2;
		
	else if(ttt[6]=='X'&&ttt[7]=='X'   &&   ttt[7]=='X'&&ttt[8]=='X')
		return 1;
	else if(ttt[6]=='O'&&ttt[7]=='O'   &&   ttt[7]=='O'&&ttt[8]=='O')
		return 2;
		
	else if(ttt[0]=='X'&&ttt[3]=='X'   &&   ttt[3]=='X'&&ttt[6]=='X')
		return 1;
	else if(ttt[0]=='O'&&ttt[3]=='O'   &&   ttt[3]=='O'&&ttt[6]=='O')
		return 2;
		
	else if(ttt[1]=='X'&&ttt[4]=='X'   &&   ttt[4]=='X'&&ttt[7]=='X')
		return 1;
	else if(ttt[1]=='O'&&ttt[4]=='O'   &&   ttt[4]=='O'&&ttt[7]=='O')
		return 2;
		
	else if(ttt[2]=='X'&&ttt[5]=='X'   &&   ttt[5]=='X'&&ttt[8]=='X')
		return 1;
	else if(ttt[2]=='O'&&ttt[5]=='O'   &&   ttt[5]=='O'&&ttt[8]=='O')
		return 2;
		
	else if(ttt[0]=='X'&&ttt[4]=='X'   &&   ttt[4]=='X'&&ttt[8]=='X')
		return 1;
	else if(ttt[0]=='O'&&ttt[4]=='O'   &&   ttt[4]=='O'&&ttt[8]=='O')
		return 2;
		
	else if(ttt[2]=='X'&&ttt[4]=='X'   &&   ttt[4]=='X'&&ttt[6]=='X')
		return 1;
	else if(ttt[2]=='O'&&ttt[4]=='O'   &&   ttt[4]=='O'&&ttt[6]=='O')
		return 2;
		
	else if(ttt[0]!='1' && ttt[1]!='2' && ttt[2]!='3' && ttt[3]!='4' && ttt[4]!='5' 
		&& ttt[5]!='6' && ttt[6]!='7' && ttt[7]!='8' && ttt[8]!='9') 
		return 0;
		
	else
		return -1;
}	
