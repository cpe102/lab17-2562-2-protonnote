#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string tolower_for_str (string x){
    string y = x;
    for (int i = 0 ; i < x.size() ; i++)
    {
        y[i] = tolower(x[i]);
    }
    return y;
}

int main(){
    ifstream name1;
    name1.open("name_score.txt");
    string textline;
    char name [100];
    vector <string> name_list;
    vector <float> score_list;
    vector <string> g_list;
    while (getline(name1,textline)){
    	float a,b,c,sum;
        string grade;
    	char format [] = "%[^:]: %f %f %f";
        sscanf (textline.c_str() , format , name , &a , &b , &c);
        sum = a + b + c ;
        if(sum > 80) grade = "A";
            else if (sum > 70) grade = "B";
            else if (sum > 60) grade = "C";
            else if (sum > 50) grade = "D";
            else grade = "F";
        g_list.push_back(grade.c_str());
        score_list.push_back(sum);
        name_list.push_back(name);
    }
    string a;
    for(int b = 0 ; ; b++){
        for (int i=0 ; ; i++){
            cout << "Please input your command : ";
            getline (cin,a);
            a = tolower_for_str (a);
            if ( a.substr(0,5) == "grade" ) break;
                else if (a.substr(0,3) == "name") break;
                else cout << "Invalid command " << endl;
        }
        cout << "---------------------------------" << endl;
        if (a.substr(6,1) == "a" || a.substr(6,1) == "b" || a.substr(6,1) == "c" || a.substr(6,1) == "d" || a.substr(6,1) == "f" ){   
            for (int j = 0 ; j < g_list.size() ; j++){
                for (int f = 0 ; f < g_list.size() ; f++){
                    g_list[f] = tolower_for_str (g_list[f]);
                }
                if (a.substr(6,1) == g_list[j]) cout << name_list[j] << endl;
                //else cout << "Cannot found" << endl;
            }
            cout << "---------------------------------" << endl;
        }
        for (int z = 0 ; z < name_list.size() ; z++){
            if (a.substr(3,a.size()-5) == name_list[z]){   
                for (int k = 0 ; k < g_list.size() ; k++){
                    if (a.substr(5) == name_list[k]) cout << name_list[k] << "grade = " << g_list[k];
                    //else cout << "Cannot found" << endl;
                } 
                cout << "---------------------------------";
            }
        }
        if ( a == "exit") break;
    }
    return 0;
}