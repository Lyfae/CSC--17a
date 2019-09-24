/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: serva(paulthai)
 *
 * Created on September 22, 2019, 5:40 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
//prototype
void prntAry(int[], int);
void sortAry(int[], int);
void median(int[], int);
void mode(int[], int);
void mean(int[], int);

int main(int argc, char** argv) {
  
  int bob[5] = {1,3,2,1,5};
  //int *bob = new int[5];
  //sort the array
  sortAry(bob,5);
  //print the array
  prntAry(bob,5);
  //calculate the mean, median, and mode
    mean(bob,5);
    median(bob,5);
    mode(bob, 5);
  
  return 0;
}

//sort array
void sortAry(int bob[], int size){
  bool notSrt;
  do{                               
    notSrt = false;       //when we loop, assume the array is sorted
    for(int i=0; i<size-1; i++){
      if(bob[i]>bob[i+1]){
        int temp;    //only use when swapping
        temp = bob[i];
        bob[i]=bob[i+1];
        bob[i+1]=temp; 
        notSrt=true; 
      }//if statement
    }//for loop
  }while(notSrt==true);
  
}
//print array
void prntAry(int bob[], int size){
  for(int i=0; i<size; i++){
    cout<<bob[i]<<" "; 
  }
  cout<<endl;
}
//find mean
void mean(int bob[], int size){
  float sum; 
  for(int i=0; i<size;i++){
    sum +=bob[i];
  }
  sum = sum/size;
  cout<<"The mean is: "<<sum<<endl;
} 
//find median
void median(int bob[], int size){
  int middle; 
  middle = size/2; 
  cout<<"The Median is: "<<bob[middle]<<endl;
}
//find mode
void mode(int bob[], int size){
  int count=0; 
  int value=0;
  
  int tempCount = 0;
  int tempValue = 0;
  
  for(int i=0; i<size; i++){
    if (tempValue == bob[i]) {
      tempCount++;
    } else {
      if (tempCount > count) {
        count = tempCount;
        value = tempValue;
      }

      tempValue = bob[i];
      tempCount = 1;
    }
  }
  
  cout <<"The Mode is: "<<value<< endl;
}