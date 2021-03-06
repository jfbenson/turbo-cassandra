#include "player.h"

#include <bitset>
#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

player_t player_populate(string row)
{
    player_t p;
    vector<string> parts;
    split(parts, row, is_any_of("\t"));

    p.name = parts[0];

    p.pos_ids = 0;
    p.pos_ids |= (parts[1].find("PG") != string::npos) ? P_PG : 0;
    p.pos_ids |= (parts[1].find("SG") != string::npos) ? P_SG : 0;
    p.pos_ids |= (parts[1].find("SF") != string::npos) ? P_SF : 0;
    p.pos_ids |= (parts[1].find("PF") != string::npos) ? P_PF : 0;
    p.pos_ids |= (parts[1].find("C") != string::npos) ? P_C : 0;


    istringstream sal(parts[3]);
    sal.imbue(locale("en_US.UTF-8"));
    sal >> get_money(p.salary);

    p.proj_pts = stold(parts[15]);

    return p;
}

void player_print(player_t &p)
{
    cout << p.name;
    cout << "\t" << bitset<5>((int)p.pos_ids);
    cout << "\t" << p.salary;
    cout << "\t" << p.proj_pts << endl;
}
