/* Solver.cpp
 *
 * CS 121.Bolden...........Jackson Staples
 * 4/10/2024 .................stap2053@vandals.uidaho.edu
 *
 * Program to take mazes from text files and Find a path through them
 * using a queue and dynamic arrays.
 *---------------------------------------------------------------------
 */



#include "queue.h"
#include<iostream>
#include<string>

using namespace std;


void Queue::Enqueue(){
    MazeQueuePtr newNode = new MazeQueue;

    n-> info = x;
    n-> next = NULL;
    count++;
}