#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

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

int main() {
    std::srand(std::time(0));// to check if the sequence is valid and not duplicate

    int n;
    std::cout << "Enter the number of pairs n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "The number of pairs must be a positive integer." << std::endl;
        return 1;
    }

    int well_balanced_count = 0;
    int trials = 10000; 

    for (int trial = 0; trial < trials; ++trial) {
        std::vector<int> list(2 * n, 1);
        std::fill(list.begin() + n, list.end(), -1);

        fisher_yates(list);

        if (is_well_balanced(list)) {
            well_balanced_count++;
        }
    }

    double proportion = static_cast<double>(well_balanced_count) / trials;
    std::cout << "Proportion of well-balanced lists: " << proportion << std::endl;

    return 0;
}