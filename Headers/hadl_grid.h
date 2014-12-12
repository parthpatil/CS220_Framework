#ifndef _HADL_GRID_BASE_H_
#define _HADL_GRID_BASE_H_

#include "node.h"
#include "path.h"
#include "point.h"
#include <vector>
#include "../Headers/problem_object.h"
using std::cerr;
using std::endl;
using std::string;
using Utilities::Node;
using Utilities::Path;

namespace Utilities {
    class hadl_grid {
        public:
           int width;
           int height;
           int source_x;
           vector<Connection> conn;
 	   vector<Blocker> block;
	int count;
	int sx,sy,tx,ty;
	int x,y,n,m;
	int v, h1;
	int w,h,l,k;
int a[1000][1000];
int temp[1000][1000];
int trc[1000][1000];
int pathx[500];
int pathy[500];
      //  public: 
            vector<Point> paths[30]; 
            int count1;
	    /* Constructors/Destructors */
            hadl_grid(ProblemObject *problem_object);
            void hadlock_algo();

void wave1(int x, int y, int c);
void wave2(int x, int y, int c);
void wave3(int x, int y, int c);
void wave4(int x, int y, int c);
void wavelf(int x, int y, int c);
void wavert(int x, int y, int c);
void waveup(int x, int y, int c);
void wavedn(int x, int y, int c);
void trace1(int x, int y,int c);
void trace2(int x, int y,int c);
void trace3(int x, int y,int c);
void trace4(int x, int y,int c);


    };
}

#endif  //_GRID_BASE_H_
