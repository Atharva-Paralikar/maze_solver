#include <iostream>
#include <string>

#include "simulator/simulator.h"
#include "simulator/robot.h"

int main(int argc , char *argv[]){
    std::cerr<<argc<<std::endl;
    std::string args;
    if (argc == 1){
        args = "left";
    }
    else{
        args = argv[1];
    }
    std::cerr << "The robot will follow the " << args <<
                                         " following algorithm" <<std::endl;
    rwa2::Robot robot;
    robot.robot_init();
    robot.search_maze(args);
}