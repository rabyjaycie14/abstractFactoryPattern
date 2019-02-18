/* JAYCIE RABY | CIS 476 | WINTER 2019 | 18 FEBRUARY 2019 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*****************************************************************/
/* CREATE ABSTRACT PRODUCTS FOR ALL WORD PROCESSING APPLICATIONS */
/*****************************************************************/
class createPanel {
public:
	virtual string typeOfProduct() = 0;
};

class createButton {
public:
	virtual string typeOfProduct() = 0;
};

class createTextBox {
public:
	virtual string typeOfProduct() = 0;
};

/*****************************************************************/
/*      CREATE CONCRETE PRODUCTS FOR EACH ABSTRACT PRODUCT       */
/*****************************************************************/

/*Concrete Products: alerts, cards, rounded and quotes created 
	for "class createPanel" */
class alerts : public createPanel {
public:
	string typeOfProduct() { return "alerts"; }
};

class cards : public createPanel {
public:
	string typeOfProduct() { return "cards"; }
};

class rounded : public createPanel {
public:
	string typeOfProduct() { return "rounded"; }
};

class quotes : public createPanel {
public:
	string typeOfProduct() { return "quotes"; }
};

/* Concrete Products: bckgrndClr_red, bckgrndClr_blue, bckgrndClr_orange and
	bckgrndClr_purple created for "class createButton" */
class bckgrndClr_red : public createButton {
public:
	string typeOfProduct() { return "bckgrndClr_red"; }
};

class bckgrndClr_blue : public createButton {
public:
	string typeOfProduct() { return "bckgrndClr_blue"; }
};

class bckgrndClr_orange : public createButton {
public:
	string typeOfProduct() { return "bckgrndClr_orange"; }
};

class bckgrndClr_purple : public createButton {
public:
	string typeOfProduct() { return "bckgrndClr_purple"; }
};

/* Concrete Products: type_text, type_submit, type_reset and type_form
	created for "class createTextBox" */
class type_text : public createTextBox {
public:
	string typeOfProduct() { return "type_text"; }
};

class type_submit : public createTextBox {
public:
	string typeOfProduct() { return "type_submit"; }
};

class type_reset : public createTextBox {
public:
	string typeOfProduct() { return "type_reset"; }
};

class type_form : public createTextBox {
public:
	string typeOfProduct() { return "type_form"; }
};

/*****************************************************************/
/*	DECLARE CLASS TO CREATE ABSTRACT FACTORY FOR ALL WORD       */
/*			PROCESSING APPLICATIONS					     */
/*****************************************************************/
class Micro_Office_Factory {
public:
	enum WORD_PROC_APPS { WORD90, WORD00, WORD10, WORD18 };
	virtual createPanel* getPanel() = 0;
	virtual createButton* getButton() = 0;
	virtual createTextBox* getTextBox() = 0;

	static Micro_Office_Factory* createFactory(WORD_PROC_APPS factory); //class prototype
};

/*****************************************************************/
/* CREATE CONCRETE FACTORIES FOR EACH WORD PROCESSING APPLICATION*/
/*****************************************************************/

// Create Concrete Factory for WORD90
class WORD90_Factory : public Micro_Office_Factory {
public:
	// Create Concrete Product 'alerts' for the Abstract Product "createPanel"
	createPanel* getPanel() {
		return new alerts();
	}

	// Create Concrete Product 'bckgrndClr_red' for the Abstract Product "createButton"
	createButton* getButton() {
		return new bckgrndClr_red();
	}

	// Create Concrete Product 'type_text' for the Abstract Product "createButton"
	createTextBox* getTextBox() {
		return new type_text();
	}
};


// Create Concrete Factory for WORD00
class WORD00_Factory : public Micro_Office_Factory {
	createPanel* getPanel() {
		return new cards();
	}
	createButton* getButton() {
		return new bckgrndClr_blue();
	}
	createTextBox* getTextBox() {
		return new type_submit();
	}
};

// Create Concrete Factory for WORD10
class WORD10_Factory : public Micro_Office_Factory {
	createPanel* getPanel() {
		return new rounded();
	}
	createButton* getButton() {
		return new bckgrndClr_orange();
	}
	createTextBox* getTextBox() {
		return new type_reset();
	}
};

// Create Concrete Factory for WORD18
class WORD18_Factory : public Micro_Office_Factory {
	createPanel* getPanel() {
		return new quotes();
	}

