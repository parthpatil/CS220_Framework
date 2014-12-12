#include "../Headers/grid.h"
#include "../Headers/problem_object.h"
#include "../Headers/hadl_grid.h"
#include "../Headers/edge.h"
#include "../Headers/claim.h"
#include "../Headers/point.h"
#include<iostream.h>
#include<stdlib.h>
#include<vector>
//Takes an x and y coordinate as input and creates a grid of that size filled with default nodes
Utilities::hadl_grid::hadl_grid(ProblemObject *problem_object) {
	width=problem_object-> get_width();
        height=problem_object-> get_height();

//cout<<width<<"\n";
//cout<<height<<"\n";
    conn = problem_object-> get_connections();
    
    block = problem_object-> get_blockers();

cout<<"\n";
}

void Utilities::hadl_grid::hadlock_algo()
{



 cout<<"\n"<<"Hadlock Algorithm\n";
 
 h1=0;
// count = conn.size()-1;
 count1=0;

//while(count>=0)
//{
//count--;


sx =  conn[h1].source.x ;
sy =  conn[h1].source.y ;
tx =  conn[h1].sink.x ;
ty =  conn[h1].sink.y ;


h1++;
		for(int i=0;i<width*height;i++)
		{
			pathx[i]=-10;
			pathy[i]=-10;
		}

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			a[i][j]=-10;
			temp[i][j]=-10;
			trc[i][j]=-10;
	
		}

	}
 x=sx;
 y=sy;
 n=tx;
 m=ty;
a[x][y]=-2;
a[n][m]=-3;
temp[x][y]=-2;
temp[n][m]=-3;
trc[x][y]=-2;
trc[n][m]=-3;


//	cout<<"entr number of blokages due to ICs\n";
//	int v;
	v = block.size();
	for(int i=0;i<v;i++)
	{
//	cout<<"entr width and height of blockage\n";
 w =	block[i].width;
 h = block[i].height;
//	cout<<"entr starting coordinates x and y\n";
 l = block[i].location.x;
 k = block[i].location.y;
	int z=l;
	for(int j=0;j<h;j++)
	{
		int l=z;
		for(int i=0;i<w;i++)
		{
			a[l][k]=-1;
			temp[l][k]=-1;

			l++;
		}
		k++;
	}
	
	}
cout<<"\n"<<"initial grid for headlock algo is \n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<a[i][j]<<"\t";

		}
		cout<<"\n";

	}


//f1
if(sx<n&&sy>m)
{
	if(a[x+1][y]==-10)
	{
	a[x+1][y]=0;
	temp[x+1][y]=0;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=0;
	temp[x][y-1]=0;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=1;
	temp[x-1][y]=1;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=1;
	temp[x][y+1]=1;

	}
}
//f3

if(sx>n&&sy<m)
{
	if(a[x+1][y]==-10)
	{
	a[x+1][y]=1;
	temp[x+1][y]=1;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=1;
	temp[x][y-1]=1;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=0;
	temp[x-1][y]=0;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=0;
	temp[x][y+1]=0;

	}

}
//f2
if(sx<n&&sy<m)
{
	if(a[x+1][y]==-10)
	{
	a[x+1][y]=0;
	temp[x+1][y]=0;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=1;
	temp[x][y-1]=1;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=1;
	temp[x-1][y]=1;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=0;
	temp[x][y+1]=0;

	}

}
//f4
if(sx>n&&sy>m)
{
	if(a[x+1][y]==-10)
	{
	a[x+1][y]=1;
	temp[x+1][y]=1;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=0;
	temp[x][y-1]=0;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=0;
	temp[x-1][y]=0;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=1;
	temp[x][y+1]=1;

	}

}
//s1
if(sx<n&&sy==m)
{
	if(a[x+1][y]==-10)
	{
	a[x+1][y]=0;
	temp[x+1][y]=0;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=1;
	temp[x][y-1]=1;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=1;
	temp[x-1][y]=1;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=1;
	temp[x][y+1]=1;

	}

}
//s3
if(sx>n&&sy==m)
{
	if(a[x+1][y]==-10)
	{
	a[x+1][y]=1;
	temp[x+1][y]=1;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=1;
	temp[x][y-1]=1;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=0;
	temp[x-1][y]=0;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=1;
	temp[x][y+1]=1;

	}

}
//s2
if(sx==n&&sy<m)
{
	if(a[x+1][y]==-10)
	{
	a[x+1][y]=1;
	temp[x+1][y]=1;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=1;
	temp[x][y-1]=1;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=1;
	temp[x-1][y]=1;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=0;
	temp[x][y+1]=0;

	}

}
//s4
if(sx==n&&sy>m)
{
	if(a[x+1][y]==-10)
	{
	a[x+1][y]=1;
	temp[x+1][y]=1;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=0;
	temp[x][y-1]=0;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=1;
	temp[x-1][y]=1;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=1;
	temp[x][y+1]=1;

	}

}

