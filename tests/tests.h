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
    std::vector<std::string> lab;
    m.get_map(lab);
    std::ifstream f("maps/map.txt");
    std::string cur_line;
    int i = 0;
    while(getline(f, cur_line))
    {
        ASSERT_EQ(lab[i], cur_line);
        i++;
    }
    f.close();
    m.clear();
}

TEST(load_map, suite2)
{
    map m;
    testing::internal::CaptureStderr();
    m.load_map("nofile.txt");
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "File not found!\n");
    m.clear();
}

TEST(hero_init, suite1)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    h.init(2, 1, m);
    int k = h.get_x();
    ASSERT_EQ(k, 2);
    k = h.get_y();
    ASSERT_EQ(k, 1);
    m.clear();
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
    m.clear();
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
    m.clear();
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
    m.clear();
}

TEST(hero_init, suite5)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    testing::internal::CaptureStderr();
    h.init(2, 2, m);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "hero obj can't be init\n");
    m.clear();
}

TEST(hero_init, suite6)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    testing::internal::CaptureStderr();
    h.init(1, 1, m);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "hero obj can't be init\n");
    m.clear();
}

TEST(hero_move, suite1)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    testing::internal::CaptureStderr();
    h.move_x(2, m);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "can't move hero obj\n");

    m.clear();
}

TEST(hero_move, suite2)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    testing::internal::CaptureStderr();
    h.move_y(2, m);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "can't move hero obj\n");
    m.clear();
}

TEST(hero_move, suite3)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    h.init(6, 1, m);
    h.move_x(1, m);
    int k = h.get_x();
    ASSERT_EQ(k, 8);
    m.clear();
}

TEST(hero_move, suite4)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    h.init(6, 2, m);
    h.move_y(1, m);
    int k = h.get_y();
    ASSERT_EQ(k, 3);
    m.clear();
}

#endif // EQTEST_H
