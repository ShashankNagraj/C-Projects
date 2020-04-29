//============================================================================
// Name        : policy.cpp
// Author      : SHASHANK NAGRAJ BHAT
// Version     :
// Copyright   : Your copyright notice
// Description : PAGE REPLACEMENT POLICY in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
void FIFO(char [ ],char [ ],int,int);
void lru(char [ ],char [ ],int,int);
int main() {
	int ch,YN=0,i,l,f;
	char F[10],s[25];
	cout<<"\n\n\tEnter the no of empty frames: ";
	cin>>f;
	cout<<"\n\n\tEnter the length of the string: ";
	cin>>l;
	cout<<"\n\n\tEnter the string: ";
	cin>>s;
	for(i=0;i<f;i++)
		F[i]='*';
	do
	{
		cout<<"\n\n\t*********** MENU ***********";
		cout<<"\n\n\t1:FIFO\n\n\t2:LRU \n\n\t4:EXIT";
		cout<<"\n\n\tEnter your choice: ";
		cin>>ch;

		switch(ch)
		{

		case 1:
			for(i=0;i<f;i++)
			{
			F[i]='*';

			}
			FIFO(s,F,l,f);
			break;
		case 2:
			for(i=0;i<f;i++)

			{
			F[i]='*';
			}
			lru(s,F,l,f);
			break;

		case 4:
			exit(0);
		}

		cout<<"\n\n\tDo u want to continue IF YES PRESS 1\n\n\tIF NO PRESS 0 : ";
		cin>>YN;
	}while(YN==1);return(0); //END OF LOOP
}//END OF MAIN FUNCTION
	//FIFO
	void FIFO(char s[],char F[],int l,int f)

	{
		int i,j=0,k,flag=0,cnt=0;
		cout<<"\n\tPAGE\t  FRAMES\tFAULTS";
		for(i=0;i<l;i++)

		{
			for(k=0;k<f;k++)
			{
				if(F[k]==s[i])
				flag=1;

			}
			if(flag==0)
			{
				cout<<"\n\t"<<s[i]<<"\t";
				F[j]=s[i];
				j++;
				for(k=0;k<f;k++)

				{
				cout<<"  "<<F[k];
				}
				cout<<"\tPage-fault"<<cnt;
				cnt++;

			}
			else
			{
				flag=0;

				cout<<"\n\t"<<s[i]<<"\t";
				for(k=0;k<f;k++)
				{
				cout<<"  "<<F[k];
				}

				cout<<"\tNo page-fault";
			}
			if(j==f)
			j=0;
		}

	}//END OF FIFO


	//LRU
	void lru(char s[],char F[],int l,int f)
	{

		int i,j=0,k,m,flag=0,cnt=0,top=0;
		cout<<"\n\tPAGE\t  FRAMES\tFAULTS";
		for(i=0;i<l;i++)
		{
			for(k=0;k<f;k++)

			{
				if(F[k]==s[i])
				{
				flag=1;

				break;
				}
			}
			cout<<"\n\t"<<s[i]<<"\t";
			if(j!=f && flag!=1)

			{
				F[top]=s[i];
				j++;
				if(j!=f)
				top++;
			}
			else

			{
				if(flag!=1)
				{
					for(k=0;k<top;k++)
					{

					F[k]=F[k+1];
					}
					F[top]=s[i];
				}

				if(flag==1)
				{
					if(j!=f){
							for(m=k;m<top-1;m++)
							{
							F[m]=F[m+1];

							}
							F[top-1]=s[i];
						}
					else
						{
							for(m=k;m<top;m++)
							{
								F[m]=F[m+1];

							}
							F[top]=s[i];
						}
				}
			}
			for(k=0;k<f;k++)

			{
				cout<<"  "<<F[k];
			}
			if(flag==0)

			{
				cout<<"\tPage-fault"<<cnt;
				cnt++;
			}
			else
				cout<<"\tNo page fault";
			flag=0;
		}
	}//END OF LRU