int vt=width;
int d=0;
	while(vt>0)
	{
vt--;

int u =width*height;

	while(u>0)
		{
u--;
		for(int j=height-1;j>=0;j--)
		{
			for(int i=0;i<width;i++)
			{
				if(a[i][j]==d)
				{
					
				a[i][j]=-20;
			//	c= d;
				x=i;
				y=j;
				if((i<n)&&(j>m))
				wave1(x,y,d);
			//	if((i<n)&&(j<=m))
				else if((i<n)&&(j<m))

				wave2(x,y,d);
			//	if((i>=n)&&(j<=m))
				else if((i>n)&&(j<m))

				wave3(x,y,d);
			//	if((i>=n)&&(j>m))
				else if((i>n)&&(j>m))

				wave4(x,y,d);
				else if(i<n&&j==m)

				wavelf(x,y,d);
				else if(i>n&&j==m)
				wavert(x,y,d);
				else if(i==n&&j<m)
				waveup(x,y,d);
				else if(i==n&&j>m)
				wavedn(x,y,d);

				if((a[x+1][y]==-3)||(a[x-1][y]==-3)||(a[x][y+1]==-3)||(a[x][y-1]==-3))
				break;

				}
			if((a[x+1][y]==-3)||(a[x-1][y]==-3)||(a[x][y+1]==-3)||(a[x][y-1]==-3))
				break;
			}
			if((a[x+1][y]==-3)||(a[x-1][y]==-3)||(a[x][y+1]==-3)||(a[x][y-1]==-3))
				break;
	
		}
			if((a[x+1][y]==-3)||(a[x-1][y]==-3)||(a[x][y+1]==-3)||(a[x][y-1]==-3))
				break;

	
				
		}
			if((a[x+1][y]==-3)||(a[x-1][y]==-3)||(a[x][y+1]==-3)||(a[x][y-1]==-3))
				break;
d++;

		}

cout<<"\t"<<d<<"\n";

if((sx<tx)&&(sy>ty))
{
trace1(tx,ty,d);
}

if(sx<tx&&sy<ty)
{trace2(tx,ty,d);
}
if(sx>tx&&sy<ty)
{trace3(tx,ty,d);
}
if(sx>tx&&sy>ty)
{trace4(tx,ty,d);
}

/*		cout<<"logic test grid\n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<a[i][j]<<"\t";

		}
		cout<<"\n";

	}

*/
		cout<<"traceback grid\n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<temp[i][j]<<"\t";

		}
		cout<<"\n";

	}
		cout<<"traceback route is\n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<trc[i][j]<<"\t";

		}
		cout<<"\n";

	}

	cout<<"("<<tx<<","<<ty<<")"<<"\t";
 Point p1; 
	
			for(int i=0;i<width*height;i++)
		{
			if((pathx[i]!=-10)&&(pathy[i]!=-10))
		{	
			cout<<"("<<pathx[i]<<","<<pathy[i]<<")"<<"\t";
		/*		p1.x = pathx[i];

			         p1.y = pathy[i];     
                                paths[count1].push_back(p1);
*/
		}
		}		
		cout<<"("<<sx<<","<<sy<<")"<<"\t";

	 	
	
       count1++;

//}
}

