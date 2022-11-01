#include "cell.h"
#include "simulator.h"
#include "robot.h"
#include <array>
#include <vector>

const int NORTH {0};
const int EAST {1};
const int SOUTH {2};
const int WEST {3};

void rwa2::Robot::move_forward(){
    Simulator::moveForward();
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