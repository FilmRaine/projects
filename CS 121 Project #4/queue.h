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

class queue
{
    public:
        void Dequeue();
        void Enqueue();    
    private:
        struct mazeQueue
        {
           // remember! you can copy over the stack class for this
           // don't create extra work for yourself. 
           // change push to add to back, and then rename stuff
           // so you don't get lost. 
        }
};
#endif