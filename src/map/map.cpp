#include "map/map.h"

Map::Map()
{
    
}

Map::~Map()
{

}

void Map::draw(unsigned int planeVAO, unsigned int map)
{
    // world transformation
    glBindVertexArray(planeVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, map);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}