//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap 
{
    int data[64];
    int size;

    MinHeap() { size = 0; }

    // Helper method to compare weights of two indices
    bool compare(int weightArr[], int i, int j) 
    {return weightArr[data[i]] < weightArr[data[j]];} // Is i less than j? then true

    void push(int idx, int weightArr[]) 
    {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;               // Insert new index at the end
        size++;
        upheap(size - 1, weightArr);    // Call upheap to maintain heap property, move new element up if its smaller than parent
    }

    int pop(int weightArr[]) 
    {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        data[0] = data[size - 1];       // Replace root with last element to maintain struct of the heap (the only element you can remove from the tree that keeps it "complete" is the very last leaf)
        size--;
        downheap(0, weightArr);         // Fix the order
        return data[size];              // Return the smallest index
    }

    void upheap(int pos, int weightArr[]) 
    {
        // TODO: swap child upward while smaller than parent
        if (pos >= size) return;        // If pos is out of bounds, return
        if (pos == 0) return;           // If at root, no need to upheap

        while( pos >0)
        {
            int p = (pos - 1) / 2;          // Calculate parent index
            if (compare(weightArr, pos, p)) // Compare pos less than parent
            {
                swap(data[pos], data[p]);   // Swap if child is smaller than parent
                pos = p;                    // Update pos to parent index
            } else
            {return;}
        }
        
    }

    void downheap(int pos, int weightArr[]) 
    {
        // TODO: swap parent downward while larger than any child
        if (pos >= size) return;         // If pos is out of bounds, return
        if (pos == 0) return;            // If at root, no need to downheap
        while (pos < size)
        {
            int left = 2 * pos + 1;         // Calculate left child index
            int right = 2 * pos + 2;        // Calculate right child index
            int smallest = pos;             // Assume current pos is smallest

            if (left < size && weightArr[left] < weightArr[smallest])
                smallest = left;
            if (right < size && weightArr[right] < weightArr[smallest])
                smallest = right;
            if (smallest == pos)
                return;                     // If current pos is smallest, return
            swap(data[pos], data[smallest]);// swap the parent with the smallest child
            pos = smallest;                 // Update pos to the smallest child index
        }
    }
};

#endif