#include<stdio.h>
#include<stdlib.h>
#define row 9
#define col 9
int sudo[row][col],i,j,count,pos,num,check[9],m,n,k,l;
int matcount[4] = {0,3,6,9};
void display()
{	
	count=0;
	for(i=0;i<row;i++)
	{	
			
		for(j=0;j<col;j++)
		{
			count++;
			printf("%d[%d]\t",sudo[i][j],count);
		}		
		printf("\n\n");
	}
}

void initialize_sudo()
{
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			sudo[i][j] = 0;
}

void rules()
{
	printf("\n\t\t\t*RULES*");
	printf("\n\t1.All rows should have digit 1 to 9 without repetition.");
	printf("\n\t2.All columns should have digit 1 to 9 without repetition.");
	printf("\n\t3.Every 3x3 matrix should have digits 1 to 9 without repetition.\n\n");
}

void input()
{
	printf("\n Enter the position at which you want to enter the no: ");
	scanf("%d",&pos);
	printf("\n Enter the number you want to enter: ");
	scanf("%d",&num);
	count=0;	
	for(i=0;i<row;i++)
	{
			
		for(j=0;j<col;j++)
		{
			count++;
			if(count==pos)
			{
				sudo[i][j]=num;
			}
		}
	}			
}

int check_rows()
{
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			check[j] = sudo[i][j];
		}
		for(m=0;m<9;m++)
		{
			for(n=m+1;n<9;n++)
			{	
				if(check[m]==0)
				{
					continue;
				}
				if((check[m]==check[n])||(check[n]<0)||(check[n]>9))
				{
					printf("row %d",i);
					return 0;
				}
			}
		}
	}
	return 1;
}

int check_cols()
{
	for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			check[j] = sudo[j][i];
		}
		for(m=0;m<9;m++)
		{
			for(n=m+1;n<9;n++)
			{	
				if(check[m]==0)
				{
					continue;
				}
				if((check[m]==check[n])||(check[n]<0)||(check[n]>9))
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int check_mat()
{	
	
	for(i=0;i<3;i++)
	{	
		for(j=0;j<3;j++)
		{
			count=0;
			for(k=matcount[i];k<matcount[i+1];k++)
			{
				
				for(l=matcount[j];l<matcount[j+1];l++)
				{
					check[count] = sudo[k][l];
					count++;
				}
			}
			for(m=0;m<9;m++)
			{
				for(n=m+1;n<9;n++)
				{	
					if(check[m]==0)
					{
						continue;
					}
					if((check[m]==check[n])||(check[n]<0)||(check[n]>9))
					{
						return 0;
					}
				}		
			}
		}
	}
	return 1;
}

void invalid_input()
{
	printf("\n\n*INVALID INPUT*\n\n");
	count=0;	
	for(i=0;i<row;i++)
	{
			
		for(j=0;j<col;j++)
		{
			count++;
			if(count==pos)
			{
				sudo[i][j]=0;
			}
		}
	}		
	
}

void main()
{
	int checkres1,checkres2,checkres3;
	
	
	printf("\n\n \t\t\t****WELCOME TO SUDOKO\n");
	rules();
	initialize_sudo();	
	do
	{
		display();
		input();
		checkres1 = check_rows();
		checkres2 = check_cols();
		checkres3 = check_mat();
		if ((checkres1!=1)||(checkres2!=1)||(checkres3!=1))
		{
			invalid_input();
			rules();
		}
	}while(1);
