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

TEST(init_finish, suite1)
{
    map m;
    m.load_map("maps/map.txt");
    testing::internal::CaptureStderr();
    m.finish(-1, -1);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "finish can't be create\n");
    m.clear();
}

TEST(init_finish, suite2)
{
    map m;
    m.load_map("maps/map.txt");
    testing::internal::CaptureStderr();
    m.finish(40, 50);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "finish can't be create\n");
    m.clear();
}

TEST(init_finish, suite3)
{
    map m;
    m.load_map("maps/map.txt");
    testing::internal::CaptureStderr();
    m.finish(39, 19);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "finish can't be create\n");
    m.clear();
}

TEST(init_finish, suite4)
{
    map m;
    m.load_map("maps/map.txt");
    testing::internal::CaptureStderr();
    m.finish(2, 2);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "finish can't be create\n");
    m.clear();
}

TEST(init_finish, suite5)
{
    map m;
    m.load_map("maps/map.txt");
    m.finish(38, 19);
    ASSERT_EQ(m.get_f_x(), 38);
    ASSERT_EQ(m.get_f_y(), 19);
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
    h.init(50, 40, m);
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
    h.init(6, 1, m);
    h.move_x(-1, m);
    int k = h.get_x();
    ASSERT_EQ(k, 4);
    m.clear();
}


TEST(hero_move, suite5)
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

TEST(hero_move, suite6)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    h.init(6, 2, m);
    h.move_y(-1, m);
    int k = h.get_y();
    ASSERT_EQ(k, 1);
    m.clear();
}

TEST(hero_move, suite7)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    h.init(6, 2, m);
    h.move_x(-1, m);
    int k = h.get_x();
    ASSERT_EQ(k, 6);
    m.clear();
}

TEST(hero_move, suite8)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    h.init(6, 2, m);
    h.move_x(1, m);
    int k = h.get_x();
    ASSERT_EQ(k, 6);
    m.clear();
}

TEST(hero_move, suite9)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    h.init(2, 1, m);
    h.move_y(1, m);
    int k = h.get_y();
    ASSERT_EQ(k, 1);
    m.clear();
}

TEST(hero_move, suite10)
{
    map m;
    m.load_map("maps/map.txt");
    hero h;
    h.init(2, 1, m);
    h.move_y(-1, m);
    int k = h.get_y();
    ASSERT_EQ(k, 1);
    m.clear();
}

TEST(enemy_init, suite1)
{
    map m;
    m.load_map("maps/map.txt");
    enemy e;
    e.init(2, 1, 10, m);
    int k = e.get_x();
    ASSERT_EQ(k, 2);
    k = e.get_y();
    ASSERT_EQ(k, 1);
    k = e.get_prev_x();
    ASSERT_EQ(k, 2);
    k = e.get_prev_y();
    ASSERT_EQ(k, 1);
    k = e.get_way_len();
    ASSERT_EQ(k, 10);
    std::vector<int> way;
    e.get_way(way);
    for (int i = 0; i < 10; i++)
    {
        ASSERT_EQ(way[i], 0);
    }
    m.clear();
}

TEST(enemy_init, suite2)
{
    map m;
    m.load_map("maps/map.txt");
    enemy e;
    testing::internal::CaptureStderr();
    e.init(-1, -1, 10, m);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "enemy obj can't be init\n");
    m.clear();
}

TEST(enemy_init, suite3)
{
    map m;
    m.load_map("maps/map.txt");
    enemy e;
    testing::internal::CaptureStderr();
    e.init(50, 50, 10, m);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "enemy obj can't be init\n");
    m.clear();
}

TEST(enemy_init, suite4)
{
    map m;
    m.load_map("maps/map.txt");
    enemy e;
    testing::internal::CaptureStderr();
    e.init(1, 1, 10, m);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "enemy obj can't be init\n");
    m.clear();
}

TEST(enemy_init, suite5)
{
    map m;
    m.load_map("maps/map.txt");
    enemy e;
    testing::internal::CaptureStderr();
    e.init(2, 1, 0, m);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "enemy obj can't be init\n");
    m.clear();
}

TEST(enemy_init, suite6)
{
    map m;
    m.load_map("maps/map.txt");
    enemy e;
    testing::internal::CaptureStderr();
    e.init(2, 1, -3, m);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "enemy obj can't be init\n");
    m.clear();
}

TEST(enemy_init, suite7)
{
    map m;
    m.load_map("maps/map.txt");
    enemy e;
    testing::internal::CaptureStderr();
    e.init(2, 2, 10, m);
    std::string s = testing::internal::GetCapturedStderr();
    ASSERT_EQ(s, "enemy obj can't be init\n");
    m.clear();
}

//TEST(enemy_init, suite1)
//{

//}

#endif // EQTEST_H
