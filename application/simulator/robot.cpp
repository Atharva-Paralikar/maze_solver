#include "simulator.h"
#include "robot.h"
#include <array>
#include <vector>
#include <iostream>

void rwa2 ::Robot::robot_init(){
    for(int x = 0; x < maze_width ; x++){
        for(int y = 0; y < maze_height ; y++){
            maze.at(x).at(y).set_wall(NORTH,(y == maze_height - 1));
            maze.at(x).at(y).set_wall(EAST,(x == maze_width - 1));
            maze.at(x).at(y).set_wall(SOUTH,(y == 0));
            maze.at(x).at(y).set_wall(WEST,(x == 0));
        }
    }
}

void rwa2::Robot::move_forward(){
    Simulator::moveForward();
    robot_y ++;
}

void rwa2::Robot::turn_left(){
    Simulator::turnLeft();
}

void rwa2::Robot::turn_right(){
    Simulator::turnRight();
}

void rwa2::Robot::check_walls(){
    
    std::array<char,4> directions{'n','e','s','w'};

    // north - cannot check south
    if (robot_dir == NORTH){
        maze.at(robot_x).at(robot_y).set_wall(NORTH,Simulator::wallFront);
        maze.at(robot_x).at(robot_y).set_wall(EAST,Simulator::wallRight);
        maze.at(robot_x).at(robot_y).set_wall(WEST,Simulator::wallLeft);
    }
    // east - cannot check west
    if (robot_dir == EAST){
        maze.at(robot_x).at(robot_y).set_wall(EAST,Simulator::wallFront);
        maze.at(robot_x).at(robot_y).set_wall(SOUTH,Simulator::wallRight);
        maze.at(robot_x).at(robot_y).set_wall(NORTH,Simulator::wallLeft);
    }
    // south - cannot check north
    if (robot_dir == SOUTH){
        maze.at(robot_x).at(robot_y).set_wall(SOUTH,Simulator::wallFront);
        maze.at(robot_x).at(robot_y).set_wall(WEST,Simulator::wallRight);
        maze.at(robot_x).at(robot_y).set_wall(EAST,Simulator::wallLeft);
    }
    // west - cannot check east
    if (robot_dir == WEST){
        maze.at(robot_x).at(robot_y).set_wall(WEST,Simulator::wallFront);
        maze.at(robot_x).at(robot_y).set_wall(NORTH,Simulator::wallRight);
        maze.at(robot_x).at(robot_y).set_wall(SOUTH,Simulator::wallLeft);
    }
    for (int i = 0; i < 4 ; i++){
        if (maze.at(robot_x).at(robot_y).is_wall(i)){
            Simulator::setWall(robot_x,robot_y,directions.at(i));
        }
    }
}