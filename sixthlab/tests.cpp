#include <gtest/gtest.h>
#include "wolf.hpp"
#include "robber.hpp"
#include "bear.hpp"
#include "npc.hpp"


TEST(Wolf_test, _01) {
    Wolf wolf(40,50);
    wolf.print();
}

TEST(Wolf_test, _02) {
    std::shared_ptr<NPC> wolf= std::make_shared<Wolf>(40, 50);
    std::shared_ptr<NPC> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<NPC> robber= std::make_shared<Robber>(30, 45);

    //success = defender->accept(attacker);
    bool successb = bear->accept(wolf);
    bool successr = robber->accept(wolf);
    bool successw = wolf->accept(wolf);
    ASSERT_FALSE(successb);
    ASSERT_FALSE(successw);
    ASSERT_TRUE(successr);
}

TEST(Wolf_test, _03) {
    std::shared_ptr<Wolf> wolf= std::make_shared<Wolf>(40, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<Robber> robber= std::make_shared<Robber>(30, 45);

    //success = defender->accept(attacker);
    bool successb = bear->fight(wolf);
    bool successr = robber->fight(wolf);
    bool successw = wolf->fight(wolf);
    ASSERT_FALSE(successr);
    ASSERT_FALSE(successw);
    ASSERT_TRUE(successb);
}

TEST(Wolf_test, _04) {

    Wolf wolf(40,50);
    std::cout << wolf << std::endl;

}

TEST(Robber_test, _01) {
    Robber robber(40,10);
    robber.print();
}

TEST(Robber_test, _02) {
    std::shared_ptr<NPC> wolf= std::make_shared<Wolf>(40, 50);
    std::shared_ptr<NPC> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<NPC> robber= std::make_shared<Robber>(30, 45);

    //success = defender->accept(attacker);
    bool successb = bear->accept(robber);
    bool successr = robber->accept(robber);
    bool successw = wolf->accept(robber);
    ASSERT_FALSE(successr);
    ASSERT_FALSE(successw);
    ASSERT_TRUE(successb);
}

TEST(Robber_test, _03) {
    std::shared_ptr<Wolf> wolf= std::make_shared<Wolf>(40, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<Robber> robber= std::make_shared<Robber>(30, 45);

    //success = defender->accept(attacker);
    bool successr = robber->fight(wolf);
    bool successrr = robber->fight(bear);
    ASSERT_FALSE(successr);
    ASSERT_TRUE(successrr);
}

TEST(Robber_test, _04) {
    Robber robber(40,10);
    std::cout << robber << std::endl;
}

TEST(Bear_test, _01) {
    Bear bear(30,45);
    bear.print();
}

TEST(Bear_test, _02) {
    std::shared_ptr<NPC> wolf= std::make_shared<Wolf>(40, 50);
    std::shared_ptr<NPC> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<NPC> robber= std::make_shared<Robber>(30, 45);

    //success = defender->accept(attacker);
    bool successb = bear->accept(bear);
    bool successr = robber->accept(bear);
    bool successw = wolf->accept(bear);
    ASSERT_FALSE(successb);
    ASSERT_FALSE(successr);
    ASSERT_TRUE(successw);
}

TEST(Bear_test, _03) {
    std::shared_ptr<Wolf> wolf= std::make_shared<Wolf>(40, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<Robber> robber= std::make_shared<Robber>(30, 45);

    //success = defender->accept(attacker);
    bool successb = bear->fight(wolf);
    bool successbb = robber->fight(bear);
    ASSERT_TRUE(successb);
    ASSERT_TRUE(successbb);
}

TEST(Bear_test, _04) {
    Bear bear(30,45);
    std::cout << bear << std::endl;
}

TEST(npc_test, _01) {
    std::set<std::shared_ptr<NPC>> array;

    std::shared_ptr<Wolf> wolf= std::make_shared<Wolf>(40, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<Robber> robber= std::make_shared<Robber>(30, 45);

    array.insert(wolf);
    array.insert(bear);
    array.insert(robber);

    size_t distance = 20;
    std::set<std::shared_ptr<NPC>> dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance)))
            {
                bool success{false};
                success = defender->accept(attacker);
                
                if (success)
                    dead_list.insert(defender);
            }

    std::cout << "killed ☠️ : " << dead_list.size() << std::endl;


}

TEST(npc_test, _02) {
    std::set<std::shared_ptr<NPC>> array;

    std::shared_ptr<Wolf> wolf= std::make_shared<Wolf>(40, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<Robber> robber= std::make_shared<Robber>(30, 45);

    array.insert(wolf);
    array.insert(bear);
    array.insert(robber);

    size_t distance = 20;
    std::set<std::shared_ptr<NPC>> dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance)))
            {
                bool success{false};
                success = defender->accept(attacker);
                
                if (success)
                    dead_list.insert(defender);
            }

    for (auto &d : dead_list)
            array.erase(d);

    std::cout << "Survivors 🎉❤️ : " << std::endl;

    for (auto &n : array)
        n->print();

}


int main(int argc, char** argv){

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
