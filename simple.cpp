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
#include "MyGenie.h"
#include "genie/dat/DatFile.h"

using namespace std;

static const char INPUT_STRING[] = "/data/aoe_images/my.png";

#define MAXSIZE 210

char* get_machine()
{
    static char machine[MAXSIZE];
    size_t len = sizeof(machine);
    
    return machine;
}

int load_dat(void* ptr, char *filename)
{
    MyGenie *g = static_cast<MyGenie*> (ptr);
    
    g->df = new genie::DatFile();
    g->df->setGameVersion(genie::GV_LatestDE2);
    
    g->df->load(filename);

    int i = 0;
    std::set<std::uint32_t> used;

    Data data; 
    
    
    
    for (genie::Civ civ : g->df->Civs) {
        if (civ.Name != "Gaia") {
            long unitsize = civ.Units.size();
            long unitctr = 0;
            
            for (genie::Unit unit : civ.Units) {
                unitctr++;
                
                if (used.find(unit.BaseID) != used.end()) {
                    continue; 
                } else {
                    used.insert(unit.BaseID);
                }
                
                
                if ((unit.BaseID == 38
                     || unit.BaseID == 4
                     || unit.BaseID == 6
                     || unit.BaseID == 7
                     || unit.BaseID == 8                 
                     || unit.BaseID == 93
                     || unit.BaseID == 358
                     || unit.BaseID == 359
                     || unit.BaseID == 329
                     || unit.BaseID == 330
                     || unit.BaseID == 207
                     || unit.BaseID == 282
                     || unit.BaseID == 291
                     || unit.BaseID == 567
                     || unit.BaseID == 752
                     || unit.BaseID == 1234
                     || unit.BaseID == 1747
                     || unit.BaseID == 1007
                     || (data.whiteListMap.find(unit.BaseID) != data.whiteListMap.end())
                     )) {
                    i++;
                    cout << "---------------" << endl;
                    cout << unit.Name << ", " << data.unitNames[unit.BaseID] << ", Speed: " << unit.Speed << endl;
                    data.unitMap[unit.BaseID] = unit;
                    data.nameMap[unit.Name] = unit.BaseID;
                }
                
            }
        } 
    }    
    
    return 0;
}
