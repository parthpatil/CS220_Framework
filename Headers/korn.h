#ifndef _KORN_BASE_H_
#define _KORN_BASE_H_

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

    
class korn{
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
            korn(ProblemObject *problem_object);
            void korn_algo();
    };

class Queue{
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

}
float cost_korn(int ix,int iy, float c_1);

#endif  //_GRID_BASE_H_

