/*
Conveyor Slot detection using Sensor Inputs
You are tasked with developing a module that simulates and analyzes 
a conveyor belt system with multiple slots. Each slot can hold one item,
and each item's presence is detected using a digital sensor (1=present, 0=absent).
The conveyor moves at a fixed intervals, and your program shoud monitor senors inputs
and maintain the status of each slot in real time

*/
/* Thought process:
1.In a class conveyor, maintaining an array of slots.
2.Each slot is represented by a boolean value indicating presence & absence of an item.
3.So over a time, each slot will update its status based on sensor input and track the change if any.
-Layer 1:   for each time step:
                Readsenor values for that time
                compare with previous values to map changes.
Layer 2:    for each slot:
                Read the current value
                Compare with previous value.
                output status and change if any.

*/
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

class Conveyor {
    public:
        vector<bool>slots;//Array to hold status of each slot
        int size;//size of conveyor slots
        int time_ticks = 0; //time ticks to simulate conveyor movement
        bool changeStatus;//flag indicating whether there is a change in status
};

int main()
{
    //Intializing input section
    cout << "Conveyor Slot Detection System" << endl;
    Conveyor conveyor;
    //Here for simplicity, assuming fixed values of time ticks and size of conveyor slots
    //In a real-world scenario, these could be dynamic or user-defined.
    conveyor.time_ticks=6;//number of time ticks to simulate
    conveyor.size=5; //size of conveyor slots

    std::cout<< "Enter the values for the slots (0 or 1): ";
    for(int i=0;i<conveyor.size;i++)
    {
        int inputValue;
        std::cin>> inputValue;
        if(inputValue==0||inputValue==1){
            conveyor.slots.push_back(static_cast<bool>(inputValue));
        } else {
            std::cout << "Invalid input. Please enter 0 or 1." << std::endl;
            i--; // Decrement i to repeat the input for the same slot
        }
    }

    //Logic to monitor and update the conveyor slots
    for(int t=0;t<conveyor.time_ticks;t++)
    {
        conveyor.changeStatus = false; // Reset change status for each time tick
        std::cout << "Time Tick: " << t+1 << std::endl;
        std::cout << "Current Slot Status: ";
        
        for(int i=0;i<conveyor.size;i++)
        {
            bool currentValue = conveyor.slots[i];
            std::cout << currentValue << " ";
            // Simulating a change in slot status for demonstration purposes
            if (t % 2 == 0) { // Change every even time tick
                currentValue = !currentValue; // Toggle the value
                conveyor.changeStatus = true; // Set change status to true
            }
            conveyor.slots[i] = currentValue; // Update the slot status
        }
        
        std::cout << std::endl;
        
        if(conveyor.changeStatus)
        {
            std::cout << "Change detected in slot status!" << std::endl;
        }
        
        // Simulate conveyor movement delay
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    

}
