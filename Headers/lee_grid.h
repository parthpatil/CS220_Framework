#ifndef _LEE_GRID_BASE_H_
#define _LEE_GRID_BASE_H_

#include "node.h"
#include "path.h"
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
        public:
            /* Constructors/Destructors */
            lee_grid(ProblemObject *problem_object);

    };
}

#endif  //_GRID_BASE_H_
