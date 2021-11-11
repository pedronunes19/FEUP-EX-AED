#include <iostream>
#include <vector>

using namespace std;

bool is_number(const std::string& s)  // thanks stackoverflow
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int diff(const vector<string> & m1, const vector<string> & m2){
    long long value1 = 0, value2 = 0, gen_bump = 5290000;
    // determine gens
    if (is_number(m1.at(0)) && !is_number(m1.at(2)))
        value1 += gen_bump;
    else if (!is_number(m1.at(1)))
        value1 += (gen_bump*2);
    else if (!is_number(m1.at(0)) && !is_number(m1.at(2)))
        value1 += (gen_bump*3);
    if (is_number(m2.at(0)) && !is_number(m2.at(2)))
        value2 += gen_bump;
    else if (!is_number(m2.at(1)))
        value2 += (gen_bump*2);
    else if (!is_number(m2.at(0)) && !is_number(m2.at(2)))
        value2 += (gen_bump*3);

    // calculate the value (how far it is from it's gen's first value)

}

int main(){
    vector <char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X','Z'};
    vector<string> f_gen1 = {"AA", "00", "00"};
    vector<string> l_gen1 = {"ZZ", "99", "99"};
    vector<string> f_gen2 = {"00", "00", "AA"};
    vector<string> l_gen2 = {"99", "99", "ZZ"};
    vector<string> f_gen3 = {"00", "AA", "00"};
    vector<string> l_gen3 = {"99", "ZZ", "99"};
    vector<string> f_gen4 = {"AA", "00", "AA"};
    vector<string> l_gen4 = {"ZZ", "99", "ZZ"};
    int t;
    vector<int> res;
    cin >> t;
    for (int i=1;i<=t;i++){
        char useless;
        string s1, s2, s3, s4, s5, s6;
        vector<string> m1, m2;
        cin >> s1 >> useless >> s2 >> useless >> s3 >> s4 >> useless >> s5  >> useless >> s6;
        m1.push_back(s1); m1.push_back(s2); m1.push_back(s3); m2.push_back(s4); m2.push_back(s5); m2.push_back(s6); 
        res.push_back(diff(m1, m2));
    }
    for (int i = 0; i< res.size(); i++){
        cout << res.at(i) << endl;
    }
    return 0;
}

