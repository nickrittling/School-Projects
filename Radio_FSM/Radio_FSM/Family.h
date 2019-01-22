#pragma once
#ifndef FAMILY_H
#define FAMILY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <thread>
#include "Radio.h"
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;


class Family {
	friend class Radio;
public:
	Family();
	void use_radio();
private:
	std::vector<std::string> fam;
	Radio radio;
};


Family::Family() :radio() {
	fam = { "mom", "dad", "son", "daughter" };
	std::srand(std::time(nullptr));
}

void Family::use_radio() {
	int count = 30;
	while (count-- > 0) {
		if (radio.getState() == "OFF") {

			std::cout << fam[std::rand() % 4] << " wants to listen to music\n";
			radio.Press_On();
		}
		else {
			if (radio.getState() == "ON") {
				radio.Press_Play();
				sleep_until(system_clock::now() + 3s);
			}
			else {
				int ran = std::rand() % 2;
				if (ran == 0) {
					std::cout << fam[std::rand() % 4] << " wants to change channel.\n";
					radio.Change_Station(rand() % 15 + 100);
					radio.Press_Play();
					sleep_until(system_clock::now() + 3s);
				}
				else {
					std::cout << fam[std::rand() % 4] << " decided to turn off the radio\n";
					radio.Press_Off();
					sleep_until(system_clock::now() + 3s);
				}



			}
		}
	}
}
#endif // !FAMILY_H
