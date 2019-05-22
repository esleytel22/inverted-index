#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	map<string, vector<pair<int, int> > > dict;
	string line, word;
	stringstream stream;
	ifstream myfile("input.txt");
	ofstream out;
	out.open("output.txt");
	int line_num = -1, word_num = 0;

	if (myfile.is_open())
	{
		while (getline(myfile, line)) {
			stringstream stream(line);
			line_num++; word_num = -1;
			while (stream >> word) {
				word_num++;
				dict[word].push_back(make_pair(line_num, word_num));
			}
		}
	}
	
	for (pair<string, vector<pair<int, int> > > p : dict) {
		out << p.first << " " << p.second.size() << "[";
		for (int i = 0; i < p.second.size(); ++i) {
			out << "(" << p.second[i].first << "," << p.second[i].second << ")";
			if (i != p.second.size() - 1) {
				out << ",";
			}
		}
		out << "]" << endl;
	}
	out.close();
	myfile.close();
	std::cout << "done";
	cin.get();

	return 0;
}