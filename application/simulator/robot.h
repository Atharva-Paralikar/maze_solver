#ifndef __ROBOT_H__
#define __ROBOT_H__

#include "cell.h"
#include <array>
#include <vector>


namespace rwa2
{
    class Robot{
        public:
        /**
         * @brief Construct a new Robot object
         * 
         */
        Robot(): robot_x{0}, robot_y{0}, robot_dir{NORTH}{
            for(int x = 0; x < maze_width ; x++){
                for(int y = 0; y < maze_height ; y++){
                    maze.at(x).at(y).set_wall(NORTH,(y == maze_height - 1));
                    maze.at(x).at(y).set_wall(EAST,(x == maze_width - 1));
                    maze.at(x).at(y).set_wall(SOUTH,(y == 0));
                    maze.at(x).at(y).set_wall(WEST,(x == 0));
                }
            }
        }
        void move_forward();
        void turn_left();
        void turn_right();
        void check_walls();
        
        private:
        const static int maze_height{16};
        const static int maze_width{16};
        int robot_x;
        int robot_y;
        int robot_dir;
        std::array<std::array<rwa2::Cell,maze_width>,maze_height> maze;
    };
} // namespace rwa2


#endif