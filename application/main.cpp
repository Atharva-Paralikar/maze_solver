/**
 * @file main.cpp
 * @author Atharva Paralikar (atharvap@umd.edu)
 * @author Abhilash Mane (amane@umd.edu)
 * @author Abhishek Reddy (areddy42@umd.edu)
 * @brief Driver code for Micro-mouse Maze-Solver
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <memory>
#include "simulator/simulator.h"
#include "robot.h"


int main(int argc , char *argv[]){
    std::string args;
    if (argc == 1){
        args = "left";
        std::cerr<<" No arguments given defaulting to left following algorithm! "<<std::endl;
    }
    else{
        args = argv[1];
    }
    std::cerr << "The robot will follow the " << args <<
                                         " following algorithm" <<std::endl;
    std::unique_ptr<rwa2_group1::Robot> robot = std::make_unique<rwa2_group1::Robot>();
    robot->robot_init();
    if(!robot->search_maze(args)){
        std::cerr << "Stuck in loop! Path not found! " << std::endl;
    }
    robot->remove_cyclic_loop_from_path();
    robot->backtrack();
}