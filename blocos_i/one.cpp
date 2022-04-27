#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "check.hpp"
#include "one.hpp"

void open(std::string name) {
    std::cout << "\n" << name;
}

int main() {

    open("in");
    check(in({-1, -50, -99}, -1), true);
    check(in({-1, -50, -99}, -50), true);
    check(in({-1, -50, -99}, -99), true);
    check(in({-1, -50, -99}, -50), false); 

    open("find_index");
    check(find_index({-1, -50, -1, -99}, -50), 1);
    check(find_index({-1, -50, -1, -99}, -99), 3);
    check(find_index({-1, -50, -1, -99}, 10), -1);

    open("find_begin");
    check(find_begin({5, 3, -1, -50, -1, -99}, -1, 0), 2);
    check(find_begin({5, 3, -1, -50, -1, -99}, -1, 3), 4); 
    check(find_begin({5, 3, -1, -50, -1, -99}, -1, 4), 4);
    check(find_begin({5, 3, -1, -50, -1, -99}, -1, 5), -1);

    open("find_if");
    check(find_if({5, 3, -1, -50, -1, -99}), 0);
    check(find_if({-1, -50, -1, -99, -444}), -1);

    open("min_element");
    check(min_element({5, 3, -1, -50, -1, -99}), 5);

    open("find_min_if");
    check(find_min_if({5, 3, -1, -50, -1, -99}), 1);
    check(find_min_if({-1, -50, -1, -99, -444}), -1);

    open("count");
    check(count({-1, -50, -1, -99}, -1), 2);
    check(count({-1, -50, -1, -99}, 10), 0);

    open("average");
    check(average({1, 2, 3, -4, -5, -6}), 3.5);

    open("more_men_or_women");
    check(more_men_or_women({5, 3, 1, -50, -1, -99}), "draw");
    check(more_men_or_women({5, -3, 1, -50, -1, -99}), "women");
    check(more_men_or_women({5, 3, 1, -50, -1, 99}), "men");

    open("half_compare");
    check(half_compare({ 5,  3, -5}), "draw");
    check(half_compare({ 5,  3, -4}), "first");
    check(half_compare({ 5,  3, -6}), "second");
    check(half_compare({ 5,  3}), "first");
    check(half_compare({ 3,  5}), "second");
    check(half_compare({  5,  3, -1, -50, -10, -999}), "second");
    check(half_compare({ 50, -98,  2, -50,  -1, -99}), "draw");
    check(half_compare({-51, 99,  1, -50,  -1,  -99}), "first");

    open("sex_battle");
    check(sex_battle({5, 3, -1, -50, -10, -999}), "women");
    check(sex_battle({50, 98, 2, -50, -1, 9991}), "men");
    check(sex_battle({-50, 99, 1, 50, -1, -99}), "draw");

    std::cout << "\n";
}