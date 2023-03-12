#include "pairwise_cosine_dist.h"

using namespace std;

double dist_cos(const vector<double>& first_, const vector<double>& second_) {
    double sum = 0.0, begin = 0.0, end = 0.0;
    for (int i = 0; i < first_.size(); i++) {
        sum += first_[i] * second_[i];
        begin += first_[i] * first_[i];
        end += second_[i] * second_[i];
    }
    double total= (sqrt(begin) * sqrt(end));
    return sum / total;
}

vector<vector<double>> accessing_file(string txt_file) {
    vector<vector<double>> vects;
    ifstream open_file(txt_file);
    string s;
    while (getline(open_file, s)) {
        double each;
        istringstream fl(s);
        vector<double> v2;

        while (fl >> each) {
            v2.push_back(each);
        }
        vects.push_back(v2);
    }
    return vects;
}

vector<pair<pair<int, int>, double>> distance_calculation(const vector<vector<double>>& pairs) {
    vector<pair<pair<int, int>, double>> dist;
    for (int i = 0; i < pairs.size(); i++) {
        for (int j = i + 1; j < pairs.size(); j++) {
            double p1 = dist_cos(pairs[i], pairs[j]);
            dist.push_back(make_pair(make_pair(i + 1, j + 1), p1));
        }
    }
    return dist;
}

vector<pair<pair<int, int>, double>> sorting_function(const vector<pair<pair<int, int>, double>>& curr_dist) {
    vector<pair<pair<int, int>, double>> dist = curr_dist;
    sort(dist.begin(), dist.end(), [](auto& left, auto& right) {
        return left.second > right.second;
    });
    return dist;
}

void output_pairs(const vector<pair<pair<int, int>, double>>& curr_pr) {
    for (const auto& i : curr_pr) {
        cout << "(" << i.first.first << "," << i.first.second << ") ";
    }
    cout << endl;
}
