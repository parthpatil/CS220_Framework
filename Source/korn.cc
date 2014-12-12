#include "../Headers/grid.h"
#include "../Headers/problem_object.h"
#include "../Headers/korn.h"
#include "../Headers/edge.h"
#include "../Headers/claim.h"
#include "../Headers/point.h"
#include "iostream"
#include<stdlib.h>
#include<vector>
using std::cin;
using std::cout;
//Takes an x and y coordinate as input and creates a grid of that size filled with default nodes
Utilities::korn::korn(ProblemObject *problem_object) {
	width=problem_object-> get_width();
        height=problem_object-> get_height();

//cout<<width<<"\n";
//cout<<height<<"\n";
    conn = problem_object-> get_connections();
    
    block = problem_object-> get_blockers();

cout<<"\n";
}

void Utilities::Queue::display(){
    if(!this->isEmpty()){
        for(int i=front; i<=rear; i++)
            cout<<item_2[i]<<endl;
    }else{
        cout<<"Queue Underflow"<<endl;
    }
}

void Utilities::Queue::enqueue(int data_1, int data_2)
{
        item_1[++rear] = data_1;
        item_2[rear] = data_2;
}
int Utilities:: Queue::dequeue()
{
		x=item_1[rear_new];
		y=item_2[rear_new];
		return x ,y;
}
int Utilities:: Queue::size(){
    return (rear + 1);
}
bool Utilities:: Queue::isEmpty(){
    if(rear==-1){
        return true;
    }else{
        return false;
    }
}




float cost_korn(int ix,int iy, float c_1,int txx, int tyy)
{
	//Utilities::korn sourdes;
	//int txx=7;//=sourdes.tx;
	//int tyy=5;//sourdes.ty;
	float dis,manhattan_dis,cost;
	dis=c_1;
	manhattan_dis=abs(ix-txx) + abs(iy-tyy);
	cost=dis + 1.5*manhattan_dis;
	return cost;
}




void Utilities::korn::korn_algo()
{

Utilities::Queue queue;
 cout<<"\n"<<"KORN Algorithm\n\n";
 
 h1=0;
 multi_path = conn.size()-1;
 count1=0;

while(multi_path>=0)
{
multi_path--;

sx =  conn[h1].source.x;
sy =  conn[h1].source.y;
tx =  conn[h1].sink.x;
ty =  conn[h1].sink.y;
 h1++;
int x=sx;
int y=sy;
int n=tx;
int m=ty;

	float a[width][height], b[width][height];
	float temp[width][height];

//Grid Initialization with 0.

   	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			a[i][j]=0;
			b[i][j]=0;
			temp[i][j]=0;

		}

	}

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
			//temp[l][k]=-1;
			l++;
		}
		k++;
	}

	}
	a[n][m]=-3;
	b[n][m]=-3;
	a[x][y]=-2;
	b[x][y]=-2;

	cout<<"Initial grid\n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<a[i][j]<<"\t";

		}
		cout<<"\n";

	}

//Define the spreading of the wavefront.


	int i=x, j=y,block=0;
	int r,first_time, y_prio=0,chk_pt=0;
	float cost;
	int ek=1;
	queue.rear=-1; //learning
	queue.front=0;
	//sd.repeat=0;
	float cmincmax=0;

int sink_found=0,c=0;//count=0;
//int dummy;
queue.rear=-1;
queue.rear_new=1;
 cmincmax=cost_korn(x,y,c,n,m);

 //cout<<cmincmax;
//cout<<queue.rear;

//int block=0;
//cout<<"lele";

