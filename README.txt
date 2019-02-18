JAYCIE RABY | CIS 476 | WINTER 2019 | 18 FEBRUARY 2019

Overview:
	1) Goal
	2) Description
	3) Program Environment
	4) Deliverables
	4) Hierarchy
	5) Implementation Strategy
	6) References

	Goal: 
		Create a program, and corresponding UML Diagram, that integrates Singleton into 
			Abstract Factory Pattern. 
		
		The ouput should include three different messages for 
			the generation in configuration file, and a warning message should be displayed if
			the same generation are asked to run more than twice.

		Definition of an Abstract Factory:
			"Provide an interface for creating families of related or dependent 
				objects without specifying their concrete classes.[1]"
		Definition of Singleton:
			"Ensure a class only has one instance, and provide a global point of access to it.[1]"

	Description:
		A software company MicroOffice has produced four generations of Word Processing Applications, 
		called:
			Word90
			Word00
			Word10
			Word18
		Suppose you are writing a program to test their GUIs. 
		The GUI components we are interested in are:
			Panel
			Button
			Textbox.
		These GUI components look a little different in each generation. 
	
		Each generation has it own program for testing these GUI components. 
	
		To know which test to run, you will need to instantiate objects that correspond to each one of 
			the GUI components. 
		
		We assume that generations of the Word to be tested are stored in a configuration file (text file).
	
		Because this situation fits the Abstract Factory pattern so well, you can use that pattern to 
			organize the creation of objects that correspond to GUI components. 
		
		You will also need to use the variation of singleton pattern to ensure that at most two instances 
			of each generation in each test run. 
		
		Please note:
			Finishing running all generations specified in the configuration file is considered as one test run. 
	
		Here is an example of the configuration file content. 
			You can create your own.
				Word90
				Word00
				Word90
				Word18
				Word10
				Word00
				Word18
				Word90
				Word00

	Program Environment:
		This program was created and tested in a Windows Visual Studio 2017 Environment
			as a .cpp (C++) file.
		Files include:
			UML Diagram, source.cpp file, and config_file.txt

	Deliverables for this Project:
		1) UML Diagram 
			1a) Integrate Singelton Into Abstract Factory Pattern
		2) Source Code (C++) based on UML Diagram
			2a) Output: Display three different messages for generation specified
				in configuration file.
			2b) Output: Warning message if same generation are asked to
				run more than twice.
		3) Zip UML Diagram, source code and output screenshot in .zip file

	Hierarchy
		*HIERARCHY TO CREATE ABSTRACT FACTORY FOR MICROOFFICE VERSIONS*
		MicroOffice
			[WORD90, WORD00, WORD10, WORD18]
				[panel, button, textbox]
					[alerts, cards, rounded, quotes,
					bckgrndClr_red, backgrndClr_blue, bckgrndClr_orange, bckgrndClr_purple,
					type_text, type_submit, type_reset, type_value]

	Implementation Details
		1) Create Abstract Products: panel, button and text box

		2) Create Concrete Products of Abstract Products:
				Panel -> [alerts, cards, rounded, quotes]
				Button ->[bckgrndClr_red, backgrndClr_blue, bckgrndClr_orange, bckgrndClr_purple]
				Text Box -> [type_text, type_submit, type_reset, typea_value]

		3) Create Abstract Factory of all Word Processing Applications:
			Word Processing Applications = [WORD90, WORD00, WORD10 and WORD18]

		4) Create Concrete Factories for EACH Word Processing Application
			WORD90 = [panel(alerts), button(bckgrndClr_red), textbox(type_text)]

	References	
		1) Gamma, Erich, et al. Design Patterns: Elements of Reusable Object-Oriented Software. 1994.