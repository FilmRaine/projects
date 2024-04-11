/* queue.h
 *
 * CS 121.Bolden...........Jackson Staples
 * 4/10/2024 .................stap2053@vandals.uidaho.edu
 *
 * interface file
 *---------------------------------------------------------------------
*/


#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

class Queue
{
    public: 
        Queue(){
            top = NULL;
        }

        void Enqueue();
        void Dequeue();
        void Print(); 
    private:
        struct mazeQueue
        {
            int size;
            int head = 0;
            int tail = 0;
            struct mazeQueue* ptr;
           // remember! you can copy over the stack class for this
           // don't create extra work for yourself. 
           // change push to add to back, and then rename stuff
           // so you don't get lost. 
        };
        typedef struct mazeQueue MazeQueue;
        typedef MazeQueue *MazeQueuePtr;
        MazeQueuePtr top;
};
#endif