void Utilities::hadl_grid::trace1(int x, int y,int c)
{
//hadlock hl;
//arr st;
int tr=100;
int i =0;
while(tr>0)
{
tr--;
//	c--;..
	if(temp[x-1][y]==c-1)
	{
		trc[x-1][y]=temp[x-1][y];
		temp[x-1][y]=-20;
		pathx[i]=x-1;
		pathy[i]=y;
		i++;

		x--;
		c--;
	}
	else if(temp[x][y+1]==c-1)
	{
		trc[x][y+1]=temp[x][y+1];
		temp[x][y+1]=-20;
		pathx[i]=x;
		pathy[i]=y+1;
		i++;

		y++;
		c--;
	}

	else if(temp[x][y-1]== c-1)
	{
		trc[x][y-1]=temp[x][y-1];
		temp[x][y-1]=-20;
		pathx[i]=x;
		pathy[i]=y-1;
		i++;

		y--;
		c--;
	}
	else if(temp[x+1][y]== c-1)
	{
		trc[x+1][y]=temp[x+1][y];
		temp[x+1][y]=-20;
		pathx[i]=x+1;
		pathy[i]=y;
		i++;

		x++;
		c--;
	}


	if(temp[x-1][y]==c)
	{
		trc[x-1][y]=temp[x-1][y];
		temp[x-1][y]=-20;
		pathx[i]=x-1;
		pathy[i]=y;
		i++;

		x--;
	}
	else if(temp[x][y+1]==c)
	{
		trc[x][y+1]=temp[x][y+1];
		temp[x][y+1]=-20;
		pathx[i]=x;
		pathy[i]=y+1;
		i++;

		y++;
	}

	else if(temp[x][y-1]== c)
	{
		trc[x][y-1]=temp[x][y-1];
		temp[x][y-1]=-20;
		pathx[i]=x;
		pathy[i]=y-1;
		i++;

		y--;
	}
	else if(temp[x+1][y]== c)
	{
		trc[x+1][y]=temp[x+1][y];
		temp[x+1][y]=-20;
		pathx[i]=x+1;
		pathy[i]=y;
		i++;

		x++;
	}
	if((temp[x+1][y]==-2)||(temp[x-1][y]==-2)||(temp[x][y+1]==-2)||(temp[x][y-1]==-2))
	break;

}

}

void Utilities::hadl_grid::trace4(int x, int y,int c)
{
//arr st;

int tr=100;
int i=0;
while(tr>0)
{
tr--;
	if(temp[x+1][y]==-2||temp[x-1][y]==-2||temp[x][y+1]==-2||temp[x][y-1]==-2)
	break;
	 if(temp[x+1][y]== c-1)
	{
		trc[x+1][y]=temp[x+1][y];
		temp[x+1][y]=-20;
		pathx[i]=x+1;
		pathy[i]=y;
		i++;

		x++;
		c--;
	}

	else if(temp[x][y+1]==c-1)
	{
		trc[x][y+1]=temp[x][y+1];
		temp[x][y+1]=-20;
		pathx[i]=x;
		pathy[i]=y+1;
		i++;

		y++;
		c--;
	}

	else if(temp[x][y-1]== c-1)
	{
		trc[x][y-1]=temp[x][y-1];
		temp[x][y-1]=-20;
		pathx[i]=x;
		pathy[i]=y-1;
		i++;

		y--;
		c--;
	}
	else if(temp[x-1][y]==c-1)
	{
		trc[x-1][y]=temp[x-1][y];
		temp[x-1][y]=-20;
		pathx[i]=x-1;
		pathy[i]=y;
		i++;

		x--;
		c--;
	}

	if(temp[x+1][y]== c)
	{
		trc[x+1][y]=temp[x+1][y];
		temp[x+1][y]=-20;
		pathx[i]=x+1;
		pathy[i]=y;
		i++;

		x++;
	}

	else if(temp[x][y+1]==c)
	{
		trc[x][y+1]=temp[x][y+1];
		temp[x][y+1]=-20;
		pathx[i]=x;
		pathy[i]=y+1;
		i++;

		y++;
	}

	else if(temp[x][y-1]== c)
	{
		trc[x][y-1]=temp[x][y-1];
		temp[x][y-1]=-20;
		pathx[i]=x;
		pathy[i]=y-1;
		i++;

		y--;
	}
	else if(temp[x-1][y]==c)
	{
		trc[x-1][y]=temp[x-1][y];
		temp[x-1][y]=-20;
		pathx[i]=x-1;
		pathy[i]=y;
		i++;

		x--;
	}


}

}

