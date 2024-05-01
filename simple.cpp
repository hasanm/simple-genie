// C program to display hostname
// and IP address
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "simple.h"
#include "data.h"
#include "ids.h"

using namespace std;

static const char INPUT_STRING[] = "/data/aoe_images/my.png";

#define MAXSIZE 210
 
char* get_machine()
{
    static char machine[MAXSIZE];
    size_t len = sizeof(machine);
 
    return machine;
}

int load_dat(void* container, char *filename)
{
    return 0;
}
