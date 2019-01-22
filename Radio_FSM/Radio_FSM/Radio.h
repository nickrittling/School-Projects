#pragma once
#ifndef RADIO_H
#define RADIO_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

/*
FSM OF A RADIO
CURRENT_STATE			TRANSITION				NEXT_STATE
ON						PLAY_MUSIC				PLAY
PRESS_OFF				OFF

OFF						PRESS_ON				ON

PLAY					CHANGE_STATION			STATIONCHANGE
PRESS_OFF				OFF

STATIONCHANGE			STOP_CHANGE				PLAY
*/


class Radio {
public:
	Radio();
	void Press_On();
	void Press_Off();
	void Press_Play();
	void Change_Station(double);
	std::string getState();
private:
	std::string state;
	double frequency;
};


Radio::Radio() {
	std::cout << "There is a radio\n\n";
	state = "OFF";
	frequency = 100.0;
}


void Radio::Press_On() {
	state = "ON";
	std::cout << "The radio is turned on\n";
}

void Radio::Press_Off() {
	state = "OFF";
	std::cout << "The radio is turned off\n\n";
}

void Radio::Press_Play() {
	std::cout << std::setprecision(4) << "Now playing chanel " << frequency << std::endl << std::endl;
	state = "PLAY";
}

void Radio::Change_Station(double freq) {
	frequency = freq;
	std::cout << std::setprecision(4) << "Change chanel to " << freq << std::endl << std::endl;
}

std::string Radio::getState() {
	return state;
}
#endif // !RADIO_H