void Utilities::hadl_grid::trace3(int x, int y,int c)
{
//arr st;

int i=0;
int tr=100;
while(tr>0)
{
tr--;
	 if(temp[x+1][y]== c-1)
	{
		trc[x+1][y]=temp[x+1][y];
		temp[x+1][y]=-20;
		pathx[i]=x+1;
		pathy[i]=y;
		i++;
		x++;
		c--;
	}	
	else if(temp[x][y-1]== c-1)
	{
		trc[x][y-1]=temp[x][y-1];
		temp[x][y-1]=-20;
		pathx[i]=x;
		pathy[i]=y-1;
		i++;
		y--;
		c--;
	}

	else if(temp[x][y+1]==c-1)
	{
		trc[x][y+1]=temp[x][y+1];
		temp[x][y+1]=-20;
		pathx[i]=x;
		pathy[i]=y+1;
		i++;

		y++;
		c--;
	}


	else if(temp[x-1][y]==c-1)
	{
		trc[x-1][y]=temp[x-1][y];
		temp[x-1][y]=-20;
		pathx[i]=x-1;
		pathy[i]=y;
		i++;

		x--;
		c--;
	}



	if(temp[x+1][y]== c)
	{
		trc[x+1][y]=temp[x+1][y];
		temp[x+1][y]=-20;
		pathx[i]=x+1;
		pathy[i]=y;
		i++;

		x++;
	}

	else if(temp[x][y-1]== c)
	{
		trc[x][y-1]=temp[x][y-1];
		temp[x][y-1]=-20;
		pathx[i]=x;
		pathy[i]=y-1;
		i++;

		y--;
	}
	else if(temp[x][y+1]==c)
	{
		trc[x][y+1]=temp[x][y+1];
		temp[x][y+1]=-20;
		pathx[i]=x;
		pathy[i]=y+1;
		i++;

		y++;
	}

	else if(temp[x-1][y]==c)
	{
		trc[x-1][y]=temp[x-1][y];
		temp[x-1][y]=-20;
		pathx[i]=x-1;
		pathy[i]=y;
		i++;

		x--;
	}

	if(temp[x+1][y]==-2||temp[x-1][y]==-2||temp[x][y+1]==-2||temp[x][y-1]==-2)
	break;

}

}
void Utilities::hadl_grid::trace2(int x, int y,int c)
{
//Utilities::stay st;

int tr=100;
int i=0;
while(tr>0)
{
tr--;
	if(temp[x+1][y]==-2||temp[x-1][y]==-2||temp[x][y+1]==-2||temp[x][y-1]==-2)
	break;
	if(temp[x-1][y]==c-1)
	{
		trc[x-1][y]=temp[x-1][y];
		temp[x-1][y]=-20;
		pathx[i]=x-1;
		pathy[i]=y;
		i++;

		x--;
		c--;
	}

	else if(temp[x][y-1]== c-1)
	{
		trc[x][y-1]=temp[x][y-1];
		temp[x][y-1]=-20;
		pathx[i]=x;
		pathy[i]=y-1;
		i++;

		y--;
		c--;
	}

	else if(temp[x][y+1]==c-1)
	{
		trc[x][y+1]=temp[x][y+1];
		temp[x][y+1]=-20;
		pathx[i]=x;
		pathy[i]=y+1;
		i++;

		y++;
		c--;
	}
	else if(temp[x+1][y]== c-1)
	{
		trc[x+1][y]=temp[x+1][y];
		temp[x+1][y]=-20;
		pathx[i]=x+1;
		pathy[i]=y;
		i++;

		x++;
		c--;
	}


	if(temp[x-1][y]==c)
	{
		trc[x-1][y]=temp[x-1][y];
		temp[x-1][y]=-20;
		pathx[i]=x-1;
		pathy[i]=y;
		i++;

		x--;
	}


	else if(temp[x][y-1]== c)
	{
		trc[x][y-1]=temp[x][y-1];
		temp[x][y-1]=-20;
		pathx[i]=x;
		pathy[i]=y-1;
		i++;

		y--;
	}
	else if(temp[x][y+1]==c)
	{
		trc[x][y+1]=temp[x][y+1];
		temp[x][y+1]=-20;
		pathx[i]=x;
		pathy[i]=y+1;
		i++;

		y++;
	}

	else if(temp[x+1][y]== c)
	{
		trc[x+1][y]=temp[x+1][y];
		temp[x+1][y]=-20;
		pathx[i]=x+1;
		pathy[i]=y;
		i++;

		x++;
	}



}

}

