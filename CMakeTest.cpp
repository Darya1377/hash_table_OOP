//
// Created by Дарья on 15.11.2021.
//

#include <iostream>
#include "hash_table.h"
#include <gtest/gtest.h>


class HashTableTest : public testing::Test{
protected:
    void SetUp() override{
        t1.insert("Kim Kardashian", {.age = 41, .weight = 60});
        t1.insert("Kanye West", {.age = 44, .weight = 75});

        t2.insert("Kylie Jenner", {.age = 24, .weight = 62});
        t2.insert("Travis Scott", {.age = 30, .weight = 80});
        t2.insert("Stormi", {.age = 3, .weight = 18});
    }
    HashTable t0;
    HashTable t1;
    HashTable t2;

};
TEST_F(HashTableTest, SwapTest){
t1.swap(t2);
EXPECT_EQ(t1.size(), 3);
EXPECT_EQ(t2.size(), 2);
EXPECT_EQ(t2["Kanye West"].weight, 75);
}
TEST_F(HashTableTest, EraseTest){
bool r = t2.erase("Kylie Jenner");
EXPECT_EQ(r, true);
}
TEST_F(HashTableTest, EmptyTest){
bool r = t1.empty();
EXPECT_EQ(r, false);
r = t0.empty();
EXPECT_EQ(r, true);
}
TEST_F(HashTableTest, ContainsTest){
bool r = t1.contains("Kim Kardashian");
EXPECT_EQ(r, true);
r = t1.contains("Kris Jenner");
EXPECT_EQ(r, false);
}
TEST_F(HashTableTest, AtTest){
Value& s = t1.at("Kim Kardashian");
EXPECT_EQ(s.weight, 60);
ASSERT_ANY_THROW(t1.at("testing"));
}
TEST_F(HashTableTest, OperatorsTest){
bool r1 = t1 == t2;
EXPECT_EQ(r1, false);
bool r2 = t1 != t2;
EXPECT_EQ(r2, true);
unsigned int r3 = t2["Travis Scott"].weight;
EXPECT_EQ(r3, 70);
t1 = t2;
r1 = t1 == t2;
EXPECT_EQ(r1, true);
}
TEST_F(HashTableTest, CopyTest){
HashTable t3 = t1;
EXPECT_EQ(t3.size(), 2);
bool r0 = t3.contains("Kanye West");
EXPECT_EQ(r0, true);
bool r2 = t3.contains("Kylie Jenner");
EXPECT_EQ(r2, false);

}
TEST_F(HashTableTest, MoveTest){
HashTable t4 = std::move(t2);

bool r0 = t4.contains("Kylie Jenner");
bool r1 = t4.contains("Travis Scott");
bool r2 = t4.contains("Stormi");
bool r3 = t2.empty();
EXPECT_EQ(r0, true);
EXPECT_EQ(r1, true);
EXPECT_EQ(r2, true);
EXPECT_EQ(r3, true);
}