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

static const char UNITS_FILENAME[] = "/data/aoe/units.txt";

#define MAXSIZE 210

char* get_machine()
{
    static char machine[MAXSIZE];
    size_t len = sizeof(machine);

    return machine;
}

void* load_dat(char *filename)
{
    MyGenie *g = new MyGenie;
    ofstream myfile;
    try {
        myfile.open(UNITS_FILENAME);
        g->df = new genie::DatFile();
        g->df->setGameVersion(genie::GV_LatestDE2);

        g->df->load(filename);

        int i = 0;
        std::set<std::uint32_t> used;


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
                         || (g->data.whiteListMap.find(unit.BaseID) != g->data.whiteListMap.end())
                         )) {
                        i++;
                        // cout << "---------------" << endl;
                        // cout << unit.Name << ", " << g->data.unitNames[unit.BaseID] << ", Speed: " << unit.Speed << endl;
                        myfile << unit.Name << "," << g->data.unitNames[unit.BaseID] << endl;
                        g->data.unitMap[unit.BaseID] = unit;
                        g->data.nameMap[unit.Name] = unit.BaseID;
                    } else {
                        myfile << unit.Name << "," << unit.BaseID << endl;
                    }


                }
            }
        }
        myfile.close();
    } catch(const exception& e) {
        cout << "Caught Exception " << endl;
        cerr << e.what();
        return g;
    }

    return g;
}

int get_unit(void* ptr, char *unit_name)
{
    MyGenie *g = static_cast<MyGenie*> (ptr);

    string s (unit_name);
    std::uint32_t id = g->data.nameMap[s];
    cout << unit_name << ", " << id << endl;

    genie::Unit unit = g->data.unitMap[id];


    for (genie::unit::AttackOrArmor attack : unit.Type50.Attacks) {
        cout << "Attack : " << g->data.armorNames[attack.Class] <<  ", "  << attack.Class << " => "  << attack.Amount << endl;
    }

    for (genie::unit::AttackOrArmor armor : unit.Type50.Armours) {
        cout << "Armor : " << g->data.armorNames[armor.Class]<< ", "<< armor.Class << " => "  << armor.Amount << endl;
    }

    return 0;
}



int print_all(void* ptr)
{
    MyGenie *g = static_cast<MyGenie*> (ptr);
    for (auto i : g->data.nameMap) {
        cout << i.first << endl;
    }
    return 0;
}
