#ifndef _LEE_GRID_BASE_H_
#define _LEE_GRID_BASE_H_

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
    class lee_grid {
        private:
           int width;
           int height;
           int source_x;
           vector<Connection> conn;
 	   vector<Blocker> block;
	int count;
	int sx,sy,tx,ty;
	int v, h1;
	int w,h,l,k;
        public: 
            vector<Point> paths[20]; 
		vector<Point> paths1[20];
			vector<Point> paths2[20];

            int count1;
	    /* Constructors/Destructors */
            lee_grid(ProblemObject *problem_object);
            void lee_algo();
		void aker_2bit_algo();
		void aker_3bit_algo();

    };
}

#endif  //_GRID_BASE_H_
