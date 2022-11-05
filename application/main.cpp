#include <iostream>
#include <string>
#include <memory>

#include "simulator/simulator.h"
#include "simulator/robot.h"

int main(int argc , char *argv[]){
    std::string args;
    if (argc == 1){
        args = "left";
    }
    else{
        args = argv[1];
    }
    std::cerr << "The robot will follow the " << args <<
                                         " following algorithm" <<std::endl;
    std::unique_ptr<rwa2::Robot> robot(new rwa2::Robot());
    robot->robot_init();
    if(!robot->search_maze(args)){
        std::cerr << "Stuck in loop! Path not found! " << std::endl;
    }
}