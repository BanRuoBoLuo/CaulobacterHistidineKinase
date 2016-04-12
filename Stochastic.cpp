//**********************************************************
//Main program of Caulobacter crescentus cell cycle model
//
//For model details please refer to 
//
//A Stochastic Spatiotemporal Model of a Response-Regulator Network 
//in the Caulobacter crescentus Cell Cycle
//Fei Li , Kartik Subramanian, Minghan Chen, John J. Tyson, Yang Cao
//
//Physical Biology, special issue of 2015 q-bio 
//
//coded by: Fei Li
//felix@cs.vt.edu
//Dec 4, 2015
//***********************************************************


#include <cstdio>
using std::sprintf;

#include <string>
using std::string; 

#include <cstring>
using std::strcpy; 
using std::strcat;

#include <cstdlib>
using std::system;
using std::srand;

#include <ctime>
using std::time;

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include "PleC.h"

int main(int argc, char* argv[]){

  PleC pc;

  //****************************************
  //seed the random variable
  //****************************************
  srand(time(NULL));

    pc.InitStage();
    pc.initSpatial();
    pc.DNAorigination();

    //********************************************
    //Fixed Length Stage for cell initiation
    //********************************************
    pc.cellFixed();
    pc.SSA(150, 1.0);

    //*******************************************
    //Simulatio of wild type cells
    //*******************************************
    pc.cellGrowth(); 
    pc.SSA(30.0, 1.0);

    pc.introDivJ();
    pc.SSA(20.0, 1.0);

    //********************************************
    //gene replication in 50 min
    //********************************************
    pc.DNAreplication();

    pc.clearPleC();
    pc.SSA(40.0, 1.0);


    pc.checkPoint3();
    pc.SSA(30.0, 1.0);


    pc.compartmentization();
    pc.SSA(30.0, 1.0);

    return 0;
}
