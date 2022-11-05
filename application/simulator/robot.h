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

const bool LEFT{true};
const bool RIGHT{false};

namespace rwa2
{
    class Robot{
        public:
        /**
         * @brief Constructs a new Robot object
         * 
         */
        Robot(){
            robot_x = 0;
            robot_y = 0;
            robot_dir = NORTH;
        }
        /**
         * @brief Sets walls around the perimeter
         * 
         */
        void robot_init();

        /**
         * @brief Get the current location of the robot in the maze
         * 
         * @return std::vector<int> returns a vector containing the robot coords
         */
        std::vector<int> get_curr_loc();

        /**
         * @brief Moves the robot forward in the simulator
         * 
         */
        void move_forward();

        /**
         * @brief Turns the robot to left in the simulator
         * 
         */
        void turn_left();

        /**
         * @brief Turns the robot to right in the simulator
         * 
         */
        void turn_right();

        /**
         * @brief Checks the surrounding walls of the robot
         * 
         */
        void check_walls();

        /**
         * @brief algorithm to move the robot
         * 
         * @param left_following true for left wall following 
         *                       false for right wall following
         * @return int 
         */
        int move_robot(bool left_following);

        /**
         * @brief Function for the Robot to search the maze
         * 
         */
        void search_maze(std::string argument);
        
        private:

        /**
         * @brief height of the maze
         * 
         */
        const static int maze_height{16};

        /**
         * @brief width of the maze
         * 
         */
        const static int maze_width{16};

        /**
         * @brief robot x-coordinate
         * 
         */
        int robot_x;

        /**
         * @brief robot y-coordinate
         * 
         */
        int robot_y;

        /**
         * @brief robot facing direction
         * 
         */
        int robot_dir;

        /**
         * @brief array to store the cells in the maze
         * 
         */
        std::array<std::array<rwa2::Cell,maze_width>,maze_height> maze;

        /**
         * @brief Function to generate a random goal on the perimeter of the maze
         * 
         * @return std::pair<int,int> return the goal coordinates as a pair
         */
        std::pair<int,int> generate_goal();
    };
} // namespace rwa2


#endif