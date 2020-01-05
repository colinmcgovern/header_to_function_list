#include <sstream>
#include <string>
#include <fstream>
#include <regex>
#include <iostream>

using namespace std;

/*
  _____     ___        __  ___    _____                    
 / ___/__  / (_)__    /  |/  /___/ ___/__ _  _____ _______ 
/ /__/ _ \/ / / _ \  / /|_/ / __/ (_ / _ \ |/ / -_) __/ _ \
\___/\___/_/_/_//_/ /_/  /_/\__/\___/\___/___/\__/_/ /_//_/
                                                           
FEEL FREE TO COPY AND REUSE
*/

//TO COMPILE:  g++ header_to_function_list.cpp -std=c++11

int main ( int argc, char *argv[] ){

	string output;

	if(argc!=3){
		cout << "Correct usage:" << endl;
		cout << "./header_to_function_list input_file output_delimiter" << endl;
		return 0;
	}

	ifstream infile(argv[1]);

	int skip_delim = 1;

	string line;
	while (getline(infile, line))
	{
	    istringstream iss(line);

	    regex r(".+\(.*\)");
	    if(regex_match(line,r)){

	    	string function_name = "";
	    	int insert_into_function_name = 0;

			for(char& c : line) {

				if(c=='(' && function_name.length()>0 ){
					if(!skip_delim){
						output.append(argv[2]);
					}
					output += function_name;
	    			insert_into_function_name = 0;
	    			skip_delim = 0;
				}

				if(insert_into_function_name){
					function_name += c;
				}

				if(c==' '){
					function_name = "";
					insert_into_function_name = 1;
				}

			}

	    }

	}

	cout << output << endl;
}