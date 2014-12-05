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
	width=problem_object-> get_width();
        height=problem_object-> get_height();

//cout<<width<<"\n";
//cout<<height<<"\n";
    conn = problem_object-> get_connections();
    
    block = problem_object-> get_blockers();

cout<<"\n";
}

void Utilities::lee_grid::lee_algo()
{
 cout<<"\n"<<"LEE Algorithm";
 
 h1=0;
 count = conn.size()-1;
 count1=0;

while(count>=0)
{
count--;
//int sx,sy,tx,ty;

int a[width*3][height*3];

sx =  conn[h1].source.x + width;
sy =  conn[h1].source.y + height;
tx =  conn[h1].sink.x + width;
ty =  conn[h1].sink.y + height;


h1++;


	for(int j=0;j<height*3;j++)
	{
		for(int i=0;i<width*3;i++)
		{
			a[i][j]=0;
			
		}
	}
a[sx][sy]=-2;//...................source of grid
a[tx][ty]=-3;//........................sink

//	cout<<"entr number of blokages due to ICs\n";
//	int v;
	v = block.size();
	for(int i=0;i<v;i++)
	{
//	cout<<"entr width and height of blockage\n";
 w =	block[i].width;
 h = block[i].height;
//	cout<<"entr starting coordinates x and y\n";
 l = block[i].location.x + width;
 k = block[i].location.y + height;
	int z=l;
	for(int j=0;j<h;j++)
	{
		int l=z;
		for(int i=0;i<w;i++)
		{
			a[l][k]=-1;
			l++;
		}
		k++;
	}
	
	}
cout<<"\n"<<"initial grid for lee algo is \n";

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

// Wavefront expansion logic
	
	while(a[tx][ty]!=a[i][j])
	{
		c++;
	i=i-1;
		for(int k=0;k<c;k++)
		{
			if((a[i][j]!= -3)&&(i<width*2)&&(j<height*2)&&(i>=0)&&(j>=0)&&(a[i][j]!= -1))
			{

				a[i][j] = c;
			}

			else if(a[i][j]== -3)
			break;
				i++;
				j--;

		}
		for(int k=0;k<c;k++)
		{
			if((a[i][j]!= -3) &&(i<width*2)&&(j<height*2)&&(i>=0)&&(j>=0)&&(a[i][j]!=-1))
			{

				a[i][j] = c;
			}
			else if(a[i][j]== -3)
			break;
				i++;
				j++;

		}
		for(int k=0;k<c;k++)
		{
			if((a[i][j]!= -3)&&(i<width*2)&&(j<height*2)&&(i>=0)&&(j>=0)&&(a[i][j]!= -1))
			{

				a[i][j] = c;
			}

			else if(a[i][j]== -3)
			break;
			i--;
			j++;

		}
		for(int k=0;k<c;k++)
		{
			if((a[i][j]!= -3)&&(a[i][j]!= -1)&&(i>=0)&&(j>=0)&&(i<width*2)&&(j<height*2))
			{
		
				a[i][j] = c;
			}

			else if(a[i][j]== -3)
			break;

			i--;
			j--;
		}
	
}

cout<<"\n";
cout<<"wavefront grid for lee\n";

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


cout<<"trace back path for route "<<(h1)<<" is as shown\n\n";
temp[sx][sy]= -2;
temp[p][q]=-3;

	for(int j=0;j<height; j++)
	{
		for(int i=0;i<width; i++)
		{
			cout<<temp[i+width][j+height]<<"\t";
			
		}
		cout<<endl;
		
	}
//	cout<<"trace back path is \n";
        Point p1; 	
	for(int j=height;j<height*2; j++)
	{
		for(int i=width;i<width*2; i++)
		{
			if(temp[i][j]!=0)
			{
                                p1.x = j-height;
                                p1.y = i-width;     
                                paths[count1].push_back(p1);
			//	cout<<"("<<j-height<<","<<i-width<<")\t";
			}
			
		}
		
	}

	
        count1++;

}
}

