#ifndef __ROBOT_H__
#define __ROBOT_H__

/**
 * @file robot.h
 * @author Atharva Paralikar (atharvap@umd.edu)
 * @author Abhilash Mane (amane@umd.edu)
 * @author Abhishek Reddy (areddy42@umd.edu)
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
#include <map>

const bool LEFT{true};
const bool RIGHT{false};

namespace rwa2_group2
{
    /**
     * @brief Robot represents the mouse in the maze
     * 
     */
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
         * @brief Get the current loaction of the Robot
         * 
         * @return std::pair<int,int>  returns current coordinates as pair
         */
        std::array<int,3> get_curr_loc();

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
         * @return bool tru if can move, false otherwise
         */
        bool move_robot(bool left_following);

        /**
         * @brief Function for the robot to search the maze
         * 
         * @param argument Select the algorithm to for the robot
         * @return true if path found
         * @return false if path found
         */
        bool search_maze(std::string argument);

        /**
         * @brief Function to return the optimized path for backtracking
         * 
         *  
         */
        void remove_cyclic_loop_from_path();

        /**
         * @brief Get the direction of the cell the robot needs to move to
         * 
         * @param next_coords coordinates of the next cell
         * @return char returns the direction char {'n','e','s','w'}
         */
        char get_next_direction(std::array<int,3> next_coords);

        /**
         * @brief Fumction to backtrack the path back to home position
         * 
         */
        void backtrack();
        
        /**
         * @brief Utility function to travel if robot is facing north
         * 
         * @param dir direction the robot needs to move
         */
        void move_from_north(char dir);

        /**
         * @brief Utility function to travel if robot is facing east
         * 
         * @param dir direction the robot needs to move
         */
        void move_from_east(char dir);

        /**
         * @brief Utility function to travel if robot is facing south
         * 
         * @param dir direction the robot needs to move
         */
        void move_from_south(char dir);

        /**
         * @brief Utility function to travel if robot is facing west
         * 
         * @param dir direction the robot needs to move
         */
        void move_from_west(char dir);
        
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
        std::array<std::array<rwa2_group2::Cell,maze_width>,maze_height> maze;

        /**
         * @brief Function to generate a random goal on the perimeter of the maze
         * 
         * @return std::pair<int,int> return the goal coordinates as a pair
         */
        std::pair<int,int> generate_goal();

        /**
         * @brief vector to save the visited nodes
         * 
         */
        std::vector<std::array<int,3>> visited;

        /**
         * @brief map to store occurence of states. Used to remove cyclic path
         * 
         */
        std::map<std::array<int,2>,int> lookup_for_repeated_entries;
    };
} // namespace rwa2


#endif