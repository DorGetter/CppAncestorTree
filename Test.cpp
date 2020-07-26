//
// Created by Dor Getter on 15/04/2020.
//
#define CHECK DOCTEST_CHECK

#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
using namespace family;



TEST_CASE("Initializing Tree Of The British Royal Family") {



/////////////////////////////////////////////////////////
/////////////Prince Louis Tree//////////////////////////
///////////////////////////////////////////////////////

    family::Tree T("Prince Louis"); // Louis is the "root" of the tree (the youngest person).
    T.addFather("Prince Louis", "Prince Williams")   // Tells the tree that the father of Louis is Williams.
            .addMother("Prince Louis", "Kate Middleton");  // Tells the tree that the mother of Louis is Kate.

    T.addFather("Prince Williams", "Prince Charles");
    T.addMother("Prince Williams", "Princess Diana");

    T.addFather("Kate Middleton", "Micheal Middleton");
    T.addMother("Kate Middleton", "Carole Middleton");


    T.addFather("Prince Charles", "King philip");
    T.addMother("Prince Charles", "Queen Elizabeth 2");

    T.addFather("Princess Diana", "John Spencer");
    T.addMother("Princess Diana", "Frances Shand Kydd");

    T.addMother("Queen Elizabeth 2", "Queen Elizabeth");
    T.addFather("Queen Elizabeth 2", "King George 6");
    std::cout<< "\n\t\t///////////////////////////////////////\n\t\t//////   British Royal Family   //////\n\t\t/////////////////////////////////////\n" << std::endl;
    T.display();
    
    /////////////////////////
    ////////Existence///////
    ///////////////////////
            CHECK(T.get_root());
            CHECK(T.get_root()->get_father());
            CHECK(T.get_root()->get_mother());
            CHECK(T.get_root()->get_father()->get_father());
            CHECK(T.get_root()->get_father()->get_mother());
            CHECK(T.get_root()->get_mother()->get_father());
            CHECK(T.get_root()->get_mother()->get_mother());
            CHECK(T.get_root()->get_father()->get_father()->get_father());
            CHECK(T.get_root()->get_father()->get_father()->get_mother());
            CHECK(T.get_root()->get_father()->get_mother()->get_father());
            CHECK(T.get_root()->get_father()->get_mother()->get_mother());
            CHECK(T.get_root()->get_father()->get_father()->get_mother()->get_mother());
            CHECK(T.get_root()->get_father()->get_father()->get_mother()->get_father());

    /////////////////////////
    ////////Rightness///////
    ///////////////////////
            CHECK(T.get_root()->get_name() == "Prince Louis");
            CHECK(T.get_root()->get_father()->get_name() == "Prince Williams");
            CHECK(T.get_root()->get_mother()->get_name() == "Kate Middleton");
            CHECK(T.get_root()->get_father()->get_father()->get_name() == "Prince Charles");
            CHECK(T.get_root()->get_father()->get_mother()->get_name() == "Princess Diana");
            CHECK(T.get_root()->get_mother()->get_father()->get_name() == "Micheal Middleton");
            CHECK(T.get_root()->get_mother()->get_mother()->get_name() == "Carole Middleton");
            CHECK(T.get_root()->get_father()->get_father()->get_father()->get_name() == "King philip");
            CHECK(T.get_root()->get_father()->get_father()->get_mother()->get_name() == "Queen Elizabeth 2");
            CHECK(T.get_root()->get_father()->get_mother()->get_father()->get_name() == "John Spencer");
            CHECK(T.get_root()->get_father()->get_mother()->get_mother()->get_name() == "Frances Shand Kydd");
            CHECK(T.get_root()->get_father()->get_father()->get_mother()->get_mother()->get_name() == "Queen Elizabeth");
            CHECK(T.get_root()->get_father()->get_father()->get_mother()->get_father()->get_name() == "King George 6");

    /////////////////////////
    ////////relations///////
    ///////////////////////
            CHECK(T.relation("Prince Louis")=="me");
            CHECK(T.relation("Prince Williams")=="father");
            CHECK(T.relation("Kate Middleton")=="mother");
            CHECK(T.relation("Prince Charles")=="grandfather");
            CHECK(T.relation("Princess Diana")=="grandmother");
            CHECK(T.relation("Micheal Middleton")=="grandfather");
            CHECK(T.relation("Carole Middleton")=="grandmother");
            CHECK(T.relation("King philip")=="great-grandfather");
            CHECK(T.relation("Queen Elizabeth 2")=="great-grandmother");
            CHECK(T.relation("John Spencer")=="great-grandfather");
            CHECK(T.relation("Frances Shand Kydd")=="great-grandmother");
            CHECK(T.relation("Queen Elizabeth")=="great-great-grandmother");
            CHECK(T.relation("King George 6")=="great-great-grandfather");

            CHECK(T.relation("Squirtel")=="unrelated");
            CHECK(T.relation("Charizard")=="unrelated");
            CHECK(T.relation("John Smith")=="unrelated");
            CHECK(T.relation("captain Jack Sparrow")=="unrelated");

    /////////////////////////
    /////////find///////////
    ///////////////////////
            CHECK(T.find("me")=="Prince Louis");
            CHECK(T.find("father")=="Prince Williams");
            CHECK(T.find("mother")=="Kate Middleton");
            CHECK(T.find("grandfather")=="Prince Charles");
            CHECK(T.find("grandmother")=="Princess Diana");
            CHECK(T.find("great-grandfather")=="King philip");
            CHECK(T.find("great-grandmother")=="Queen Elizabeth 2");
            CHECK(T.find("great-great-grandfather")=="King George 6");
            CHECK(T.find("great-great-grandmother")=="Queen Elizabeth");

    /////////////////////////
    ////Throw exception/////
    ///////////////////////
            CHECK_THROWS(T.find("get_father()dy"));
            CHECK_THROWS(T.find("get_mother()my"));
            CHECK_THROWS(T.find("uncle"));
            CHECK_THROWS(T.find("brother"));
            CHECK_THROWS(T.find("sister"));
            CHECK_THROWS(T.find("nephew"));
            CHECK_THROWS(T.find("sibling"));

    ///////////////////////////
    /////Remove From Tree/////
    /////////////////////////

    T.remove("Prince Charles");
            CHECK(T.relation("Queen Elizabeth")=="unrelated");
            CHECK(T.relation("King George 6")=="unrelated");
            CHECK(T.relation("King philip")=="unrelated");
            CHECK(T.relation("Queen Elizabet 2")=="unrelated");
            CHECK(T.relation("Prince Charles")=="unrelated");
            CHECK(T.relation("Prince Williams")=="father");

    //////////////////////////////////////////////////////////////////////////////
    ////////////////////////////New Tree- LION KING//////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    std::cout<< "\n\t\t///////////////////////////////////////\n\t\t////////   Lion King Family   ////////\n\t\t/////////////////////////////////////\n" << std::endl;

    family::Tree L("Kiara");
    L.addFather("Kiara", "Simba")   // Tells the tree that the father of Louis is Williams.
            .addMother("Kiara", "Nala");  // Tells the tree that the mother of Louis is Kate.

    L.addFather("Simba", "Mufasa");
    L.addMother("Simba", "Sarabi");

    L.addFather("Nala", "Unknown");
    L.addMother("Nala", "Sarafina");

    L.addFather("Mufasa", "Ahadi");
    L.addMother("Mufasa", "Ura");

    L.addFather("Ahadi", "Mohatu");
    L.addMother("Ahadi", "Unknown2");


    L.display();

    /////////////////////////
    ////////Existence///////
    ///////////////////////
            CHECK(L.get_root());
            CHECK(L.get_root()->get_father());
            CHECK(L.get_root()->get_mother());
            CHECK(L.get_root()->get_father()->get_father());
            CHECK(L.get_root()->get_father()->get_mother());
            CHECK(L.get_root()->get_mother()->get_father());
            CHECK(L.get_root()->get_mother()->get_mother());
            CHECK(L.get_root()->get_father()->get_father()->get_father());
            CHECK(L.get_root()->get_father()->get_father()->get_mother());



    /////////////////////////
    ////////Rightness///////
    ///////////////////////
            CHECK(L.get_root()->get_name() == "Kiara");
            CHECK(L.get_root()->get_father()->get_name() == "Simba");
            CHECK(L.get_root()->get_mother()->get_name() == "Nala");
            CHECK(L.get_root()->get_father()->get_father()->get_name() == "Mufasa");
            CHECK(L.get_root()->get_father()->get_mother()->get_name() == "Sarabi");
            CHECK(L.get_root()->get_mother()->get_father()->get_name() == "Unknown");
            CHECK(L.get_root()->get_mother()->get_mother()->get_name() == "Sarafina");
            CHECK(L.get_root()->get_father()->get_father()->get_father()->get_name() == "Ahadi");
            CHECK(L.get_root()->get_father()->get_father()->get_mother()->get_name() == "Ura");

            CHECK(L.get_root()->get_father()->get_father()->get_father()->get_mother()->get_name() == "Unknown2");
            CHECK(L.get_root()->get_father()->get_father()->get_father()->get_father()->get_name() == "Mohatu");

    /////////////////////////
    ////////relations///////
    ///////////////////////
            CHECK(L.relation("Kiara")=="me");
            CHECK(L.relation("Simba")=="father");
            CHECK(L.relation("Nala")=="mother");
            CHECK(L.relation("Mufasa")=="grandfather");
            CHECK(L.relation("Sarabi")=="grandmother");
            CHECK(L.relation("Sarafina")=="grandmother");
            CHECK(L.relation("Unknown")=="grandfather");
            CHECK(L.relation("Ahadi")=="great-grandfather");
            CHECK(L.relation("Ura")=="great-grandmother");
            CHECK(L.relation("Mohatu")=="great-great-grandfather");
            CHECK(L.relation("Unknown2")=="great-great-grandmother");

            CHECK(L.relation("Scar")=="unrelated");
            CHECK(L.relation("Zira")=="unrelated");
            CHECK(L.relation("Kova")=="unrelated");


    /////////////////////////
    ////Throw exception/////
    ///////////////////////
            CHECK_THROWS(L.find("fatheeer"));
            CHECK_THROWS(L.find("mfatherotherer"));
            CHECK_THROWS(L.find("uncqwele"));
            CHECK_THROWS(L.find("brother"));
            CHECK_THROWS(L.find("sister"));
            CHECK_THROWS(L.find("nephew"));
            CHECK_THROWS(L.find("KITTEN"));

    /////////////////////////
    /////////find///////////
    ///////////////////////

            CHECK(L.find("me")=="Kiara");
            CHECK(L.find("father")=="Simba");
            CHECK(L.find("mother")=="Nala");
            CHECK(L.find("grandfather")=="Mufasa");
            CHECK(L.find("grandmother")=="Sarabi");
            CHECK(L.find("great-grandfather")=="Ahadi");
            CHECK(L.find("great-grandmother")=="Ura");
            CHECK(L.find("great-great-grandfather")=="Mohatu");
            CHECK(L.find("great-great-grandmother")=="Unknown2");


    //////////////////////////
    /////Remove From Tree/////
    /////////////////////////

    L.remove("Mufasa");
            CHECK(T.relation("Mufasa")=="unrelated");
            CHECK(T.relation("Ahadi")=="unrelated");
            CHECK(T.relation("Ura")=="unrelated");
            CHECK(T.relation("Mohatu")=="unrelated");
            CHECK(T.relation("Unknown2")=="unrelated");
}

