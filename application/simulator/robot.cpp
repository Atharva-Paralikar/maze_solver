#include "simulator.h"
#include "robot.h"
#include <array>
#include <vector>
#include <iostream>
#include <cstring>

void rwa2 ::Robot::robot_init(){
    Simulator::setColor(0,0,'b');
    Simulator::setText(0,0,"Start");
    for(int x = 0; x < maze_width ; x++){
        for(int y = 0; y < maze_height ; y++){
            maze.at(x).at(y).set_wall(NORTH,(y == maze_height - 1));
            maze.at(x).at(y).set_wall(EAST,(x == maze_width - 1));
            maze.at(x).at(y).set_wall(SOUTH,(y == 0));
            maze.at(x).at(y).set_wall(WEST,(x == 0));
            std::array<char,4> directions{'n','e','s','w'};
            for (int i = 0; i < 4 ; i++){
                if (maze.at(x).at(y).is_wall(i)){
                    Simulator::setWall(x,y,directions.at(i));
                }
            }
        }
    }
}

std::pair<int,int> rwa2::Robot::generate_goal(){
    std::pair<int,int> goal(0,0);
    int max {15};
    srand(time(0));
    goal.first = rand()%max + 1;
    if ((goal.first == 0) || (goal.first == 15)){
        goal.second = rand()%max + 1;
    }
    Simulator::setColor(goal.first,goal.second,'G');
    Simulator::setText(goal.first,goal.second,"GOAL");
    return goal;
}

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
        maze.at(robot_x).at(robot_y).set_wall(NORTH,Simulator::wallFront());
        maze.at(robot_x).at(robot_y).set_wall(EAST,Simulator::wallRight());
        maze.at(robot_x).at(robot_y).set_wall(WEST,Simulator::wallLeft());
    }
    // east - cannot check west
    if (robot_dir == EAST){
        maze.at(robot_x).at(robot_y).set_wall(EAST,Simulator::wallFront());
        maze.at(robot_x).at(robot_y).set_wall(SOUTH,Simulator::wallRight());
        maze.at(robot_x).at(robot_y).set_wall(NORTH,Simulator::wallLeft());
    }
    // south - cannot check north
    if (robot_dir == SOUTH){
        maze.at(robot_x).at(robot_y).set_wall(SOUTH,Simulator::wallFront());
        maze.at(robot_x).at(robot_y).set_wall(WEST,Simulator::wallRight());
        maze.at(robot_x).at(robot_y).set_wall(EAST,Simulator::wallLeft());
    }
    // west - cannot check east
    if (robot_dir == WEST){
        maze.at(robot_x).at(robot_y).set_wall(WEST,Simulator::wallFront());
        maze.at(robot_x).at(robot_y).set_wall(NORTH,Simulator::wallRight());
        maze.at(robot_x).at(robot_y).set_wall(SOUTH,Simulator::wallLeft());
    }
    for (int i = 0; i < 4 ; i++){
        if (maze.at(robot_x).at(robot_y).is_wall(i)){
            Simulator::setWall(robot_x,robot_y,directions.at(i));
        }
    }
}
std::array<int,3> rwa2::Robot::get_curr_loc(){
    std::array<int,3> coords = {robot_x,robot_y,robot_dir};
    std::cerr<< "Current location: (" << robot_x << " , " << robot_y << ")" <<std::endl;
    return coords;
}
bool rwa2::Robot::search_maze(std::string argument){
    auto goal = generate_goal();
    std::array<int,3> curr_location = get_curr_loc();
    std::string left = "left";
    std::string right = "right";
    while (!((curr_location[0] == goal.first) && (curr_location[1] == goal.second))){
        if (argument.compare(right) == 0){
            // std::cerr<< "right" << std::endl;
            if(!move_robot(RIGHT)){
                return false;
            }
            else{
                visited.emplace_back(curr_location);
                visited.shrink_to_fit();
            }
        }
        else{
            // std::cerr<< "left" << std::endl;
            if(!move_robot(LEFT)){
                return false;
            }
            else{
                visited.emplace_back(curr_location);
                visited.shrink_to_fit();
            }
        }
        curr_location = get_curr_loc();
        Simulator::setColor(curr_location.at(0),curr_location.at(1),'c');
    }
    std::cerr << "----- GOAL REACHED -----" << std::endl;
    return true;  
}