while(queue.rear_new!=-1 && sink_found==0)
{
		block=0;
		chk_pt++;
		if(first_time==0)
		{
		queue.rear=-1;
	//	queue1.rear1=-1;
		first_time=1;
		}
		//cout<<"nn"<<queue.rear<<"\n";
		//cout<<y_prio;
		//cout<<"\n b:"<<b[i+1][j];
		//cout<<"\n a:"<<a[i][j];
		//cout<<"\n c:"<<c<<"\n";
		//cin>>dummy;


	while(a[i][j] !=-1 && sink_found==0 && block==0)
	{

		c++;
		if(i<=n && j<=m)
		{
			r=1;
			//cout<<r<<"\n";
		}
		else if(i<=n && j>=m)
		{
			r=2;
			//cout<<r<<"\n";
		}
		else if(i>=n && j>=m)
		{
			r=3;
			//cout<<r<<"\n";
		}
		else if	(i>=n && j<=m)
		{
			r=4;
			//cout<<r<<"\n";
		}
		if(j==m)
			y_prio=0;
	
	switch(r)
	{
		case 1:
		  if((cost_korn(i+1,j,c,n,m)<cmincmax)&& (b[i+1][j]>cmincmax || b[i+1][j]==0) && y_prio==0 && (i!=n))
				{


					if((a[i][j-1]!=-3)&&((i<width)&&((j-1)<height))&&(i>=0)&&((j-1)>=0)&&(a[i][j-1]!=-1)&&(a[i][j-1]==0))
					{

					  cost=cost_korn(i,j-1,c,n,m);
						b[i][j-1]=cost;
						if(a[i][j-1]==0)
						a[i][j-1]=c;
						queue.enqueue(i,j-1);
					}
					else if(a[i][j-1]==-3)
					{
						sink_found=1;
						break;
					}



					if((a[i+1][j]!=-3)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=-1)&&(a[i+1][j]==0))
					{
						if(a[i+1][j]==0)
						a[i+1][j]=c;
						cost=cost_korn(i+1,j,c,n,m);
						b[i+1][j]=cost;
					}
					else if(a[i+1][j]==-3)
					{
						sink_found=1;
						break;
					}

					if((a[i][j+1]!=-3)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=-1)&&(a[i][j+1]==0))
					{
					  cost=cost_korn(i,j+1,c,n,m);
								b[i][j+1]=cost;
								if(a[i][j+1]==0)
								a[i][j+1]=c;
								queue.enqueue(i,j+1);
					}
					else if(a[i][j+1]==-3)
					{
						sink_found=1;
						break;
					}

					if((a[i-1][j]!=-3)&&((i-1<width)&&((j)<height))&&(i-1>=0)&&((j)>=0)&&(a[i-1][j]!=-1)&&(a[i-1][j]==0))
										{

										  cost=cost_korn(i-1,j,c,n,m);
											b[i-1][j]=cost;
											if(a[i-1][j]==0)
											a[i-1][j]=c;
											queue.enqueue(i,j-1);
										}
										else if(a[i-1][j]==-3)
										{
											sink_found=1;
											break;
										}


					i=i+1;
				}
		  else if((cost_korn(i,j+1,c,n,m)<cmincmax) && (j!=m))// && (j<=height+1)) //&& a[i][j+1]==0)
				{
					y_prio=1;
					if((a[i-1][j]!=-3)&&(((i-1)<width)&&(j<height))&&(((i-1)>=0)&&(j>=0))&&(a[i-1][j]!=-1))//&&(a[i-1][j]==0))
					{
						if(a[i-1][j]==0)
						a[i-1][j]=c;
						cost=cost_korn(i-1,j,c,n,m);
						b[i-1][j]=cost;
						queue.enqueue(i-1,j);
					}
					else if(a[i-1][j]==-3)
					{
						sink_found=1;
						break;
					}
					
					if((a[i+1][j]!=-3)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=-1)&&(a[i+1][j]==0))
					{
						if(a[i+1][j]==0)
						a[i+1][j]=c;
						cost=cost_korn(i+1,j,c,n,m);
						b[i+1][j]=cost;
						queue.enqueue(i+1,j);
					}
					else if(a[i+1][j]==-3)
					{
						sink_found=1;
						break;
					}

					if((a[i][j+1]!=-3)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=-1)&&(a[i][j+1]==0))
					{
						if(a[i][j+1]==0)
						a[i][j+1]=c;
						cost=cost_korn(i,j+1,c,n,m);
						b[i][j+1]=cost;
					}
					else if(a[i][j+1]==-3)
					{
						sink_found=1;
						break;
					}

					if((a[i][j-1]!=-3)&&((i<width)&&((j-1)<height))&&((i>=0)&&((j-1)>=0))&&(a[i][j-1]!=-1)&&(a[i][j-1]==0))
										{
											if(a[i][j-1]==0)
											a[i][j-1]=c;
											cost=cost_korn(i,j-1,c,n,m);
											b[i][j-1]=cost;
											queue.enqueue(i+1,j);
										}
										else if(a[i][j-1]==-3)
										{
											sink_found=1;
											break;
										}

					j=j+1;
				}
				else
					block=1;

				if(j==m && (a[i+1][j]==0 || a[i+1][j]==-3))
				{
					y_prio=0;
				}
				
		break;

		case 2:
		  if(cost_korn(i+1,j,c,n,m)<cmincmax && (b[i+1][j]>cmincmax || b[i+1][j]==0) && y_prio==0 && i!=n)
				{

					if((a[i][j-1]!=-3)&&((i<width)&&((j-1)<height))&&(i>=0)&&((j-1)>=0)&&(a[i][j-1]!=-1)&&(a[i][j-1]==0))
					{
						if(a[i][j-1]==0)
						a[i][j-1]=c;
						cost=cost_korn(i,j-1,c,n,m);
						b[i][j-1]=cost;
						queue.enqueue(i,j-1);
					}
					else if(a[i][j-1]==-3)
					{
						sink_found=1;
						break;
					}

					if((a[i+1][j]!=-3)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=-1)&&(a[i+1][j]==0))
					{
						if(a[i+1][j]==0)
						a[i+1][j]=c;
						cost=cost_korn(i+1,j,c,n,m);
						b[i+1][j]=cost;
					}
					else if(a[i+1][j]==-3)
					{
						sink_found=1;
						break;
					}

					if((a[i][j+1]!=-3)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=-1)&&(a[i][j+1]==0))
					{
						if(a[i][j+1]==0)
						a[i][j+1]=c;
						cost=cost_korn(i,j+1,c,n,m);
						b[i][j+1]=cost;
						queue.enqueue(i,j+1);
					}
					else if(a[i][j+1]==-3)
					{
						sink_found=1;
						break;
					}

					if((a[i-1][j]!=-3)&&(((i-1)<width)&&(j<height))&&(((i-1)>=0)&&(j>=0))&&(a[i-1][j]!=-1)&&(a[i-1][j]==0))
										{

											if(a[i-1][j]==0)
											a[i-1][j]=c;
											cost=cost_korn(i-1,j,c,n,m);
											b[i-1][j]=cost;
											queue.enqueue(i+1,j);
										}
										else if(a[i-1][j]==-3)
										{
											sink_found=1;
											break;
										}

					i=i+1;

				}
		  else if(cost_korn(i,j-1,c,n,m)<cmincmax && j!=m)
				{
					y_prio=1;
					if((a[i-1][j]!=-3)&&(((i-1)<width)&&(j<height))&&(((i-1)>=0)&&(j>=0))&&(a[i-1][j]!=-1)&&(a[i-1][j]==0))
					{
						if(a[i-1][j]==0)
						a[i-1][j]=c;
						cost=cost_korn(i-1,j,c,n,m);
						b[i-1][j]=cost;
						queue.enqueue(i-1,j);
					}
					else if(a[i-1][j]==-3)
					{
						sink_found=1;
						break;
					}

					if((a[i+1][j]!=-3)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=-1)&&(a[i+1][j]==0))
					{
						if(a[i+1][j]==0)
						a[i+1][j]=c;
						cost=cost_korn(i+1,j,c,n,m);
						b[i+1][j]=cost;
						queue.enqueue(i+1,j);
					}
					else if(a[i+1][j]==-3)
					{
						sink_found=1;
						break;
					}

					if((a[i][j-1]!=-3)&&((i<width)&&((j-1)<height))&&(i>=0)&&((j-1)>=0)&&(a[i][j-1]!=-1)&&(a[i][j-1]==0))
					{
						if(a[i][j-1]==0)
						a[i][j-1]=c;
						cost=cost_korn(i,j-1,c,n,m);
						b[i][j-1]=cost;
					}
					else if(a[i][j-1]==-3)
					{
						sink_found=1;
						break;
					}

					if((a[i][j+1]!=-3)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=-1)&&(a[i][j+1]==0))
										{
											if(a[i][j+1]==0)
											a[i][j+1]=c;
											cost=cost_korn(i,j+1,c,n,m);
											b[i][j+1]=cost;
											queue.enqueue(i,j+1);
										}
										else if(a[i][j+1]==-3)
										{
											sink_found=1;
											break;
										}
					j=j-1;

				}
				else
					block=1;

				if(j==m && (a[i+1][j]==0 || a[i+1][j]==-3))
				{
					y_prio=0;
				}
		break;


		case 3:
		  if(cost_korn(i-1,j,c,n,m)<cmincmax && (b[i-1][j]>cmincmax || b[i-1][j]==0) && y_prio==0 && i!=n)
				{
				
				if((a[i-1][j]!=-3)&&(((i-1)<width)&&(j<height))&&(((i-1)>=0)&&(j>=0))&&(a[i-1][j]!=-1)&&(a[i-1][j]==0))
					{
						if(a[i-1][j]==0)
						a[i-1][j]=c;
						cost=cost_korn(i-1,j,c,n,m);
						b[i-1][j]=cost;
					}
				else if(a[i-1][j]==-3)
					{
						sink_found=1;
						break;
					}
				if((a[i][j-1]!=-3)&&((i<width)&&((j-1)<height))&&(i>=0)&&((j-1)>=0)&&(a[i][j-1]!=-1)&&(a[i][j-1]==0))
					{
						if(a[i][j-1]==0)
						a[i][j-1]=c;
						cost=cost_korn(i,j-1,c,n,m);
						b[i][j-1]=cost;
						queue.enqueue(i,j-1);
					}
				else if(a[i][j-1]==-3)
					{
						sink_found=1;
						break;
					}

				if((a[i][j+1]!=-3)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=-1)&&(a[i][j+1]==0))
					{
						if(a[i][j+1]==0)
						a[i][j+1]=c;
						cost=cost_korn(i,j+1,c,n,m);
						b[i][j+1]=cost;
						queue.enqueue(i,j+1);
					}
				else if(a[i][j+1]==-3)
					{
						sink_found=1;
						break;
					}

				if((a[i+1][j]!=-3)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=-1)&&(a[i+1][j]==0))
									{
										if(a[i+1][j]==0)
										a[i+1][j]=c;
										cost=cost_korn(i+1,j,c,n,m);
										b[i+1][j]=cost;
										queue.enqueue(i+1,j);
									}
									else if(a[i+1][j]==-3)
									{
										sink_found=1;
										break;
									}

					i=i-1;
				}
		  else if(cost_korn(i,j-1,c,n,m)<cmincmax && j!=m)
				{
					y_prio=1;

					if((a[i-1][j]!=-3)&&(((i-1)<width)&&(j<height))&&(((i-1)>=0)&&(j>=0))&&(a[i-1][j]!=-1)&&(a[i-1][j]==0))
					{
						if(a[i-1][j]==0)
						a[i-1][j]=c;
						cost=cost_korn(i-1,j,c,n,m);
						b[i-1][j]=cost;
						queue.enqueue(i-1,j);
					}
					else if(a[i-1][j]==-3)
					{
						sink_found=1;
						break;
					}

					if((a[i+1][j]!=-3)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=-1)&&(a[i+1][j]==0))
					{
						if(a[i+1][j]==0)
						a[i+1][j]=c;
						cost=cost_korn(i+1,j,c,n,m);
						b[i+1][j]=cost;
						queue.enqueue(i+1,j);
					}
					else if(a[i+1][j]==-3)
					{
						sink_found=1;
						break;
					}

					if((a[i][j-1]!=-3)&&((i<width)&&((j-1)<height))&&(i>=0)&&((j-1)>=0)&&(a[i][j-1]!=-1)&&(a[i][j-1]==0))
					{
						if(a[i][j-1]==0)
						a[i][j-1]=c;
						cost=cost_korn(i,j-1,c,n,m);
						b[i][j-1]=cost;
					}
					else if(a[i][j-1]==-3)
					{
						sink_found=1;
						break;
					}

					if((a[i][j+1]!=-3)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=-1)&&(a[i][j+1]==0))
						{
							if(a[i][j+1]==0)
							a[i][j+1]=c;
							cost=cost_korn(i,j+1,c,n,m);
							b[i][j+1]=cost;
							queue.enqueue(i,j+1);
						}
					else if(a[i][j+1]==-3)
						{
							sink_found=1;
							break;
						}


					j=j-1;

				}
				else
					block=1;

				if(j==m && (a[i-1][j]==0 || a[i-1][j]==-3))
				{
					y_prio=0;
				}
		break;

		case 4:

		  if(cost_korn(i-1,j,c,n,m)<cmincmax && (b[i-1][j]>cmincmax || b[i-1][j]==0) && y_prio==0 && i!=n)
				{


					if((a[i-1][j]!=-3)&&(((i-1)<width)&&(j<height))&&(((i-1)>=0)&&(j>=0))&&(a[i-1][j]!=-1))//&&(a[i-1][j]==0))
							{
								if(a[i-1][j]==0)
								a[i-1][j]=c;
								cost=cost_korn(i-1,j,c,n,m);
								b[i-1][j]=cost;
							}
					else if(a[i-1][j]==-3)
							{
								sink_found=1;
								break;
							}
					if((a[i][j-1]!=-3)&&((i<width)&&((j-1)<height))&&(i>=0)&&((j-1)>=0)&&(a[i][j-1]!=-1)&&(a[i][j-1]==0))
							{
								if(a[i][j-1]==0)
								a[i][j-1]=c;
								cost=cost_korn(i,j-1,c,n,m);
								b[i][j-1]=cost;
								queue.enqueue(i,j-1);
							}
					else if(a[i][j-1]==-3)
							{
								sink_found=1;
								break;
							}

					if((a[i][j+1]!=-3)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=-1)&&(a[i][j+1]==0))
							{
								if(a[i][j+1]==0)
								a[i][j+1]=c;
								cost=cost_korn(i,j+1,c,n,m);
								b[i][j+1]=cost;
								queue.enqueue(i,j+1);
							}
					else if(a[i][j+1]==-3)
							{
								sink_found=1;
								break;
							}

					if((a[i+1][j]!=-3)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=-1)&&(a[i+1][j]==0))
					{
						if(a[i+1][j]==0)
						a[i+1][j]=c;
						cost=cost_korn(i+1,j,c,n,m);
						b[i+1][j]=cost;
						queue.enqueue(i+1,j);
					}
					else if(a[i+1][j]==-3)
					{
						sink_found=1;
						break;
					}
					i=i-1;
				}
		  else if(cost_korn(i,j+1,c,n,m)<=cmincmax && j!=m)
				{
					y_prio=1;
					if((a[i-1][j]!=-3)&&(((i-1)<width)&&(j<height))&&(((i-1)>=0)&&(j>=0))&&(a[i-1][j]!=-1)&&(a[i-1][j]==0))
							{
								if(a[i-1][j]==0)
								a[i-1][j]=c;
								cost=cost_korn(i-1,j,c,n,m);
								b[i-1][j]=cost;
		//						if(sd.repeat==0)
								queue.enqueue(i-1,j);
							}
					else if(a[i-1][j]==-3)
							{
								sink_found=1;
								break;
							}

					if((a[i+1][j]!=-3)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=-1))//&&(a[i+1][j]==0))
							{
								if(a[i+1][j]==0)
								a[i+1][j]=c;
								cost=cost_korn(i+1,j,c,n,m);
								b[i+1][j]=cost;
								queue.enqueue(i+1,j);
							}
					else if(a[i+1][j]==-3)
							{
								sink_found=1;
								break;
							}

					if((a[i][j+1]!=-3)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=-1)&&(a[i][j+1]==0))
							{
								if(a[i][j+1]==0)
								a[i][j+1]=c;
								cost=cost_korn(i,j+1,c,n,m);
								b[i][j+1]=cost;
							}
					else if(a[i][j+1]==-3)
							{
								sink_found=1;
								break;
							}

					if((a[i][j-1]!=-3)&&((i<width)&&((j-1)<height))&&(i>=0)&&((j-1)>=0)&&(a[i][j-1]!=-1)&&(a[i][j-1]==0))
												{
													if(a[i][j-1]==0)
													a[i][j-1]=c;
													cost=cost_korn(i,j-1,c,n,m);
													b[i][j-1]=cost;
													queue.enqueue(i,j-1);
												}
										else if(a[i][j-1]==-3)
												{
													sink_found=1;
													break;
												}

					j=j+1;
					}
				else
					block=1;

				if(j==m && (a[i-1][j]==0 || a[i-1][j]==-3))
				{
					y_prio=0;
				}

				break;
		default:
			cout<<"No path to sink \n";
			sink_found=1;
			block=1;
			break;

	}

}

	if(sink_found==0)
	{
		y_prio=0;
		while(ek==1)
				{
				queue.rear_new=queue.rear-1;
				ek=ek-1;
				}

						queue.dequeue();
							i=queue.x;
							j=queue.y;
							queue.rear_new++;
							c=a[i][j]; // Assigning float data to integer variable will not affect operation because c values are integers  only in array a. 


//				cout<<"queue="<<i<<j;
//				cout<<"\n q1:"<<queue.rear;
//				cout<<"\n q2:"<<queue1.rear1;

							cmincmax=cost_korn(i,j,c,n,m);
		if((i!=x && j!=y)||(i==x && j!=y)||(i!=x && j==y))
		{
			a[i][j]=c;
			b[i][j]=cmincmax;
		}


	}

}


