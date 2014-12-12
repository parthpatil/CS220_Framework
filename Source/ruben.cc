#include "../Headers/grid.h"
#include "../Headers/problem_object.h"
#include "../Headers/ruben.h"
#include "../Headers/edge.h"
#include "../Headers/claim.h"
#include "../Headers/point.h"
#include "iostream"
#include<stdlib.h>
#include<vector>
using std::cin;
using std::cout;
//Takes an x and y coordinate as input and creates a grid of that size filled with default nodes
Utilities::ruben::ruben(ProblemObject *problem_object) {
	width=problem_object-> get_width();
        height=problem_object-> get_height();

    conn = problem_object-> get_connections();
    
    block = problem_object-> get_blockers();

cout<<"\n";
}

void Utilities::Queue_2::display(){
    if(!this->isEmpty()){
        for(int i=front; i<=rear; i++)
            cout<<item_2[i]<<endl;
    }else{
        cout<<"Queue Underflow"<<endl;
    }
}

void Utilities::Queue_2::enqueue(int data_1, int data_2)
{
        item_1[++rear] = data_1;
        item_2[rear] = data_2;
}
int Utilities:: Queue_2::dequeue()
{
		x=item_1[rear_new];
		y=item_2[rear_new];
		return x ,y;
}
int Utilities:: Queue_2::size(){
    return (rear + 1);
}
bool Utilities:: Queue_2::isEmpty(){
    if(rear==-1){
        return true;
    }else{
        return false;
    }
}


void Utilities:: Queue_3::enqueue_1(int data_3, int data_4)
{
        item1_1[++rear1] = data_3;
        item1_2[rear1] = data_4;
}
int Utilities:: Queue_3::dequeue_1()
{
        x=item1_1[rear1_new];
        y= item1_2[rear1_new];
		  return x,y;
}

int Utilities:: Queue_3::size_1(){
    return (rear1 + 1);
}
bool Utilities:: Queue_3::isEmpty_1(){
    if(rear1==-1){
        return true;
    }else{
        return false;
    }
}


int cost_ruben(int ix,int iy, int c_1, int stx, int sty)
{
	int dis,manhattan_dis,cost;
	dis=c_1;
	manhattan_dis=abs(ix-stx) + abs(iy-sty);
	cost=dis + manhattan_dis;
	return cost;
}


void Utilities::ruben::ruben_algo()
{

Utilities::Queue_2 queue;
 Utilities::Queue_3 queue1;

 
 h1=0;
 multi_path = conn.size()-1;
 count1=0;

while(multi_path>=0)
{
multi_path--;
cout<<"\n\n\n"<<"RUBEN's Algorithm \n for SOURCE and SINK :"<<h1+1<<"\n\n";

sx =  conn[h1].source.x;
sy =  conn[h1].source.y;
tx =  conn[h1].sink.x;
ty =  conn[h1].sink.y;
 h1++;
int x=sx;
int y=sy;
int n=tx;
int m=ty;

int a[width][height], b[width][height];
int temp[width][height];

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
		 w = block[i].width;
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
			a[l][k]=100;
			//temp[l][k]=100;
			l++;
		}
		k++;
	}

	}
	a[n][m]=80;
	b[n][m]=80;
	a[x][y]=70;
	b[x][y]=70;

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


	int i=x, j=y;
	int r,first_time, y_prio=0;
	int cost,chk_pt=0;
	int ek=1,ek_1=1,save_queue1;
	queue.rear=-1;
	queue.front=0;

	queue1.rear1=-1;
	queue1.front1=0;
	
	int cminmax=0;

int sink_found=0,c=0,dummy,xyz=0;
queue.rear=1;
queue1.rear1=1;
queue.rear_new=1;
 cminmax=cost_ruben(x,y,c,n,m);
