#ifndef __COSINE_DISTANCE__
#define __COSINE_DISTANCE__

#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <string>

using namespace std;

vector<vector<double>> accessing_file(string txt_file);

double dist_cos(const vector<double>& first_, const vector<double>& second_);

vector<pair<pair<int, int>, double>> distance_calculation(const vector<vector<double>>& pairs);

vector<pair<pair<int, int>, double>> sorting_function(const vector<pair<pair<int, int>, double>>& curr_dist);

void output_pairs(const vector<pair<pair<int, int>, double>>& pairs);

#endif
