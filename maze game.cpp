#include <iostream>
using namespace std;
int top=-1;
struct path
{
	int x;
	int y;
	struct path *next;
};
int main()
{
	struct path *maze,*n;
	top++;
	n=new path();
	n->x=0;
	n->y=0;
	n->next=NULL;
	maze=n;
	char arr[6][6];
	int dummy[6][6];
	char show[6][6];
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			dummy[i][j]=0;
			if((i==0&&j==2)||(i==1&&j==2)||(i==2&&j==1)||(i==2&&j==2)||(i==2&&j==3)||(i==4&&j==1)||(i==4&&j==2)||(i==4&&j==4)||(i==5&&j==2)||(i==5&&j==4))
			{
				arr[i][j]='x';
				show[i][j]='x';
			}
			else
			{
			arr[i][j]=' ';
			show[i][j]=' ';
		    }
		}
	}
	arr[0][0]='S';
	arr[5][5]='D';
	show[5][5]='D';
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	int xxx=0;
	char val;
	do
	{
		if(maze->x<5&&arr[(maze->x)+1][maze->y]!='f'&&arr[(maze->x)+1][maze->y]!='x'&&xxx!=4)//down
		{
			n=new path();
			n->x=(maze->x)+1;
			n->y=(maze->y);
			n->next=maze;
			maze=n;
			dummy[maze->x][maze->y]=1;
			top++;
			xxx=1;
		}
		else if(maze->y<5&&arr[(maze->x)][(maze->y)+1]!='f'&&arr[(maze->x)][(maze->y)+1]!='x'&&xxx!=3)//right
		{
			n=new path();
			n->x=(maze->x);
			n->y=(maze->y)+1;
			n->next=maze;
			maze=n;
			dummy[maze->x][maze->y]=1;
			top++;
			xxx=2;
		}
		else if(maze->x>0&&arr[(maze->x)-1][maze->y]!='f'&&arr[(maze->x)-1][maze->y]!='x'&&xxx!=1)//up
		{
			n=new path();
			n->x=(maze->x)-1;
			n->y=(maze->y);
			n->next=maze;
			dummy[maze->x][maze->y]=1;
			maze=n;
			top++;
			xxx=4;
		}
		else if(maze->y>0&&arr[(maze->x)][(maze->y)-1]!='f'&&arr[(maze->x)][(maze->y)-1]!='x'&&xxx!=2)//left
		{
			n=new path();
			n->x=(maze->x);
			n->y=(maze->y)-1;
			n->next=maze;
			dummy[maze->x][maze->y]=1;
			maze=n;
			top++;
			xxx=3;
		}
		
		else
		{
			top--;
			dummy[maze->x][maze->y]=0;
			arr[maze->x][maze->y]='f';
			maze=maze->next;
		}
		val=arr[maze->x][maze->y];
		//cout<<endl<<maze->x<<" "<<maze->y;
		}while(val!='S'&&val!='D');
		dummy[4][0]=0;
		dummy[5][0]=0;
	/*if(arr[maze->x][maze->y]=='D')
	{
	cout<<"yes";
    }
	else
	cout<<"no";
	cout<<endl;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			cout<<dummy[i][j];
		}
		cout<<endl;
	}*/
	int life=3;
	show[0][0]='@';
	int a=0,b=0;
	char move;
	cout<<"w->for up"<<endl<<"s->for down"<<endl<<"a->for left"<<endl<<"d->for right"<<endl<<"x->for exit";
	cout<<endl<<"your left life is "<<life<<endl;
	cin>>move;
	while(show[5][5]!='@'&&move!='x')
	{
		switch(move)
		{
			case 'w':
				if(dummy[a-1][b]==1)
				{
					show[a][b]=' ';
					a=a-1;
					show[a][b]='@';
				}
				else
				{
					life--;
				}
				break;
				case 's':
				if(dummy[a+1][b]==1)
				{
					show[a][b]=' ';
					a=a+1;
					show[a][b]='@';
				}
				else
				{
					life--;
				}
				break;
				case 'a':
				if(dummy[a][b-1]==1)
				{
					show[a][b]=' ';
					b=b-1;
					show[a][b]='@';
				}
				else
				{
					life--;
				}
				break;
				case 'd':
				if(dummy[a][b+1]==1)
				{
					show[a][b]=' ';
					b=b+1;
					show[a][b]='@';
				}
				else
				{
					life--;
				}
				break;
				
		}
		if(life<1)
		{
		   show[a][b]=' ';
			a=0;
			b=0;
			show[a][b]='@';
			life=3;
		}
			 system("cls");
		for(int i=0;i<6;i++)
	    {
		for(int j=0;j<6;j++)
		{
			cout<<show[i][j];
		}
		cout<<endl;
     	}
     	cout<<"w->for up"<<endl<<"s->for down"<<endl<<"a->for left"<<endl<<"d->for right"<<endl<<"x->for exit";
     	cout<<endl<<"your left life is "<<life<<endl;
	cin>>move;
	}
	cout<<endl<<"FINISH";
}
