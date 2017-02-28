#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

char ch[40];

int change1(char c)
{
	if(c>='0'&&c<='9')
		return c-'0';
	else
		return c-'A'+10;
}

int change2(char c)
{
	if(c<10)
		return c+'0';
	else
		return c-10+'A';
}

main()
{
	int base1,base2;
	while(scanf("%s%d%d",ch,&base1,&base2)!=EOF)
	{
		int value=0,move=0,save=0;
		while(ch[move])
		{
			value*=base1;
			value+=change1(ch[move++]);
		}
		if(!value)
			ch[save++]='0';
		while(value)
		{
			ch[save++]=change2(value%base2);
			value=value/base2;
		}
		if(save>7)
			cout<<"  ERROR"<<endl;
		else
		{
			for(int i=save;i<7;++i)
				cout<<" ";
			while(--save>=0)
				cout<<ch[save];
			cout<<endl;
		}
	}
}
