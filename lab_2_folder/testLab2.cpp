#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./include/doctest.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

bool non_neg_prefix_sum(const std::vector<int>& list) {
    int sum = 0;
    for (int value : list) {
        sum += value;
        if (sum < 0) {
            return false;
        }
    }
    return true;
}

bool non_pos_prefix_sum(const std::vector<int>& list) {
    int sum = 0;
    for (int value : list) {
        sum += value;
        if (sum > 0) {
            return false;
        }
    }
    return true;
}

void fisher_yates(std::vector<int>& list) {
    for (int i = list.size() - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(list[i], list[j]);
    }
}

bool is_well_balanced(const std::vector<int>& list) {
    return non_neg_prefix_sum(list) || non_pos_prefix_sum(list);
}

TEST_CASE("Testing non_neg_prefix_sum") {
    CHECK(non_neg_prefix_sum({1, 2, 3}));
    CHECK(non_neg_prefix_sum({0, 1, 2, 3}));
    CHECK(!non_neg_prefix_sum({1, -3, 2}));
    CHECK(non_neg_prefix_sum({}));
}

TEST_CASE("Testing non_pos_prefix_sum") {
    CHECK(non_pos_prefix_sum({-1, -2, -3}));
    CHECK(non_pos_prefix_sum({0, -2, -3}));
    CHECK(!non_pos_prefix_sum({-1, 3}));
    CHECK(non_pos_prefix_sum({}));
}

TEST_CASE("Testing fisher_yates") {
    std::vector<int> original_list = {1, 2, 3, 4, 5};
    std::vector<int> list = {1, 2, 3, 4, 5};
    fisher_yates(list);
    CHECK(list.size() == original_list.size());
    CHECK(std::is_permutation(list.begin(), list.end(), original_list.begin()));
}

TEST_CASE("Testing is_well_balanced") {
    CHECK(is_well_balanced({1, -1, 1, -1}));
    CHECK(is_well_balanced({-1, 1, -1, 1}));
    CHECK(!is_well_balanced({1, 1, -2, -1}));
    CHECK(!is_well_balanced({-1, -1, 2, 1}));
}