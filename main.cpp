#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string test, cdate;
    cdate = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + "-" + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min);
    vector<string> temp;
    ifstream infile;
    ofstream outfile;
    outfile.open("output/Ingram-" + cdate + ".csv");
    infile.open("input.csv");
    outfile << "SKU,VPN,Quantity\n";
    while (getline(infile, test))
    {
        temp.clear();
        char delimiter = ',';
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
        for (int i = 0; i < temp.size(); i++)
        {
            //outfile << temp[i] << endl;
        }
        outfile << temp[1] << ',' << temp[0] << ',' << temp[2] << endl;
    }
    return 0;
}