void Utilities::lee_grid::aker_2bit_algo()
{
	cout<<"\n"<<"AKERS 2 BIT's algorithm\n";

//	int sx,sy,tx,ty;
h1=0;
count=conn.size()-1;
count1=0;
while(count>=0)
{
count--;
int a[width*3][height*3];

sx =  conn[h1].source.x + width;
sy =  conn[h1].source.y + height;
tx =  conn[h1].sink.x + width;
ty =  conn[h1].sink.y + height;

h1++;
//	cout<<"entr  width and height of grid\n"<<endl;
	
//	cout<<"entr source coordinates\n"<<endl;

//	cout<<"entr drain coordinates\n"<<endl;



    	for(int j=0;j<height*3;j++)
	{
		for(int i=0;i<width*3;i++)
		{
			a[i][j]=0;

		}

	}

a[sx][sy]=-2;//...............source
a[tx][ty]=-3;//...............sink


//	cout<<"entr number of blokages due to ICs\n";
//	int v;
	v = block.size();
	for(int i=0;i<v;i++)
	{
//	cout<<"entr width and height of blockage\n";
 w =	block[i].width;
 h = block[i].height;
//	cout<<"entr starting coordinates x and y\n";
 l = block[i].location.x + width;
 k = block[i].location.y + height;
	int z=l;
	for(int j=0;j<h;j++)
	{
		int l=z;
		for(int i=0;i<w;i++)
		{
			a[l][k]=-1;
			l++;
		}
		k++;
	}
	
	}


	cout<<"\n"<<"initial grid \n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<a[i+width][j+height]<<"\t";

		}
		cout<<"\n";

	}

int n=tx;
int m=ty;
int x=sx;
int y=sy;

//wavefront logic for 2 bit akers

	int c = 0;
	int e = 4;
	int i=x;
	int j=y;


	while(a[n][m]!=a[i][j])
	{
		if (e==0)
		{
		 e=4;
		}
		c++;
	i=i-1;
		for(int k=0;k<c;k++)
		{
			if((a[i][j]!=-3)&&(i<width*2)&&(j<height*2)&&(i>=0)&&(j>=0)&&(a[i][j]!=-1))
			{
				if((e==3)||(e==4))
				a[i][j] = 1;
				else
				a[i][j]=2;
			}

			else if(a[i][j]==-3)
			break;
				i++;
				j--;

		}
		for(int k=0;k<c;k++)
		{
			if((a[i][j]!=-3)&&(i<width*2)&&(j<height*2)&&(i>=0)&&(j>=0)&&(a[i][j]!=-1))
			{
				if((e==3)||(e==4))
				a[i][j] = 1;
				else
				a[i][j]=2;

				
			}
			else if(a[i][j]==-3)
			break;
				i++;
				j++;

		}
		for(int k=0;k<c;k++)
		{
			if((a[i][j]!=-3)&&(i<width*2)&&(j<height*2)&&(i>=0)&&(j>=0)&&(a[i][j]!=-1))
			{
				if((e==3)||(e==4))
				a[i][j] = 1;
				else
				a[i][j]=2;
			}

			else if(a[i][j]==-3)
			break;
			i--;
			j++;

		}
		for(int k=0;k<c;k++)
		{
			if((a[i][j]!=-3)&&(a[i][j]!=-1)&&(i>=0)&&(j>=0)&&(i<width*2)&&(j<height*2))
			{
				if((e==3)||(e==4))
				a[i][j] = 1;
				else
				a[i][j]=2;
			}

			else if(a[i][j]==-3)
			break;

			i--;
			j--;
		}
e--;
}





cout<<"\n"<<"wavefront for 2 bit akers\n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<a[i+width][j+height]<<"\t";

		}
		cout<<"\n";

	}

//not required in akers...	cout<<c<<"  is the cost to reach drain \t"<<endl;

int p=n;
int q=m;

// Trace back logic for 2 bit aakers

int temp[width][height];

for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			temp[i+width][j+height]=0;

		}

	}

//for(int i=c;i>=1;i--)
temp[x][y]=-2;
temp[p][q]=-3;
int u= width + height;