cout<<cminmax<<"\n";
int block=0,count=0;
int out_this=0,first=1,switch_queue=0,stop_count=width*height;
while(queue1.rear1!=-1 && sink_found==0)
{
	queue.rear_new++;

	while(queue.rear_new!=-1 && sink_found==0 && out_this==0)
{
		block=0;
		chk_pt++;
		if(first_time==0)
		{
		queue.rear=-1;
		queue1.rear1=-1;
		first_time=1;
		}
		//cout<<"nn"<<queue.rear_new<<"\n";
		//cout<<y_prio;
		//cout<<"b:"<<b[i+1][j];
		//cout<<"a:"<<a[i][j];
		//cout<<"\n c:"<<c;
		for(int time=0;time<65535;time++);
		

while(a[i][j] !=100 && sink_found==0 && block==0)
{
	stop_count--;

		c++;
		if(i<=n && j<=m)
		{
			r=1;
			//cout<<cminmax<<"\n";
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

	
	switch(r)
	{

		case 1:
		  if((cost_ruben(i+1,j,c,n,m)==cminmax) && (b[i+1][j]>cminmax || b[i+1][j]==0) && y_prio==0 )// && a[i+1][j]==0)
				{
	
					if((a[i][j-1]!=80)&&((i<width)&&((j-1)<height))&&(i>=0)&&((j-1)>=0)&&(a[i][j-1]!=100)&&(a[i][j-1]==0))
					{
					  cost=cost_ruben(i,j-1,c,n,m);
						b[i][j-1]=cost;
						queue1.enqueue_1(i,j-1);
					}
					else if(a[i][j-1]==80)
					{
						sink_found=1;
						//cout<<"cought1";
						break;
					}

					if((a[i+1][j]!=80)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=100)&&(a[i+1][j]==0))
					{
						a[i+1][j]=c;
						cost=cost_ruben(i+1,j,c,n,m);
						b[i+1][j]=cost;
					}
					else if(a[i+1][j]==80)
					{
						sink_found=1;
						//cout<<"cought2";
						break;
					}

					if((a[i][j+1]!=80)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=100)&&(a[i][j+1]==0))
					{
					  cost=cost_ruben(i,j+1,c,n,m);
						b[i][j+1]=cost;
						if(switch_queue==0)
							queue.enqueue(i,j+1);
						else
							queue1.enqueue_1(i,j+1);
					}
					else if(a[i][j+1]==80)
					{
						sink_found=1;
						//cout<<"cought3";
						break;
					}
					if((a[i-1][j]!=80)&&((i-1<width)&&((j)<height))&&(i-1>=0)&&((j)>=0)&&(a[i-1][j]!=100)&&(a[i-1][j]==0))
					{

					  cost=cost_ruben(i-1,j,c,n,m);
						b[i-1][j]=cost;
						if(a[i-1][j]==0)
						a[i-1][j]=c;
						queue1.enqueue_1(i,j-1);
					}
					else if(a[i-1][j]==80)
					{
						sink_found=1;
						break;
					}

					i=i+1;
				}
		  else if(cost_ruben(i,j+1,c,n,m)==cminmax)// && (j<=height+1)) //&& a[i][j+1]==0)
				{
					y_prio=1;
					if((a[i-1][j]!=80)&&(((i-1)<width)&&(j<height))&&(((i-1)>=0)&&(j>=0))&&(a[i-1][j]!=100)&&(a[i-1][j]==0))
					{
						//a[i-1][j]=c;
					  cost=cost_ruben(i-1,j,c,n,m);
						b[i-1][j]=cost;
						queue1.enqueue_1(i-1,j);
					}
					else if(a[i-1][j]==80)
					{
						sink_found=1;
						//cout<<"cought4";
						break;
					}
					
					if((a[i+1][j]!=80)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=100)&&(a[i+1][j]==0))
					{
					  cost=cost_ruben(i+1,j,c,n,m);
						b[i+1][j]=cost;
						queue1.enqueue_1(i+1,j);
					}
					else if(a[i+1][j]==80)
					{
						sink_found=1;
						//cout<<"cought5";
						break;
					}

					if((a[i][j+1]!=80)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=100)&&(a[i][j+1]==0))
					{
						a[i][j+1]=c;
						cost=cost_ruben(i,j+1,c,n,m);
						b[i][j+1]=cost;
					}
					else if(a[i][j+1]==80)
					{
						sink_found=1;
						//cout<<"cought6";
						break;
					}
					if((a[i][j-1]!=80)&&((i<width)&&((j-1)<height))&&((i>=0)&&((j-1)>=0))&&(a[i][j-1]!=100)&&(a[i][j-1]==0))
					{
						if(a[i][j-1]==0)
						a[i][j-1]=c;
						cost=cost_ruben(i,j-1,c,n,m);
						b[i][j-1]=cost;
						queue1.enqueue_1(i+1,j);
					}
						else if(a[i][j-1]==80)
					{
						sink_found=1;
						break;
					}
					j=j+1;
				}
				else
					block=1;

				if(j==m && (a[i+1][j]==0 || a[i+1][j]==80))
				{
					y_prio=0;
				}
				
		break;

		case 2:
		  if(cost_ruben(i+1,j,c,n,m)==cminmax && (b[i+1][j]>cminmax || b[i+1][j]==0) && y_prio==0 )
				{

					if((a[i][j-1]!=80)&&((i<width)&&((j-1)<height))&&(i>=0)&&((j-1)>=0)&&(a[i][j-1]!=100)&&(a[i][j-1]==0))
					{
					  cost=cost_ruben(i,j-1,c,n,m);
						b[i][j-1]=cost;
						if(switch_queue==0)
							queue.enqueue(i,j-1);
						else
							queue1.enqueue_1(i,j-1);
					}
					else if(a[i][j-1]==80)
					{
						sink_found=1;
						break;
					}

					if((a[i+1][j]!=80)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=100)&&(a[i+1][j]==0))
					{
						a[i+1][j]=c;
						cost=cost_ruben(i+1,j,c,n,m);
						b[i+1][j]=cost;
					}
					else if(a[i+1][j]==80)
					{
						sink_found=1;
						break;
					}

					if((a[i][j+1]!=80)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=100)&&(a[i][j+1]==0))
					{
					  cost=cost_ruben(i,j+1,c,n,m);
						b[i][j+1]=cost;
						queue1.enqueue_1(i,j+1);
					}
					else if(a[i][j+1]==80)
					{
						sink_found=1;
						break;
					}
					if((a[i-1][j]!=80)&&(((i-1)<width)&&(j<height))&&(((i-1)>=0)&&(j>=0))&&(a[i-1][j]!=100)&&(a[i-1][j]==0))
					{
						if(a[i-1][j]==0)
						a[i-1][j]=c;
						cost=cost_ruben(i-1,j,c,n,m);
						b[i-1][j]=cost;
						queue1.enqueue_1(i+1,j);
					}
						else if(a[i-1][j]==80)
					{
						sink_found=1;
						break;
					}

					i=i+1;

				}
		  else if(cost_ruben(i,j-1,c,n,m)==cminmax)
				{
					y_prio=1;
					if((a[i-1][j]!=80)&&(((i-1)<width)&&(j<height))&&(((i-1)>=0)&&(j>=0))&&(a[i-1][j]!=100)&&(a[i-1][j]==0))
					{
					  cost=cost_ruben(i-1,j,c,n,m);
						b[i-1][j]=cost;
						queue1.enqueue_1(i-1,j);
					}
					else if(a[i-1][j]==80)
					{
						sink_found=1;
						break;
					}

					if((a[i+1][j]!=80)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=100)&&(a[i+1][j]==0))
					{
					  cost=cost_ruben(i+1,j,c,n,m);
						b[i+1][j]=cost;
						queue1.enqueue_1(i+1,j);
					}
					else if(a[i+1][j]==80)
					{
						sink_found=1;
						break;
					}

					if((a[i][j-1]!=80)&&((i<width)&&((j-1)<height))&&(i>=0)&&((j-1)>=0)&&(a[i][j-1]!=100)&&(a[i][j-1]==0))
					{
						a[i][j-1]=c;
						cost=cost_ruben(i,j-1,c,n,m);
						b[i][j-1]=cost;
					}
					else if(a[i][j-1]==80)
					{
						sink_found=1;
						break;
					}

					if((a[i][j+1]!=80)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=100)&&(a[i][j+1]==0))
					{
						if(a[i][j+1]==0)
						a[i][j+1]=c;
						cost=cost_ruben(i,j+1,c,n,m);
						b[i][j+1]=cost;
						queue1.enqueue_1(i,j+1);
					}
						else if(a[i][j+1]==80)
					{
						sink_found=1;
						break;
					}
					j=j-1;

				}
				else
					block=1;

				if(j==m && (a[i+1][j]==0 || a[i+1][j]==80))
				{
					y_prio=0;
				}
		break;


		case 3:
		  if(cost_ruben(i-1,j,c,n,m)==cminmax && (b[i-1][j]>cminmax || b[i-1][j]==0) && y_prio==0 )
				{
				
				if((a[i-1][j]!=80)&&(((i-1)<width)&&(j<height))&&(((i-1)>=0)&&(j>=0))&&(a[i-1][j]!=100)&&(a[i-1][j]==0))
					{
						a[i-1][j]=c;
						cost=cost_ruben(i-1,j,c,n,m);
						b[i-1][j]=cost;
					}
				else if(a[i-1][j]==80)
					{
						sink_found=1;
						break;
					}
				if((a[i][j-1]!=80)&&((i<width)&&((j-1)<height))&&(i>=0)&&((j-1)>=0)&&(a[i][j-1]!=100)&&(a[i][j-1]==0))
					{
					  cost=cost_ruben(i,j-1,c,n,m);
						b[i][j-1]=cost;
						if(switch_queue==0)
							queue.enqueue(i,j-1);
						else
							queue1.enqueue_1(i,j-1);
					}
				else if(a[i][j-1]==80)
					{
						sink_found=1;
						break;
					}

				if((a[i][j+1]!=80)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=100)&&(a[i][j+1]==0))
					{
					  cost=cost_ruben(i,j+1,c,n,m);
						b[i][j+1]=cost;
						queue.enqueue(i,j+1);
					}
				else if(a[i][j+1]==80)
					{
						sink_found=1;
						break;
					}
				if((a[i+1][j]!=80)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=100)&&(a[i+1][j]==0))
													{
						if(a[i+1][j]==0)
						a[i+1][j]=c;
						cost=cost_ruben(i+1,j,c,n,m);
						b[i+1][j]=cost;
						queue1.enqueue_1(i+1,j);
					}
						else if(a[i+1][j]==80)
					{
						sink_found=1;
						break;
					}
					i=i-1;
				}
		  else if(cost_ruben(i,j-1,c,n,m)==cminmax)
				{
					y_prio=1;

					if((a[i-1][j]!=80)&&(((i-1)<width)&&(j<height))&&(((i-1)>=0)&&(j>=0))&&(a[i-1][j]!=100)&&(a[i-1][j]==0))
					{
					  cost=cost_ruben(i-1,j,c,n,m);
						b[i-1][j]=cost;
						queue1.enqueue_1(i-1,j);
					}
					else if(a[i-1][j]==80)
					{
						sink_found=1;
						break;
					}

					if((a[i+1][j]!=80)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=100)&&(a[i+1][j]==0))
					{
					  cost=cost_ruben(i+1,j,c,n,m);
						b[i+1][j]=cost;
						queue1.enqueue_1(i+1,j);
					}
					else if(a[i+1][j]==80)
					{
						sink_found=1;
						break;
					}

					if((a[i][j-1]!=80)&&((i<width)&&((j-1)<height))&&(i>=0)&&((j-1)>=0)&&(a[i][j-1]!=100)&&(a[i][j-1]==0))
					{
						a[i][j-1]=c;
						cost=cost_ruben(i,j-1,c,n,m);
						b[i][j-1]=cost;
					}
					else if(a[i][j-1]==80)
					{
						sink_found=1;
						break;
					}
					if((a[i][j+1]!=80)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=100)&&(a[i][j+1]==0))
					{
						if(a[i][j+1]==0)
						a[i][j+1]=c;
						cost=cost_ruben(i,j+1,c,n,m);
						b[i][j+1]=cost;
						queue1.enqueue_1(i,j+1);
					}
					else if(a[i][j+1]==80)
					{
					sink_found=1;
					break;
					}
					j=j-1;

				}
				else
					block=1;

				if(j==m && (a[i-1][j]==0 || a[i-1][j]==80))
				{
					y_prio=0;
				}
		break;

		case 4:

		  if(cost_ruben(i-1,j,c,n,m)==cminmax && (b[i-1][j]>cminmax || b[i-1][j]==0) && y_prio==0 )
				{


					if((a[i-1][j]!=80)&&(((i-1)<width)&&(j<height))&&(((i-1)>=0)&&(j>=0))&&(a[i-1][j]!=100)&&(a[i-1][j]==0))
							{
								a[i-1][j]=c;
								cost=cost_ruben(i-1,j,c,n,m);
								b[i-1][j]=cost;
							}
					else if(a[i-1][j]==80)
							{
								sink_found=1;
								break;
							}
					if((a[i][j-1]!=80)&&((i<width)&&((j-1)<height))&&(i>=0)&&((j-1)>=0)&&(a[i][j-1]!=100)&&(a[i][j-1]==0))
							{
							  cost=cost_ruben(i,j-1,c,n,m);
								b[i][j-1]=cost;
								queue1.enqueue_1(i,j-1);
							}
					else if(a[i][j-1]==80)
							{
								sink_found=1;
								break;
							}

					if((a[i][j+1]!=80)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=100)&&(a[i][j+1]==0))
							{
							  cost=cost_ruben(i,j+1,c,n,m);
								b[i][j+1]=cost;
								if(switch_queue==0)
									queue.enqueue(i,j+1);
								else
									queue1.enqueue_1(i,j+1);
							}
					else if(a[i][j+1]==80)
							{
								sink_found=1;
								break;
							}

					if((a[i+1][j]!=80)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=100)&&(a[i+1][j]==0))
							{
								if(a[i+1][j]==0)
								a[i+1][j]=c;
								cost=cost_ruben(i+1,j,c,n,m);
								b[i+1][j]=cost;
								queue1.enqueue_1(i+1,j);
							}
					else if(a[i+1][j]==80)
							{
								sink_found=1;
								break;
							}
					i=i-1;
				}
		  else if(cost_ruben(i,j+1,c,n,m)==cminmax)
				{
					y_prio=1;
					if((a[i-1][j]!=80)&&(((i-1)<width)&&(j<height))&&(((i-1)>=0)&&(j>=0))&&(a[i-1][j]!=100)&&(a[i-1][j]==0))
							{
							  cost=cost_ruben(i-1,j,c,n,m);
								b[i-1][j]=cost;
								queue1.enqueue_1(i-1,j);
							}
					else if(a[i-1][j]==80)
							{
								sink_found=1;
								break;
							}

					if((a[i+1][j]!=80)&&(((i+1)<width)&&(j<height))&&(((i+1)>=0)&&(j>=0))&&(a[i+1][j]!=100)&&(a[i+1][j]==0))
							{
							  cost=cost_ruben(i+1,j,c,n,m);
								b[i+1][j]=cost;
								queue1.enqueue_1(i+1,j);
							}
					else if(a[i+1][j]==80)
							{
								sink_found=1;
								break;
							}

					if((a[i][j+1]!=80)&&((i<width)&&((j+1)<height))&&(i>=0)&&((j+1)>=0)&&(a[i][j+1]!=100)&&(a[i][j+1]==0))
							{
								a[i][j+1]=c;
								cost=cost_ruben(i,j+1,c,n,m);
								b[i][j+1]=cost;
							}
					else if(a[i][j+1]==80)
							{
								sink_found=1;
								break;
							}
					if((a[i][j-1]!=80)&&((i<width)&&((j-1)<height))&&(i>=0)&&((j-1)>=0)&&(a[i][j-1]!=100)&&(a[i][j-1]==0))
							{
								if(a[i][j-1]==0)
								a[i][j-1]=c;
								cost=cost_ruben(i,j-1,c,n,m);
								b[i][j-1]=cost;
								queue1.enqueue_1(i,j-1);
							}
					else if(a[i][j-1]==80)
							{
								sink_found=1;
								break;
							}

					j=j+1;
					}
				else
					block=1;

				if(j==m && (a[i-1][j]==0 || a[i-1][j]==80))
				{
					y_prio=0;
				}

				break;
		default:
			block=1;
			break;

	}
	if(stop_count==0)
			{
				cout<<"Sink Not Found";
				sink_found=1;
			}

}
/*
cout<<cminmax<<"\n";
cout<<block<<"\n";
cout<<a[i][j]<<"\n";
cout<<sink_found<<"\n";*/
	if(sink_found==0 && count==0)
	{
		while(ek==1)
				{
				save_queue1=queue1.rear1;
				queue.rear_new=queue.rear;
				//cout<<save_queue1;
				ek=ek-1;
				}

		                queue.dequeue();
				i=queue.x;
				j=queue.y;
				//	cout<<"queue="<<i<<j;
				queue.rear_new--;

		if(queue.rear_new==0)
			queue.rear_new=queue.rear_new-1;
		
		if(r==1)
		{
			c=a[i][j-1]+1;
			if(a[i][j-1]==70)
			{
				c=1;
				a[i][j]=c;
			}
		}
		else if(r==2)
		{
			c=a[i][j+1]+1;
			if(a[i][j+1]==70)
			{
				c=1;
				a[i][j]=c;
			}
		}
		else if(r==3)
		{
			c=a[i][j+1]+1;
			if(a[i][j+1]==70)
			{
				c=1;
				a[i][j]=c;
			}
		}
		else if(r==4)
		{
			c=a[i][j-1]+1;
			if(a[i][j-1]==70)
			{
				c=1;
				a[i][j]=c;
			}
		}

		cminmax=cost_ruben(i,j,c,n,m);
		if((i!=x && j!=y)||(i==x && j!=y)||(i!=x && j==y))
		{
			a[i][j]=c;
			b[i][j]=cminmax;
		}

	}
	else if(sink_found==0 && count!=0)
	{
		out_this=1;
	}

}
count++;
out_this=0;
	if(sink_found==0)
	{
		while(ek_1==1)
				{
					queue1.rear1_new=save_queue1;
					ek_1=ek_1-1;
				}

		 queue1.dequeue_1();
			i=queue1.x;
			j=queue1.y;
			//cout<<"\n queue1:"<<i<<j;
							if(first==1)
								queue1.rear1_new--;
							else
								queue1.rear1_new++;

			//cout<<"\n rear1_new:"<<queue1.rear1_new;
			if(queue1.rear1_new==1)
			{
				queue1.rear1_new=save_queue1+1;
				cout<<"\n rear1_change:"<<queue1.rear1_new;
				first=0;
				switch_queue=1;
				queue1.rear1_new--;
			}

			if(r==1)
				c=a[i-1][j]+1;
			else if(r==2)
				c=a[i+1][j]+1;
			else if(r==3)
				c=a[i+1][j]+1;
			else if(r==4)
				c=a[i-1][j]+1;

			a[i][j]=c;
			cminmax=cost_ruben(i,j,c,n,m);
			b[i][j]=cminmax;
			//if(a[i][j]!=100)
				y_prio=1;
			xyz++;
	}

}

cout<<"a array\n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<a[i][j]<<"\t";

		}
		cout<<"\n";

	}

cout<<"b array\n";

	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			cout<<b[i][j]<<"\t";

		}
		cout<<"\n";

	}

	cout<<"\n\n"<<c<<"\n";

	int n1=n;
		int m1=m;


	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			temp[i][j]=0;
		}

	}

	cout<<"\n\n"<<c<<"\n";
	for(int i=c;i>=1;i-- )
	{
		c--;

		cout<<"("<<n1<<","<<m1<<")\t";
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

	temp[x][y]=70;
	temp[n][m]=80;

	cout<<"\n";

	for(j=0;j<height;j++)
	{
		for(i=0;i<width;i++)
		{
			cout<<temp[i][j]<<"\t";
		}
		cout<<"\n";
	}

	cout<<"traceback path is\n";
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
