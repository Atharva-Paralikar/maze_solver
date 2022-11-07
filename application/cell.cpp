#include "cell.h"

void rwa2_group1::Cell::set_wall(int direction, bool is_wall){
    cell_walls.at(direction) = is_wall;
}

bool rwa2_group1::Cell::is_wall(int direction) const{
    return cell_walls.at(direction);
}

int rwa2_group1::Cell::number_of_walls() const{
    int walls {0};
    int wall_north{0};
    int wall_east{0};
    int wall_south{0};
    int wall_west{0};
    if (is_wall(NORTH)){
        wall_north = 1;
    }
    if (is_wall(EAST)){
        wall_east = 1;
    }
    if (is_wall(SOUTH)){
        wall_south = 1;
    }
    if (is_wall(WEST)){
        wall_west = 1;
    }
    walls = wall_north + wall_east + wall_south + wall_west;
    return walls;
}