while(u>0)
{
u--;
switch(e)
{
case 4 : 
  {	if((a[n-1][m]== 2)&&(n!=x))
	{
		temp[n-1][m]=a[n-1][m];
		n--;
	}
	else if((a[n+1][m]== 2)&&(x!=n))
	{
		temp[n+1][m]=a[n+1][m];
		n++;
	}
	else if((a[n][m-1]== 2)&&(m!=y))
	{
		temp [n][m-1]=a[n][m-1];
		m--;
	}
	else if((a[n][m+1]== 2)&&(m!=y))
	{
		temp[n][m+1]=a[n][m+1];
		m++;
	}
  }
break;
case 3 : 
  {	if((a[n-1][m]== 1)&&(n!=x))
	{
		temp[n-1][m]=a[n-1][m];
		n--;
	}
	else if((a[n+1][m]== 1)&&(x!=n))
	{
		temp[n+1][m]=a[n+1][m];
		n++;
	}
	else if((a[n][m-1]== 1)&&(m!=y))
	{
		temp [n][m-1]=a[n][m-1];
		m--;
	}
	else if((a[n][m+1]== 1)&&(m!=y))
	{
		temp[n][m+1]=a[n][m+1];
		m++;
	}
  }
break;
case 2 : 
  {	if((a[n-1][m]== 1)&&(n!=x))
	{
		temp[n-1][m]=a[n-1][m];
		n--;
	}
	else if((a[n+1][m]== 1)&&(x!=n))
	{
		temp[n+1][m]=a[n+1][m];
		n++;
	}
	else if((a[n][m-1]== 1)&&(m!=y))
	{
		temp [n][m-1]=a[n][m-1];
		m--;
	}
	else if((a[n][m+1]== 1)&&(m!=y))
	{
		temp[n][m+1]=a[n][m+1];
		m++;
	}
  }
break;
case 1 : 
  {	if((a[n-1][m]== 2)&&(n!=x))
	{
		temp[n-1][m]=a[n-1][m];
		n--;
	}
	else if((a[n+1][m]== 2)&&(x!=n))
	{
		temp[n+1][m]=a[n+1][m];
		n++;
	}
	else if((a[n][m-1]== 2)&&(m!=y))
	{
		temp [n][m-1]=a[n][m-1];
		m--;
	}
	else if((a[n][m+1]== 2)&&(m!=y))
	{
		temp[n][m+1]=a[n][m+1];
		m++;
	}
   }
break;
}
e--;
if(e==0)
{
e=4;
}


}





cout<<"trace back path for route "<<h1<<" is as shown\n\n";


	for(int j=0;j<height; j++)
	{
		for(int i=0;i<width; i++)
		{
			cout<<temp[i+width][j+height]<<"\t";

		}
		cout<<endl;

	}
//	cout<<"trace back path is \n";
	Point p2;
	for(int j=height;j<height*2; j++)
	{
		for(int i=width;i<width*2; i++)
		{
			if(temp[i][j]!=0)
			{

				p2.x= j-height;
				p2.y= i-width;
				paths1[count1].push_back(p2);
			//	cout<<"("<<j-height<<","<<i-width<<")\t";
			}

		}

	}
	count1++;

	}
}

void Utilities::lee_grid::aker_3bit_algo()
{
	cout<<"\n"<<"AKERS 3 BIT's algorithm\n";

//	int sx,sy,tx,ty;
h1=0;
count= conn.size()-1;
count1=0;
while(count>=0)
{
count--;

int a[width*3][height*3];

sx =  conn[h1].source.x + width;
sy =  conn[h1].source.y + height;
tx =  conn[h1].sink.x + width;
ty =  conn[h1].sink.y + height;

h1++;
//	cout<<"entr  width and height of grid\n"<<endl;
	
//	cout<<"entr source coordinates\n"<<endl;

//	cout<<"entr drain coordinates\n"<<endl;



    	for(int j=0;j<height*3;j++)
	{
		for(int i=0;i<width*3;i++)
		{
			a[i][j]=0;

		}

	}

a[sx][sy]=-2;
a[tx][ty]=-3;


//	cout<<"entr number of blokages due to ICs\n";
//	int v;
	v = block.size();
	for(int i=0;i<v;i++)
	{
//	cout<<"entr width and height of blockage\n";
 w =	block[i].width;
 h = block[i].height;
//	cout<<"entr starting coordinates x and y\n";
 l = block[i].location.x + width;
 k = block[i].location.y + height;
	int z=l;
	for(int j=0;j<h;j++)
	{
		int l=z;
		for(int i=0;i<w;i++)
		{
			a[l][k]=-1;
			l++;
		}
		k++;
	}
	
	}


	cout<<"\n"<<"initial grid\n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<a[i+width][j+height]<<"\t";

		}
		cout<<"\n";

	}

