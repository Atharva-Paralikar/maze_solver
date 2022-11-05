#include <iostream>
#include <string>

#include "simulator/simulator.h"
#include "simulator/robot.h"

int main(int argc, char *argv[]){

    std::cerr << "The robot will follow the " << argv[1] <<
                                         " following algorithm" <<std::endl;
    std::string args(argv[1]);
    std::cerr<< args.length() <<std::endl;
    rwa2::Robot robot;
    robot.robot_init();
    robot.search_maze(args);
}
