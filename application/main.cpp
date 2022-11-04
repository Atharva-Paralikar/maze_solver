#include <iostream>
#include <string>

#include "simulator/simulator.h"
// #include "simulator/robot.h"

int main(int argc, char *argv[])
{
    // rwa2::Robot robot;
    // robot.move_forward();
    if (Simulator::wallFront){
        Simulator::setWall(0,0,'n');
        // robot.check_walls();
    }
}
