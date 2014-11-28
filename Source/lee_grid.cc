#include "../Headers/grid.h"
#include "../Headers/problem_object.h"
#include "../Headers/lee_grid.h"
#include "../Headers/edge.h"
#include "../Headers/claim.h"
#include "../Headers/point.h"
#include<iostream.h>
#include<stdlib.h>
#include<vector>
//Takes an x and y coordinate as input and creates a grid of that size filled with default nodes
Utilities::lee_grid::lee_grid(ProblemObject *problem_object) {
	int width=problem_object-> get_width();
int height=problem_object-> get_height();

cout<<width<<"\n";
cout<<height<<"\n";
    vector<Connection> conn = problem_object-> get_connections();
    for (int i=0;i<conn.size();i++)
    {
        cout<<conn[i].name;
	cout<<"\n";
	cout<<conn[i].source.x;
	cout<<"\n";
        cout<<conn[i].source.y;
	cout<<"\n";
        cout<<conn[i].sink.x;
	cout<<"\n";
        cout<<conn[i].sink.y;
	cout<<"\n";
    }   
    vector<Blocker> block = problem_object-> get_blockers();
	for(int i=0;i<block.size();i++)
	{
	cout<<block[i].name;
	cout<<"\n";
	cout<<block[i].location.x;
	cout<<"\n";
	cout<<block[i].location.y;
	cout<<"\n";
	cout<<block[i].width;
	cout<<"\n";
	cout<<block[i].height;
	cout<<"\n";
 
	}
cout<<"\n";

int sx,sy,tx,ty;

int a[width*3][height*3];

sx =  conn[0].source.x + width;
sy =  conn[0].source.y + height;
tx =  conn[0].sink.x + width;
ty =  conn[0].sink.y + height;

/*cout<<sx;
cout<<"\n";
cout<<sy;
cout<<"\n";
cout<<tx;
cout<<"\n";
cout<<ty;
cout<<"\n";
*/



	for(int j=0;j<height*3;j++)
	{
		for(int i=0;i<width*3;i++)
		{
			a[i][j]=0;
			
		}
	}
a[sx][sy]=70;
a[tx][ty]=80;

//	cout<<"entr number of blokages due to ICs\n";
	int v;
	v = block.size();
	for(int i=0;i<v;i++)
	{
//	cout<<"entr width and height of blockage\n";
int w =	block[i].width;
int h = block[i].height;
//	cout<<"entr starting coordinates x and y\n";
int l = block[i].location.x + width;
int k = block[i].location.y + height;
	int z=l;
	for(int j=0;j<h;j++)
	{
		int l=z;
		for(int i=0;i<w;i++)
		{
			a[l][k]=100;
			l++;
		}
		k++;
	}
	
	}
cout<<"initial grid \n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<a[i+ width][j+ height]<<"\t";
			
		}
		cout<<"\n";
		
	}

	int c = 0;
	int i=sx;
	int j=sy;
	a[i][j];
	
	while(a[tx][ty]!=a[i][j])
	{
		c++;
	i=i-1;
		for(int k=0;k<c;k++)
		{
			if((a[i][j]!=80)&&(i<width*2)&&(j<height*2)&&(i>=0)&&(j>=0)&&(a[i][j]!=100))
			{

				a[i][j] = c;
			}

			else if(a[i][j]==80)
			break;
				i++;
				j--;

		}
		for(int k=0;k<c;k++)
		{
			if(a[i][j]!=80&&(i<width*2)&&(j<height*2)&&(i>=0)&&(j>=0)&&(a[i][j]!=100))
			{

				a[i][j] = c;
			}
			else if(a[i][j]==80)
			break;
				i++;
				j++;

		}
		for(int k=0;k<c;k++)
		{
			if((a[i][j]!=80)&&(i<width*2)&&(j<height*2)&&(i>=0)&&(j>=0)&&(a[i][j]!=100))
			{

				a[i][j] = c;
			}

			else if(a[i][j]==80)
			break;
			i--;
			j++;

		}
		for(int k=0;k<c;k++)
		{
			if((a[i][j]!=80)&&(a[i][j]!=100)&&(i>=0)&&(j>=0)&&(i<width*2)&&(j<height*2))
			{
		
				a[i][j] = c;
			}

			else if(a[i][j]==80)
			break;

			i--;
			j--;
		}
	
}

cout<<"\n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<a[i+ width][j+ height]<<"\t";
			
		}
		cout<<"\n";
		
	}
	
	cout<<c<<"  is the cost to reach drain \t"<<endl;

int p=tx;
int q=ty;


//Trace back logic

int temp[width][height];

for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			temp[i+width][j+height]=0;
			
		}
		
	}

for(int i=c;i>=1;i--)
{
	c--;
	if(a[tx-1][ty]==c)
	{
		temp[tx-1][ty]=a[tx-1][ty];
		tx--;
	}
	else if(a[tx+1][ty]== c)
	{
		temp[tx+1][ty]=a[tx+1][ty];
		tx++;
	}
	else if(a[tx][ty-1]== c)
	{
		temp [tx][ty-1]=a[tx][ty-1];
		ty--;
	}
	else if(a[tx][ty+1]==c)
	{
		temp[tx][ty+1]=a[tx][ty+1];
		ty++;
	}
}


cout<<"trace back path is as shown\n\n";
temp[sx][sy]=70;
temp[p][q]=80;

	for(int j=0;j<height; j++)
	{
		for(int i=0;i<width; i++)
		{
			cout<<temp[i+width][j+height]<<"\t";
			
		}
		cout<<endl;
		
	}
	cout<<"trace back path is \n";
	
	for(int j=height;j<height*2; j++)
	{
		for(int i=width;i<width*2; i++)
		{
			if(temp[i][j]!=0)
			{
				cout<<"("<<j-height<<","<<i-width<<")\t";
			}
			
		}
		
	}


}

