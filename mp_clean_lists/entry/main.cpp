#include <catch2/catch_test_macros.hpp>
#include "../tests/tests_helper.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <random>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include "List.h"
using namespace cs225;
int main() {
    List<int> list;
    list.insertBack(1);
    list.insertBack(2);
    list.insertBack(3);
    list.insertBack(4);
    list.insertBack(5);
    list.insertBack(6);

    std::cout << list << std::endl;
    //list.tester();
    std::cout << list << std::endl;
    return 0;
}
