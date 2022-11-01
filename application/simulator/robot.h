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
        Robot(){
            robot_x = 0;
            robot_y = 0;
            robot_dir = NORTH;
        }
        void robot_init();
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