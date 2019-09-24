/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: serva
 *
 * Created on September 22, 2019, 6:50 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
//prototype
void arySort(float*, int);
float avg(float*, int);

int main(int argc, char** argv) {
    //declare variable
    int test; 
    //inputs
    cout<<"Input the number of tests"<<endl;
    cin>>test; 
    
    //make a big array;
    float *tstScr = new float[test];
    //read array
    for(int i=0; i<test; i++){
        cout<<"Test "<<i+1<<" = ";
        cin>> *(tstScr+i);
        //if scores are negative
    while(tstScr<0){
        cout<<"Test can only be entered as a positive number or zero."<<endl;
        cout<<"Enter again... "<< endl;
        cin>> *(tstScr+i);
        }         
    }
    //sort array
    arySort(tstScr, test);
    //display array
    cout<<endl;
    cout<<"Here are the scores: "<<endl;
    for(int i=0; i<test; i++){
        cout<< *(tstScr+i)<<" ";
    }
    cout<<endl;
    //display the average
    cout<<"The average test scores are "<<avg(tstScr, test)<<" out of "<<test<<" tests."<<endl;
    return 0;
}

//sort array
void arySort(float *ptr, int size){
    //temporary variable to deal with swapping
    float temp; 
    //bool => array when done sorting
    bool swap = true; 
    
    while(swap){
        swap = false; 
        for(int i=0; i<size-1; i++){
            if(*(ptr+i)> *(ptr+i+1)){
            temp = *(ptr+i+1);
            *(ptr+i+1) = *(ptr+i);
            *(ptr+i) = temp;   
            //update the bool
            swap = true;
            }  //if                     
        }//for
    }//while
}

float avg(float *ptr, int size){
    float tot = 0; 
    //loop array values
    for(int i=1; i<size; i++){
        tot += *(ptr+i);
    }
    //(prevent number division)
    //manipulate the size to exclude the lowest number
    return(float)tot/(size-1); 
}