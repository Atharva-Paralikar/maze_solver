#ifndef __ROBOT_H__
#define __ROBOT_H__

/**
 * @file robot.h
 * @author Atharva Paralikar (atharvap@umd.edu)
 * @brief Functions to Control Robot
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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
        std::vector<int> get_curr_loc();
        void move_forward();
        void turn_left();
        void turn_right();
        void check_walls();
        int move_robot(bool left_following);
        void search_maze(int goal_x,int goal_y);
        
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