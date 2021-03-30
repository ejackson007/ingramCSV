#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>

using namespace std;

time_t now = time(0);
tm *ltm = localtime(&now);
string test, cdate;
vector<string> temp;

void ingram(ofstream &outfile, ifstream &infile){
    outfile.open("output/Ingram-" + cdate + ".csv");
    infile.open("input.csv");
    outfile << "SKU,VPN,Quantity\n";
    while (getline(infile, test))
    {
        temp.clear();
        char delimiter = '\t';
        size_t pos = 0;
        int count = 0;
        string token;
        while ((pos = test.find(delimiter)) != string::npos)
        {
            count++;
            token = test.substr(0, pos);
            //outfile << token << " " << count << endl;
            test.erase(0, pos + 1);
            temp.push_back(token);
        }
        //remove excess
        temp.erase(temp.end() - 12, temp.end());
        temp.erase(temp.begin());
        temp.erase(temp.begin() + 2, temp.end() - 1);
        outfile << temp[1] << ',' << temp[0] << ',' << temp[2] << endl;
    }
    outfile.close();
    infile.close();
}

void techdata(ofstream &outfile, ifstream &infile){
    outfile.open("output/TechData-" + cdate + ".csv");
    infile.open("input.csv");
    outfile << "SKU\n";
    while (getline(infile, test))
    {
        temp.clear();
        char delimiter = '\t';
        size_t pos = 0;
        int count = 0;
        string token;
        while ((pos = test.find(delimiter)) != string::npos)
        {
            count++;
            token = test.substr(0, pos);
            //outfile << token << " " << count << endl;
            test.erase(0, pos + 1);
            temp.push_back(token);
        }
        //remove excess
        temp.erase(temp.end() - 12, temp.end());
        temp.erase(temp.begin());
        temp.erase(temp.begin() + 2, temp.end() - 1);
        outfile << temp[1] << endl;
    }
    outfile.close();
    infile.close();
}

void synnex(ofstream &outfile, ifstream &infile){
    outfile.open("output/Synnex-" + cdate + ".csv");
    infile.open("input.csv");
    outfile << "SKU,QTY\n";
    while (getline(infile, test))
    {
        temp.clear();
        char delimiter = '\t';
        size_t pos = 0;
        int count = 0;
        string token;
        while ((pos = test.find(delimiter)) != string::npos)
        {
            count++;
            token = test.substr(0, pos);
            //outfile << token << " " << count << endl;
            test.erase(0, pos + 1);
            temp.push_back(token);
        }
        //remove excess
        temp.erase(temp.end() - 12, temp.end());
        temp.erase(temp.begin());
        temp.erase(temp.begin() + 2, temp.end() - 1);
        outfile << temp[1] << ',' << temp[2] << endl;
    }
    outfile.close();
    infile.close();
}

int main(int argc, char** argv)
{
    cdate = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + "-" + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min);
    ifstream infile;
    ofstream outfile;
    //cout << argv[1] << " argument\n";
    
    if(string(argv[1]) == "I"){
        //cout << "in ingram\n";
        ingram(outfile, infile);
    }
    else if(string(argv[1]) == "T"){
        //cout << "in techdata\n";
        techdata(outfile, infile);
    }
    else if(string(argv[1]) == "S"){
        //cout << "in synnex\n";
        synnex(outfile, infile);
    }
    
    return 0;
}
