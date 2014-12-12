#ifndef _RUBEN_BASE_H_
#define _RUBEN_BASE_H_

#include "node.h"
#include "path.h"
#include "point.h"
#include <vector>
#include "../Headers/problem_object.h"
#define MAX_SIZE 200
using std::cerr;
using std::endl;
using std::string;
using Utilities::Node;
using Utilities::Path;

namespace Utilities {

    
class ruben{
        public:
           int width;
           int height;
           int source_x;
           vector<Connection> conn;
 	   vector<Blocker> block;
	int multi_path;
	int sx,sy,tx,ty;
	int v, h1;
	int w,h,l,k;
       // public: 
            vector<Point> paths[20]; 
		vector<Point> paths1[20];
			vector<Point> paths2[20];

            int count1;
	    /* Constructors/Destructors */
            ruben(ProblemObject *problem_object);
            void ruben_algo();
    };

class Queue_2{
    public:
	int item_1[MAX_SIZE],item_2[MAX_SIZE];
	int rear,rear_new;
        int front,x,y;
        void enqueue(int, int);
        int dequeue();
        int size();
        void display();
        bool isEmpty();
};

class Queue_3{
    public:
  
	int item1_1[MAX_SIZE],item1_2[MAX_SIZE];
	int rear1,rear1_new,x,y;
        int front1;
        void enqueue_1(int, int);
        int dequeue_1();
        int size_1();
        void display_1();
        bool isEmpty_1();
};

}
int cost_ruben(int ix,int iy, int c_1,int stx,int sty);

#endif  //_GRID_BASE_H_