	createButton* getButton() {
		return new bckgrndClr_purple();
	}
	createTextBox* getTextBox() {
		return new type_form();
	}
};

/********************************************************************/
/* DEFINE CREATE FACTORY FUNCTION FOR ABSTRACT FACTORY UTILIZATION */
/*******************************************************************/
Micro_Office_Factory* Micro_Office_Factory::createFactory(WORD_PROC_APPS factory) {
	if (factory == WORD_PROC_APPS::WORD90) {
		return new WORD90_Factory();
	}
	else if (factory == WORD_PROC_APPS::WORD00) {
		return new WORD00_Factory();
	}
	else if (factory == WORD_PROC_APPS::WORD10) {
		return new WORD10_Factory();
	}
	else if (factory == WORD_PROC_APPS::WORD18) {
		return new WORD18_Factory();
	}
}

/********************************************************************/
/* PRINT FUNCTION TO DISPLAY CONCRETE FACTORIES AND THEIR PRODUCTS */
/*******************************************************************/
void print_word_proc(Micro_Office_Factory *factory, string name) {
	cout << name << endl;
	cout << "Panel: " + factory->getPanel()->typeOfProduct() << endl;
	cout << "Button: " +  factory->getButton()->typeOfProduct() << endl;
	cout << "Text Box: " + factory->getTextBox()->typeOfProduct() << endl;
	cout << endl;
};

/********************************************************************/
/* PRINT FUNCTION TO DISPLAY WARNING IF CONFIG_FILE.TXT CONTAINS   */
/*		MORE THAN TWO INSTANCES OF A CONCRETE FACTORY		  */
/*******************************************************************/
void print_warning(string name) {
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "WARNING: SAME GENERATION OF " + name + " IS BEING ATTEMPTED TO RUN MORE THAN TWICE." << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << endl;
};

/********************************************************************/
/* CREATE "CLIENT" TO INTERFACE WITH HIERARCHY TO CREATE SPECIFIC   */
/*   INSTANCES OF EACH WORD PROCESSESING APPLICATION                */
/********************************************************************/
int main() {
	ifstream inputFile;
	string word_processor;
	vector<string> all_word_processors;
	int WORD90_WARN = 0, WORD00_WARN = 0, WORD10_WARN = 0, WORD18_WARN = 0;
	inputFile.open("config_file.txt");

	if (!inputFile) { 
		cout << "Unable to open 'config_file.txt'";
		exit(1);
	}

	while (inputFile.good()) {
		getline(inputFile, word_processor);
		all_word_processors.push_back(word_processor);
	}
	inputFile.close();

	for (unsigned int i = 0; i < all_word_processors.size(); i++) {
		if (all_word_processors[i] == "WORD90") {
			if (WORD90_WARN > 2) {
				print_warning(all_word_processors[i]);
			}
			else {
				Micro_Office_Factory *factory = Micro_Office_Factory::createFactory(Micro_Office_Factory::WORD_PROC_APPS::WORD90);
				print_word_proc(factory, all_word_processors[i]);
				WORD90_WARN++;
			}
		}
		else if (all_word_processors[i] == "WORD00") {
			if (WORD00_WARN > 2) {
				print_warning(all_word_processors[i]);
			}
			else {
				Micro_Office_Factory *factory = Micro_Office_Factory::createFactory(Micro_Office_Factory::WORD_PROC_APPS::WORD00);
				print_word_proc(factory, all_word_processors[i]);
				WORD00_WARN++;
			}
		}
		else if (all_word_processors[i] == "WORD10") {
			if (WORD10_WARN >= 2) {
				print_warning(all_word_processors[i]);
			}
			else {
				Micro_Office_Factory *factory = Micro_Office_Factory::createFactory(Micro_Office_Factory::WORD_PROC_APPS::WORD10);
				print_word_proc(factory, all_word_processors[i]);
				WORD10_WARN++;
			}
		}
		else if (all_word_processors[i] == "WORD18") {
			if (WORD18_WARN > 2) {
				print_warning(all_word_processors[i]);
			}
			else {
				Micro_Office_Factory *factory = Micro_Office_Factory::createFactory(Micro_Office_Factory::WORD_PROC_APPS::WORD18);
				print_word_proc(factory, all_word_processors[i]);
				WORD18_WARN++;

			}
		}
	}
	return 0;
}