cout<<"\n";


cout<<"a array\n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<a[i][j]<<"\t";

		}
		cout<<"\n";

	}

cout<<"\n";

cout<<"b array\n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<b[i][j]<<"\t";

		}
		cout<<"\n";

	}



	int n1=n;
		int m1=m;

	for(i=c;i>=1;i--)
	{
		c--;

		if(a[n1][m1-1]==c)
		{
			temp[n1][m1-1]=a[n1][m1-1];
			m1--;
		}
		else if(a[n1][m1+1]==c)
		{
			temp[n1][m1+1]=a[n1][m1+1];
			m1++;
		}
		else if(a[n1+1][m1]==c)
		{
			temp[n1+1][m1]=a[n1+1][m1];
			n1++;
		}
		else if(a[n1-1][m1]==c)
		{
			temp[n1-1][m1]=a[n1-1][m1];
			n1--;
		}

	}

	temp[x][y]=-2;
	temp[n][m]=-3;

	cout<<"\n\n";
	cout<<"Final Traced Path (blockage not shown):";
	cout<<"\n";
	for(j=0;j<height;j++)
	{
		for(i=0;i<width;i++)
		{
			cout<<temp[i][j]<<"\t";
		}
		cout<<"\n";
	}

	cout<<"Traceback path interms of co-ordinates: \n (Co-ordinate starts from left upper corner and increasing in both direction \n\n";
	for(j=0;j<height;j++)
	{
		for(i=0;i<width;i++)
		{
			if(temp[i][j]!=0)
			{
				cout<<"("<<j<<","<<i<<")\t";
			}
		}

	}
 }
}
