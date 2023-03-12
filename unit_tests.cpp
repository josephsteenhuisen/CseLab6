#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "pairwise_cosine_dist.h"


TEST_CASE("Test Case") {
    vector<pair<pair<int, int>, double>> dist = {{{2, 4}, 0.5}, {{2, 6}, 0.4}, {{4, 6}, 0.3}};
    auto sorted_distances = sorting_function(dist);
    CHECK(sorted_distances.size() == 3);
    CHECK(sorted_distances[0].second == 0.9);
    CHECK(sorted_distances[1].second == 0.8);
    CHECK(sorted_distances[2].second == 0.7);
    vector<vector<double>> vect = {{1, 2, 3}, {4, 5, 6}};
    auto pairs = distance_calculation(vect);
    CHECK(pairs.size() == 1);
    CHECK(pairs[0].second == doctest::Approx(0.974632));
}
