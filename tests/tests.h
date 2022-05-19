#ifndef EQTEST_H
#define EQTEST_H
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include <ncurses.h>
#include <fstream>

#include "game.h"

TEST(load_map, suite1)
{
    map m;
    m.load_map("maps/map.txt");
    std::ifstream f("maps/map.txt");
    std::string cur;
    f.close();
}

TEST(hero_init, suite1)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    h.init(2, 1, m);
    int k = h.get_x();
    ASSERT_EQ(k, 2);
}

TEST(hero_init, suite2)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    testing::internal::CaptureStderr();
    h.init(0, 0, m);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "hero obj can't be init\n");
}

TEST(hero_init, suite3)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    testing::internal::CaptureStderr();
    h.init(-1, -3, m);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "hero obj can't be init\n");
}

TEST(hero_init, suite4)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    testing::internal::CaptureStderr();
    h.init(40, 40, m);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "hero obj can't be init\n");
}

#endif // EQTEST_H
