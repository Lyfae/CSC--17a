/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: serva
 *
 * Created on September 22, 2019, 6:05 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
//prototype 
int *aryAll(int);
int main(int argc, char** argv) {

    
    return 0;
}

int *aryAll(int num){
    //check if the number is zero or negative
    if(num <=0){
        return nullptr;
    }
    //otherwise, allocate memory
    int *ptr = new int[num];
    //return to pointer
    return ptr; 
}