#include "glad/glad.h"

#include <GL/glcorearb.h>

class Map
{
    public:
        Map();
        ~Map();

        void draw(unsigned int planeVAO, unsigned int map);
};