void Utilities::hadl_grid::wave1(int x,int y,int d)
{
//hadlock hl;

	if(a[x+1][y]==-10)
	{
	a[x+1][y]=d;
	temp[x+1][y]=d;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=d;
	temp[x][y-1]=d;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=d+1;
	temp[x-1][y]=d+1;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=d+1;
	temp[x][y+1]=d+1;

	}


}

void Utilities::hadl_grid::wave2(int x,int y,int d)
{
	
//hadlock hl;
	if(a[x+1][y]==-10)
	{
	a[x+1][y]=d;
	temp[x+1][y]=d;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=d+1;
	temp[x][y-1]=d+1;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=d+1;
	temp[x-1][y]=d+1;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=d;
	temp[x][y+1]=d;

	}


}

void Utilities::hadl_grid::wave4(int x,int y,int d)
{
//	hadlock 

	if(a[x+1][y]==-10)
	{
	a[x+1][y]=d+1;
	temp[x+1][y]=d+1;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=d;
	temp[x][y-1]=d;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=d;
	temp[x-1][y]=d;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=d+1;
	temp[x][y+1]=d+1;

	}


}

void Utilities::hadl_grid::wave3(int x,int y,int d)
{
//	hadlock hl;

	if(a[x+1][y]==-10)
	{
	a[x+1][y]=d+1;
	temp[x+1][y]=d+1;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=d+1;
	temp[x][y-1]=d+1;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=d;
	temp[x-1][y]=d;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=d;
	temp[x][y+1]=d;

	}


}

void Utilities::hadl_grid::wavelf(int x,int y,int d)
{
	
//hadlock hl;
	if(a[x+1][y]==-10)
	{
	a[x+1][y]=d;
	temp[x+1][y]=d;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=d+1;
	temp[x][y-1]=d+1;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=d+1;
	temp[x-1][y]=d+1;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=d+1;
	temp[x][y+1]=d+1;

	}


}
void Utilities::hadl_grid::wavert(int x,int y,int d)
{
//hadlock hl;

	if(a[x+1][y]==-10)
	{
	a[x+1][y]=d+1;
	temp[x+1][y]=d+1;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=d+1;
	temp[x][y-1]=d+1;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=d;
	temp[x-1][y]=d;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=d+1;
	temp[x][y+1]=d+1;

	}


}
void Utilities::hadl_grid::waveup(int x,int y,int d)
{
//hadlock hl;

	if(a[x+1][y]==-10)
	{
	a[x+1][y]=d+1;
	temp[x+1][y]=d+1;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=d+1;
	temp[x][y-1]=d+1;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=d+1;
	temp[x-1][y]=d+1;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=d;
	temp[x][y+1]=d;

	}


}
void Utilities::hadl_grid::wavedn(int x,int y,int d)
{
	
//hadlock hl;
	if(a[x+1][y]==-10)
	{
	a[x+1][y]=d+1;
	temp[x+1][y]=d+1;

	}

	if(a[x][y-1]==-10)
	{
	a[x][y-1]=d;
	temp[x][y-1]=d;

	}
	if(a[x-1][y]==-10)
	{
	a[x-1][y]=d+1;
	temp[x-1][y]=d+1;

	}
	if(a[x][y+1]==-10)
	{
	a[x][y+1]=d+1;
	temp[x][y+1]=d+1;

	}


}