//wavefront logic for 3 bit akers

	int c = 0;
	int e = 0;
	int i=sx;
	int j=sy;
	a[i][j];

	while(a[tx][ty]!=a[i][j])
	{
		e++;
		if (e>3)
		{
		 e=1;
		}
		c++;
	i=i-1;
		for(int k=0;k<c;k++)
		{
			if((a[i][j]!=-3)&&(i<width*2)&&(j<height*2)&&(i>=0)&&(j>=0)&&(a[i][j]!=-1))
			{

				a[i][j] = e;
			}

			else if(a[i][j]==-3)
			break;
				i++;
				j--;

		}
		for(int k=0;k<c;k++)
		{
			if(a[i][j]!=-3&&(i<width*2)&&(j<height*2)&&(i>=0)&&(j>=0)&&(a[i][j]!=-1))
			{

				a[i][j] = e;
			}
			else if(a[i][j]==-3)
			break;
				i++;
				j++;

		}
		for(int k=0;k<c;k++)
		{
			if((a[i][j]!=-3)&&(i<width*2)&&(j<height*2)&&(i>=0)&&(j>=0)&&(a[i][j]!=-1))
			{

				a[i][j] = e;
			}

			else if(a[i][j]==-3)
			break;
			i--;
			j++;

		}
		for(int k=0;k<c;k++)
		{
			if((a[i][j]!=-3)&&(a[i][j]!=-1)&&(i>=0)&&(j>=0)&&(i<width*2)&&(j<height*2))
			{

				a[i][j] = e;
			}

			else if(a[i][j]==-3)
			break;

			i--;
			j--;
		}

}





cout<<"\n"<<"wavefront grid for 3 bit akers\n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<a[i+width][j+height]<<"\t";

		}
		cout<<"\n";

	}

//not required in akers...	cout<<c<<"  is the cost to reach drain \t"<<endl;

int p=tx;
int q=ty;

// Trace back logic for 3 bit akers

int temp[width][height];

for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			temp[i+width][j+height]=0;

		}

	}

//for(int i=c;i>=1;i--)
temp[sx][sy]=-2;
temp[p][q]=-3;
int u= width + height;
//while(temp[n][m]!=70)
//while((x!=n)
//while((x!=n)||(y!=m))
int n=tx;
int m=ty;
int x=sx;
int y=sy;
while(u>0)
{
u--;
	
	--e;
	if(e== 0)
	{
		e=3;
	}

	if((a[n-1][m]== e)&&(n!=x))
	{
		temp[n-1][m]=a[n-1][m];
		n--;
	}
	else if((a[n+1][m]== e)&&(x!=n))
	{
		temp[n+1][m]=a[n+1][m];
		n++;
	}
	else if((a[n][m-1]== e)&&(m!=y))
	{
		temp [n][m-1]=a[n][m-1];
		m--;
	}
	else if((a[n][m+1]== e)&&(m!=y))
	{
		temp[n][m+1]=a[n][m+1];
		m++;
	}


}

cout<<"trace back path for route "<<h1<<" is as shown\n\n";


	for(int j=0;j<height; j++)
	{
		for(int i=0;i<width; i++)
		{
			cout<<temp[i+width][j+height]<<"\t";

		}
		cout<<endl;

	}
//	cout<<"trace back path is \n";
	Point p3;
	for(int j=height;j<height*2; j++)
	{
		for(int i=width;i<width*2; i++)
		{
			if(temp[i][j]!=0)
			{
				p3.x = j-height;
				p3.y = i-width;
				paths2[count1].push_back(p3);
			//	cout<<"("<<j-height<<","<<i-width<<")\t";
			}

		}

	}

	count1++;







}
}




