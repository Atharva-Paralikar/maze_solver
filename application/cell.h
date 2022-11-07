#ifndef __CELL_H__
#define __CELL_H_

/**
 * @file cell.h
 * @author Atharva Paralikar (atharvap@umd.edu)
 * @author Abhilash Mane (amane@umd.edu)
 * @author Abhishek Reddy (areddy42@umd.edu)
 * @brief Functions and atrributes of the maze cell
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <array>

const int NORTH {0};
const int EAST {1};
const int SOUTH {2};
const int WEST {3};

namespace rwa2_group1{

    /**
     * @brief Cell represents a position in the maze
     * 
     * A cell is surrounded by 4 walls 
     */
    class Cell{
        public:
        /**
         * @brief Construct a new Cell object with no walls present
         * 
         */
        Cell(){
            for (int i = 0; i < 4; i++){
                set_wall(i,false);
                // cell_walls[i] = false;
            }
        }

        /**
         * @brief Sets the wall object
         * 
         * @param direction direction of the cell the wall need to be placed
         * @param is_wall true if wall is present, false if not
         */
        void set_wall(int direction,bool is_wall);

        /**
         * @brief checks if the wall is present in the given direction
         * 
         * @param direction the direction in which to check if there is wall
         * @return true if wall is present
         * @return false if wall is not present
         */
        bool is_wall(int direction) const;

        /**
         * @brief computes the number of walls the given cell has
         * 
         * @return int Number of walls surrounding the cell
         */
        int number_of_walls() const;

        private:
        /**
         * @brief boolean array to store all four walls of the cell
         * 
         */
        std::array<bool,4> cell_walls;
    };
}
#endif