bool rwa2::Robot::move_robot(bool left_following = true){
    auto curr_location = get_curr_loc();
    if (visited.capacity() > 0){
        for (int i = 0; i < visited.capacity();i++){
            if (visited.at(i) == curr_location){
                return false;
            }
        }
    }
    check_walls();
    if (left_following){
        if (robot_dir == NORTH){
            if(!maze.at(robot_x).at(robot_y).is_wall(WEST)){
                turn_left();
                move_forward();
                robot_x --;
                robot_dir = WEST;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(NORTH)){
                move_forward();
                robot_y ++;
                robot_dir = NORTH;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(EAST)){
                turn_right();
                move_forward();
                robot_x ++;
                robot_dir = EAST;
                return true;
            }
            else{
                turn_left();
                turn_left();
                move_forward();
                robot_y --;
                robot_dir = SOUTH;
                return true;
            }
        }
        if(robot_dir == EAST){
            if(!maze.at(robot_x).at(robot_y).is_wall(NORTH)){
                turn_left();
                move_forward();
                robot_y ++;
                robot_dir = NORTH;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(EAST)){
                move_forward();
                robot_x ++;
                robot_dir = EAST;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(SOUTH)){
                turn_right();
                move_forward();
                robot_y --;
                robot_dir = SOUTH;
                return true;
            }
            else{
                turn_left();
                turn_left();
                move_forward();
                robot_x --;
                robot_dir = WEST;
                return true;
            }
        }
        if (robot_dir == SOUTH){
            if(!maze.at(robot_x).at(robot_y).is_wall(EAST)){
                turn_left();
                move_forward();
                robot_x ++;
                robot_dir = EAST;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(SOUTH)){
                move_forward();
                robot_y --;
                robot_dir = SOUTH;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(WEST)){
                turn_right();
                move_forward();
                robot_x --;
                robot_dir = WEST;
                return true;
            }
            else{
                turn_left();
                turn_left();
                move_forward();
                robot_y ++;
                robot_dir = NORTH;
                return true;
            }
        }
        if(robot_dir == WEST){
            if(!maze.at(robot_x).at(robot_y).is_wall(SOUTH)){
                turn_left();
                move_forward();
                robot_y --;
                robot_dir = SOUTH;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(WEST)){
                move_forward();
                robot_x --;
                robot_dir = WEST;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(NORTH)){
                turn_right();
                move_forward();
                robot_y ++;
                robot_dir = NORTH;
                return true;
            }
            else{
                turn_left();
                turn_left();
                move_forward();
                robot_x ++;
                robot_dir = EAST;
                return true;
            }
        }
    }
    else{ 
        if (robot_dir == NORTH){
                      
            if(!maze.at(robot_x).at(robot_y).is_wall(EAST)){
                turn_right();
                move_forward();
                robot_x ++;
                robot_dir = EAST;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(NORTH)){
                move_forward();
                robot_y ++;
                robot_dir = NORTH;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(WEST)){
                turn_left();
                move_forward();
                robot_x --;
                robot_dir = WEST;
                return true;
            }
            else{
                turn_right();
                turn_right();
                move_forward();
                robot_y --;
                robot_dir = SOUTH;
                return true;
            }
        }
        if(robot_dir == EAST){
            if(!maze.at(robot_x).at(robot_y).is_wall(SOUTH)){
                turn_right();
                move_forward();
                robot_y --;
                robot_dir = SOUTH;
                return true;
            }            
            else if(!maze.at(robot_x).at(robot_y).is_wall(EAST)){
                move_forward();
                robot_x ++;
                robot_dir = EAST;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(NORTH)){
                turn_left();
                move_forward();
                robot_y ++;
                robot_dir = NORTH;
                return true;
            }
            else{
                turn_right();
                turn_right();
                move_forward();
                robot_x --;
                robot_dir = WEST;
                return true;
            }
        }
        if (robot_dir == SOUTH){
            if(!maze.at(robot_x).at(robot_y).is_wall(WEST)){
                turn_right();
                move_forward();
                robot_x --;
                robot_dir = WEST;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(SOUTH)){
                move_forward();
                robot_y --;
                robot_dir = SOUTH;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(EAST)){
                turn_left();
                move_forward();
                robot_x ++;
                robot_dir = EAST;
                return true;
            }
            else{
                turn_right();
                turn_right();
                move_forward();
                robot_y ++;
                robot_dir = NORTH;
                return true;
            }
        }
        if(robot_dir == WEST){
            if(!maze.at(robot_x).at(robot_y).is_wall(NORTH)){
                turn_right();
                move_forward();
                robot_y ++;
                robot_dir = NORTH;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(WEST)){
                move_forward();
                robot_x --;
                robot_dir = WEST;
                return true;
            }
            else if(!maze.at(robot_x).at(robot_y).is_wall(SOUTH)){
                turn_left();
                move_forward();
                robot_y --;
                robot_dir = SOUTH;
                return true;
            }
            else{
                turn_right();
                turn_right();
                move_forward();
                robot_x ++;
                robot_dir = EAST;
                return true;
            }
        }
    }
    return 1;
}