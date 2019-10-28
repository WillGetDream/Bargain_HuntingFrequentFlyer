#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
using namespace std;
#define earthRadiusKm 3958.75

// This function converts decimal degrees to radians
double deg2rad(double deg) {
    return (deg * M_PI / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
    return (rad * 180 / M_PI);
}

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
    double lat1r, lon1r, lat2r, lon2r, u, v;
    lat1r = deg2rad(lat1d);
    lon1r = deg2rad(lon1d);
    lat2r = deg2rad(lat2d);
    lon2r = deg2rad(lon2d);
    u = sin((lat2r - lat1r)/2);
    v = sin((lon2r - lon1r)/2);
    return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

struct airport{
    string name;
    float latpos[3];
    float logpos[3];
    float  lat,log;

};
int main() {
   //DD = d + (min/60) + (sec/3600)
   vector<airport> airports;
    airport air;
   cin>>air.name;
   while(air.name.compare("---")){
       char tmp;
       cin>>air.latpos[0]>>air.latpos[1]>>air.latpos[2];
       cin>>tmp;
       cin>>air.logpos[0]>>air.logpos[1]>>air.logpos[2];
       cin>>tmp;
       airports.push_back(air);
       cin.ignore();
       cin>>air.name;
   }
   cout<<airports.size();

   //change to dd
    vector<airport>::iterator itr;
    for(itr=airports.begin();itr!=airports.end();itr++){
        itr->log=itr->logpos[0]+(itr->logpos[1]/60)+(itr->logpos[2]/3600);
        itr->lat=itr->latpos[0]+(itr->latpos[1]/60)+(itr->latpos[2]/3600);
    }


    cin.get();
    while(!cin.eof()){

        vector<string> locations;
        vector<string>::iterator itr5;

        char s[4];

        while(cin.peek()!='\n'){
            cin.get(s,4,' ');
            if(cin.peek()==' ')cin.get();

            string str(s);
            cout<<str<<endl;
            locations.push_back(str);
        }
        cin.get();

        float ds=0;
        for(int i=0;i<locations.size()-1;i++){
             airport ai[2];
            for(itr=airports.begin();itr!=airports.end();itr++){
                if(!locations.at(i).compare((itr->name))){
                    ai[0]=*itr;
                };
                if(!locations.at(i+1).compare((itr->name))){
                    ai[1]=*itr;
                };
            }
            cout<<ai[0].name<<"->"<<ai[1].name<<endl;
            cout<<ai[0].lat<<" "<<ai[0].log<<" "<<ai[1].lat<<" "<<ai[1].log<<endl;
            ds+=distanceEarth(ai[0].lat,ai[0].log,ai[1].lat,ai[1].log);
            cout<<ds<<endl;
        }
        cout<<ds<<endl;

    }



    return 0;
}