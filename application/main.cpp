#include <iostream>
#include <string>

#include "simulator/simulator.h"
#include "simulator/robot.h"

int main(int argc, char *argv[]){

    rwa2::Robot robot;
    robot.robot_init();
    robot.search_maze(15,15);
}
