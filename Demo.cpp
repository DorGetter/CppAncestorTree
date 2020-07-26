/**
 * Demo for Family Tree
 * 
 * First version by Adam Lev-Ari,  2019-12
 * Second version by Erel Segal-Halevi, 2020-04
 */

#include "FamilyTree.hpp"

#include <iostream>
using namespace std;
/*
 int main() {
 family::Tree T ("Yosef");
	T.addFather("Yosef", "Yaakov");
	T.addMother("Yosef", "Rachel");

	if(T.get_root()->get_name() == nullptr ){}
    std::cout<< T.get_root()->get_father()->get_name() << std::endl;
	//(T.addFather("Yosef", "Yaakov")); // duplicate father
	//(T.addMother("Yosef", "Rivka"));  // duplicate mother
	T.addFather("Yaakov", "Isaac");
	T.addMother("Yaakov", "Rivka");
	T.addFather("Rachel", "Avi");
	T.addMother("Rachel", "Ruti");
	T.addFather("Isaac", "Avraham");
	T.addMother("Isaac", "Ruti");
	//(T.addFather("Isaac", "Israel"));  // duplicate father
	//(T.addMother("Isaac", "Ruti"));    // duplicate mother
	T.addFather("Avraham", "Yosi");
	T.addMother("Avraham", "Shelly");
	T.addFather("Avi", "Israel");
	T.addMother("Avi", "Sara");
	//(T.addFather("Avraham", "Avraham"));    // duplicate father
	//(T.addMother("Avraham", "Sara"));       // duplicate mother

	// Relation test case
	if(T.relation("Yaakov") == string("father"));
	if(T.relation("Rachel") == string("mother"));
	if(T.relation("Isaac") == string("grandfather"));
	if(T.relation("Rivka") == string("grandmother"));
	if(T.relation("Avi") == string("grandfather"));
	if((T.relation("Ruti") == string("grandmother") || T.relation("Ruti") == string("great-grandmother")));
	if(T.relation("Avraham") == string("great-grandfather"));
	if((T.relation("Ruti") == string("grandmother") || T.relation("Ruti") == string("great-grandmother")));
	if(T.relation("Israel") == string("great-grandfather"));
	if(T.relation("Sara") == string("great-grandmother"));
	if(T.relation("Yosi") == string("great-great-grandfather"));
    if(T.relation("Shelly") == string("great-great-grandmother"));

    if(T.relation("xyz") == string("unrelated"));
	if(T.relation("Omer") == string("unrelated"));
	if(T.relation("Ariel") == string("unrelated"));
	if(T.relation(" ") == string("unrelated"));
	if(T.relation("  Ariel") == string("unrelated"));

	// Find test case
	if(T.find("father") == string("Yaakov"));
	if(T.find("mother") == string("Rachel"));
	if((T.find("grandfather") == string("Isaac") || T.find("grandfather") == string("Avi")));
	if((T.find("grandmother") == string("Rivka") || T.find("grandmother") == string("Ruti")));
	if((T.find("great-grandmother") == string("Sara") || T.find("great-grandmother") == string("Ruti")));
	if((T.find("great-grandfather") == string("Avraham") || T.find("great-grandfather") == string("Israel")));
	if(T.find("great-great-grandfather") == string("Yosi"));
	if(T.find("great-great-grandmother") == string("Shelly"));
//
	//(T.find("grandfatrher"));
	//(T.find("great"));
	//(T.find(" "));
	//(T.find("   great"));
	//(T.find("grandfatrher   "));
	//(T.find("great,great,grandmother"));
	//(T.find("great?grandmother"));
	//(T.find("great grandmother"));

	// Remove test case
	////(T.remove("Yosef"));  // removing the root is an error
	//(T.remove(" "));      // removing a non-existent person
	//(T.remove("xyz"));
	//(T.remove("Ariel"));
	//(T.remove("  Rivka"));

	T.remove("Yosi");  // remove the great-great-grandfather

	//(T.find("great-great-grandfather"));  // A removed relation does not exist
	T.addFather("Avraham", "Ido");  // Add a new father after removal
	T.remove("Avi");
	//(T.addFather("Avi", "Israel"));  // add to a removed person
	T.addFather("Rachel", "Shmual");
	//T.remove("Isaac");
	T.remove("Rivka");
	T.remove("Ruti");
	//(T.find("grandmother"));
	//(T.addFather("Isaac", "Avraham"));


	T.addMother("Isaac", "Ruti");
	//(T.addFather("Rivka", "Israel"));
	//(T.addMother("Rivka", "Sara"));
	T.remove("Yaakov");  // remove father
	T.remove("Rachel");  // remove mother


    //(T.find("father"));
	//(T.find("mother"));
	//(T.addFather("Yaakov", "Avraham"));   // add to non-existent person
	//(T.addMother("Yaakov", "Ruti"));      // add to non-existent person
	//(T.addFather("Rachel", "Avraham"));   // add to non-existent person
	//(T.addMother("Rachel", "Ruti"));      // add to non-existent person
}*/