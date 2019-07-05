#include <stdio.h>
#include <iostream>
#include <string>
#include "main_helper.h"

int main(int argc, char **argv)
{
	//Functions to achieve, asking for input
	bool shut=false;
	while(!shut){
		//asking for user options
		std::cout << "Please enter an option or enter \"opts\" for a list of options" << std::endl;
		std::string s;
		std::cin >> s;
		if(s=="opts"){
			printOpts();
		}
		else if(s=="restaurant"){
			//print out restaurant information list
		}
		else if(s=="check"){
			//enter the information page and options for a particular restuarant
		}
		else if(s=="edit"){
			//manage restaurant list
		}
		else if(s=="quit"){
			shut=true;
		}
	}
}
