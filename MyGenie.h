#ifndef MY_GENIE_H
#define MY_GENIE_H

#include<vector>
#include "genie/dat/DatFile.h"
#include "data.h"

using namespace std;

class MyGenie {
 public:
    MyGenie();
    ~MyGenie();

    int load(char* filename);

    genie::DatFile *df; 

};

#endif
