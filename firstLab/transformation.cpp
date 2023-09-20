#include <iostream>

using namespace std;

string transformation(int h, int m, string p){
    if (h >= 1 && h <= 12 && m <= 59 && m >= 0 && (p == "am" || p == "pm")){
        string ziro = "";
        if (p == "pm"){
            if (h == 12){
                h = 0;
                ziro = "0";
            }else {
                h += 12;
            }
        }else{
            if (h<=9){
                ziro = "0";
            }
        }
        if (m <= 9){
            return ziro+to_string(h)+"0"+to_string(m);
            //cout << to_string(h)+"0"+to_string(m) << endl;
            //cout << h << ":0" << m << endl;
            //return 1;
        } else {
            return ziro+to_string(h)+to_string(m);
            //cout << to_string(h)+":"+to_string(m) << endl;
            //cout << h << ":" << m << endl;
            //return 2;
        }
    }else{
       return "error"; 
    }
}